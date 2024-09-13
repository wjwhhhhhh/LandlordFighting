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
    const std::vector<Card> &getCards() const;

  private:
    bool is_landlord_; // 是否地主
    bool is_owner;     // 是否是本人
    std::vector<Card> cards_;
};
} // namespace layout