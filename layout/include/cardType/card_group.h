#ifndef CARD_GROUP_H
#define CARD_GROUP_H
#include "card.h"
#include <vector>
namespace layout
{
class CardGroup
{
  public:
    enum type
    {
        normal,    // 正常
        sequences, // 顺子
        bomb,      // 炸弹
    };

  private:
  protected:
    type group_card_;
};

class NormalGroup : public CardGroup
{
  public:
    NormalGroup()
    {
        group_card_ = type::normal;
    }
    ~NormalGroup() {};
    std::vector<Card> master_; // 主牌
    std::vector<Card> slave_;  // 带的
  private:
};

class SequencesGroup : public CardGroup
{
  public:
    SequencesGroup()
    {
        group_card_ = type::sequences;
    }
    ~SequencesGroup() {};
    std::vector<NormalGroup> master_;

  private:
};

class BombGroup : public CardGroup
{
  public:
    BombGroup()
    {
        group_card_ = type::bomb;
    }
    ~BombGroup() {};
    std::vector<Card> cards_;

  private:
};
} // namespace layout
#endif // CARD_GROUP_H
