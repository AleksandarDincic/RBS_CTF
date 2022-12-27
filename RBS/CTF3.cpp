#include"crow.h"
#include "crow/middlewares/cors.h"
#include<iostream>
#include<string>

typedef struct test3 {
    int canTakeFlag = 0;
    int money[3] = {450, 1000, 600};
    std::string names[3] = {"Pera", "Mika", "Laza"};
} ctf3Data;

ctf3Data data3;

int indexFromName(std::string name) {
    for (int i = 0; i < 3; ++i) {
        if (strcmp(name.c_str(), data3.names[i].c_str()) == 0) {
            return i;
        }
    }
    return -1;
}

bool requestFlag() {
    return data3.canTakeFlag;
}

void changeMoney(std::string name, int newAmount) {
    int index = indexFromName(name);
    data3.money[index] = newAmount;
}

crow::json::wvalue getTableData() {
    crow::json::wvalue retVal = {};

    for (int i = 0; i < 3; ++i) {
        retVal[data3.names[i]] = data3.money[i];
    }
    return retVal;
}

void initCTF3(crow::App<crow::CORSHandler>& app)
{
    CROW_ROUTE(app, "/ctf3/changeMoney")
        .methods("POST"_method)
        ([](const crow::request& req) {
        auto x = crow::json::load(req.body);

        if (!x || !x.has("name") || !x.has("newAmount"))
            return crow::response(400);


        changeMoney(x["name"].s(), x["newAmount"].i());

        crow::json::wvalue retVal = getTableData();

        return crow::response(200, retVal);
            });

    CROW_ROUTE(app, "/ctf3/getFlag")
        .methods("GET"_method)
        ([](const crow::request& req) {
        
        if (requestFlag()) {
            return crow::response(200, "Flag captured!");
        }
        else {
            return crow::response(200, "No flag for you!");
        }
            });

    CROW_ROUTE(app, "/ctf3/getData")
        .methods("GET"_method)
        ([](const crow::request& req) {
        crow::json::wvalue retVal = getTableData();
        
        return crow::response(200, retVal);
            });
}