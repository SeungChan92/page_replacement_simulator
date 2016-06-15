#ifndef Pager_h__
#define Pager_h__

#include "PageReplacement_Algorithm.h"

class Pager
{
public:
    Pager();

    int get_numberOfFrames();

    void ask_setting();
    void init();
    void paging(PageReplacement_Algorithm*);
    void show_string();
private:
    char* frames;
    char* pageReference_string;
    int numberOf_frames;
    int lengthOf_pageReference;
    int numberOf_pages;

    void make_pageReferenceString();
    bool is_inFrame(int page_number);
    bool empty_exist();
    void load(char page_number);
    void load(char page_number, int frame_number);
    int swapOut(char victim);
};

#endif //Pager_h__