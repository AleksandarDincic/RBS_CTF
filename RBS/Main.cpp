#define _CRT_SECURE_NO_WARNINGS
#include "crow.h"
#include "crow/middlewares/cors.h"
#include<iostream>
#include<string>

typedef struct test {
    std::string userName = "Admin";
    char checkPassword[20];
    char password[20] = "Sifra12345";
} adminData;

adminData testAdmin;

int main()
{
    //crow::SimpleApp app;
    crow::App<crow::CORSHandler> app;
    
    CROW_ROUTE(app, "/")([]() {
        return "Hello world";
        });

    CROW_ROUTE(app, "/ctf1")
        .methods("POST"_method)
        ([](const crow::request& req) {
            auto x = crow::json::load(req.body);

            if (!x || !x.has("username") || !x.has("password"))
                return crow::response(400);

            if (testAdmin.userName.compare(std::string(x["username"].s())) == 0)
            {
                strcpy(testAdmin.checkPassword, std::string(x["password"].s()).c_str());

                std::cout << testAdmin.password << std::endl;

                if (strcmp(testAdmin.checkPassword, testAdmin.password) != 0)
                    return crow::response(401);
            }
            else
                return crow::response(400);

            return crow::response(200);
            });

    app.port(18080).multithreaded().run();
}