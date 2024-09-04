#pragma once
#include "card_group.h"
#include "listen.h"
#include <memory>
namespace layout
{
class BombCard : public Listener
{
  public:
    std::shared_ptr<CardGroup> deal(const std::vector<Card> &cards) override;
    bool shouldResponse(const std::vector<int32_t> &cards) override;
    bool shouldResponse(const std::vector<Card> &cards) override;

  private:
};
} // namespace layout
