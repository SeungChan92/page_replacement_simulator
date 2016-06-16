#ifndef Second_Chance_h__
#define Second_Chance_h__

#include "PageReplacement_Algorithm.h"

#include <list>
using namespace std;

class Second_Chance: public PageReplacement_Algorithm
{
public:
    Second_Chance();

    Page* select_victim();
    void informed_newPage(Page *page, bool page_fault);
    
protected:
    struct Node
    {
        Page *page;
        bool reference_bit;
        
        Node(Page *page, bool reference_bit)
        {
            this->page = page;
            this->reference_bit = reference_bit;
        };
    };
        
    list<Node*> mylist;
    list<Node*>::iterator cursor;
};

#endif //Second_Chance_h__