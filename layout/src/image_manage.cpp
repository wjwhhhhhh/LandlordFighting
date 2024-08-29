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
    QPixmap cards(":/res/images/card.png");
    auto width=cards.width(),height=cards.height();
    auto card_width=width/13,card_height=height/5;
    for(int i=0;i<13;i++)
    {
        card_images_.emplace_back(cards.copy(i*card_width,2*card_height,card_width,card_height));
        card_images_.emplace_back(cards.copy(i*card_width,0*card_height,card_width,card_height));
        card_images_.emplace_back(cards.copy(i*card_width,1*card_height,card_width,card_height));
        card_images_.emplace_back(cards.copy(i*card_width,3*card_height,card_width,card_height));
    }
       card_images_.emplace_back(cards.copy(0*card_width,4*card_height,card_width,card_height));
       card_images_.emplace_back(cards.copy(1*card_width,4*card_height,card_width,card_height));
       card_images_.emplace_back(cards.copy(2*card_width,4*card_height,card_width,card_height));
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

const QPixmap& ImageManage::getCardByInt(int32_t id)
{
    return card_images_[id];
}
const QPixmap& ImageManage::getCardByCard(const Card& card)
{
    return card_images_[card.getPoint()];
}

} // namespace layout
