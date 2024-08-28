#include "layout/include/image_manage.h"
namespace layout
{
void ImageManage::init()
{
    loadCard();
    loadPlayer();
    loadBackground();
}

void ImageManage::loadCard()
{

}
void ImageManage::loadPlayer()
{

}
void ImageManage::loadBackground()
{

    background_images_.emplace_back(":/res/images/background-1.png");
}
const QPixmap& ImageManage::getBackground()
{
    return background_images_[0];
}
} // namespace layout
