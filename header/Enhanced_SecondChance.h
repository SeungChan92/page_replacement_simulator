#include "Second_Chance.h"

class Enhanced_SecondChance: public Second_Chance
{
public:
    Enhanced_SecondChance();

    Page* select_victim();
};