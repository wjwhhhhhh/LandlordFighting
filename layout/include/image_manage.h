#ifndef IMAGE_MANAGE_H
#define IMAGE_MANAGE_H
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
    void init();
  private:
    void loadCard();
    void loadPlayer();
    void loadBackground();
    std::vector<QPixmap> card_images_;// 一副牌54张
    std::vector<QPixmap> player_images_;
    std::vector<QPixmap> background_images_;
};
} // namespace layout
#endif // IMAGE_MANAGE_H
