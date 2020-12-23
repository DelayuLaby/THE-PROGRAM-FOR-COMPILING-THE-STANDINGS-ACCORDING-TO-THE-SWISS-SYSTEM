#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playertableform.h"
#include <QDebug>
#include <QMessageBox>

void MainWindow::sort(List<Player> * list) {
    for (int i = 0; i < list->size(); i++) {
        for (int j = list->size() - 1; j > i; j--) {
            if (list->operator[](i).getPoint() < list->operator[](j).getPoint()) {
                Player player(list->operator[](i).getId(), list->operator[](i).getSurname(), list->operator[](i).getPoint());
                list->operator[](i).setId(list->operator[](j).getId());
                list->operator[](i).setPoint(list->operator[](j).getPoint());
                list->operator[](i).setSurname(list->operator[](j).getSurname());
                list->operator[](j).setId(player.getId());
                list->operator[](j).setSurname(player.getSurname());
                list->operator[](j).setPoint(player.getPoint());
            }
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    playerList = new List<Player>();
    gameList = new List<List<Game>*>();
    File::openPlayer(playerList, "players.txt");
    for (int i = 0; i < playerList->size(); i++) {
        List<Game>*list = new List<Game>();
        string text = QString::number(i + 1).toStdString() + ".txt";
        File::openGame(list, text);
        gameList->pushTail(list);
        list->~List();
    }
    List<Player> *tableList = new List<Player>();
    File::openPlayer(tableList, "players.txt");
    sort(tableList);
    int row = 0;
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Первый игрок"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Балл"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Второй игрок"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Балл"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Результат 1-ого"));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Результат 2-ого"));
    while (tableList->size() > 0) {
        int i = 1;
        bool flag = true;
        while (flag && i < tableList->size()) {
            List<Game>* forGame = gameList->operator[](tableList->operator[](i).getId() - 1);
            for (int j = 0; j < forGame->size(); j++) {
                if(forGame->operator[](j).getEnemyId() == tableList->operator[](i).getId()) {
                    flag = false;
                }
            }
            if (!flag) {
                flag = true;
            } else {
                break;
            }
        }
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(tableList->operator[](0).getSurname()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(tableList->operator[](0).getPoint())));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(tableList->operator[](i).getSurname()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(tableList->operator[](i).getPoint())));
        for(; i < tableList->size() - 1; i++) {
            tableList->operator[](i) = tableList->operator[](i + 1);
        }
        tableList->popHead();
        tableList->popTail();
        row++;
    }
    ui->tableWidget->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QApplication::exit(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->clear();
    List<Player> *tableList = new List<Player>();
    File::openPlayer(tableList, "players.txt");
    for (int i = 0; i < tableList->size(); i++) {
        string text = QString::number(i + 1).toStdString() + ".txt";
        ofstream on(text);
        on.close();
        tableList->operator[](i).setPoint(0);
    }
    File::savePlayer(tableList, "players.txt");
    int row = 0;
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Первый игрок"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Балл"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Второй игрок"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Балл"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Результат 1-ого"));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Результат 2-ого"));
    while (tableList->size() > 0) {
        int i = 1;
        bool flag = true;
        while (flag && i < tableList->size()) {
            List<Game>* forGame = gameList->operator[](tableList->operator[](i).getId() - 1);
            for (int j = 0; j < forGame->size(); j++) {
                if(forGame->operator[](j).getEnemyId() == tableList->operator[](i).getId()) {
                    flag = false;
                }
            }
            if (!flag) {
                flag = true;
            } else {
                break;
            }
        }
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(tableList->operator[](0).getSurname()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(tableList->operator[](0).getPoint())));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(tableList->operator[](i).getSurname()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(tableList->operator[](i).getPoint())));
        for(; i < tableList->size() - 1; i++) {
            tableList->operator[](i) = tableList->operator[](i + 1);
        }
        tableList->popHead();
        tableList->popTail();
        row++;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    for(int i = 0; i < playerList->size() / 2; i++) {
        QString first = ui->tableWidget->item(i, 4)->text();
        QString second = ui->tableWidget->item(i, 5)->text();
        if ((first != "1" && first != "0.5" && first != "0,5" && first != "0")) {
            QMessageBox::critical(nullptr, "Внесение новых результатов", "Введите результаты!");
            return;
        }
        if ((second != "1" && second != "0.5" && second != "0,5" && second != "0")) {
            QMessageBox::critical(nullptr, "Внесение новых результатов", "Введите результаты!");
            return;
        }
    }
    for(int i = 0; i < playerList->size() / 2; i++) {
        QString first = ui->tableWidget->item(i, 0)->text();
        QString second = ui->tableWidget->item(i, 2)->text();
        int id1 = 0, id2 = 0;
        for (int j = 0; j < playerList->size(); j++) {
            if (playerList->operator[](j).getSurname() == first) {
                id1 = playerList->operator[](j).getId();
            }
            if (playerList->operator[](j).getSurname() == second) {
                id2 = playerList->operator[](j).getId();
            }
        }
        double result1 = ui->tableWidget->item(i, 4)->text().toDouble();
        double result2 = ui->tableWidget->item(i, 5)->text().toDouble();
        qDebug() << result1 << " " << result2;
        playerList->operator[](id1 - 1).setPoint(playerList->operator[](id1 - 1).getPoint() + result1);
        playerList->operator[](id2 - 1).setPoint(playerList->operator[](id2 - 1).getPoint() + result2);
        gameList->operator[](id1 - 1)->pushTail(Game(id2, result1));
        gameList->operator[](id2 - 1)->pushTail(Game(id1, result2));
    }
    File::savePlayer(playerList, "players.txt");
    for (int i = 0; i < playerList->size(); i++) {\
        string text = QString::number(i + 1).toStdString() + ".txt";
        File::saveGame(gameList->operator[](i), text);
    }
    MainWindow *w = new MainWindow;
    w->show();
    this->close();
    delete this;
}

void MainWindow::on_pushButton_4_clicked()
{
    sortList = new List<Player>();
    File::openPlayer(sortList, "players.txt");
    sort(sortList);
    PlayerTableForm *w = new PlayerTableForm(sortList);
    w->show();
    this->close();
    delete this;
}
