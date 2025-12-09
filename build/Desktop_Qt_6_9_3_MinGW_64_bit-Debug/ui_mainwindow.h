/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *scoreLabel;
    QWidget *gameBoardWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *resetButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        scoreLabel = new QLabel(centralWidget);
        scoreLabel->setObjectName("scoreLabel");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        scoreLabel->setFont(font);
        scoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(scoreLabel);

        gameBoardWidget = new QWidget(centralWidget);
        gameBoardWidget->setObjectName("gameBoardWidget");
        gameBoardWidget->setMinimumSize(QSize(400, 400));

        verticalLayout->addWidget(gameBoardWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName("startButton");

        horizontalLayout->addWidget(startButton);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName("pauseButton");

        horizontalLayout->addWidget(pauseButton);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName("resetButton");

        horizontalLayout->addWidget(resetButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\264\252\345\220\203\350\233\207\346\270\270\346\210\217", nullptr));
        scoreLabel->setText(QCoreApplication::translate("MainWindow", "\345\210\206\346\225\260: 0", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
