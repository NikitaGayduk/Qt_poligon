#include <QCoreApplication>
#include <firstwidget.h>
#include <QtWidgets>
#include <iostream>
#include <QtSQL>
#include <QDebug>
#include <Qstring>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    FirstWidget MainWindow;
//    MainWindow.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "1");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("mydb");
    db.setUserName("root");
    db.setPassword("12345");
    if(!db.open()){qDebug()<<db.lastError();}

    QSqlQuery Query(db);

    Query.prepare("INSERT INTO employee(tab_num, surname, name, patronymic)"
                  "VALUES (:tab_num, :surname, :name, :patronymic)");


    Query.bindValue(":tab_num", 1234);
    Query.bindValue(":surname", "Гайдук");
    Query.bindValue(":name", "Никита");
    Query.bindValue(":patronymic", "Дмитриевич");

    Query.exec();

    qDebug()<<Query.lastError().text();

    return a.exec();


}



