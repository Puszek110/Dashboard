#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// --------------------------------------Funkcje-----------------------------------------------------------------------------
void con(QString nazwa)
{
    QSqlDatabase baza =  QSqlDatabase ::addDatabase("TEST");
    baza.setHostName("127.0.0.0");
    baza.setUserName("root");
    baza.setPassword("");
    baza.setDatabaseName(nazwa);

    QMessageBox inform;
    if(baza.open())
    {
      inform.setText("Połączenie udane");
    }
    else
    {
     inform.setText("Brak Połączenia, sprawdź dane");
    }
    inform.exec();
}

void select(QString nazwa)
{
    QSqlDatabase::database().transaction();
        QSqlQuery query;
        query.exec("SELECT * FROM "+nazwa);
    QSqlDatabase::database().commit();
}
void sort(QString nazwa, QString kolumna)
{
    QSqlDatabase::database().transaction();
        QSqlQuery query;
        query.exec("SELECT * FROM "+nazwa+"order by"+kolumna);
    QSqlDatabase::database().commit();
}
void add(QString nazwa, QString k1, QString k2, QString k3, QString k4, QString k5)
{
    QSqlDatabase::database().transaction();
        QSqlQuery query;
        query.exec("INSERT INTO "+nazwa+" VAULES("+k1+","+k2+","+k3+","+k4+","+k5+")");
    QSqlDatabase::database().commit();
}
void del(QString nazwa, QString k1)
{
    QSqlDatabase::database().transaction();
        QSqlQuery query;
        query.exec("DELETE FROM "+nazwa+" WHERE id="+k1);
    QSqlDatabase::database().commit();
}
//-----------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_con_clicked()
{
   QString nazwa = "baza";
   con(nazwa);
}


void MainWindow::on_sort_clicked()
{
    QString nazwa = "baza";
    QString kolumna = "baza";
    sort(nazwa, kolumna);
}


void MainWindow::on_show_clicked()
{
    QString nazwa = "baza";
    select(nazwa);
}


void MainWindow::on_help_clicked()
{
QMessageBox inform;
inform.setText("Instrukacja");
inform.exec();
}

void MainWindow::on_del_clicked()
{
    QString nazwa,k1;
    del(nazwa,k1);
}


void MainWindow::on_add_clicked()
{
     QString nazwa,k1,k2,k3,k4,k5;
     add(nazwa,k1,k2,k3,k4,k5);
}

void MainWindow::on_enter_clicked()
{

}


void MainWindow::on_exit_clicked()
{

}


