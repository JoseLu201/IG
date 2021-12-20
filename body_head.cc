#include "body_head.h"

_body_head::_body_head()
{

}


void _body_head::create(){
    body.create();
    head.create();
    body_tail.create(20);
}
void _body_head::transf(){
    glScalef(0.5,0.8,1);
    //glRotatef(90,0,0,1);
}
void _body_head::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    body.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.8,0,0);
    head.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.8,0,0);
    glScalef(2,1,1);
    glRotatef(90,0,0,1);
    body_tail.draw_point();
    glPopMatrix();
}

void _body_head::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    body.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.8,0,0);
    head.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.8,0,0);
    glScalef(2,1,1);
    glRotatef(90,0,0,1);
    body_tail.draw_line();
    glPopMatrix();
}

void _body_head::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    body.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.8,0,0);
    head.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.8,0,0);
    glScalef(2,1,1);
    glRotatef(90,0,0,1);
    body_tail.draw_fill();
    glPopMatrix();
}

void _body_head::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    body.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.8,0,0);
    head.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.8,0,0);
    glRotatef(90,0,0,1);
    body_tail.draw_chess();
    glPopMatrix();
}

void _body_head::draw_lighted_flat_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    transf();
    body.draw_lighted_flat_smooth();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.8,0,0);
    head.draw_lighted_flat_smooth();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.8,0,0);
    glRotatef(90,0,0,1);
    body_tail.draw_lighted_flat_smooth();
    glPopMatrix();
}
