#include "wheel.h"

void transf(){
    glRotatef(90,0,0,1);
    glScalef(1,0.1,1);
}

void _wheel::create(){
    cylinder.create(20);
}
void _wheel::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    this->cylinder.draw_point();
    glPopMatrix();
}

void _wheel::draw_line(float angle){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    glRotatef(0+angle,0,1,0);
    this->cylinder.draw_line();
    glPopMatrix();

}

void _wheel::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    this->cylinder.draw_fill();
    glPopMatrix();
}

void _wheel::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    this->cylinder.draw_chess();
    glPopMatrix();
}

void _wheel::draw_lighted_flat_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    this->cylinder.draw_lighted_flat_smooth();
    glPopMatrix();
}

