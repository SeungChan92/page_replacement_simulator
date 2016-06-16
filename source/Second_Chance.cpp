#include "../header/Second_Chance.h"

#include <iostream>
using namespace std;

Second_Chance::Second_Chance()
    : PageReplacement_Algorithm("Second Chance")
{
    cursor = mylist.end();
}

Page* Second_Chance::select_victim()
{    
    Page* victim = NULL;
    
    while(true)
    {
        if(cursor == mylist.end())
        {
            cursor = mylist.begin();
        }
        
        /*
        cout << "select_victim - cursor -> page_number   : " << (*cursor)->page_number << endl;
        cout << "select_victim - cursor -> reference_bit : " << (*cursor)->reference_bit << endl;
        cout << "list - before erase :";
        for(list<Node*>::iterator it=mylist.begin()
                ; it != mylist.end()
                ; ++it)
        {
            cout << ' ' << (*it)->page_number;
        }
        cout << endl;
        */
    
        if((*cursor)->reference_bit == 1)
        {
            (*cursor)->reference_bit = 0;
            cursor++;
        }
        else
        {
            victim = (*cursor)->page;
            cursor = mylist.erase(cursor);
            
            /*
            cout << "list - after erase  :";
            for(list<Node*>::iterator it=mylist.begin()
                    ; it != mylist.end()
                    ; ++it)
            {
                cout << ' ' << (*it)->page_number;
            }
            cout << endl << endl;
            */
            
            break;
        }
    }
    
    if(victim->is_dirty())
    {
        elapsed_time += 8;
    }
    
    return victim;
}

void Second_Chance::informed_newPage(Page *page, bool page_fault)
{
    if(page_fault)
    {
        mylist.insert(cursor, new Node(page, 0));
        
        numberOf_pageFaults ++;
        elapsed_time += 8;
    }
    else
    {
        for(list<Node*>::iterator it=mylist.begin()
                ; it != mylist.end()
                ; ++it)
        {
            if((*it)->page->number == page->number)
            {
                (*it)->reference_bit = 1;
                break;
            }
        }
    }
}