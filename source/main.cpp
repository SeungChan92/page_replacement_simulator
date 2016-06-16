#include "../header/Pager.h"
#include "../header/PageReplacement_Algorithm.h"
#include "../header/FIFO.h"
#include "../header/OPT.h"
#include "../header/True_LRU.h"
#include "../header/Second_Chance.h"
#include "../header/Enhanced_SecondChance.h"

#include <iostream>
using namespace std;

int numberOf_Algorithms = 5; 

int main()
{
    Pager pager;
    pager.ask_setting();
    pager.make_frames();
    
    //cout << "--- 0-1 ---" << endl;
    
    pager.make_pageReferenceString();
    
    //cout << "--- 0-2 ---" << endl;

    PageReplacement_Algorithm *pageReplacement_Algorithm[numberOf_Algorithms];
    pageReplacement_Algorithm[0] = new FIFO();
    pageReplacement_Algorithm[1] = new OPT(pager.get_pageReferenceString(), pager.get_lengthOfPageReference());
    pageReplacement_Algorithm[2] = new True_LRU();
    pageReplacement_Algorithm[3] = new Second_Chance();
    pageReplacement_Algorithm[4] = new Enhanced_SecondChance();
    
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