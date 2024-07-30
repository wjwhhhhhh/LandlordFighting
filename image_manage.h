#ifndef IMAGE_MANAGE_H
#define IMAGE_MANAGE_H
#include <memory>
#include <vector>
#include <Qpixmap>
namespace collab
{
class ImageManage
{
public:
    std::shared_ptr<ImageManage>defaultImageManage()
    {
        static std::shared_ptr<ImageManage> imageManage=std::make_shared<ImageManage>();
        return imageManage;
    }
private:
    void init();
    std::vector<QPixmap>cards_image;
    ImageManage(){init();};
};
const std::shared_ptr<ImageManage> ImageManage=ImageManage::defaultImageManage();
}
#endif // IMAGE_MANAGE_H
