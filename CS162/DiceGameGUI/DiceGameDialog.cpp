#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <iostream>

using namespace std;

#include "dicegamedialog.h"

DiceGameDialog::DiceGameDialog(QWidget *parent)
    : QDialog(parent)
{
    title = new QLabel("Three Dice Poker");
    title->setFont(QFont("Arial", 24));
    instructions = new QLabel("Click Button to start:");

    QHBoxLayout* diceLayout = new QHBoxLayout;
    for (int i = 0; i < 3; i++)
    {
        dice[i] = new QPushButton("?");
        dice[i]->setStyleSheet("font-size: 16pt; padding: 0px;");

        dice[i]->setMinimumSize(150,150);
        dice[i]->setMaximumSize(150,150);
        diceLayout->addWidget(dice[i]);
        connect(dice[i],SIGNAL(clicked()), this, SLOT(dieClicked()));
    }
    controlButton = new QPushButton("Start");
    connect(controlButton,SIGNAL(clicked()),this,SLOT(roll()));



    scoreLabel = new QLabel("Score:");
    scoreCalc = new QLineEdit();

    QHBoxLayout* botline = new QHBoxLayout;
    botline->addWidget(controlButton);
    botline->addWidget(scoreLabel);
    botline->addWidget(scoreCalc);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(title);
    mainLayout->addLayout(diceLayout);
    mainLayout->addWidget(instructions);
    mainLayout->addLayout(botline);

    setLayout(mainLayout);
}

void DiceGameDialog::roll()
{
    if (instructions->text() == "Click Start to play again:")
    {
        instructions->setText("Click Button to start:");

        for (int i = 0; i < 3; i++)
        {
            dice[i]->setText("?");
        }
    }
    if (instructions->text() == "Click the dice to reroll, then click Reroll:")
    {
        controlButton->setText("Start");
        instructions->setText("Click Start to play again:");
    }
    if(instructions->text() == "Click Button to start:")
    {
        instructions->setText("Click the dice to reroll, then click Reroll:");
        controlButton->setText("Reroll");
    }

    for (int i = 0; i < 3; i++)
    {
        if (dice[i]->text() == "?")
            gameEngine.rollDie(i);
    }
    string num[3];
    for (int i = 0; i < 3; i++)
    {
        num[i] = to_string(gameEngine.getDieValue(i));
    }

    QString Qnum[3];
    for (int i = 0; i < 3; i++)
    {
        Qnum[i] = QString::fromStdString(num[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        if (dice[i]->text() == "?")
        {
            dice[i]->setText(Qnum[i]);
        }
    }

    string scoreString = to_string(gameEngine.getScore());
    QString theScore = QString::fromStdString(scoreString);
    scoreCalc->setText(theScore);


}

void DiceGameDialog::dieClicked()
{
    QObject* mySender = QObject::sender();
    QPushButton* pressedButton = dynamic_cast<QPushButton*>(mySender);
    for (int i = 0; i < 3; i++)
    {
        if (dice[i] == pressedButton)
        {
            dice[i]->setText("?");
        }
    }
}

DiceGameDialog::~DiceGameDialog(){}
