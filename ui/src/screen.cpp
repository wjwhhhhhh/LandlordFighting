#include "ui/include/screen.h"
namespace ui
{
void screen::init()
{

    this->resize(1600,1200);
    background_.resize(size());
    //写死
    background_.setParent(this);
    background_.setPixmap(layout::ImageManage::defaultImageManage()->getBackground());
    background_.setScaledContents(true);

}
void screen::setBackground(const QPixmap& background)
{
    background_.setPixmap(background);
}
void screen::paintEvent(QPaintEvent*)
{

}
void screen::resizeEvent(QResizeEvent * )
{
    background_.resize(size());
}
}
