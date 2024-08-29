#include "ui/include/screen.h"
#include <QPainter>
namespace ui
{
void screen::init()
{

    this->resize(1600,1200);

}
void screen::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),layout::ImageManage::defaultImageManage()->getBackground());
    painter.drawPixmap(300,200,layout::ImageManage::defaultImageManage()->getCardByInt(0));
}
}
