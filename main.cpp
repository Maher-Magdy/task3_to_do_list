#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QString>
#include <QVector>
#include <QDebug>
#include <QPair>
#include <QObject>
#include <QtGui>
#include <QtQml>

#include "QAbstractListModel_Data.h"
int main(int argc, char *argv[])
{
    //command line
    QGuiApplication app(argc, argv);
    //engine
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/task3_to_do_list/main.qml"));
    engine.addImportPath("D:/Atomica/Repos/task3_to_do_list");
    //unknown code
    QObject::connect
        (
            &engine,
            &QQmlApplicationEngine::objectCreated,
            &app,
            [url](QObject *obj, const QUrl &objUrl)
            {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            },
            Qt::QueuedConnection
            );


    //main code area
    qmlRegisterType<QAbstractListModel_Data>("task3_to_do_list", 1, 0, "ToDoData");


    //QAbstractListModel_Data _Data;
    //_Data.m_data.push_back(QString("test"));
    //QQmlContext* context=engine.rootContext();
    //context->setContextProperty("_Data",&_Data);
    //loading qml
    engine.load(url);
    return app.exec();

}
