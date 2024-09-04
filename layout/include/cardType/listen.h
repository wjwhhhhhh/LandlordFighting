#ifndef LISTEN_H
#define LISTEN_H
#include "card.h"
#include <memory.h>
#include <vector>
namespace layout
{
class Listener
{
  public:
    virtual std::shared_ptr<CardGroup> deal(const std::vector<Card> &cards) = 0;
    virtual bool shouldResponse(const std::vector<int32_t> &cards) = 0;
    virtual bool shouldResponse(const std::vector<Card> &cards) = 0;

  private:
};
} // namespace layout
#endif // LISTEN_H
