#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

namespace Ui {
class InterFace;
}

class InterFace : public QWidget
{
    Q_OBJECT

public:
    explicit InterFace(QWidget *parent = 0);
    ~InterFace();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::InterFace *ui;
};

#endif // INTERFACE_H
