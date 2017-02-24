#ifndef LOSEGAME_H
#define LOSEGAME_H

#include <QDialog>

namespace Ui {
class LoseGame;
}

class LoseGame : public QDialog
{
    Q_OBJECT

public:
    explicit LoseGame(QWidget *parent = 0);
    ~LoseGame();
public slots:
    void end(void);

private:
    Ui::LoseGame *ui;
};

#endif // LOSEGAME_H
