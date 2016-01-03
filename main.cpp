#include "backend/include/Application.h"
#include "ui/qt/include/QTUIApplication.h"

int main(int argc, char *argv[])
{
    RabidSQL::QTUIApplication app(argc, argv);

    return app.bind(RabidSQL::Application::getInstance())->run();
}