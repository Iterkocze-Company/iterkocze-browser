#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webEngineView->load(QUrl("https://iterkocze.vercel.app"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_editingFinished()
{
    QString query = ui->lineEdit->text();
    const QString filename = "BrowserHistory.txt";
    ui->webEngineView->load(QUrl("https://duckduckgo.com/?q=" + query));

    QFile f(filename); // Nobody told me how to append text, so I will do it in the Michau wae.
        if (!f.open(QFile::ReadOnly | QFile::Text)) return;
        QTextStream in(&f);
        QString oldText = in.readAll();


        QFile file(filename);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << query << Qt::endl << oldText;
            stream.flush();
        }
}

