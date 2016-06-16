#include "../header/FIFO.h"

FIFO::FIFO()
    : PageReplacement_Algorithm("FIFO") { }

Page* FIFO::select_victim()
{
    Page *victim = myqueue.front();
    myqueue.pop();
    
    if(victim->is_dirty())
    {
        elapsed_time += 8;
    }
    
    return victim;
}

void FIFO::informed_newPage(Page *page, bool page_fault)
{
    if(page_fault)
    {
        myqueue.push(page);
        
        numberOf_pageFaults ++;
        elapsed_time += 8;
    }    
}