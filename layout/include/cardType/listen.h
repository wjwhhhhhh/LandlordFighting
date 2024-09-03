#ifndef LISTEN_H
#define LISTEN_H
#include <memory.h>
#include "card.h"
#include <vector>
namespace layout {
    class Listener
{
 public:
private:
     virtual bool shouldResponse(const std::vector<int32_t>& cards)=0;
     virtual bool shouldResponse(const std::vector<Card>&cards)=0;
    };
}
#endif // LISTEN_H
