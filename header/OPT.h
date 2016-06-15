#include "PageReplacement_Algorithm.h"

#include <list>
using namespace std;

class OPT: public PageReplacement_Algorithm
{
public:
    OPT(int *pageReference_string, int lengthOf_pageReference);

    int select_victim();
    void informed_newPage(int page_number, bool page_fault);
private:    
    list<int> inMemory;
    int *pageReference_string;
    int lengthOf_pageReference;
    int numberOf_loaded;
    
    int identify_nextReference(int page_number);
};