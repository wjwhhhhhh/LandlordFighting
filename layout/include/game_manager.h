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
    GameManager() = default;
    ~GameManager() = default;
    static std::shared_ptr<GameManager> defaultGameManager()
    {
        static std::shared_ptr<GameManager> manager = std::make_shared<GameManager>();
        return manager;
    }
    void startGame();
    void washCard();
    const Player &getPlayer(int32_t index);
    void playerSentCard(int index, const std::vector<Card> &cards);
    void playerGetCard(int index, const std::vector<Card> &cards);

  private:
    std::vector<Player> playes_;
    std::vector<Card> landlordCard;
};
const std::shared_ptr<GameManager> gameManager = GameManager::defaultGameManager();
}; // namespace layout