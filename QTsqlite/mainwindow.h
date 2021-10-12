#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QSqlQuery>
#include <QFile>
#include "settings.h"
#include <QTextStream>
#include <QList>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString seriNo;
    QList<QString> seriNom;



    void yenileme();
private slots:



    void on_pushButton_Ekle_clicked();



    void on_pushButton_Sil_clicked();

    void add_new_user_slot();



    void on_pushButton_id_clicked();

private:
    Ui::MainWindow *ui;


    settings *yeni_pencere;

};
#endif // MAINWINDOW_H
