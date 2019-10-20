#ifndef TEMPCONVERSIONDIALOG_H
#define TEMPCONVERSIONDIALOG_H

#include <QWidget>
#include <QLineEdit>

class TempConversionDialog : public QWidget
{
    Q_OBJECT
public:
    explicit TempConversionDialog(QWidget *parent = 0);
private:
    QLineEdit* editFahrenheit;
    QLineEdit* editCelsius;
signals:

public slots:
    void convertFtoC();
    void convertCtoF();
};

#endif // TEMPCONVERSIONDIALOG_H
