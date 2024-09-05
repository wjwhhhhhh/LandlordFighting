#pragma once
#include "layout/include/cardType/card.h"
#include "layout/include/player.h"
#include <memory>
#include <vector>
namespace layout
{
class GameManager
{
  public:
    GameManager();
    ~GameManager();
    static std::shared_ptr<GameManager> defaultGameManager()
    {
        static std::shared_ptr<GameManager> manager = std::make_shared<GameManager>();
        return manager;
    }
    void startGame();
    void washCard();
    void sentCard(int index, const std::vector<Card> &cards);

  private:
    std::vector<Player> playes_;
};
const std::shared_ptr<GameManager> gameManager = GameManager::defaultGameManager();
}; // namespace layout