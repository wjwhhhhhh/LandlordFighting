#include "layout/include/game_manager.h"
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
namespace layout
{
void GameManager::startGame()
{
    washCard();
}

void GameManager::washCard()
{
    std::vector<int32_t> cards(54);
    std::iota(cards.begin(), cards.end(), 0);
    std::shuffle(cards.begin(), cards.end(), rng);
    for (int i = 0; i < 3; i++)
    {
        std::vector<Card> card;
        for (int j = i * 17; j < i * 17 + 17; j++)
        {
            card.emplace_back(cards[j]);
        }
        playerGetCard(i, card);
    }
    landlordCard.emplace_back(cards[51]);
    landlordCard.emplace_back(cards[52]);
    landlordCard.emplace_back(cards[53]);
}

void GameManager::playerSentCard(int index, const std::vector<Card> &cards)
{
}

void GameManager::playerGetCard(int index, const std::vector<Card> &cards)
{
    playes_[index].addCard(cards);
}

const Player &GameManager::getPlayer(int32_t index)
{
    return playes_[index];
}
}; // namespace layout