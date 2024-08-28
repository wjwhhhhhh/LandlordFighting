#include <memory>
#include <string>
namespace collab
{
class DataManager
{
  public:
    static std::shared_ptr<DataManager> defaultDataManager()
    {
        static std::shared_ptr<DataManager> manager = std::make_shared<DataManager>();
        return manager;
    };

  private:
    DataManager();
    ~DataManager();
};
}; // namespace collab
