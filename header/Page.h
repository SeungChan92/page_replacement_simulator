#ifndef Page_h__
#define Page_h__

class Page
{
public:
    Page(int number, bool dirty);
    
    bool is_dirty();
    void set_dirty(bool dirty);

    int number;
    bool dirty;
};

#endif //Page_h__