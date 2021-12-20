#ifndef _HEAD_H
#define _HEAD_H


#include <sphere.h>



class _head : public _object3D
{
private:
    _sphere head;
public:
    _head();
    void create();
    void transf();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_smooth();
};

#endif // _HEAD_H
