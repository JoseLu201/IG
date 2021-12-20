/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D : public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;
    vector<_vertex3f> Triangles_normals;
  void draw_line();
  void draw_fill();
  void draw_chess();
  void draw_lighted_flat_smooth();

  void compute_triangles_normals();


  /*
    instruiccion para luces, glLight donde light es un numero del uno al maxlight,
    utiizaremos glLight0, tambien utilizaremos el gl matirial
*/
  void PrintPoints(vector<_vertex3f> v){
      cout << "Printing Vertex ..." << endl;
      for(unsigned int i = 0; i < v.size();i++)
          cout <<"P"<<i<<" ->" << v[i].x << " " << v[i].y << " " << v[i].z << endl;
  }

  void PrintTriangles(){
      cout << "Printing Triangles ..." << endl;
      for(unsigned int i = 0; i < Triangles.size();i++)
          cout <<"T"<<i<<" ->" << Triangles[i].x << " " << Triangles[i].y << " " <<Triangles[i].z << endl;
  }

};

#endif // OBJECT3D_H
