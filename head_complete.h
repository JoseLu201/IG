#ifndef _HEAD_COMPLETE_H
#define _HEAD_COMPLETE_H

#include <object3d.h>
#include <head.h>
#include <beak.h>
#include <sphere.h>


class _head_complete //: public _object3D
{
protected:
    _head head;
    _beak beak;
    _sphere eye1, eye2;

public:
    _head_complete();
    void create();
    void transf();
    void transf_eye();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_smooth();
};

#endif // _HEAD_COMPLETE_H
