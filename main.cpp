#include <QApplication>
#include <Qwidget>
#include "ui/include/screen.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ui::screen w;
    w.show();
    return a.exec();
}
