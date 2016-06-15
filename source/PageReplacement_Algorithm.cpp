#include "../header/PageReplacement_Algorithm.h"

#include <iostream>
using namespace std;

PageReplacement_Algorithm::PageReplacement_Algorithm(string name)
{
    this->name = name;
    numberOf_pageFaults = 0;
}

void PageReplacement_Algorithm::show_result()
{
    cout << "ALGORITHM   : " << name << endl;
    cout << "PAGE FAULTS : " << numberOf_pageFaults << endl;
    cout << endl;
}

void PageReplacement_Algorithm::pageFault()
{
    numberOf_pageFaults ++;
}