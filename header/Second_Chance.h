#include "PageReplacement_Algorithm.h"

#include <list>
using namespace std;

class Second_Chance: public PageReplacement_Algorithm
{
public:
    Second_Chance();

    int select_victim();
    void informed_newPage(int page_number, bool page_fault);
private:
    struct Node
    {
        int page_number;
        bool reference_bit;
        
        Node(int page_number, bool reference_bit)
        {
            this->page_number = page_number;
            this->reference_bit = reference_bit;
        };
    };
        
    list<Node*> mylist;
    list<Node*>::iterator cursor;
};