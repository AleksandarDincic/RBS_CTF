#include "crow.h"
#include "crow/middlewares/cors.h"
#include "Korisnik.h"
#include<iostream>
#include<string>

std::string korisnikData::whiteList[4] = { "Guga", "Paja", "Bogdan", "Type"};
int korisnikData::creditMap[4] = { 0, 0, 0, 0 };
#define WHITE_LIST_SIZE sizeof(korisnikData::whiteList)/sizeof(korisnikData::whiteList[0])

korisnikData korisnik;

void initCTF2(crow::App<crow::CORSHandler>& app)
{
    CROW_ROUTE(app, "/ctf2")
        .methods("POST"_method)
        ([](const crow::request& req) {
        auto x = crow::json::load(req.body);

        if (!x || !x.has("username"))
            return crow::response(400);


        for (int i = 0; i < WHITE_LIST_SIZE; i++) {

            korisnik.successfullLogin = korisnikData::whiteList[i].compare(std::string(x["username"].s())) == 0;

            strcpy(korisnik.logIme, std::string(x["username"].s()).c_str());

            if (korisnik.successfullLogin)
            {
                std::cout << "Korisnik se ulogovao: "<<korisnik.logIme;
                return crow::response(200);
            }
        }
        return crow::response(401);
    });
}