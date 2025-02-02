#include "headers/interfacemainwindow.h"
#include "ui_interfacemainwindow.h"
#include <QRandomGenerator> // Pour générer des couleurs aléatoires
#include <QPalette> //pour la couleur dans qt
#include <QFrame>
#include <QBoxLayout>
#include <QPlainTextEdit>
#include <QTabBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QTextCursor>
#include <QStringListModel>
InterfaceMainWindow::InterfaceMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InterfaceMainWindow)
{

    ui->setupUi(this);
    QFontDatabase::addApplicationFont(":/asset/SourceCodePro-Italic-VariableFont_wght.ttf");
    QFontDatabase::addApplicationFont(":/asset/SourceCodePro-VariableFont_wght.ttf");
    ui->viewTab->setTabsClosable(true);
    ui->viewTab->setDocumentMode(false);

    setCentralWidget(windowSplit);
    windowSplit->addWidget(treeView);
    windowSplit->addWidget(ui->viewTab);
    treeView->setMinimumWidth(0);
    treeView->setMaximumWidth(0);

    //connect(ui->myButton, &QPushButton::clicked, this, &InterfaceMainWindow::changeButtonColor);
    connect(ui->viewTab, &QTabWidget::tabCloseRequested, this, &InterfaceMainWindow::on_actionCloseTabButton_triggered);

}

InterfaceMainWindow::~InterfaceMainWindow()
{
    delete ui;

}


void InterfaceMainWindow::changeButtonColor()
{
    int red = QRandomGenerator::global()->bounded(256);
    int green = QRandomGenerator::global()->bounded(256);
    int blue = QRandomGenerator::global()->bounded(256);

    // Créer une nouvelle couleur
    QColor randomColor(red, green, blue);

    // Appliquer la couleur au bouton via une feuille de style
    QString style = QString("background-color: %1;").arg(randomColor.name());
   // ui->myButton->setStyleSheet(style);
}






void InterfaceMainWindow::on_actionNew_file_triggered()
{
    creationTab_otherAction();
}


void InterfaceMainWindow::on_actionclose_triggered()
{
    ui->viewTab->removeTab(ui->viewTab->currentIndex());
}


void InterfaceMainWindow::on_actionClose_All_triggered()
{
    while(ui->viewTab->count()>0){
        ui->viewTab->removeTab(ui->viewTab->currentIndex());
    }
}

void InterfaceMainWindow::on_actionCloseTabButton_triggered(int index)
{
    if (index != -1) {
        QWidget *currentWidget = ui->viewTab->widget(index);
        ui->viewTab->removeTab(index);
        delete currentWidget;
    }
}

void InterfaceMainWindow::creationTab_otherAction() {
    // Créer un cadre pour le nouvel onglet
    QFrame *frame = new QFrame(ui->viewTab);
    QVBoxLayout *layout = new QVBoxLayout(frame);

    // Ajouter une zone de texte
    QPlainTextEdit *textSpace = new QPlainTextEdit(frame);
    textSpace->setObjectName("editFile");
    QFont font = textSpace->document()->defaultFont();
    font.setFamily("Source Code Pro");
    font.setBold(true);
    textSpace->setFont(font);

    // Appliquer un style gris foncé au fond et texte clair
    textSpace->setStyleSheet("background-color: #2e3238; color: #ffffff;");
    textSpace->setTabStopDistance(QFontMetrics(textSpace->font()).horizontalAdvance(" ") * 4);

    // Ajouter un placeholder
    textSpace->setPlaceholderText("Start typing here...");

    // Ajouter des marges au layout
    layout->setContentsMargins(10, 10, 10, 10);
    layout->addWidget(textSpace);

    // Créer une barre de statut
    QStatusBar *statusBar = new QStatusBar(frame);
    QLabel *statusLabel = new QLabel("Line 1, Column 1", statusBar);
    statusBar->addWidget(statusLabel);
    layout->addWidget(statusBar);

    // Ajouter un titre unique pour chaque nouvel onglet
    static int untitledCount = 1;
    QString tabTitle = QString("Untitled %1").arg(untitledCount++);
    ui->viewTab->addTab(frame, tabTitle);
    ui->viewTab->setCurrentWidget(frame);
    ui->viewTab->setTabToolTip(ui->viewTab->currentIndex(), "Untitled");

    // Connecter les signaux
    connect(textSpace, &QPlainTextEdit::textChanged, [this, tabTitle]() {
        int index = ui->viewTab->currentIndex();
        QString title = ui->viewTab->tabText(index);
        if (!title.startsWith("*")) {
            ui->viewTab->setTabText(index, "*" + title);
        }
    });

    // Connecter le signal pour afficher la ligne et la colonne courante
    connect(textSpace, &QPlainTextEdit::cursorPositionChanged, [textSpace, statusLabel]() {
        QTextCursor cursor = textSpace->textCursor();
        int line = cursor.blockNumber() + 1;
        int column = cursor.positionInBlock() + 1;
        statusLabel->setText(QString("Line %1, Column %2").arg(line).arg(column));
    });
}


