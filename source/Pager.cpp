#include "../header/Pager.h"

#include <iostream>
#include <cstdlib>
using namespace std;

Pager::Pager()
{
    numberOf_pages = 0;
}

int Pager::get_numberOfFrames()
{
    return numberOf_frames;
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
    frames = new char[numberOf_frames];
    make_pageReferenceString();
}

void Pager::make_pageReferenceString()
{
    pageReference_string = new char[lengthOf_pageReference];
    int offset = -1;
    
    for(int i=0; i<lengthOf_pageReference; i++)
    {
        offset = rand() % 10;
        pageReference_string[i] = '0' + offset;
    }
}

void Pager::paging(PageReplacement_Algorithm* pageReplacement_Algorithm)
{
    char page_number = 0;
    char victim = 0;
    int freed_frame = -1;
    
    for(int i=0; i<lengthOf_pageReference; i++)
    {
        page_number = pageReference_string[i];
        
        if(is_inFrame(page_number))
        {
            continue;
        }
        else
        {
            pageReplacement_Algorithm->pageFault();
            
            if(empty_exist())
            {
                load(page_number);
            }
            else
            {
                victim = pageReplacement_Algorithm->select_victim();
                freed_frame = swapOut(victim);
                load(page_number, freed_frame);
            }
            
            pageReplacement_Algorithm->informed_newPage(page_number);
        }
        
        cout << "FRAME           : " << frames << endl; 
        //cout << "NUMBER OF PAGES : " << numberOf_pages << endl; 
    }
    cout << endl;
}

void Pager::show_string()
{
    cout << "PAGE REFERENCE STRING : " << pageReference_string << endl;
    cout << endl;
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

void Pager::load(char page_number)
{
    for(int i=0; i<numberOf_frames; i++)
    {
        if(frames[i] == 0)
        {
            load(page_number, i);
            break;
        }
    }
}

void Pager::load(char page_number, int frame_number)
{
    frames[frame_number] = page_number;
    numberOf_pages ++;
}

int Pager::swapOut(char victim)
{
    int i=0;
    
    for(; i<numberOf_frames; i++)
    {
        if(frames[i] == victim)
        {
            frames[i] = 0;
            break;
        }
    }
    numberOf_pages --;
    
    return i;
}