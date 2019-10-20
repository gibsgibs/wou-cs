#ifndef DICEGAMEDIALOG_H
#define DICEGAMEDIALOG_H
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include "ThreeDicePoker.h"

class DiceGameDialog : public QDialog
{
    Q_OBJECT

public:
    DiceGameDialog(QWidget *parent = 0);
    ~DiceGameDialog();
private:
    QPushButton* dice[3];
    QLabel* title;
    QLabel* instructions;
    QLabel* scoreLabel;
    QPushButton* controlButton;
    QLineEdit* scoreCalc;

    void resetGame();
    void restartGame();
    ThreeDicePoker gameEngine;

public slots:
    void roll();
    void dieClicked();
};

#endif // DICEGAMEDIALOG_H
