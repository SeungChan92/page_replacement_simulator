#include "../header/True_LRU.h"

True_LRU::True_LRU()
    : PageReplacement_Algorithm("True LRU") { }

Page* True_LRU::select_victim()
{
    Page* victim = mylist.front();
    mylist.pop_front();
    
    if(victim->is_dirty())
    {
        elapsed_time += 8;
    }
    
    return victim;
}

void True_LRU::informed_newPage(Page *page, bool page_fault)
{
    if(page_fault)
    {
        numberOf_pageFaults ++;
        elapsed_time += 8;
    }
    else
    {
        for(list<Page*>::iterator it=mylist.begin()
                ; it != mylist.end()
                ; ++it)
        {
            if((*it)->number == page->number)
            {
                mylist.erase(it);
                break;
            }
        }       
    }
    mylist.push_back(page);
}