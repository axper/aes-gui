#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
//#include <QtGui>
#include "aes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QApplication *app);
    ~MainWindow();
    
private slots:
    void on_buttonEncrypt_clicked();
    void on_buttonDecrypt_clicked();

private:
    classAES aes;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
