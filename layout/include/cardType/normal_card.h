#ifndef NORMAL_CARD_H
#define NORMAL_CARD_H
#include "card_group.h"
#include "listen.h"
#include <memory>
#include <tuple>
namespace layout
{
class NormalCard : public Listener
{
  public:
    NormalCard()
    {
    }
    ~NormalCard()
    {
    }
    std::shared_ptr<CardGroup> deal(const std::vector<Card> &cards) override;
    bool shouldResponse(const std::vector<int32_t> &cards) override;
    bool shouldResponse(const std::vector<Card> &cards) override;

  private:
    std::tuple<bool, int32_t> check(const std::vector<Card> &cards);
};
} // namespace layout
#endif // NORMAL_CARD_H