void InterfaceMainWindow::openTabFile(QString path)
{
    // Vérifier si le chemin est valide
    QFile file(path);
    if (!file.exists()) {
        QMessageBox::warning(this, "Erreur", "Le fichier n'existe pas.");
        return;
    }

    // Ouvrir le fichier en lecture
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }

    // Lire le contenu du fichier
    QTextStream stream(&file);
    QString content = stream.readAll();
    file.close();

    // Trouver l'onglet actif
    QWidget *currentWidget = ui->viewTab->currentWidget();
    if (!currentWidget) {
        QMessageBox::warning(this, "Erreur", "Aucun onglet actif.");
        return;
    }

    // Trouver la zone de texte dans l'onglet actif
    QPlainTextEdit *textSpace = currentWidget->findChild<QPlainTextEdit *>();
    if (!textSpace) {
        QMessageBox::warning(this, "Erreur", "Impossible de trouver la zone de texte.");
        return;
    }

    textSpace->setPlainText(content);
    ui->viewTab->setTabToolTip(ui->viewTab->currentIndex(),path);
}

void InterfaceMainWindow::on_actionFile_triggered()
{
    // Ouvrir une boîte de dialogue pour sélectionner un fichier
    QString path = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Text Files (*.txt);;All Files (*)");

    if (path.isEmpty())
        return;
    creationTab_otherAction();
    openTabFile(path);
    QString tabTitle = QFileInfo(path).fileName();
    ui->viewTab->setTabText(ui->viewTab->currentIndex(), tabTitle);

}


QPlainTextEdit*InterfaceMainWindow::currentTextEdit()
{
    QList<QPlainTextEdit *>fileEditList=ui->viewTab->findChildren<QPlainTextEdit*>("editFile");
    for(int i=0;i<fileEditList.count();i++)
    {
        if(ui->viewTab->indexOf(fileEditList[i]->parentWidget())==ui->viewTab->currentIndex()){
            return fileEditList[i];
        }
    }
    return new QPlainTextEdit();
}


void InterfaceMainWindow::textEditChanged()
{
    QString name= ui->viewTab->tabText(ui->viewTab->currentIndex());
    if(name.at(0)!='*'){
        ui->viewTab->setTabText(ui->viewTab->currentIndex(),"*"+name);
    }
}

void InterfaceMainWindow::on_actionSave_2_triggered()
{

    QString currentTabName = ui->viewTab->tabText(ui->viewTab->currentIndex());


    if (currentTabName.startsWith("Untitled")) {
        on_actionSave_as_triggered();
        return;
    }


    QFile file(currentTabName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier pour écriture.");
        return;
    }


    QTextStream out(&file);
    QString text = currentTextEdit()->toPlainText();
    out << text;
    file.close();
     QString newTabName = ui->viewTab->tabText(ui->viewTab->currentIndex());
    if (newTabName.startsWith("*")) {
        newTabName.remove(0, 1);
        ui->viewTab->setTabText(ui->viewTab->currentIndex(), newTabName);
    }
}


void InterfaceMainWindow::on_actionSave_as_triggered()
{
    if (ui->viewTab->count() <= 0) {
        QMessageBox::warning(this, "Warning", "Cannot save file. Try to create a new file!");
        return;
    }

    // Récupérer l'éditeur de texte de l'onglet actuel
    QPlainTextEdit *textEdit = qobject_cast<QPlainTextEdit *>(ui->viewTab->currentWidget()->layout()->itemAt(0)->widget());
    if (!textEdit) {
        QMessageBox::warning(this, "Warning", "No valid editor found in the current tab.");
        return;
    }

    // Demander le chemin de sauvegarde à l'utilisateur
    QString filePath = QFileDialog::getSaveFileName(this, "Save File As", QDir::homePath(), "Text Files (*.txt);;All Files (*)");

    // Si l'utilisateur annule, ne rien faire
    if (filePath.isEmpty())
        return;

    // Créer et ouvrir le fichier pour écriture
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open file for writing.");
        return;
    }


    QTextStream out(&file);
    out << textEdit->toPlainText();
    file.close();

    // Mettre à jour le titre de l'onglet avec le nouveau chemin
    ui->viewTab->setTabText(ui->viewTab->currentIndex(), QFileInfo(filePath).fileName());
    ui->viewTab->setTabToolTip(ui->viewTab->currentIndex(), filePath);

    QMessageBox::information(this, "Success", "File saved successfully.");
}


