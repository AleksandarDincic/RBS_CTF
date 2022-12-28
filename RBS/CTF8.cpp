#include"crow.h"
#include "crow/middlewares/cors.h"
#include "Korisnik.h"
#include<iostream>
#include<string>

typedef struct ctf8 {
    char c;
    char ret[4];
}ctf8Data;

ctf8Data data8;

void initCTF8(crow::App<crow::CORSHandler>& app)
{
    CROW_ROUTE(app, "/ctf8")
        .methods("POST"_method)
        ([](const crow::request& req) {
        auto x = crow::json::load(req.body);
        strcpy(data8.ret, "rsd");
        void* pointer = &data8.c;

        if (!x || !x.has("number"))
            return crow::response(400);

        int num = x["number"].i();

        *(int *)(pointer) = num;


        char k = *(char*)(pointer);
        int kk = int(k);

        std::string msg = std::to_string(kk*10) + std::string(data8.ret);

        return crow::response(crow::json::wvalue({
                      {"RacunCena", msg}
            }));
            });
}