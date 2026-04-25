/********************************************************************************
** Form generated from reading UI file 'child_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILD_DIALOG_H
#define UI_CHILD_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChildDialog
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *enter_main;
    QPushButton *exit;

    void setupUi(QDialog *ChildDialog)
    {
        if (ChildDialog->objectName().isEmpty())
            ChildDialog->setObjectName("ChildDialog");
        ChildDialog->resize(400, 300);
        label = new QLabel(ChildDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 50, 91, 16));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(ChildDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 110, 170, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        enter_main = new QPushButton(layoutWidget);
        enter_main->setObjectName("enter_main");

        horizontalLayout->addWidget(enter_main);

        exit = new QPushButton(layoutWidget);
        exit->setObjectName("exit");

        horizontalLayout->addWidget(exit);


        retranslateUi(ChildDialog);
        QObject::connect(exit, &QPushButton::clicked, ChildDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ChildDialog);
    } // setupUi

    void retranslateUi(QDialog *ChildDialog)
    {
        ChildDialog->setWindowTitle(QCoreApplication::translate("ChildDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChildDialog", "\345\255\220\347\252\227\345\217\243", nullptr));
        enter_main->setText(QCoreApplication::translate("ChildDialog", "\350\277\233\345\205\245\344\270\273\347\225\214\351\235\242", nullptr));
        exit->setText(QCoreApplication::translate("ChildDialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChildDialog: public Ui_ChildDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILD_DIALOG_H
