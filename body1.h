#ifndef _BODY1_H
#define _BODY1_H

#include <object3d.h>
#include <cylinder.h>

class _body1
{
protected :
    _cylinder body;
public:
    _body1();
    void create();
    void transf();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_smooth();
};

#endif // _BODY1_H
