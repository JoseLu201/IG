#include "head_complete.h"

_head_complete::_head_complete()
{

}

void _head_complete::transf(){
    //glTranslatef(2,1,1);
}

void _head_complete::transf_eye(){

    glScalef(0.2,0.2,0.2);
}

void _head_complete::create(){
    head.create();
    beak.create();
    eye1.create(20);
    eye2.create(20);
}

void _head_complete::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_point();
    glPopMatrix();


    glPushMatrix();
    transf();
    beak.draw_point();
    glPopMatrix();

    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,1);
    eye1.draw_point();
    glPopMatrix();

    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,-1);
    eye2.draw_point();
    glPopMatrix();
}

void _head_complete::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_line();
    glPopMatrix();


    glPushMatrix();
    transf();
    beak.draw_line();
    glPopMatrix();

    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,1);
    eye1.draw_line();
    glPopMatrix();

    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,-1);
    eye2.draw_line();
    glPopMatrix();
}

void _head_complete::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_fill();
    glPopMatrix();


    glPushMatrix();
    transf();
    beak.draw_fill();
    glPopMatrix();

    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,1);
    eye1.draw_fill();
    glPopMatrix();

    transf_eye();
    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,-1);
    eye2.draw_fill();
    glPopMatrix();
}

void _head_complete::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_chess();
    glPopMatrix();


    glPushMatrix();
    transf();
    beak.draw_chess();
    glPopMatrix();

    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,1);
    eye1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,-1);
    eye2.draw_chess();
    glPopMatrix();
}

void _head_complete::draw_lighted_flat_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    head.draw_lighted_flat_smooth();
    glPopMatrix();


    glPushMatrix();
    transf();
    beak.draw_lighted_flat_smooth();
    glPopMatrix();

    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,1);
    eye1.draw_lighted_flat_smooth();
    glPopMatrix();

    glPushMatrix();
    transf_eye();
    glTranslatef(2,1,-1);
    eye2.draw_lighted_flat_smooth();
    glPopMatrix();
}
