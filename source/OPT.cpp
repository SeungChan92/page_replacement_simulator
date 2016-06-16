#include "../header/OPT.h"

#include <iostream>
using namespace std;

OPT::OPT(Page **pageReference_string, int lengthOf_pageReference)
    : PageReplacement_Algorithm("OPT")
{
    this->pageReference_string = pageReference_string;
    this->lengthOf_pageReference = lengthOf_pageReference;
    numberOf_loaded = 0;
}

Page* OPT::select_victim()
{
    Page *victim = NULL;
    int next_reference = -1;
    int farthest_distance = -1;
    list<Page*>::iterator farthest_page;
    
    for(list<Page*>::iterator it = inMemory.begin()
            ; it != inMemory.end()
            ; ++it)
    {
        //cout << "*it : " << *it << endl;
        
        next_reference = identify_nextReference(*it);
        if(next_reference > farthest_distance)
        {
            farthest_page = it;
            farthest_distance = next_reference;
        }
        
        //cout << "NEXT REFERENCE : " << next_reference << endl;
        
        //cout << endl;
    }
    
    victim = *farthest_page;
    inMemory.erase(farthest_page);

    //cout << endl;
    
    if(victim->is_dirty())
    {
        elapsed_time += 8;
    }

    return victim;
}

void OPT::informed_newPage(Page *page, bool page_fault)
{
    numberOf_loaded ++;
    
    if(page_fault)
    {
        inMemory.push_front(page);
        
        elapsed_time += 8;   
        numberOf_pageFaults ++;
    }
}

int OPT::identify_nextReference(Page *page)
{
    int i = numberOf_loaded;
    for(; i<lengthOf_pageReference; i++)
    {
        if(page->number == pageReference_string[i]->number) break;
    }
    
    return i;
}
