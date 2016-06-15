#include "../header/Pager.h"
#include "../header/PageReplacement_Algorithm.h"
#include "../header/FIFO.h"
#include "../header/OPT.h"

#include <iostream>
using namespace std;

int numberOf_Algorithms = 2; 

int main()
{
    Pager pager;
    pager.ask_setting();
    pager.make_frames();
    pager.make_pageReferenceString();
    
    PageReplacement_Algorithm *pageReplacement_Algorithm[numberOf_Algorithms];
    pageReplacement_Algorithm[0] = new FIFO();
    pageReplacement_Algorithm[1] = new OPT(pager.get_pageReferenceString(), pager.get_lengthOfPageReference());
    
    for(int i=0; i<numberOf_Algorithms; i++)
    {
        //cout << "--- 1 ---" << endl;
        pager.init();
        //cout << "--- 2 ---" << endl;        
        pager.paging(pageReplacement_Algorithm[i]);
        //cout << "--- 3 ---" << endl;        
    }
    
    pager.show_string();
    for(int i=0; i<numberOf_Algorithms; i++)
    {
        pageReplacement_Algorithm[i]->show_result();
    }
    
    return 0;
}