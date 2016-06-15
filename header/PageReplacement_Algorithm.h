#ifndef PageReplacement_Algorithm_h__
#define PageReplacement_Algorithm_h__

#include <string>
using namespace std;

class PageReplacement_Algorithm
{
public:
    PageReplacement_Algorithm(string name);

    virtual char select_victim() {};
    virtual void informed_newPage(char page_number) {};
    void show_result();
    void pageFault();
protected:
    string name;
    int numberOf_pageFaults;
};

#endif //PageReplacement_Algorithm_h__