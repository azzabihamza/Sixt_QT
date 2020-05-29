#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "DataBase.db"

#define ASSURANCE               "ASSURANCE"


class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();
    bool inserIntoDeviceTable(const QVariantList &data);

private:
    QSqlDatabase    db;

private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createDeviceTable();
};

#endif // DATABASE_H
