#include "../header/FIFO.h"

FIFO::FIFO()
    : PageReplacement_Algorithm("FIFO") { }

int FIFO::select_victim()
{
    int victim = myqueue.front();
    myqueue.pop();
    return victim;
}

void FIFO::informed_newPage(int page_number, bool page_fault)
{
    if(page_fault)
    {
        numberOf_pageFaults ++;
        myqueue.push(page_number);        
    }    
}