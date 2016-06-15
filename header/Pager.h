#ifndef Pager_h__
#define Pager_h__

#include "PageReplacement_Algorithm.h"

class Pager
{
public:
    Pager();

    int get_numberOfFrames();
    int get_lengthOfPageReference();
    int* get_pageReferenceString();

    void ask_setting();
    void make_frames();
    void make_pageReferenceString();
    void init();
    void paging(PageReplacement_Algorithm*);
    void show_string();
private:
    int* frames;
    int* pageReference_string;
    int numberOf_frames;
    int lengthOf_pageReference;
    int numberOf_pages;

    bool is_inFrame(int page_number);
    bool empty_exist();
    void load(int page_number);
    void load(int page_number, int frame_number);
    int swapOut(int victim);
};

#endif //Pager_h__