#include "TempConversionDialog.h"
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>
#include <iostream>

using namespace std;

TempConversionDialog::TempConversionDialog(QWidget *parent) : QWidget(parent)
{
    QLabel* binaryLabel = new QLabel("Fahrenheit:");
    QLabel* decimalLabel = new QLabel("Celsius");

    editFahrenheit = new QLineEdit();
    editCelsius = new QLineEdit();

    QFormLayout* topPane = new QFormLayout;
    topPane->addRow(binaryLabel, editFahrenheit);
    topPane->addRow(decimalLabel, editCelsius);

    QPushButton* btnFToC = new QPushButton("Convert to F to C");
        QPushButton* btnCToF = new QPushButton("Convert to C to F");

        QHBoxLayout* bottomPane = new QHBoxLayout;
        bottomPane->addWidget(btnFToC);
        bottomPane->addWidget(btnCToF);


        //Put two panes into main layout
        QVBoxLayout* mainLayout = new QVBoxLayout;
        mainLayout->addLayout(topPane);
        mainLayout->addLayout(bottomPane);

        setLayout(mainLayout);

        connect(btnFToC, SIGNAL(clicked()), this, SLOT(convertFtoC()));
        connect(btnCToF, SIGNAL(clicked()), this, SLOT(convertCtoF()));
}

void TempConversionDialog::convertFtoC()
{
    bool ok;
    QString FString = editFahrenheit->text();
    double fTemp = FString.toDouble(&ok);
    if(ok)
    {
        double cTemp = 5.0 / 9.0 * (fTemp - 32);
        QString CString = QString::number(cTemp);
        editCelsius->setText(CString);
    }
    else
    {
        QMessageBox errMsg;
        errMsg.setText("That is not a number");
        errMsg.exec();
    }
}

void TempConversionDialog::convertCtoF()
{
    string CString = editCelsius->text().toStdString();
    try
    {
        double cTemp = stod(CString);
        double fTemp = 9.0 / 5.0 * cTemp + 32;
        QString FString = QString::number(fTemp);
        editFahrenheit->setText(FString);
    }
    catch(invalid_argument ex)
    {
        QMessageBox errMsg;
        errMsg.setText("That is not a number");
        errMsg.exec();
    }
}
