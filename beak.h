#ifndef _BEAK_H
#define _BEAK_H

#include <cone.h>

class _beak : public _object3D
{
protected:
    _cone cone;
public:
    _beak();
    void create();
    void transf();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_smooth();
};

#endif // _BEAK_H