void InterfaceMainWindow::on_actionSave_All_triggered()
{
    if (ui->viewTab->count() <= 0) {
        QMessageBox::warning(this, "Warning", "No files to save. Please open or create a file!");
        return;
    }

    for (int i = 0; i < ui->viewTab->count(); ++i) {
        // Récupérer le texte de l'onglet courant
        QWidget *currentWidget = ui->viewTab->widget(i);
        QPlainTextEdit *textEdit = qobject_cast<QPlainTextEdit *>(currentWidget->layout()->itemAt(0)->widget());

        if (!textEdit) {
            QMessageBox::warning(this, "Warning", QString("No valid editor found in tab %1.").arg(i + 1));
            continue;
        }

        // Récupérer le chemin du fichier associé à cet onglet
        QString filePath = ui->viewTab->tabToolTip(i);

        // Si le fichier n'a pas encore été sauvegardé
        if (filePath.isEmpty() || filePath == "Untitled") {
            filePath = QFileDialog::getSaveFileName(
                this,
                QString("Save Tab %1 As").arg(i + 1),
                QDir::homePath(),
                "All Files (*.*)"
                );

            // Si l'utilisateur annule le dialogue, passer au prochain onglet
            if (filePath.isEmpty()) {
                continue;
            }

            // Ajouter une extension par défaut si aucune n'est spécifiée
            if (QFileInfo(filePath).suffix().isEmpty()) {
                filePath += ".txt";
            }

            // Mettre à jour les propriétés de l'onglet (titre et tooltip)
            ui->viewTab->setTabText(i, QFileInfo(filePath).fileName());
            ui->viewTab->setTabToolTip(i, filePath);
        }

        // Sauvegarder le contenu du fichier
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(
                this,
                "Error",
                QString("Cannot open file for writing: %1").arg(filePath)
                );
            continue;
        }

        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();

        // Mettre à jour le statut pour indiquer que l'onglet est sauvegardé
        QString tabText = ui->viewTab->tabText(i);
        if (tabText.startsWith("*")) {
            ui->viewTab->setTabText(i, tabText.remove(0, 1));
        }
    }

    QMessageBox::information(this, "Success", "All files have been saved successfully.");
}





void InterfaceMainWindow::on_actionDirectory_triggered()
{
    // Ouvrir un dialogue pour sélectionner un répertoire
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), QString(),
                                                          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (directory.isEmpty())
        return;  // Si aucun répertoire n'est sélectionné, sortir de la fonction

    // Créer un modèle de système de fichiers pour afficher les fichiers et dossiers
    QFileSystemModel *fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(directory);

    // Définir le modèle du TreeView
    treeView->setModel(fileSystemModel);
    treeView->hideColumn(1);
    treeView->hideColumn(2);
    treeView->hideColumn(3);
    fileSystemModel->setHeaderData(0, Qt::Horizontal, tr("Projets"));
    // Définir le répertoire racine à afficher dans le TreeView
    treeView->setRootIndex(fileSystemModel->index(directory));

    // Définir les dimensions par défaut, minimale et maximale du TreeView
    treeView->setMinimumWidth(width()*20/100);
    treeView->setMaximumWidth(width()*30/100);


    // Connecter un signal pour double-cliquer sur un fichier dans le TreeView
    connect(treeView, &QTreeView::doubleClicked, this, &InterfaceMainWindow::onFileDoubleClicked);
}

void InterfaceMainWindow::onFileDoubleClicked(const QModelIndex &index)
{
    // Récupérer le nom du fichier à partir du modèle
    QString fileName = index.data(Qt::DisplayRole).toString();

    // Ouvrir le fichier dans un nouvel onglet dans ui->viewTab
    openFileInTab(fileName);
}

void InterfaceMainWindow::openFileInTab(const QString &fileName)
{
    // Créer un cadre pour le nouvel onglet
    QFrame *frame = new QFrame(ui->viewTab);
    QVBoxLayout *layout = new QVBoxLayout(frame);

    // Ajouter une zone de texte
    QPlainTextEdit *textSpace = new QPlainTextEdit(frame);
    textSpace->setObjectName("editFile");
    QFont font = textSpace->document()->defaultFont();
    font.setFamily("Source Code Pro");
    font.setBold(true);
    textSpace->setFont(font);

    // Appliquer un style gris foncé au fond et texte clair
    textSpace->setStyleSheet("background-color: #2e3238; color: #ffffff;");
    textSpace->setTabStopDistance(QFontMetrics(textSpace->font()).horizontalAdvance(" ") * 4);

    // Ajouter un QLabel pour le statut
    QLabel *status = new QLabel(frame);
    status->setText("Line 1, Column 1");
    layout->addWidget(status);

    // Ajouter un placeholder
    textSpace->setPlaceholderText("Start typing here...");

    // Ajouter des marges au layout
    layout->setContentsMargins(10, 10, 10, 10);
    layout->addWidget(textSpace);

    // Ajouter un titre unique pour chaque nouvel onglet
    static int untitledCount = 1;
    QString tabTitle = QString("Untitled %1").arg(untitledCount++);
    ui->viewTab->addTab(frame, tabTitle);
    ui->viewTab->setCurrentWidget(frame);
    ui->viewTab->setTabToolTip(ui->viewTab->currentIndex(), "Untitled");

    // Charger le fichier dans le QPlainTextEdit
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        textSpace->setPlainText(in.readAll());
        file.close();
    } else {
        QMessageBox::critical(this, "Error", "Failed to open file.");
    }

    // Connecter les signaux pour la mise à jour du statut et autres
    connect(textSpace, &QPlainTextEdit::cursorPositionChanged, [textSpace, status]() {
        QTextCursor cursor = textSpace->textCursor();
        int line = cursor.blockNumber() + 1;
        int column = cursor.positionInBlock() + 1;
        status->setText(QString("Line %1, Column %2").arg(line).arg(column));
    });
}


