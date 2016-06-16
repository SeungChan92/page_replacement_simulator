#include "../header/PageReplacement_Algorithm.h"

#include <iostream>
using namespace std;

PageReplacement_Algorithm::PageReplacement_Algorithm(string name)
{
    this->name = name;
    numberOf_pageFaults = 0;
    elapsed_time = 0;
}

void PageReplacement_Algorithm::show_result()
{
    cout << "ALGORITHM    : " << name << endl;
    cout << "PAGE FAULTS  : " << numberOf_pageFaults << endl;
    cout << "ELAPSED TIME : " << elapsed_time << " ms" << endl;
    cout << endl;
}

bool PageReplacement_Algorithm::is_dirty(int page_number)
{
    if(page_number >= 50)
    {
        return true;
    }
    return false;
}
