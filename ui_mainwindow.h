/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelInput;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *buttonQuit;
    QLabel *labelDecrypted;
    QTextEdit *lineEditDecrypted;
    QTextEdit *lineEditEncrypted;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonDecrypt;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonEncrypt;
    QTextEdit *lineEditInput;
    QLineEdit *lineEditKey;
    QLabel *labelEncrypted;
    QLabel *labelKey;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 450);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelInput = new QLabel(centralWidget);
        labelInput->setObjectName(QStringLiteral("labelInput"));

        gridLayout->addWidget(labelInput, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        buttonQuit = new QPushButton(centralWidget);
        buttonQuit->setObjectName(QStringLiteral("buttonQuit"));
        buttonQuit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(buttonQuit);


        gridLayout->addLayout(horizontalLayout_3, 6, 1, 1, 1);

        labelDecrypted = new QLabel(centralWidget);
        labelDecrypted->setObjectName(QStringLiteral("labelDecrypted"));

        gridLayout->addWidget(labelDecrypted, 5, 0, 1, 1);

        lineEditDecrypted = new QTextEdit(centralWidget);
        lineEditDecrypted->setObjectName(QStringLiteral("lineEditDecrypted"));

        gridLayout->addWidget(lineEditDecrypted, 5, 1, 1, 1);

        lineEditEncrypted = new QTextEdit(centralWidget);
        lineEditEncrypted->setObjectName(QStringLiteral("lineEditEncrypted"));

        gridLayout->addWidget(lineEditEncrypted, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonDecrypt = new QPushButton(centralWidget);
        buttonDecrypt->setObjectName(QStringLiteral("buttonDecrypt"));
        buttonDecrypt->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(buttonDecrypt);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        buttonEncrypt = new QPushButton(centralWidget);
        buttonEncrypt->setObjectName(QStringLiteral("buttonEncrypt"));
        buttonEncrypt->setMaximumSize(QSize(80, 16777215));
        buttonEncrypt->setLayoutDirection(Qt::LeftToRight);
        buttonEncrypt->setDefault(true);

        horizontalLayout_2->addWidget(buttonEncrypt);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        lineEditInput = new QTextEdit(centralWidget);
        lineEditInput->setObjectName(QStringLiteral("lineEditInput"));

        gridLayout->addWidget(lineEditInput, 0, 1, 1, 1);

        lineEditKey = new QLineEdit(centralWidget);
        lineEditKey->setObjectName(QStringLiteral("lineEditKey"));

        gridLayout->addWidget(lineEditKey, 2, 1, 1, 1);

        labelEncrypted = new QLabel(centralWidget);
        labelEncrypted->setObjectName(QStringLiteral("labelEncrypted"));

        gridLayout->addWidget(labelEncrypted, 3, 0, 1, 1);

        labelKey = new QLabel(centralWidget);
        labelKey->setObjectName(QStringLiteral("labelKey"));

        gridLayout->addWidget(labelKey, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEditInput, buttonEncrypt);
        QWidget::setTabOrder(buttonEncrypt, lineEditKey);
        QWidget::setTabOrder(lineEditKey, lineEditEncrypted);
        QWidget::setTabOrder(lineEditEncrypted, buttonDecrypt);
        QWidget::setTabOrder(buttonDecrypt, lineEditDecrypted);
        QWidget::setTabOrder(lineEditDecrypted, buttonQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labelInput->setText(QApplication::translate("MainWindow", "Input", 0));
        buttonQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        labelDecrypted->setText(QApplication::translate("MainWindow", "Decrypted", 0));
        buttonDecrypt->setText(QApplication::translate("MainWindow", "Decrypt", 0));
        buttonEncrypt->setText(QApplication::translate("MainWindow", "Encrypt", 0));
        lineEditInput->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Need help over here!</p></body></html>", 0));
        lineEditKey->setText(QApplication::translate("MainWindow", "Strong key", 0));
        labelEncrypted->setText(QApplication::translate("MainWindow", "Encrypted", 0));
        labelKey->setText(QApplication::translate("MainWindow", "Key", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
