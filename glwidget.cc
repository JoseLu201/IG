/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"
#include "QTimer"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/






_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);

   r_ply = new _revolution_ply("../skeleton/ply_models/peonza.ply");
  //ply = new _ply("../skeleton/ply_models/ant.ply");

}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/
//HAY OTRA PARA EL RATON Y LA RUEDA

void _gl_widget::mousePressEvent(QMouseEvent *event){
    if ( event->buttons() & Qt::RightButton ) {
        cout <<"Entrando en en el menu  de press buttom" << endl;

           Selection_position_x = event->x();
           Selection_position_y = height() - event->y();
       }
}
void _gl_widget::mouseReleaseEvent(QMouseEvent *event){
     int x = event->x(), y = event->y();
    if(event->button() == Qt::LeftButton){
        if ( last_x <  x)   Observer_angle_y+=ANGLE_STEP*3;
            else if (last_x > x )   Observer_angle_y-=ANGLE_STEP*3;
            if ( last_y < y )   Observer_angle_x+=ANGLE_STEP*3;
            else if (last_y > y )   Observer_angle_x-=ANGLE_STEP*3;

            last_x = x;
            last_y = y;

    }

    update();

}
void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{

  switch(Keyevent->key()){

  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CYLINDER;break;
  case Qt::Key_5:Object=OBJECT_SPHERE;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_R:Object=OBJECT_REV_PLY;break;
  case Qt::Key_7:Object=OBJECT_WHEEL;break;
  case Qt::Key_8:Object=OBJECT_EJE;break;
  case Qt::Key_9:Object=OBJECT_HEAD;break;
  case Qt::Key_0:Object=OBJECT_BODY1;break;
  //case Qt::Key_0:Object=OBJECT_CONE_SEC;break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_C:Draw_chess=!Draw_chess;break;
  case Qt::Key_T:Draw_texture=!Draw_texture;break;
  case Qt::Key_B:Draw_light=!Draw_light;break;

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_M:Observer_angle_z-=ANGLE_STEP;break;
  case Qt::Key_N:Observer_angle_z+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
 // case Qt::Key_M: rotateP+=1;break;
  //case Qt::Key_N: rotateP-=1;break;
      //default : break;



  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
//  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);

  //Mantener las proporciones de las figuras en resize de pantalla
  glFrustum(X_MIN*ratio,X_MAX*ratio,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
//glOrtho(-5,5,-5,5,-1000,1000);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
  //_vertex3 VRP();




}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/


///LO MEJOR ES ROTAR LAS PIEZAD CUANDO ESTAN EN EL ORIGEN POR LO QUE LO MEJOR SERIA HACER
/// EL ROTATE JUSTO ANTES DE DIBUJAR LA PIEZA ES DECIR QUE LA PRIMERA TRANSFORMACION DE LA PIEZA
void _gl_widget::draw_objects()
{
  Axis.draw_line();

    if (Draw_point){
    glPointSize(8);
    glColor3fv((GLfloat *) &RED);
    switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
        case OBJECT_CUBE:Cube.draw_point();break;
        case OBJECT_PLY:ply.draw_point();break;
        case OBJECT_REV_PLY:r_ply->draw_point();break;
        case OBJECT_CONE:cone.draw_point();break;
        case OBJECT_CYLINDER:cylinder.draw_point();break;
        case OBJECT_SPHERE:sphere.draw_point();break;
        case OBJECT_WHEEL:wheel.draw_point();break;
        case OBJECT_EJE:eje.draw_point();break;
        case OBJECT_BODY1:body1.draw_point();break;
        case OBJECT_HEAD:head.draw_point();break;

    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(4);
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
        case OBJECT_CUBE:Cube.draw_line();break;
        case OBJECT_PLY:ply.draw_line();break;
        case OBJECT_REV_PLY:r_ply->draw_line();break;
        case OBJECT_CONE:cone.draw_line();break;
        case OBJECT_CYLINDER:cylinder.draw_line();break;
        case OBJECT_SPHERE:sphere.draw_line();break;
        case OBJECT_WHEEL:wheel.draw_line();break;
    case OBJECT_EJE: eje.draw_line();break;
        case OBJECT_BODY1:body1.draw_line();break;
        case OBJECT_HEAD:head.draw_line();break;

    default:break;
    }
  }

  if (Draw_fill){
    switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
        case OBJECT_CUBE:Cube.draw_fill();break;
        case OBJECT_PLY:ply.draw_fill();break;
        case OBJECT_REV_PLY:r_ply->draw_fill();break;
        case OBJECT_CONE:cone.draw_fill();break;
       case OBJECT_CYLINDER:cylinder.draw_fill();break;
       // case OBJECT_CYLINDER:cylinder.draw_lighted_flat_smooth();break;
        case OBJECT_SPHERE:sphere.draw_fill();break;
        // case OBJECT_SPHERE:sphere.draw_lighted_flat_smooth();break;
    case OBJECT_WHEEL:wheel.draw_fill();break;
    case OBJECT_EJE:eje.draw_fill();break;
        case OBJECT_BODY1:body1.draw_fill();break;
        case OBJECT_HEAD:head.draw_fill();break;

    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
        case OBJECT_CUBE:Cube.draw_chess();break;
        case OBJECT_PLY:ply.draw_chess();break;
        case OBJECT_REV_PLY:r_ply->draw_chess();break;
        case OBJECT_CONE:cone.draw_chess();break;
        case OBJECT_CYLINDER:cylinder.draw_chess();break;
        case OBJECT_SPHERE:sphere.draw_chess();break;
        case OBJECT_EJE:eje.draw_chess();break;
        case OBJECT_WHEEL:wheel.draw_chess();break;
case OBJECT_BODY1:body1.draw_chess();break;

    case OBJECT_HEAD:head.draw_chess();break;
    default:break;
    }
  }

  if (Draw_light){
    switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_lighted_flat_smooth();break;
        case OBJECT_CUBE:Cube.draw_lighted_flat_smooth();break;
        case OBJECT_PLY:ply.draw_lighted_flat_smooth();break;
        case OBJECT_REV_PLY:r_ply->draw_lighted_flat_smooth();break;
        case OBJECT_CONE:cone.draw_lighted_flat_smooth();break;
        case OBJECT_CYLINDER:cylinder.draw_lighted_flat_smooth();break;
        case OBJECT_SPHERE:sphere.draw_lighted_flat_smooth();break;
        case OBJECT_EJE:eje.draw_lighted_flat_smooth();break;
        case OBJECT_WHEEL:wheel.draw_lighted_flat_smooth();break;
        case OBJECT_BODY1:body1.draw_lighted_flat_smooth();break;
        case OBJECT_HEAD:head.draw_lighted_flat_smooth();break;

    default:break;
    }
  }
  if(Draw_texture){
      QRect rec = QApplication::desktop()->screenGeometry();
       int height = rec.height();
       int width = rec.width();
       cout << "--------------------" << endl;
               cout << width << " " << height << endl;
      glEnable(GL_TEXTURE_2D);
      glPolygonMode(GL_FRONT,GL_FILL);
      glBegin(GL_TRIANGLES);
      glTexCoord2f(0,0);
      glVertex3f(-width/2,-height/2,0);
      glTexCoord2f(1,0);
      glVertex3f(width/2,-height/2,0);
      glTexCoord2f(0,1);
      glVertex3f(-width/2,height/2,0);

      glTexCoord2f(1,0);
      glVertex3f(width/2,-height/2,0);
      glTexCoord2f(1,1);
      glVertex3f(width/2,height/2,0);
      glTexCoord2f(0,1);
      glVertex3f(-width/2,height/2,0);
      glEnd();
      glDisable(GL_TEXTURE_2D);
  }
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
  ratio = Width1/ (float)Height1;
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;
  rotateP = 0;
  rotateM = 0;
  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_angle_z=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;
  Draw_light = false;
  Draw_texture = false;;
    //-----------------

    r_ply->create(10);
    cylinder.create(20);

    cone.create(10);
    wheel.create();
    eje.create(1);
    sphere.create(20);
   // cons.create(10);
   body1.create();
  head.create();

//////////
/// // Code to define the Qtimer for the animation
    Timer = new QTimer(this);
    Timer->setInterval(0);
    connect(Timer, SIGNAL(timeout()), this, SLOT(tick()));

    // Code for reading an image
    QString File_name("../skeleton/img/dia_8192.jpg");
    QImage Image;
    QImageReader Reader(File_name);
    Reader.setAutoTransform(true);
    Image = Reader.read();
    if (Image.isNull()) {
      QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                               tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
      exit(-1);
    }
    Image=Image.mirrored();
    Image=Image.convertToFormat(QImage::Format_RGB888);

    // Code to control the application of the texture
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    // Code to pass the image to OpenGL to form a texture 2D
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());
/////////////////
/// a
last_x = 0;
        last_y = 0;
        Selection_position_x = 0;
        Selection_position_y = 0;
}
