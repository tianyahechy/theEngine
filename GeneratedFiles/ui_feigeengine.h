/********************************************************************************
** Form generated from reading UI file 'feigeengine.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEIGEENGINE_H
#define UI_FEIGEENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_feigeEngineClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *feigeEngineClass)
    {
        if (feigeEngineClass->objectName().isEmpty())
            feigeEngineClass->setObjectName(QStringLiteral("feigeEngineClass"));
        feigeEngineClass->resize(600, 400);
        menuBar = new QMenuBar(feigeEngineClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        feigeEngineClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(feigeEngineClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        feigeEngineClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(feigeEngineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        feigeEngineClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(feigeEngineClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        feigeEngineClass->setStatusBar(statusBar);

        retranslateUi(feigeEngineClass);

        QMetaObject::connectSlotsByName(feigeEngineClass);
    } // setupUi

    void retranslateUi(QMainWindow *feigeEngineClass)
    {
        feigeEngineClass->setWindowTitle(QApplication::translate("feigeEngineClass", "feigeEngine", 0));
    } // retranslateUi

};

namespace Ui {
    class feigeEngineClass: public Ui_feigeEngineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEIGEENGINE_H
