#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include <QPixmap>
#include "layout/include/image_manage.h"

namespace ui
{
class screen:public QWidget
{
public:
    screen()
    {
        init();
    }
    void paintEvent(QPaintEvent*)override;
private:
    void init();

};
}
#endif // SCREEN_H
