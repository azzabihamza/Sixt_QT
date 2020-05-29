#include "dialogaddassurance.h"
#include "ui_dialogaddassurance.h"

DialogAddAssurance::DialogAddAssurance(int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddAssurance)
{
    ui->setupUi(this);

    ui->comboBoxTypeAssurance->addItems({ "Assurance au tiers", "Assurance au tiers plus", "Assurance tous risques", "Assurance auto au kilomètre" });
    ui->comboBoxTypeAssurance->setCurrentIndex(-1);
    QSqlQueryModel* modalMatricule = new QSqlQueryModel();
    modalMatricule->setQuery("select PLAQUE from VEHICULES");
    ui->comboBoxMatriculeVehicule->setModel(modalMatricule);
    ui->comboBoxMatriculeVehicule->setCurrentIndex(-1);

       /* Method for initializing the model, from which data will be transmitted
        * */
       setupModel();

       /* If the string is not specified, that is equal to -1,
        * then the dialog works on the principle of creating a new record.
        * Namely, in the model of the new line is inserted and the work is done with it.
        * */
       if(row == -1){
           model->insertRow(model->rowCount(QModelIndex()));
           mapper->toLast();
       /* Otherwise, the dialogue is tuned to a given record
        * */
       } else {
           mapper->setCurrentModelIndex(model->index(row,0));
       }

       //createUI();
}

DialogAddAssurance::~DialogAddAssurance()
{
    delete ui;
}

void DialogAddAssurance::setupModel()
{
    model = new QSqlTableModel(this);
    model->setTable(ASSURANCE);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    /* Initialize mapper and bind data fields to objects QLineEdit
     * */
    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->lineEdit_reference, 0);
    mapper->addMapping(ui->comboBoxTypeAssurance, 1);
    mapper->addMapping(ui->lineEdit_Assureur, 2);
    mapper->addMapping(ui->tarifA, 3);
    mapper->addMapping(ui->DateDebutAssurance, 4);
    mapper->addMapping(ui->DateFinAssurance, 5);
    mapper->addMapping(ui->comboBoxMatriculeVehicule, 6);
    /* Manual confirmation of the change via the mapper
     * */
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);

    /* Connect "Connects" from the scroll buttons to prilistyvaniyu data model mapper
     * */
    connect(ui->previousButton, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(ui->nextButton, SIGNAL(clicked()), mapper, SLOT(toNext()));
    /* When you change the index mapper to change the state of the buttons
     * */
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateButtons(int)));
}

void DialogAddAssurance::on_buttonBox_accepted()
{
    /* SQL-query to check for the existence of records with the same credentials.
         * If a record does not exist or is only editable index is currently recording,
         * the dialog box allows you to record in a data table
         * */
        QSqlQuery query;

        QString str = QString("SELECT  MATRICULE  FROM " ASSURANCE
                              " WHERE (  MATRICULE  = '"+ui->comboBoxMatriculeVehicule->currentText()+"' "
                              " AND REFERENCE NOT LIKE '"+ui->lineEdit_reference->text()+"' ");


        query.prepare(str);
        query.exec();
        query.next();

        /* If a record exists, the dialog is a warning message
         * */
        if(query.value(0) == NULL){
            QMessageBox::information(this, trUtf8("erreur"),
                                     trUtf8("Existe deja des la base de donnée "));
        /* Otherwise, you are inserting new data into the table and the dialogue ends
         * with the transmission of a signal to update the table in the main window
         * */
        } else {
            mapper->submit();
            model->submitAll();
            emit signalReady();
            this->close();
        }
}

void DialogAddAssurance::accept()
{

}

void DialogAddAssurance::updateButtons(int row)
{
    /* In that case, if we reach one of the extremes (the first or the last) of the indices
     * in the data table, then we change the state
     * of a corresponding button on the inactive state
     * */
    ui->previousButton->setEnabled(row > 0);
    ui->nextButton->setEnabled(row < model->rowCount() - 1);
}
