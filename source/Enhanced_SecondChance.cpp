#include "../header/Enhanced_SecondChance.h"

Enhanced_SecondChance::Enhanced_SecondChance()
    : Second_Chance()
{
    name = "Enhanced Second Chance";
}

Page* Enhanced_SecondChance::select_victim()
{    
    Page* victim = NULL;
    
    while(true)
    {
        if(cursor == mylist.end())
        {
            cursor = mylist.begin();
        }
        
        if((*cursor)->reference_bit == 1)
        {
            (*cursor)->reference_bit = 0;
            cursor++;
        }
        else
        {
            if((*cursor)->page->dirty == 1)
            {
                (*cursor)->page->dirty = 0;
                cursor++;
            }
            else
            {
                victim = (*cursor)->page;
                cursor = mylist.erase(cursor);
                break;
            }
        }
    }
    
    return victim;
}