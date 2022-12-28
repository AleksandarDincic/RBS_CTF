#include"crow.h"
#include "crow/middlewares/cors.h"
#include "Korisnik.h"
#include<iostream>
#include<string>

typedef struct ctf6 {
    char address[10];
    int funds;
} buyData;

buyData buy;

void initCTF6(crow::App<crow::CORSHandler>& app)
{
    CROW_ROUTE(app, "/ctf6")
        .methods("POST"_method)
        ([](const crow::request& req) {
        auto x = crow::json::load(req.body);

        if (!x || !x.has("address"))
            return crow::response(400);

        buy.funds = korisnikData::users[0].credit;

        strcpy(buy.address, std::string(x["address"].s()).c_str());

        if (buy.funds > 600) {
            return crow::response(200);
        }

        return crow::response(401);
            });
}