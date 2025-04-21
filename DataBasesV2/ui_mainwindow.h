/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "dbview.h"
#include "editorwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    EditorWidget *editorWidget;
    QVBoxLayout *verticalLayout;
    DbView *dbView;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton_GPU;
    QPushButton *addButton_CPU;
    QPushButton *addButton_RAM;
    QPushButton *removeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(698, 550);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        editorWidget = new EditorWidget(centralwidget);
        editorWidget->setObjectName(QString::fromUtf8("editorWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editorWidget->sizePolicy().hasHeightForWidth());
        editorWidget->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(editorWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dbView = new DbView(centralwidget);
        dbView->setObjectName(QString::fromUtf8("dbView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dbView->sizePolicy().hasHeightForWidth());
        dbView->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(dbView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        addButton_GPU = new QPushButton(centralwidget);
        addButton_GPU->setObjectName(QString::fromUtf8("addButton_GPU"));

        horizontalLayout->addWidget(addButton_GPU);

        addButton_CPU = new QPushButton(centralwidget);
        addButton_CPU->setObjectName(QString::fromUtf8("addButton_CPU"));

        horizontalLayout->addWidget(addButton_CPU);

        addButton_RAM = new QPushButton(centralwidget);
        addButton_RAM->setObjectName(QString::fromUtf8("addButton_RAM"));

        horizontalLayout->addWidget(addButton_RAM);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::ListRemove")));
        removeButton->setIcon(icon);

        horizontalLayout->addWidget(removeButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 698, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(addButton_RAM, SIGNAL(clicked()), dbView, SLOT(createNewRAM()));
        QObject::connect(removeButton, SIGNAL(clicked()), dbView, SLOT(deleteSelected()));
        QObject::connect(addButton_CPU, SIGNAL(clicked()), dbView, SLOT(createNewCPU()));
        QObject::connect(addButton_GPU, SIGNAL(clicked()), dbView, SLOT(createNewGPU()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton_GPU->setText(QCoreApplication::translate("MainWindow", "GPU", nullptr));
        addButton_CPU->setText(QCoreApplication::translate("MainWindow", "CPU", nullptr));
        addButton_RAM->setText(QCoreApplication::translate("MainWindow", "RAM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
