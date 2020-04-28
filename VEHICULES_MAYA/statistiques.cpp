#include "statistiques.h"
#include "ui_statistiques.h"
#include "connexion.h"
#include <QMap>
#include <QVector>
#include <QString>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include <QSqlQuery>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE
statistiques::statistiques(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
    QVector <QPieSlice *> tab;
        QPieSeries *series = new QPieSeries();
        QSqlQuery qry;
        int tous=0;
        int panne=0;
        int fonctionnel=0;

        qry.prepare("select * from VEHICULES");
        if (qry.exec())
        {

            while (qry.next())
            {

    tous++;
    if (qry.value(4)>20)
    {
        panne++;
    }
    else if(qry.value(4)<=20)
    {
        fonctionnel++;
    }
            }
        }


        qDebug () << " " << panne;
            qDebug () << " " << fonctionnel;


float testing1 =(panne*100)/tous;
float testing2 =100-testing1;
QString pleasework = QString::number(testing1);
QString pleaseworks= QString::number(testing2);
    series ->append("supp 20 "+pleasework+"%",(panne));
        series ->append("inf 20 "+pleaseworks+"%",(fonctionnel));


QPieSlice * slice0= series->slices().at(0);
slice0->setLabelVisible();
QPieSlice * slice1= series->slices().at(1);
slice1->setLabelVisible();

    if (panne>fonctionnel)
    {

       slice0->setExploded();
        slice0->setPen(QPen(Qt::darkGreen,1));
       slice0->setBrush(Qt::red);

    }
    else
    {

 slice1->setExploded();
  slice1->setPen(QPen(Qt::darkGreen,1));
 slice1->setBrush(Qt::red);
    }





    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("VEHICULES  : ");
    chart->legend()->hide();



                QChartView *chartview = new QChartView (chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        QGridLayout *mainLayout = new QGridLayout;
            mainLayout->addWidget(chartview, 1, 1);
            setLayout(mainLayout);


}

statistiques::~statistiques()
{
    delete ui;
}
