#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <fstream>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 //  QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
//  db.setDatabaseName("C:/Users/samar/OneDrive/Masaüstü/data/database.db");




    QSqlDatabase db= QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("veriler");
    db.setUserName("postgres");
    db.setPassword("172754");


    if(!db.open()){
        QMessageBox::information(this,"Uyarı","Bağlanmadı");
    }
    /*else { QMessageBox::information(this,"Uyarı","Bağlandı");}*/

    QSqlQuery *gry = new QSqlQuery;
    gry->exec("select * from users");
    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*gry);
    ui->tableView->setModel(model_tablom);

//----------------------------------------------------------------------------------------
    yeni_pencere = new settings();
    connect(yeni_pencere,SIGNAL(add_new_user_clicked()),this,SLOT(add_new_user_slot()));


    ui->pushButton_Ekle->setToolTip("<font color='black'><b>ADD</b> ");
    ui->pushButton_Sil->setToolTip("<font color='black'><b>DELETE</b> ");

    connect(this,SIGNAL(yenileme()),this,SIGNAL(yenileme()));
//--------------------------------------------------------------------------------
   /*
    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM users");
    QSqlQueryModel *model_tabl = new QSqlQueryModel;
    model_tabl->setQuery(*query);
    ui->tableView->setModel(model_tabl);



    //Toplam Ürün Sayısı COUNT işlemi
    QSqlQuery *queryCount = new QSqlQuery;
    queryCount->exec("SELECT count(*) FROM users");
    queryCount->next();
    int sno_sayisi = queryCount->value(0).toInt();
    // Toplam Ürün Sayısı COUNT işlemi



    while(query->next()){
        seriNom << query->value(1).toString();
    }

    for (int i=0; i<sno_sayisi; i++ ) {
        seriNo = seriNom[i];
       // qDebug() << seriNo;
    }


    QFile dosyam("C:/Users/samar/OneDrive/Masaüstü/excell/excel.csv");
    dosyam.open(QIODevice::WriteOnly);
    QTextStream ciktimiz(&dosyam);
    for (int i=0; i<sno_sayisi; i++ ) {
        seriNo = seriNom[i];
        ciktimiz << seriNo << Qt::endl;

        QSqlQueryModel *model_tablo = new QSqlQueryModel;
        model_tablo->setQuery(seriNo);
        ui->tableView->setModel(model_tablo);
       // qDebug() << seriNo;
    }


*/

}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::yenileme()
{
    QSqlQuery *gry = new QSqlQuery;
    gry->exec("SELECT * FROM users");
    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*gry);
    ui->tableView->setModel(model_tablom);
}



void MainWindow::on_pushButton_Ekle_clicked()
{

    QSqlQuery *gry_ekle = new QSqlQuery;

     QString name = ui->lineEdit_isim->text();
     QString age  = ui->lineEdit_yas->text();
     QString surname = ui->lineEdit_Soyisim->text();



     QDate trh = QDate::currentDate();
     QString Tarih=trh.toString();

     if(name==""){
           QMessageBox::critical(this,"HATA","isim Boş Bırakılamaz.");
     }else if(surname==""){
          QMessageBox::critical(this,"HATA","Soyisim Boş Bırakılamaz.");
     }else if(age==""){
          QMessageBox::critical(this,"HATA","Yaş Boş Bırakılamaz.");
     }else{




          gry_ekle->exec("insert into users values('"+name+"','"+surname+"','"+age+"','"+Tarih+"')");
           QMessageBox::information(this,"EKLENDİ","Ekleme Başarılı");


             yenileme();
     }
}

void MainWindow::on_pushButton_Sil_clicked()
{
    yeni_pencere->show();
}

void MainWindow::add_new_user_slot()
{


    QSqlQuery *gry_sil = new QSqlQuery;
    yeni_pencere->close();
    QString new_name = yeni_pencere->id_getir();
    gry_sil->exec("DELETE FROM users WHERE id ='"+new_name+"' ");
    QMessageBox::information(this,"SİLİNDİ","Silme Başarılı");
    yeni_pencere->clear_lineEdit();

    yenileme();


}

void MainWindow::on_pushButton_id_clicked()
{
    QSqlQuery *gry_id = new QSqlQuery;
    QString id =ui->lineEdit_idAra->text();


    gry_id->exec("SELECT * FROM users WHERE id = '"+id+"'");

    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*gry_id);
    ui->tableView_2->setModel(model_tablom);
}
