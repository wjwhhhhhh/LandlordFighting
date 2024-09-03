#ifndef CONFIG_H
#define CONFIG_H
namespace laypout
{
    class Config
    {
    public:
        int min_one_sequences=5;
        int min_two_sequences=3;
        int min_three_sequences=2;
    };
    const Config config;

}
#endif // CONFIG_H
