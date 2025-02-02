/********************************************************************************
** Form generated from reading UI file 'interfacemainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEMAINWINDOW_H
#define UI_INTERFACEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceMainWindow
{
public:
    QAction *actionNew_file;
    QAction *actionNew_Project;
    QAction *actionFile;
    QAction *actionProject_Solution;
    QAction *actionOthers;
    QAction *actionclose;
    QAction *actionClose_All;
    QAction *actionSave;
    QAction *actionSave_2;
    QAction *actionSave_as;
    QAction *actionSave_All;
    QAction *actionRecent;
    QAction *actionClose_Editor;
    QAction *actionNew_Editor;
    QAction *actionAbout;
    QAction *actionDirectory;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *viewTab;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuOpen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InterfaceMainWindow)
    {
        if (InterfaceMainWindow->objectName().isEmpty())
            InterfaceMainWindow->setObjectName("InterfaceMainWindow");
        InterfaceMainWindow->resize(800, 600);
        actionNew_file = new QAction(InterfaceMainWindow);
        actionNew_file->setObjectName("actionNew_file");
        actionNew_Project = new QAction(InterfaceMainWindow);
        actionNew_Project->setObjectName("actionNew_Project");
        actionFile = new QAction(InterfaceMainWindow);
        actionFile->setObjectName("actionFile");
        actionProject_Solution = new QAction(InterfaceMainWindow);
        actionProject_Solution->setObjectName("actionProject_Solution");
        actionOthers = new QAction(InterfaceMainWindow);
        actionOthers->setObjectName("actionOthers");
        actionclose = new QAction(InterfaceMainWindow);
        actionclose->setObjectName("actionclose");
        actionClose_All = new QAction(InterfaceMainWindow);
        actionClose_All->setObjectName("actionClose_All");
        actionSave = new QAction(InterfaceMainWindow);
        actionSave->setObjectName("actionSave");
        actionSave_2 = new QAction(InterfaceMainWindow);
        actionSave_2->setObjectName("actionSave_2");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        actionSave_2->setIcon(icon);
        actionSave_as = new QAction(InterfaceMainWindow);
        actionSave_as->setObjectName("actionSave_as");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSaveAs));
        actionSave_as->setIcon(icon1);
        actionSave_All = new QAction(InterfaceMainWindow);
        actionSave_All->setObjectName("actionSave_All");
        actionRecent = new QAction(InterfaceMainWindow);
        actionRecent->setObjectName("actionRecent");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpenRecent));
        actionRecent->setIcon(icon2);
        actionClose_Editor = new QAction(InterfaceMainWindow);
        actionClose_Editor->setObjectName("actionClose_Editor");
        actionNew_Editor = new QAction(InterfaceMainWindow);
        actionNew_Editor->setObjectName("actionNew_Editor");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::WindowNew));
        actionNew_Editor->setIcon(icon3);
        actionAbout = new QAction(InterfaceMainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        actionAbout->setIcon(icon4);
        actionDirectory = new QAction(InterfaceMainWindow);
        actionDirectory->setObjectName("actionDirectory");
        centralwidget = new QWidget(InterfaceMainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        viewTab = new QTabWidget(centralwidget);
        viewTab->setObjectName("viewTab");
        viewTab->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        viewTab->setAcceptDrops(true);
        viewTab->setUsesScrollButtons(true);
        viewTab->setDocumentMode(true);
        viewTab->setTabsClosable(true);
        viewTab->setMovable(true);

        gridLayout->addWidget(viewTab, 0, 0, 1, 1);

        InterfaceMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InterfaceMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName("menuNew");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        menuNew->setIcon(icon5);
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName("menuOpen");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        menuOpen->setIcon(icon6);
        InterfaceMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(InterfaceMainWindow);
        statusbar->setObjectName("statusbar");
        InterfaceMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionclose);
        menuFile->addAction(actionClose_All);
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionSave_All);
        menuFile->addAction(actionRecent);
        menuFile->addAction(actionClose_Editor);
        menuFile->addAction(actionNew_Editor);
        menuFile->addAction(actionAbout);
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuNew->addAction(actionNew_file);
        menuNew->addAction(actionNew_Project);
        menuOpen->addAction(actionFile);
        menuOpen->addAction(actionDirectory);
        menuOpen->addAction(actionProject_Solution);
        menuOpen->addAction(actionOthers);

        retranslateUi(InterfaceMainWindow);

        viewTab->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(InterfaceMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InterfaceMainWindow)
    {
        InterfaceMainWindow->setWindowTitle(QCoreApplication::translate("InterfaceMainWindow", "InterfaceMainWindow", nullptr));
        actionNew_file->setText(QCoreApplication::translate("InterfaceMainWindow", "New file", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_file->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_Project->setText(QCoreApplication::translate("InterfaceMainWindow", "New Project", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Project->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFile->setText(QCoreApplication::translate("InterfaceMainWindow", "File", nullptr));
#if QT_CONFIG(shortcut)
        actionFile->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionProject_Solution->setText(QCoreApplication::translate("InterfaceMainWindow", "Project/Solution...", nullptr));
        actionOthers->setText(QCoreApplication::translate("InterfaceMainWindow", "Others", nullptr));
        actionclose->setText(QCoreApplication::translate("InterfaceMainWindow", "Close", nullptr));
#if QT_CONFIG(shortcut)
        actionclose->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose_All->setText(QCoreApplication::translate("InterfaceMainWindow", "Close All", nullptr));
#if QT_CONFIG(shortcut)
        actionClose_All->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+Shift+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("InterfaceMainWindow", "Save", nullptr));
        actionSave_2->setText(QCoreApplication::translate("InterfaceMainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_2->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("InterfaceMainWindow", "Save as...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_All->setText(QCoreApplication::translate("InterfaceMainWindow", "Save All", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_All->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRecent->setText(QCoreApplication::translate("InterfaceMainWindow", "Recent", nullptr));
        actionClose_Editor->setText(QCoreApplication::translate("InterfaceMainWindow", "Close Editor", nullptr));
        actionNew_Editor->setText(QCoreApplication::translate("InterfaceMainWindow", "New Editor", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Editor->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("InterfaceMainWindow", "About", nullptr));
        actionDirectory->setText(QCoreApplication::translate("InterfaceMainWindow", "Directory", nullptr));
#if QT_CONFIG(shortcut)
        actionDirectory->setShortcut(QCoreApplication::translate("InterfaceMainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("InterfaceMainWindow", "File", nullptr));
        menuNew->setTitle(QCoreApplication::translate("InterfaceMainWindow", "New", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("InterfaceMainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfaceMainWindow: public Ui_InterfaceMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEMAINWINDOW_H
