#include "body1.h"

_body1::_body1()
{

}

void _body1::create(){
    body.create(20);
}
void _body1::transf(){
    glRotatef(90,0,0,1);
}
void _body1::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,1,1);
    transf();
    body.draw_point();
    glPopMatrix();
}

void _body1::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,1,1);
    transf();
    body.draw_line();
    glPopMatrix();
}

void _body1::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,1,1);
    transf();
    body.draw_fill();
    glPopMatrix();
}

void _body1::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,1,1);
    transf();
    body.draw_chess();
    glPopMatrix();
}

void _body1::draw_lighted_flat_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,1,1);
    transf();
    body.draw_lighted_flat_smooth();
    glPopMatrix();
}
