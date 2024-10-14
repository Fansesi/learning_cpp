#include <iostream>

enum DaysOfWeek
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
};

namespace Monsters
{
    enum MonsterType
    {
        orc, goblin, troll, ogre, skeleton,

    };
}

int main()
{
    DaysOfWeek myday {sunday};
    std::cout << myday;
    return 0;
}
