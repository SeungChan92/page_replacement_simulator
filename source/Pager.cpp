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
int* Pager::get_pageReferenceString()
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
        frames[i] = -1;
    }
    
    numberOf_pages = 0;
}

void Pager::make_frames()
{
    frames = new int[numberOf_frames];    
}

void Pager::make_pageReferenceString()
{
    pageReference_string = new int[lengthOf_pageReference];
    
    srand(time(NULL));
    for(int i=0; i<lengthOf_pageReference; i++)
    {
        pageReference_string[i] = rand() % 100;
    }
}

void Pager::paging(PageReplacement_Algorithm* pageReplacement_Algorithm)
{
    //cout << "paging - 1" << endl << endl;
    
    char page_number = 0;
    char victim = 0;
    int freed_frame = -1;
    bool page_fault = 0;
    
    for(int i=0; i<lengthOf_pageReference; i++)
    {
        page_number = pageReference_string[i];
        
        //cout << "paging - 2" << endl << endl;
        
        if(is_inFrame(page_number))
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
                
                load(page_number);
            }
            else
            {
                //cout << "paging - 6" << endl << endl; 
                
                victim = pageReplacement_Algorithm->select_victim();
                freed_frame = swapOut(victim);
                load(page_number, freed_frame);
            }            
        }
        
        pageReplacement_Algorithm->informed_newPage(page_number, page_fault);
        
        if(page_fault)
        {
            cout << "FRAME  :";         
            for(int i=0; i<numberOf_frames; i++)
            {
                cout << ' ' << frames[i]; 
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
        cout << ' ' << pageReference_string[i]; 
    }
    cout << endl << endl;
}

bool Pager::is_inFrame(int page_number)
{
    for(int i=0; i<numberOf_frames; i++)
    {
        if(page_number == frames[i])
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

void Pager::load(int page_number)
{
    for(int i=0; i<numberOf_frames; i++)
    {
        if(frames[i] == -1)
        {
            load(page_number, i);
            break;
        }
    }
}

void Pager::load(int page_number, int frame_number)
{
    frames[frame_number] = page_number;
    numberOf_pages ++;
}

int Pager::swapOut(int victim)
{
    int i=0;
    
    for(; i<numberOf_frames; i++)
    {
        if(frames[i] == victim)
        {
            frames[i] = -1;
            break;
        }
    }
    numberOf_pages --;
    
    return i;
}