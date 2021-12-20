#ifndef _BODY_HEAD_H
#define _BODY_HEAD_H

#include <body1.h>
#include <head_complete.h>
#include <cone_sectioned.h>

class _body_head
{
protected :
    _body1 body;
    _head_complete head;
    _cone_sectioned body_tail;
public:
    _body_head();
    void create();
    void transf();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_smooth();
};

#endif // _BODY_HEAD_H
