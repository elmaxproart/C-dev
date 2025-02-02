#ifndef INTERFACEMAINWINDOW_H
#define INTERFACEMAINWINDOW_H

#include "qplaintextedit.h"
#include <QMainWindow>
#include <QTreeView>
#include <QSplitter>
#include <QFileSystemModel>
QT_BEGIN_NAMESPACE
namespace Ui {
class InterfaceMainWindow;
}
QT_END_NAMESPACE

class InterfaceMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    InterfaceMainWindow(QWidget *parent = nullptr);
    ~InterfaceMainWindow();

private slots:

    void changeButtonColor();

    void on_actionNew_file_triggered();

    void on_actionclose_triggered();

    void on_actionClose_All_triggered();

    void on_actionCloseTabButton_triggered(int);

    void creationTab_otherAction();

    void on_actionFile_triggered();

    void openTabFile(QString path);

    QPlainTextEdit *currentTextEdit();

    void textEditChanged();
    void on_actionSave_2_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_All_triggered();

    void on_actionDirectory_triggered();

    void onFileDoubleClicked(const QModelIndex &index);

    void openFileInTab(const QString &fileName);

private:
    Ui::InterfaceMainWindow *ui;
    QSplitter *windowSplit=new QSplitter(this);
    QTreeView *treeView =new QTreeView();
    QFileSystemModel * dirModel =new QFileSystemModel(this);
};
#endif // INTERFACEMAINWINDOW_H
