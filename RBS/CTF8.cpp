#include"crow.h"
#include "crow/middlewares/cors.h"
#include "Korisnik.h"
#include<iostream>
#include<string>

void initCTF7(crow::App<crow::CORSHandler>& app)
{
    CROW_ROUTE(app, "/ctf7")
        .methods("POST"_method)
        ([](const crow::request& req) {
        auto x = crow::json::load(req.body);
        char c;
        char ret[4];
        strcpy(ret, "rsd");
        void* pointer = &c;

        if (!x || !x.has("number"))
            return crow::response(400);

        strcpy(korisnikData::users[0].name, std::string(x["number"].s()).c_str());

        int num = x["number"].i();

        *(int *)(pointer) = num;


        char k = *(char*)(pointer);
        int kk = int(k);

        std::string msg = std::to_string(kk*10) + std::string(ret);

        return crow::response(crow::json::wvalue({
                      {"RacunCena", msg}
            }));
            });
}