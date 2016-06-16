#include "PageReplacement_Algorithm.h"

#include <list>
using namespace std;

class True_LRU: public PageReplacement_Algorithm
{
public:
    True_LRU();

    Page* select_victim();
    void informed_newPage(Page *page, bool page_fault);
private:    
    list<Page*> mylist;
};