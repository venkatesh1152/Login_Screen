#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "databaseconnection.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    databaseConnection database;
    engine.rootContext()->setContextProperty("database",&database);
    const QUrl url(QStringLiteral("qrc:/LoginApplication/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
