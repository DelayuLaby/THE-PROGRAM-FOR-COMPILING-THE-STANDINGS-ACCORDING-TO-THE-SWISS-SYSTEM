/********************************************************************************
** Form generated from reading UI file 'playertableform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERTABLEFORM_H
#define UI_PLAYERTABLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerTableForm
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *PlayerTableForm)
    {
        if (PlayerTableForm->objectName().isEmpty())
            PlayerTableForm->setObjectName(QString::fromUtf8("PlayerTableForm"));
        PlayerTableForm->resize(499, 483);
        tableWidget = new QTableWidget(PlayerTableForm);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 481, 411));
        pushButton = new QPushButton(PlayerTableForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 440, 131, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);

        retranslateUi(PlayerTableForm);

        QMetaObject::connectSlotsByName(PlayerTableForm);
    } // setupUi

    void retranslateUi(QWidget *PlayerTableForm)
    {
        PlayerTableForm->setWindowTitle(QCoreApplication::translate("PlayerTableForm", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("PlayerTableForm", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerTableForm: public Ui_PlayerTableForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERTABLEFORM_H
