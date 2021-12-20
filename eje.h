#ifndef EJE_H
#define EJE_H

#include <wheel.h>

class _eje : public _object3D
{
public:

    void create(float dist_btw_wheels = 1);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

private:
    _wheel right_wheel;
    _wheel left_wheel;
    _wheel eje_wheel;

    float dist_btw_wheel;
};

#endif // EJE_H
