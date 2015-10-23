#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <iostream>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public  slots:
    void openFile();
    void saveFile();
    void quitApp();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
