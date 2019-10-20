#include <iostream>
#include <QApplication>
#include <TempConversionDialog.h>

using namespace std;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    TempConversionDialog dlg;
    dlg.show();

    return app.exec();
}
