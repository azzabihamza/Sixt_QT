#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase()
{
    /*if(!QFile("C:/example/" DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else { */
        this->openDataBase();
    //}
}

bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createDeviceTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Failed to restore the database";
        return false;
    }
    return false;
}

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QODBC");
   // db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Azzabi");
    db.setPassword("Admin");
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase()
{
    db.close();
}

bool DataBase::createDeviceTable()
{
    /*QSqlQuery query;
    if(!query.exec( "CREATE TABLE " DEVICE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            DEVICE_HOSTNAME  " VARCHAR(255)    NOT NULL,"
                            DEVICE_IP        " VARCHAR(16)     NOT NULL,"
                            DEVICE_MAC       " VARCHAR(18)     NOT NULL"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << ASSURANCE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;*/
}

bool DataBase::inserIntoDeviceTable(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO ASSURANCE (REFERENCE, TYPE, ASSUREUR, TARIF, DATEDEBUT, DATEFIN, MATRICULE) "
                        "VALUES (:ref, :type, :assureur, :tarif, :dd, :df, :matricule)");
    query.bindValue(":ref",      data[0].toInt());
    query.bindValue(":type",     data[1].toString());
    query.bindValue(":assureur", data[2].toString());
    query.bindValue(":tarif",    data[3].toDouble());
    query.bindValue(":dd",       data[4].toDate());
    query.bindValue(":df",       data[5].toDate());
    query.bindValue(":matricule",data[6].toString());


    if(!query.exec()){
        qDebug() << "error insert into " << ASSURANCE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}
