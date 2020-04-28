#ifndef ASSURANCE_H
#define ASSURANCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Assurance
{
private:
    int Reference;
    QString Type;
    QString Assureur;
    float Tarif;
public:
    Assurance();
    Assurance(QString,QString,float);

    int getReference();
    QString getType();
    QString getAssureur();
    float getTarif();

    bool ajoutAssurance();
    bool modifierAssurance(int);
    bool supprimerAssurance(int);

    QSqlQueryModel *afficherAssurance();

};

#endif // ASSURANCE_H
