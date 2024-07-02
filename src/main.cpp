#include <QQmlApplicationEngine>
#include <QGuiApplication>

int main(int argc, char *argv[]) {

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/AppModule/src/ui/main.qml")));

    return QGuiApplication::exec();
}