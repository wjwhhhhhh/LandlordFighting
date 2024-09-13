#ifndef IMAGE_MANAGE_H
#define IMAGE_MANAGE_H
#include "cardType/card.h"
#include <Qpixmap>
#include <memory>
#include <vector>
namespace layout
{
class ImageManage
{
  public:
    ImageManage()
    {
        init();
    };
    ~ImageManage() {};
    static std::shared_ptr<ImageManage> defaultImageManage()
    {
        static std::shared_ptr<ImageManage> imageManage = std::make_shared<ImageManage>();
        return imageManage;
    }
    std::string toString()
    {
        return "ImageManager";
    }
    const QPixmap &getBackground();
    const QPixmap &getCardByInt(int32_t);
    const QPixmap &getCardByCard(const Card &card);
    const QPixmap &getFarmerAvatar(const int32_t id);
    const QPixmap &getPreparationByInt(const int32_t);
    void init();

  private:
    void loadCard();
    void loadPlayer();
    void loadBackground();
    void loadPreparation();
    std::vector<QPixmap> card_images_; // 一副牌54张  55为背面
    std::vector<QPixmap> player_images_;
    std::vector<QPixmap> background_images_;
    std::vector<QPixmap> Preparation_images_;
};
} // namespace layout
#endif // IMAGE_MANAGE_H
