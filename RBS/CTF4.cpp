#include"crow.h"
#include "crow/middlewares/cors.h"
#include<iostream>
#include<string>

typedef struct ctf4 {
    std::string carName = "Car name";
    std::string carPrice = "10000";
    std::string carYear = "2005";
    std::string carBrand = "Toyota";
    char comment[100] = "newest comment";
    int soldStatus = 0;
} ctf4Data;


ctf4Data data;

void initCTF4(crow::App<crow::CORSHandler>& app)
{
    CROW_ROUTE(app, "/ctf4")
        .methods("GET"_method, "POST"_method)
        ([](const crow::request& req) {
        if (req.method == "GET"_method)
        {
            return crow::response(crow::json::wvalue({
                      {"name", data.carName},
                      {"price", data.carPrice},
                      {"year", data.carYear},
                      {"brand",data.carBrand},
                      {"comment", data.comment},
                      {"sold", data.soldStatus ? "flag" : "not sold"},
                }));
        }
        else
        {
            auto x = crow::json::load(req.body);
            std::cout << req.body << std::endl;
    
            if (!x || !x.has("comment"))
            {
                std::cout << "AAAAAAAA" << std::endl;
                std::cout << x << std::endl;
                return crow::response(400);
            }


            strcpy(data.comment, std::string(x["comment"].s()).c_str());

            return crow::response(200);
        }
            });
}