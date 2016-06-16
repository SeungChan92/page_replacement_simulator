#include "../header/Pager.h"

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

Pager::Pager()
{
    numberOf_pages = 0;
}

int Pager::get_numberOfFrames()
{
    return numberOf_frames;
}
int Pager::get_lengthOfPageReference()
{
    return lengthOf_pageReference;
}
Page** Pager::get_pageReferenceString()
{
    return pageReference_string;
}


void Pager::ask_setting()
{
    cout << "NUMBER OF FRAMES                   : ";
    cin >> numberOf_frames;
    cout << "LENGTH OF PAGE-REFERENCE-STRING    : ";
    cin >> lengthOf_pageReference;
    cout << endl;
}

void Pager::init()
{
    for (int i=0; i<numberOf_frames; i++)
    {
        frames[i] = NULL;
    }
    
    numberOf_pages = 0;
}

void Pager::make_frames()
{
    frames = new Page*[numberOf_frames];    
}

void Pager::make_pageReferenceString()
{
    pageReference_string = new Page*[lengthOf_pageReference];
    
    srand(time(NULL));
    for(int i=0; i<lengthOf_pageReference; i++)
    {
        pageReference_string[i] = new Page(rand() % 100, rand() % 2);
    }
}

void Pager::paging(PageReplacement_Algorithm* pageReplacement_Algorithm)
{
    //cout << "paging - 1" << endl << endl;
    
    Page *page;
    Page *victim = 0;
    int freed_frame = -1;
    bool page_fault = 0;
    
    for(int i=0; i<lengthOf_pageReference; i++)
    {
        page = pageReference_string[i];
        
        //cout << "paging - 2" << endl << endl;
        
        if(is_inFrame(page))
        {
            page_fault = 0;
            //cout << "paging - 3" << endl << endl;  
        }
        else
        {
            page_fault = 1;
            //cout << "paging - 4" << endl << endl;    
            
            if(empty_exist())
            {
                //cout << "paging - 5" << endl << endl; 
                
                load(page);
            }
            else
            {
                //cout << "paging - 6" << endl << endl; 
                
                victim = pageReplacement_Algorithm->select_victim();
                freed_frame = swapOut(victim);
                load(page, freed_frame);
            }            
        }
        
        pageReplacement_Algorithm->informed_newPage(page, page_fault);
        
        if(page_fault)
        {
            cout << "FRAME  :";         
            for(int i=0; i<numberOf_frames; i++)
            {
                cout << ' ';
                if(frames[i] == NULL)
                {
                    cout << 0;
                }
                else
                {
                    cout << frames[i]->number << '-' << frames[i]->dirty;
                } 
            }
            cout << endl << endl;
        }
    }
    cout << endl;
}

void Pager::show_string()
{
    cout << "PAGE REFERENCE STRING :";    
    
    for(int i=0; i<lengthOf_pageReference; i++)
    {
        cout << ' ' << pageReference_string[i]->number; 
    }
    cout << endl << endl;
}

bool Pager::is_inFrame(Page *page)
{
    //cout << "is_inFrame() - page -> number      : " << page->number << endl;
    
    for(int i=0; i<numberOf_frames; i++)
    {
        if(frames[i] == NULL) continue;
        
        if(page->number == frames[i]->number)
        {
            return true;
        }
    }
    
    return false;
}

bool Pager::empty_exist()
{
    if(numberOf_frames > numberOf_pages)
    {
        return true;
    }
    return false;
}

void Pager::load(Page *page)
{
    for(int i=0; i<numberOf_frames; i++)
    {
        if(frames[i] == NULL)
        {
            load(page, i);
            break;
        }
    }
}

void Pager::load(Page *page, int frame_number)
{
    frames[frame_number] = page;
    numberOf_pages ++;
}

int Pager::swapOut(Page *victim)
{
    int i=0;
    
    for(; i<numberOf_frames; i++)
    {
        if(frames[i]->number == victim->number)
        {
            frames[i] = NULL;
            break;
        }
    }
    numberOf_pages --;
    
    return i;
}