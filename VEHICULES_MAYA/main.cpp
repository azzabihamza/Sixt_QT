#include "login.h"
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{  QApplication a(argc, argv);

    Connexion c;

  bool test=c.ouvrirConnexion();
  login w;

  if(test)
  {
      w.resize(404,203);
      w.show();}


    return a.exec();}
