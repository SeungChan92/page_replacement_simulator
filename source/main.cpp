#include "../header/Pager.h"
#include "../header/PageReplacement_Algorithm.h"
#include "../header/FIFO.h"

#include <iostream>
using namespace std;

int numberOf_Algorithms = 1; 

int main()
{
    Pager pager;
    pager.ask_setting();
    pager.init();
    
    PageReplacement_Algorithm *pageReplacement_Algorithm[numberOf_Algorithms];
    pageReplacement_Algorithm[0] = new FIFO(pager.get_numberOfFrames());
    
    for(int i=0; i<numberOf_Algorithms; i++)
    {
        pager.paging(pageReplacement_Algorithm[i]);
    }
    
    pager.show_string();
    for(int i=0; i<numberOf_Algorithms; i++)
    {
        pageReplacement_Algorithm[i]->show_result();
    }
    
    return 0;
}