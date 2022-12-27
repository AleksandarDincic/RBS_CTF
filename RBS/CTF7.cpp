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

void initCTF6(crow::App<crow::CORSHandler>& app)
{
    CROW_ROUTE(app, "/ctf6")
        .methods("POST"_method)
        ([](const crow::request& req) {
        auto x = crow::json::load(req.body);

        if (!x || !x.has("username"))
            return crow::response(400);

        strcpy((char *)korisnikData::whiteList[0].c_str(), std::string(x["username"].s()).c_str());

        return crow::response(200);
            });
}