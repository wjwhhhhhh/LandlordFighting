#ifndef IMAGE_MANAGE_H
#define IMAGE_MANAGE_H
#include <Qpixmap>
#include <memory>
#include <vector>
namespace collab
{
class ImageManage
{
  public:
    static std::shared_ptr<ImageManage> defaultImageManage()
    {
        static std::shared_ptr<ImageManage> imageManage = std::make_shared<ImageManage>();
        return imageManage;
    }

  private:
    void init();
    std::vector<QPixmap> cards_image;
    ImageManage()
    {
        init();
    };
};
const std::shared_ptr<ImageManage> image_manage = ImageManage::defaultImageManage();
} // namespace collab
#endif // IMAGE_MANAGE_H
