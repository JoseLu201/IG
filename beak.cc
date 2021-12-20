#include "beak.h"

_beak::_beak()
{

}


void _beak::transf(){
     glColor3f(0.1,0.2,0.9);
     glTranslatef(0.5,0,0);
    glRotatef(-90,0,0,1);
    glScalef(0.5,1,1);
}
void _beak::create(){
    cone.create(30);
}

void _beak::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    cone.draw_point();
    glPopMatrix();
}

void _beak::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    cone.draw_line();
    glPopMatrix();
}

void _beak::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    cone.draw_fill();
    glPopMatrix();
}

void _beak::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    cone.draw_chess();
    glPopMatrix();
}

void _beak::draw_lighted_flat_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    cone.draw_lighted_flat_smooth();
    glPopMatrix();
}
