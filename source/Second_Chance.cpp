#include "../header/Second_Chance.h"

#include <iostream>
using namespace std;

Second_Chance::Second_Chance()
    : PageReplacement_Algorithm("Second Chance")
{
    cursor = mylist.end();
}

int Second_Chance::select_victim()
{    
    int victim = -1;
    
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
            victim = (*cursor)->page_number;
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
    
    return victim;
}

void Second_Chance::informed_newPage(int page_number, bool page_fault)
{
    if(page_fault)
    {
        numberOf_pageFaults ++;
        mylist.insert(cursor, new Node(page_number, 0));
    }
    else
    {
        for(list<Node*>::iterator it=mylist.begin()
                ; it != mylist.end()
                ; ++it)
        {
            if((*it)->page_number == page_number)
            {
                (*it)->reference_bit = 1;
                break;
            }
        }
    }
}