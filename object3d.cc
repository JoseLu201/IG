/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/


void _object3D::compute_triangles_normals(){
    //vector<> aux;
    _vertex3f p2,p1,p0,vA,vB;


    for(unsigned int i = 0; i < Triangles.size();i++){
       vA = Vertices[Triangles[i]._0] - Vertices[Triangles[i]._1];
       vB = Vertices[Triangles[i]._1] - Vertices[Triangles[i]._2];
       Triangles_normals.push_back((vA.cross_product(vB)).normalize());
    }

}

void _object3D::draw_line()
{//cout << "LINIGN" << endl;
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            glBegin(GL_TRIANGLES);
            glColor3fv((GLfloat *) &BLACK);
            for(unsigned int i = 0; i < Triangles.size();i++){
                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._2]);
            }

        glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            glBegin(GL_TRIANGLES);

            for(unsigned int i = 0; i < Triangles.size();i++){
                glColor3fv((GLfloat *) &GREEN);

                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._2]);


                }
        glEnd();
}


void _object3D::draw_lighted_flat_smooth()
{
    compute_triangles_normals();
    GLfloat light_position[] = {1,1,1,0}; //Posicion de la luz
    GLfloat light_ambient[] = {0.1,1,0};
    GLfloat Material_difuse[] = {0.7,0,0};
    GLfloat Material_ambient[] = {0.1,0,0};

    glLightfv(GL_LIGHT0, GL_POSITION,(GLfloat*) & light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT,(GLfloat*) & light_ambient);



    glPolygonMode(GL_FRONT,GL_FILL);

    glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat*) &Material_ambient);
    glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat*) &Material_difuse);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glShadeModel(GL_FLAT);
            glBegin(GL_TRIANGLES);
            for(unsigned int i = 0; i < Triangles.size();i++){
                glNormal3fv((GLfloat *) &Triangles_normals[i]);
                glColor3fv((GLfloat *) &BLUE);

                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._2]);


                }
            glEnd();
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            glBegin(GL_TRIANGLES);
            for(unsigned int i = 0; i < Triangles.size();i++){
                glColor3fv((GLfloat *) &BLUE);
                if(i % 2 == 0 )
                    glColor3fv((GLfloat *) &MAGENTA);

                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat * ) & Vertices[Triangles[i]._2]);
            }
        glEnd();
}
