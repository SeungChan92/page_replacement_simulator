#ifndef PageReplacement_Algorithm_h__
#define PageReplacement_Algorithm_h__

#include "Page.h"

#include <string>
using namespace std;

class PageReplacement_Algorithm
{
public:
    PageReplacement_Algorithm(string name);

    virtual Page* select_victim() {};
    virtual void informed_newPage(Page *page, bool page_fault) {};
    void show_result();
protected:
    string name;
    int numberOf_pageFaults;
    int elapsed_time;
};

#endif //PageReplacement_Algorithm_h__