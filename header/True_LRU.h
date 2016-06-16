#include "PageReplacement_Algorithm.h"

#include <list>
using namespace std;

class True_LRU: public PageReplacement_Algorithm
{
public:
    True_LRU();

    int select_victim();
    void informed_newPage(int page_number, bool page_fault);
private:    
    list<int> mylist;
};