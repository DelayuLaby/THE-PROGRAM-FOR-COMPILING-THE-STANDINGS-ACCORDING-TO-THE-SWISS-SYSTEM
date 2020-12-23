#ifndef PLAYERTABLEFORM_H
#define PLAYERTABLEFORM_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class PlayerTableForm;
}

class PlayerTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerTableForm(List<Player>*list = nullptr);
    ~PlayerTableForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PlayerTableForm *ui;
    List<Player>* list;
};

#endif // PLAYERTABLEFORM_H
