#include "eje.h"

void _eje::create(float dist_btw_wheel){
    this->dist_btw_wheel = dist_btw_wheel;
    left_wheel.create();
    right_wheel.create();
    eje_wheel.create();
}




void _eje::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(dist_btw_wheel,0,0);
    right_wheel.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-dist_btw_wheel,0,0);
    left_wheel.draw_line();
    glPopMatrix();

    glPushMatrix();

    glScalef(19,0.1,0.1);
    eje_wheel.draw_line();
    glPopMatrix();
}

void _eje::draw_fill(){
    glColor3f(100,100,100);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(dist_btw_wheel,0,0);
    right_wheel.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-dist_btw_wheel,0,0);
    left_wheel.draw_fill();
    glPopMatrix();


    glPushMatrix();
     glScalef(19,0.1,0.1);
    eje_wheel.draw_fill();
    glPopMatrix();
}

void _eje::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(dist_btw_wheel,0,0);
    right_wheel.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-dist_btw_wheel,0,0);
    left_wheel.draw_point();
    glPopMatrix();


    glPushMatrix();
     glScalef(19,0.1,0.1);
    eje_wheel.draw_point();
    glPopMatrix();
}

void _eje::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(dist_btw_wheel,0,0);
    right_wheel.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-dist_btw_wheel,0,0);
    left_wheel.draw_chess();
    glPopMatrix();


    glPushMatrix();
     glScalef(19,0.1,0.1);
    eje_wheel.draw_chess();
    glPopMatrix();
}
