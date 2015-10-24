#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QMenuBar * menuBar = this->menuBar( );
    QMenu * fileMenu = menuBar->addMenu( tr ("&Ficher") );
    QToolBar* toolBar=this->addToolBar(tr("File"));
    textEdit=new QTextEdit();

    this->setCentralWidget(textEdit);

    QAction * newAction = new QAction( QIcon(":/icons/new"), tr("&New..."), this);
    newAction->setShortcut( tr("Ctrl+N")); // accélérateur clavier
    newAction->setToolTip( tr("New file")); // bulle d’aide
    newAction->setStatusTip( tr("New file")); // barre de statut
    fileMenu->addAction(newAction); // rajouter l’action au menu déroulant
    // connecter le signal à un slot de this
    connect(newAction, SIGNAL(triggered( )), this, SLOT(openFile()));

    QAction * newAction1 = new QAction( QIcon(":/icons/save"), tr("&Save..."), this);
    newAction1->setShortcut( tr("Ctrl+S")); // accélérateur clavier
    newAction1->setToolTip( tr("Save")); // bulle d’aide
    newAction1->setStatusTip( tr("Save")); // barre de statut
    fileMenu->addAction(newAction1); // rajouter l’action au menu déroulant
    // connecter le signal à un slot de this
    connect(newAction1, SIGNAL(triggered( )), this, SLOT(saveFile()));

    QAction * newAction2 = new QAction( QIcon(":/icons/quit"), tr("&Quit..."), this);
    newAction2->setShortcut( tr("Ctrl+Q")); // accélérateur clavier
    newAction2->setToolTip( tr("Quit")); // bulle d’aide
    newAction2->setStatusTip( tr("Quit")); // barre de statut
    fileMenu->addAction(newAction2); // rajouter l’action au menu déroulant
    // connecter le signal à un slot de this
    connect(newAction2, SIGNAL(triggered( )), this, SLOT(quitApp()));



    toolBar->addAction(newAction);
    toolBar->addAction(newAction1);
    toolBar->addAction(newAction2);







    //ui->setupUi(this);
QtMainWindow:statusBar();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openFile(){

    QString fileName =
            QFileDialog::getOpenFileName( this,
                                          tr("Open File")// titre
                                          );

    cout<<"openFile:"<<fileName.toStdString()<<endl;

    QFile myOpenFile(fileName);
    myOpenFile.open(QIODevice::Text | QIODevice::ReadOnly);
    QTextStream stream(&myOpenFile);
    QString allline;
    allline = stream.readAll();
    cout << allline.toStdString();

    textEdit->setPlainText(allline);
    myOpenFile.close();

}
void MainWindow::saveFile(){


    QString fileName =
            QFileDialog::getSaveFileName( this,
                                          tr("Save File")// titre
                                          );

    cout<<"saveFile:"<<fileName.toStdString()<<endl;

    QFile mySaveFile(fileName);
    mySaveFile.open(QIODevice::Text | QIODevice::WriteOnly);
    QTextStream stream(&mySaveFile);
    QString allline=textEdit->toPlainText();
    stream << allline;
    mySaveFile.close();
    cout<<"saveFile()"<<endl;

}
void MainWindow::quitApp(){

    int reponse=QMessageBox::question(this,"Confirmation", "Vous voulez quitter l'application?",QMessageBox::Yes , QMessageBox::No);

    cout<<"quitApp()"<<endl;
    if (reponse == QMessageBox::Yes)
        {
            QApplication::quit();
        }
        else if (reponse == QMessageBox::No)
        {
            return;
        }

}
void MainWindow::closeEvent(QCloseEvent * e)
{
    quitApp();
}

