#include "PageReplacement_Algorithm.h"

#include <queue>
using namespace std;

class FIFO: public PageReplacement_Algorithm
{
public:
    FIFO();

    Page* select_victim();
    void informed_newPage(Page *page, bool page_fault);
private:    
    queue<Page*> myqueue;
};