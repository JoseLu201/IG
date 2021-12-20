#ifndef WHEEL_H
#define WHEEL_H

#include "cylinder.h"

class _wheel : public _object3D
{
public:

    void create();
    void draw_point();
    void draw_line(float rotate = 0.1f);
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_smooth();
private:
    _cylinder cylinder;

};

#endif // WHEEL_H
