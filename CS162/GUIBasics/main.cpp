#include <iostream>
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //rest of code

    //make a dialog widget to be top container
    QDialog* window = new QDialog();

    //make the top row
    QHBoxLayout* hBoxTopRow = new QHBoxLayout();

    //make the two widgets for top row and add to that row
    QLabel* lblName = new QLabel("Enter your name:");
    hBoxTopRow->addWidget(lblName);
    QLineEdit* lneName = new QLineEdit("");
    hBoxTopRow->addWidget(lneName);

    //Make a hBox to hold bottom row of buttons
    QHBoxLayout* hBoxBottomRow = new QHBoxLayout;

    hBoxBottomRow->addStretch();

    QPushButton* btnEnter = new QPushButton("Enter");
    hBoxBottomRow->addWidget(btnEnter);

    QPushButton* btnCancel = new QPushButton("Cancel");
    hBoxBottomRow->addWidget(btnCancel);


    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addStretch();

    mainLayout->addLayout(hBoxTopRow);

    mainLayout->addStretch();
    mainLayout->addLayout(hBoxBottomRow);

    mainLayout->addStretch();

    window->setLayout(mainLayout);
    window->show();

    return app.exec();
}
