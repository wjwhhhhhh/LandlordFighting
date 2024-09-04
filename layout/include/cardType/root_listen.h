#include "collab/include/stdc++.h"
#include "listen.h"
namespace layout
{
class RootListen
{
  public:
    RootListen()
    {
        init();
    }
    ~RootListen();
    static std::shared_ptr<RootListen> defaultRootListen()
    {
        std::shared_ptr<RootListen> manager = std::make_shared<RootListen>();
        return manager;
    }
    void addListener(const std::shared_ptr<Listener> &listener);
    void init();
    std::shared_ptr<CardGroup> deal(std::vector<Card> cards);

  private:
    std::vector<std::shared_ptr<Listener>> listeners;
};
const std::shared_ptr<RootListen> rootListen = RootListen::defaultRootListen();
} // namespace layout