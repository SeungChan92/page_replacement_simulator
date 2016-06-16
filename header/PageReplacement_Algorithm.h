#ifndef PageReplacement_Algorithm_h__
#define PageReplacement_Algorithm_h__

#include <string>
using namespace std;

class PageReplacement_Algorithm
{
public:
    PageReplacement_Algorithm(string name);

    virtual int select_victim() {};
    virtual void informed_newPage(int page_number, bool page_fault) {};
    void show_result();
protected:
    string name;
    int numberOf_pageFaults;
    int elapsed_time;
    
    bool is_dirty(int page_number);
};

#endif //PageReplacement_Algorithm_h__