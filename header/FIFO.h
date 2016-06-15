#include "PageReplacement_Algorithm.h"

#include <queue>
using namespace std;

class FIFO: public PageReplacement_Algorithm
{
public:
    FIFO();

    int select_victim();
    void informed_newPage(int page_number, bool page_fault);
private:    
    queue<int> myqueue;
};