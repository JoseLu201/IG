/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "axis.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_axis::_axis(float Size)
{
  Vertices.resize(12);

  Vertices[0]=_vertex3f(-Size,0,0);
  Vertices[1]=_vertex3f(Size,0,0);

  Vertices[2]=_vertex3f(0,-Size,0);
  Vertices[3]=_vertex3f(0,Size,0);

  Vertices[4]=_vertex3f(0,0,-Size);
  Vertices[5]=_vertex3f(0,0,Size);
  //Puntos de referencia
  Vertices[6] = _vertex3f(0,0,0);
  Vertices[7] = _vertex3f(1,0,0);
  Vertices[8] = _vertex3f(-1,0,0);
  Vertices[9] = _vertex3f(0,1,0);
  Vertices[10] = _vertex3f(0,-1,0);
  Vertices[11] = _vertex3f(0,0,1);
  Vertices[12] = _vertex3f(0,0,-1);
}



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _axis::draw_line()
{
  glLineWidth(1);
  glBegin(GL_LINES);
  // eje X, color rojo
  glColor3fv((GLfloat *) &RED);
  glVertex3fv((GLfloat *) &Vertices[0]);
  glVertex3fv((GLfloat *) &Vertices[1]);
  // eje Y, color verde
  glColor3fv((GLfloat *) &GREEN);
  glVertex3fv((GLfloat *) &Vertices[2]);
  glVertex3fv((GLfloat *) &Vertices[3]);
  // eje Z, color azul
  glColor3fv((GLfloat *) &BLUE);
  glVertex3fv((GLfloat *) &Vertices[4]);
  glVertex3fv((GLfloat *) &Vertices[5]);
  glEnd();

  glPointSize(6);
  glEnable(GL_POINT_SMOOTH);
  glBegin(GL_POINTS);
  glColor3fv((GLfloat *) &BLACK);
  for(int i = 6; i <= 12;i++)
    glVertex3fv((GLfloat *) &Vertices[i]);

  glEnd();
}


