#include "../header/FIFO.h"

FIFO::FIFO(int numberOf_frames)
    : PageReplacement_Algorithm("FIFO")
{
    this->numberOf_frames = numberOf_frames;
}

char FIFO::select_victim()
{
    char victim = myqueue.front();
    myqueue.pop();
    return victim;
}

void FIFO::informed_newPage(char page_number)
{
    if(myqueue.size() == numberOf_frames) return;
    
    myqueue.push(page_number);
}