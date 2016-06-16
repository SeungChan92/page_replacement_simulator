#include "PageReplacement_Algorithm.h"

#include <list>
using namespace std;

class OPT: public PageReplacement_Algorithm
{
public:
    OPT(Page **pageReference_string, int lengthOf_pageReference);

    Page* select_victim();
    void informed_newPage(Page *page, bool page_fault);
private:    
    list<Page*> inMemory;
    Page **pageReference_string;
    int lengthOf_pageReference;
    int numberOf_loaded;
    
    int identify_nextReference(Page *page);
};