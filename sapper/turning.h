#ifndef TURNING_H
#define TURNING_H

#include <QDialog>
#include <QString>

namespace Ui {
class Turning;
}

class Turning : public QDialog
{
    Q_OBJECT
signals:
    void getData(int,int,int);
public:
    explicit Turning(QWidget *parent = 0);
    ~Turning();
public slots:
    void end(void);
    void setTur(void);\
    void remember(QString);

private:
    Ui::Turning *ui;
    QString str;
};

#endif // TURNING_H
