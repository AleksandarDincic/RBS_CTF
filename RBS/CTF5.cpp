#include "crow.h"
#include "crow/middlewares/cors.h"
#include<iostream>
#include<string>

typedef struct ctf5Helper {
    int id;
    bool bought;
}ctf5Item;

typedef struct ctf5 {

    ctf5Item items[10];
    int numOfItems;
    bool flag;

}ctf5Data;

ctf5Data data5;

void initCTF5(crow::App<crow::CORSHandler>& app)
{
    data5.flag = false;
    data5.numOfItems = 10;

    for (int i = 0; i < 10; i++)
    {
        data5.items[i].id = i;
        data5.items[i].bought = false;
    }

    CROW_ROUTE(app, "/ctf5")
        .methods("POST"_method)
        ([](const crow::request& req) {
        auto x = crow::json::load(req.body);

        if (!x || !x.has("numItems"))
            return crow::response(400);

        int num = x["numItems"].i();
        for (int i = 0; i < num; i++)
            data5.items[i].bought = true;


        return crow::response(crow::json::wvalue({
            {"flag", data5.flag ? "Flag" : "no Flag"}
            }));
    });
}