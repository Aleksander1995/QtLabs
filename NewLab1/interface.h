#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include "treal.h"
namespace Ui {
class InterFace;
}

class InterFace : public QMainWindow
{
    Q_OBJECT

public:
    explicit InterFace(QWidget *parent = 0);
    ~InterFace();

    double d=0;
    double a;
    double b;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::InterFace *ui;
};

#endif // INTERFACE_H
