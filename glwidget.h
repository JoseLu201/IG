/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "ply.h"
#include "cylinder.h"
#include "cone.h"
#include "sphere.h"
#include "wheel.h"
#include "eje.h"
#include "revolution_ply.h"
#include "QMouseEvent"
#include "QApplication"
#include <QTimer>
#include <QImageReader>
#include <QVector3D>
#include <QDesktopWidget>
#include <cone_sectioned.h>
#include <body1.h>
#include <head_complete.h>
#include <body_head.h>
//////////////
///
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=2;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_PLY,OBJECT_REV_PLY,
                OBJECT_CYLINDER,OBJECT_CONE,OBJECT_SPHERE,OBJECT_WHEEL,OBJECT_EJE,
                OBJECT_TEXTURE, OBJECT_BODY1,OBJECT_HEAD, OBJECT_CONE_SEC} _object; // Aqui tenemos que ir añadiendo los objetos que hacemos
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();

  float ratio = 0;


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
  //void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
 void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;




private:


  _window *Window;

  _axis Axis;
  //Quitar para pintar el tetrahedro
  _tetrahedron Tetrahedron;
//Añadimos el cubo

  _cube Cube;

  //PLY
  _ply ply =  _ply("../skeleton/ply_models/beethoven.ply");
  _revolution_ply *r_ply;
  _cylinder cylinder;
  _cone cone;
  _sphere sphere;

  _wheel wheel;

  _eje eje;

  //_cone_sectioned cons;
  _head_complete head;

    QTimer *time;
  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;
  bool Draw_light;
  bool Draw_texture;

  float Observer_angle_x;
  float Observer_angle_y;
  //Borrar
  float Observer_angle_z;
  float Observer_distance;

  int numDivisiones;
  float rotateP;
  float rotateM;
  QTimer *Timer;
  //QBasicTimer *Timer;

  //
  //_body1 body1;
  _body_head body1;

//Camara
  QVector2D mousePressPosition;
  int last_x, last_y,Selection_position_x,Selection_position_y;
};

#endif
