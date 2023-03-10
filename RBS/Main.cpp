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

    initCTF3(app);

    initCTF4(app);

    initCTF5(app);

    initCTF6(app);

    initCTF7(app);

    initCTF8(app);

    initCTF9(app);

    app.port(18080).multithreaded().run();
}