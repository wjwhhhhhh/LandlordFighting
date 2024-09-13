#ifndef CONFIG_H
#define CONFIG_H
#include <cstdint>
#include <vector>
namespace layout
{
class Config
{
  public:
    const std::vector<int32_t> min_with = {0, 0, 2, 3};
    const std::vector<int32_t> min_sequences = {5, 3, 2};
    const int32_t max_cards = 20;
};
const Config config;

} // namespace layout
#endif // CONFIG_H
