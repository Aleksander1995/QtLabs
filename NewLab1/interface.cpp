#include "interface.h"
#include "ui_interface.h"
#include"treal.h"
#include<iostream>

InterFace::InterFace(QWidget *parent) :
    QMainWindow(parent),
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
    TReal r1(ui->A->text().toDouble());
    TReal r2(ui->B->text().toDouble());

    QString s("Сумма= ");

    TReal w(0.0);
    w>>(r1+r2);
    s<<(r1);

    ui->lineEdit_3->setText(s);

    ui->M->setText(QString::number(w.m));
    ui->p->setText(QString::number(w.p));
    d=(double)w.m;

    while(w.p!=0)
    {
        if(w.p>0){d=d*10;w.p--;}
        if(w.p<0){d=d/10;w.p++;}
    }
}

void InterFace::on_pushButton_2_clicked()
{
    QString s("+=");
    TReal r2(ui->B->text().toDouble());
    TReal r1(d);
    TReal w(0.0);
    w>>(r1+r2);
    s<<(r1);
    ui->lineEdit_3->setText(s);

    ui->M->setText(QString::number(w.m));
    ui->p->setText(QString::number(w.p));
    d=(double)w.m;

    while(w.p!=0)
    {
        if(w.p>0){d=d*10;w.p--;}
        if(w.p<0){d=d/10;w.p++;}
    }
}

void InterFace::on_pushButton_5_clicked()
{
    bool l;
    TReal r1(ui->A->text().toDouble());
    TReal r2(b=ui->B->text().toDouble());
    TReal w(0.0);
    w>>(r1>r2);
    l=w.m;
    ui->lineEdit_3->setText(QString::number(l));

    ui->M->clear();
    ui->p->clear();
}

void InterFace::on_pushButton_6_clicked()
{
    bool l;
    TReal r1(ui->A->text().toDouble());
    TReal r2(b=ui->B->text().toDouble());
    TReal w(0.0);
    w>>(r1>=r2);
    l=w.m;
    ui->lineEdit_3->setText(QString::number(l));

    ui->M->clear();
    ui->p->clear();
}

void InterFace::on_pushButton_7_clicked()
{
    bool l;
    TReal r1(ui->A->text().toDouble());
    TReal r2(b=ui->B->text().toDouble());
    TReal w(0.0);
    w>>(r1<r2);
    l=w.m;
    ui->lineEdit_3->setText(QString::number(l));

    ui->M->clear();
    ui->p->clear();
}

void InterFace::on_pushButton_8_clicked()
{
    bool l;
    TReal r1(ui->A->text().toDouble());
    TReal r2(b=ui->B->text().toDouble());
    TReal w(0.0);
    w>>(r1<=r2);
    l=w.m;
    ui->lineEdit_3->setText(QString::number(l));

    ui->M->clear();
    ui->p->clear();
}

void InterFace::on_pushButton_9_clicked()
{
    bool l;
    TReal r1(ui->A->text().toDouble());
    TReal r2(b=ui->B->text().toDouble());
    TReal w(0.0);
    w>>(r1==r2);
    l=w.m;
    ui->lineEdit_3->setText(QString::number(l));

    ui->M->clear();
    ui->p->clear();
}



void InterFace::on_pushButton_10_clicked()
{
    bool l;
    TReal r1(ui->A->text().toDouble());
    TReal r2(b=ui->B->text().toDouble());
    TReal w(0.0);
    w>>(r1!=r2);
    l=w.m;
    ui->lineEdit_3->setText(QString::number(l));

    ui->M->clear();
    ui->p->clear();
}

void InterFace::on_pushButton_3_clicked()
{

    QString s("Сдвиг влево= ");
    TReal r2(1);
    TReal r1(d);
    TReal w(0.0);
    w>>(r1-r2);
    s<<(r1);
    ui->lineEdit_3->setText(s);

    ui->M->setText(QString::number(w.m));
    ui->p->setText(QString::number(w.p));
    d=(double)w.m;

    while(w.p!=0)
    {
        if(w.p>0){d=d*10;w.p--;}
        if(w.p<0){d=d/10;w.p++;}
    }
}
