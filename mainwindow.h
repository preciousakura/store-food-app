#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_home_btn_1_clicked();
    void on_home_btn_2_clicked();
    void on_user_btn_1_clicked();
    void on_user_btn_2_clicked();
    void on_product_btn_1_clicked();
    void on_product_btn_2_clicked();
    void on_order_btn_1_clicked();
    void on_order_btn_2_clicked();
    void on_submit_user_btn_clicked();

    void on_create_user_btn_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_Connection;
};
#endif // MAINWINDOW_H
