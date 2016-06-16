#include "../header/True_LRU.h"

True_LRU::True_LRU()
    : PageReplacement_Algorithm("True LRU") { }

int True_LRU::select_victim()
{
    int victim = mylist.front();
    mylist.pop_front();
    return victim;
}

void True_LRU::informed_newPage(int page_number, bool page_fault)
{
    if(page_fault)
    {
        numberOf_pageFaults ++;
    }
    else
    {
        mylist.remove(page_number);       
    }
    mylist.push_back(page_number);
}