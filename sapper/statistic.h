#ifndef STATISTIC_H
#define STATISTIC_H

#include <QDialog>
#include <QString>
#include <QFile>

namespace Ui {
class Statistic;
}

class Statistic : public QDialog
{
    Q_OBJECT

public:
    explicit Statistic(QWidget *parent = 0);
    ~Statistic();
    void update1(void);
public slots:
    void end(void);

private:
    Ui::Statistic *ui;
    QString str;
};

#endif // STATISTIC_H
