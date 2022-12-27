#pragma once
#include"crow.h"
#include "crow/middlewares/cors.h"

void initCTF1(crow::App<crow::CORSHandler>& app);

void initCTF2(crow::App<crow::CORSHandler>& app);