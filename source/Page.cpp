#include "../header/Page.h"

Page::Page(int number, bool dirty)
{
    this->number = number;
    this->dirty = dirty;
}

bool Page::is_dirty()
{
    return dirty;
}
void Page::set_dirty(bool dirty)
{
    this->dirty = dirty;
}
