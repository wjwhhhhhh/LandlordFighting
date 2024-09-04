#pragma once
#include "collab/include/stdc++.h"
#include "layout/include/cardType/card.h"
namespace layout
{
class Player
{
  public:
    std::vector<Card> robotSend();
    std::vector<Card> gptSend();
    std::vector<Card> peopleSend();
    void removeCard(std::vector<Card> cards);
    void addCard(std::vector<Card> cards);
    void sort();
    std::vector<Card> getCards() const;

  private:
    bool is_landlord_; // 是否地主
    std::vector<Card> cards_;
};
} // namespace layout