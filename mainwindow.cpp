#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QMenuBar * menuBar = this->menuBar( );


    QMenu * fileMenu = menuBar->addMenu( tr ("&Ficher") );

    QAction * newAction = new QAction( QIcon("icons/images/new.png"), tr("&New..."), this);
    newAction->setShortcut( tr("Ctrl+N")); // accélérateur clavier
    newAction->setToolTip( tr("New file")); // bulle d’aide
    newAction->setStatusTip( tr("New file")); // barre de statut
    fileMenu->addAction(newAction); // rajouter l’action au menu déroulant
    // connecter le signal à un slot de this
    connect(newAction, SIGNAL(triggered( )), this, SLOT(open( )));

    QAction * newAction1 = new QAction( QIcon("icons/images/save.png"), tr("&Save..."), this);
    newAction1->setShortcut( tr("Ctrl+S")); // accélérateur clavier
    newAction1->setToolTip( tr("Save")); // bulle d’aide
    newAction1->setStatusTip( tr("Save")); // barre de statut
    fileMenu->addAction(newAction1); // rajouter l’action au menu déroulant
    // connecter le signal à un slot de this
    connect(newAction1, SIGNAL(triggered( )), this, SLOT(open( )));

    QAction * newAction2 = new QAction( QIcon(":/icons/save.png"), tr("&Quit..."), this);
    newAction2->setShortcut( tr("Ctrl+Q")); // accélérateur clavier
    newAction2->setToolTip( tr("Quit")); // bulle d’aide
    newAction2->setStatusTip( tr("Quit")); // barre de statut
    fileMenu->addAction(newAction2); // rajouter l’action au menu déroulant
    // connecter le signal à un slot de this
    connect(newAction2, SIGNAL(triggered( )), this, SLOT(open( )));

    //ui->setupUi(this);
    QtMainWindow:statusBar();

}

MainWindow::~MainWindow()
{
    delete ui;
}
