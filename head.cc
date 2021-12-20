#include "head.h"

_head::_head()
{

}

void _head::transf(){

}
void _head::create(){
    head.create(30);
}

void _head::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_point();
    glPopMatrix();
}

void _head::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_line();
    glPopMatrix();
}

void _head::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_fill();
    glPopMatrix();
}

void _head::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_chess();
    glPopMatrix();
}

void _head::draw_lighted_flat_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_lighted_flat_smooth();
    glPopMatrix();
}
