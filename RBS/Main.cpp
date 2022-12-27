#include "crow.h"
#include "crow/middlewares/cors.h"
#include "CTF.h"


int main()
{
    //crow::SimpleApp app;
    crow::App<crow::CORSHandler> app;
    
    CROW_ROUTE(app, "/")([]() {
        return "Hello world";
        });

    initCTF1(app);

    initCTF2(app);

    initCTF4(app);

    app.port(18080).multithreaded().run();
}