#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QtCore>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_clicked();

    void on_con_clicked();

    void on_sort_clicked();

    void on_show_clicked();

    void on_help_clicked();

    void on_del_clicked();

    void on_enter_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
