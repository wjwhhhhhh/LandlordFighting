#ifndef IMAGE_MANAGE_H
#define IMAGE_MANAGE_H
#include <Qpixmap>
#include <memory>
#include <vector>
#include "card.h"
namespace layout
{
class ImageManage
{
  public:
    ImageManage()
    {
        init();
    };
    ~ImageManage()
    {
    };
    static std::shared_ptr<ImageManage> defaultImageManage()
    {
        static std::shared_ptr<ImageManage> imageManage = std::make_shared<ImageManage>();
        return imageManage;
    }
    std::string toString()
    {
        return "ImageManager";
    }
    const QPixmap& getBackground();
     const QPixmap& getCardByInt(int32_t);
    const QPixmap& getCardByCard(const Card& card);
    void init();
  private:
    void loadCard();
    void loadPlayer();
    void loadBackground();
    std::vector<QPixmap> card_images_;// 一副牌54张，55张为背面
    std::vector<QPixmap> player_images_;
    std::vector<QPixmap> background_images_;
};
} // namespace layout
#endif // IMAGE_MANAGE_H
