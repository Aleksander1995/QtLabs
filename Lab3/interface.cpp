#include "interface.h"
#include "ui_interface.h"
#include "vect.h"

InterFace::InterFace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InterFace)
{
    ui->setupUi(this);
}

InterFace::~InterFace()
{
    delete ui;
}

void InterFace::on_pushButton_clicked()
{
    QString s("A= ");
    Vect a(ui->A->text());
    Vect c=a;
    ui->lineEdit_3->clear();
    s<<c;
    ui->lineEdit_3->setText(s);
}

void InterFace::on_pushButton_2_clicked()
{
    QString s;
    Vect a(ui->A->text());
    Vect b(ui->B->text());
    ui->lineEdit_3->clear();
    s<<(a+b);
    ui->lineEdit_3->setText(s);
}

void InterFace::on_pushButton_3_clicked()
{
    QString s;
    Vect a(ui->B->text());
    Vect b(ui->lineEdit_3->text());
    ui->lineEdit_3->clear();
    s<<(a+b);
    ui->lineEdit_3->setText(s);
}

void InterFace::on_pushButton_5_clicked()
{
    QString s;
    Vect a(ui->A->text());
    Vect b(ui->B->text());
    ui->lineEdit_3->clear();
    s<<(a-b);
    ui->lineEdit_3->setText(s);
}

void InterFace::on_pushButton_4_clicked()
{
    QString s;
    Vect a(ui->lineEdit_3->text());
    Vect b(ui->B->text());
    ui->lineEdit_3->clear();
    s<<(a-b);
    ui->lineEdit_3->setText(s);
}

void InterFace::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{

}

void InterFace::on_pushButton_6_clicked()
{
    QString s;
    Vect a(ui->A->text());
    Vect b(ui->B->text());
    ui->lineEdit_3->clear();
    s<<(a*b);
    ui->lineEdit_3->setText(s);
}

void InterFace::on_pushButton_7_clicked()
{
    QString s;
    Vect a(ui->A->text());
    ui->lineEdit_3->clear();
    s>>(a);
    ui->lineEdit_3->setText(s);
}
