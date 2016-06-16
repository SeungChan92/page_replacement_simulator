#ifndef Pager_h__
#define Pager_h__

#include "PageReplacement_Algorithm.h"
#include "Page.h"

class Pager
{
public:
    Pager();

    int get_numberOfFrames();
    int get_lengthOfPageReference();
    Page** get_pageReferenceString();

    void ask_setting();
    void make_frames();
    void make_pageReferenceString();
    void init();
    void paging(PageReplacement_Algorithm*);
    void show_string();
private:
    Page **frames;
    Page **pageReference_string;
    int numberOf_frames;
    int lengthOf_pageReference;
    int numberOf_pages;

    bool is_inFrame(Page *page);
    bool empty_exist();
    void load(Page *page);
    void load(Page *page, int frame_number);
    int swapOut(Page *victim);
};

#endif //Pager_h__