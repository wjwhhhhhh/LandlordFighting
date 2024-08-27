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
const std::shared_ptr<DataManager> dataManager = DataManager::defaultDataManager();
}; // namespace collab