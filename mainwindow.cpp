#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QRegExp>
#include <QString>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_start, SIGNAL (clicked()),
            this, SLOT (begintask1()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::begintask1()
{
    QString tmp;
    QVector<QChar> Vt, Vn;
    QChar S;
    QVector<QString> P;
    tmp = ui->lineEdit_Vt->text();
    QRegExp zap("[, ]");
    tmp.remove(zap);
    for (int i = 0; i < tmp.size(); i++)
        Vt.push_back(tmp[i]);

    tmp = ui->lineEdit_Vn->text();
    tmp.remove(zap);
    for (int i = 0; i < tmp.size(); i++)
        Vn.push_back(tmp[i]);

    tmp = ui->lineEdit_S->text();
    tmp.remove(zap);
    S = tmp[0];

    QString p = ui->textEdit_P->toPlainText();
    QString scob = "[";
    for (auto item : Vt)
        scob += item;

    for (auto item : Vn)
        scob += item;

    scob += ']';
    QRegExp reg("^" + scob + "+->" + scob + "+$");
    QTextStream stream(&p);
    while (!(stream.atEnd()))
    {
        QString rule;
        stream >> rule;
        if (!(reg.exactMatch(rule)))
        {
            ui->label_answer->setText("Ответ: Ошибка ввода!");
            return;
        }
        else
        {
            P.push_back(rule);
        }
    }

    switch(pars.checkGrammar(Vt, Vn, P))
    {
    case Parser::TYPE0:
        ui->label_answer->setText("Ответ: тип 0");
        break;
    case Parser::TYPE1:
        ui->label_answer->setText("Ответ: тип 1");
        break;
    case Parser::TYPE2:
        ui->label_answer->setText("Ответ: тип 2");
        break;
    case Parser::TYPE3LEFT:
        ui->label_answer->setText("Ответ: тип 3 левосторонний");
        break;
    case Parser::TYPE3RIGHT:
        ui->label_answer->setText("Ответ: тип 3 правосторонний");
        break;
    }

//    QString answer;
//    for (auto item : Vt)
//        answer += item;

//    answer += '\n';

//    for (auto item : Vn)
//        answer += item;

//    answer += '\n';
//    answer += S;
//    answer += '\n';

//    for (auto item : P)
//        answer += item;

//    ui->label_haha->setText(answer);
}
