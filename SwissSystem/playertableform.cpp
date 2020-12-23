#include "playertableform.h"
#include "ui_playertableform.h"

PlayerTableForm::PlayerTableForm(List<Player>* list) :
    list(list),
    ui(new Ui::PlayerTableForm)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Игрок"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Балл"));
    for (int i = 0; i < list->size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(list->operator[](i).getSurname()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(list->operator[](i).getPoint())));
    }
    ui->tableWidget->resizeColumnsToContents();
}

PlayerTableForm::~PlayerTableForm()
{
    delete ui;
}

void PlayerTableForm::on_pushButton_clicked()
{
    MainWindow *w = new MainWindow;
    w->show();
    this->close();
    delete this;
}
