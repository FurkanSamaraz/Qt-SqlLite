#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "settings.h"
namespace Ui {
class settings;
}

class settings : public QWidget
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

    QString id_getir();

    void clear_lineEdit();

signals:
    void add_new_user_clicked();

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
