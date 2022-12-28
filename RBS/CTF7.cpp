#include"crow.h"
#include "crow/middlewares/cors.h"
#include "Korisnik.h"
#include<iostream>
#include<string>

/*typedef struct test {
    char newName[20];
    char oldName[20];
} nameChangeData;

nameChangeData nameChange;*/

void initCTF7(crow::App<crow::CORSHandler>& app)
{
    CROW_ROUTE(app, "/ctf7")
        .methods("POST"_method)
        ([](const crow::request& req) {
        auto x = crow::json::load(req.body);

        if (!x || !x.has("username"))
            return crow::response(400);

        strcpy(korisnikData::users[0].name, std::string(x["username"].s()).c_str());

        return crow::response(crow::json::wvalue({
                      {"name", korisnikData::users[0].name},
                      {"credit", korisnikData::users[0].credit},
            }));
            });
}