#include "crow.h"
#include "crow/middlewares/cors.h"

int main()
{
    //crow::SimpleApp app;
    crow::App<crow::CORSHandler> app;
    
    CROW_ROUTE(app, "/")([]() {
        return "Hello world";
        });

    app.port(18080).multithreaded().run();
}