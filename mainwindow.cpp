#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
================
MainWindow::MainWindow
Constructor
================
*/
MainWindow::MainWindow(QApplication *app) :
    QMainWindow(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("AES-128 Encryption");
    connect(ui->buttonQuit, SIGNAL(clicked()), app, SLOT(quit()));
}

/*
================
MainWindow::~MainWindow
Destructor
================
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*
================
MainWindow::on_buttonEncrypt_clicked
Encrypts the text in lineEditInput using key in lineEditKey
and displays result in lineEditEncrypted
================
*/
void MainWindow::on_buttonEncrypt_clicked()
{
    int returncode = aes.InputForEncrypt(ui->lineEditInput->toPlainText().toStdString(), ui->lineEditKey->text().toStdString());

    if (returncode == 1) {
        ui->statusBar->showMessage("There's nothing in 'Input'");
    }
    else if (returncode == 2) {
        ui->statusBar->showMessage("Key should have less than 16 symbols");
    }
    else if (returncode == 3) {
        ui->statusBar->showMessage("Key is empty");
    }
    else {
        ui->statusBar->clearMessage();

        string str = aes.Encrypt();

        ui->lineEditEncrypted->clear();
        ui->lineEditEncrypted->append(QString::fromUtf8( str.data(), str.size() ));
    }
}

/*
================
MainWindow::on_buttonDecrypt_clicked
Decrypts the text in lineEditEncrypt using key in lineEditKey
and displays result in lineEditDecrypt
================
*/
void MainWindow::on_buttonDecrypt_clicked()
{
    int returncode = aes.InputForDecrypt(ui->lineEditEncrypted->toPlainText().toStdString(), ui->lineEditKey->text().toStdString());

    if (returncode == 1) {
        ui->statusBar->showMessage("Number of symbols in 'Encrypted' should be divisible by 32");
    }
    else if (returncode == 2) {
        ui->statusBar->showMessage("Key should have less than 16 symbols");
    }
    else if (returncode == 3) {
        ui->statusBar->showMessage("Key is empty");
    }
    else {
        ui->statusBar->clearMessage();

        string str = aes.Decrypt();

        ui->lineEditDecrypted->clear();
        ui->lineEditDecrypted->append(QString::fromUtf8( str.data(), str.size() ));
    }
}
