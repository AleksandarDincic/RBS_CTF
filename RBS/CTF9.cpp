#include"crow.h"
#include "crow/middlewares/cors.h"
#include<iostream>
#include<string>

typedef struct ctf9Node {
	char val;
	struct ctf9Node* next;

} CTF9Node;

CTF9Node* head = nullptr;
CTF9Node* tail = nullptr;

void createList(unsigned char size, std::string values) {
	head = nullptr;
	tail = nullptr;

	for (int i = 0; i < 1 + size; ++i) {
		CTF9Node* newNode = new CTF9Node();
		newNode->val = 'X';
		newNode->next = nullptr;
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail = tail->next = newNode;
		}
	}
	
	int cnt = 0;
	for (CTF9Node* current = head; current != nullptr; current = current->next) {
		if (cnt < values.size()) {
			current->val = values[cnt];
		}

		++cnt;
	}
}

bool requestFlag9() {
	return tail != nullptr && tail->val == 'Y';
}

void initCTF9(crow::App<crow::CORSHandler>& app)
{
    CROW_ROUTE(app, "/ctf9/createList")
        .methods("POST"_method)
        ([](const crow::request& req) {
        auto x = crow::json::load(req.body);

        if (!x || !x.has("size") || !x.has("values"))
            return crow::response(400);

		if (x["size"].i() != x["values"].s().size()) {
			return crow::response(200, "Invalid values size");
		}

        createList((unsigned char) (x["size"].i()), x["values"].s());

        return crow::response(200, "OK");
            });

    CROW_ROUTE(app, "/ctf9/getFlag")
        .methods("GET"_method)
        ([](const crow::request& req) {

        if (requestFlag9()) {
            return crow::response(200, "Flag captured!");
        }
        else {
            return crow::response(200, "No flag for you!");
        }
            });
}
