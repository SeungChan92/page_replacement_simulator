#include "PageReplacement_Algorithm.h"

#include <queue>
using namespace std;

class FIFO: public PageReplacement_Algorithm
{
public:
    FIFO(int numberOf_frames);

    char select_victim();
    void informed_newPage(char page_number);
private:    
    queue<char> myqueue;
    int numberOf_frames;
};