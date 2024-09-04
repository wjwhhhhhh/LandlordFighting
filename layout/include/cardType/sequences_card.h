#pragma once
#include "card_group.h"
#include "listen.h"
#include <memory>
#include <tuple>
namespace layout
{
class SequencesCard : public Listener
{
  public:
    SequencesCard()
    {
    }
    ~SequencesCard()
    {
    }
    std::shared_ptr<CardGroup> dealOne(const std::vector<Card> &cards);
    std::shared_ptr<CardGroup> dealTwo(const std::vector<Card> &cards);
    std::shared_ptr<CardGroup> dealThree(const std::vector<Card> &cards);
    bool shouldResponse(const std::vector<int32_t> &cards) override;
    bool shouldResponse(const std::vector<Card> &cards) override;
    std::shared_ptr<CardGroup> deal(const std::vector<Card> &cards) override;

  private:
    std::tuple<bool, int32_t> check(const std::vector<Card> &cards);
};
} // namespace layout
