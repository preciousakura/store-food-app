#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sidebar_widget->setVisible(false);
    ui->home_btn_1->setChecked(true);

    qDebug() << QSqlDatabase::drivers();
    DB_Connection = QSqlDatabase::addDatabase("QPSQL");
    DB_Connection.setHostName("127.0.0.1");
    DB_Connection.setUserName("postgres");
    DB_Connection.setPassword("admin");
    DB_Connection.setDatabaseName("postgres");

    if(DB_Connection.open())
    {
        qDebug() << "Database is connected";
    }
    else
    {
        qDebug() << "Database is not connected";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_home_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_home_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_product_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_product_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_order_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_order_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_user_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->user_pages->setCurrentIndex(0);
}

void MainWindow::on_user_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->user_pages->setCurrentIndex(0);
}

void MainWindow::on_create_user_btn_clicked()
{
    ui->user_pages->setCurrentIndex(1);
}

void MainWindow::on_submit_user_btn_clicked()
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();
    QSqlQuery Query_Insert_Data(DB_Connection);
    Query_Insert_Data.prepare("INSERT INTO users(name, birth, phone, street, number, neighborhood, complement) VALUES(:name, :birth, :phone, :street, :number, :neighborhood, :complement)");
    Query_Insert_Data.bindValue(":name", ui->user_name_field->text());
    Query_Insert_Data.bindValue(":birth", ui->user_birth_field->text());
    Query_Insert_Data.bindValue(":phone", ui->user_phone_field->text());
    Query_Insert_Data.bindValue(":street", ui->user_street_field->text());
    Query_Insert_Data.bindValue(":number", ui->user_number_field->text());
    Query_Insert_Data.bindValue(":neighborhood", ui->user_neighborhood_field->text());
    Query_Insert_Data.bindValue(":complement", ui->user_complement_field->text());
    Query_Insert_Data.exec();
    QSqlDatabase::database().commit();

    QDialog *dialog = new QDialog();
    dialog->setMinimumHeight(480);
    dialog->setMaximumWidth(640);
    dialog->show();

    DB_Connection.close();
}

