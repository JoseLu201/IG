#ifndef REVOLUTION_OBJETCT_H
#define REVOLUTION_OBJETCT_H

#include "object3d.h"
#include "cmath"
class _revolution_objetct : public _object3D
{
public:
    void createVertex(vector<_vertex3f> profile,int numDivisionesH);
    void createRevolutionObject(vector<_vertex3f> profile, int numDivisiones);
    void createVertex(vector<_vertex3f> profile,int numDivisionesH,float section);
    void createRevolutionObject(vector<_vertex3f> profile, int numDivisiones,float sections);

    void createTriangles(vector<_vertex3f> profile, int numeroDivisiones);
    void createPuntosSinRepetir(vector<_vertex3f> profile, int numeroDivisiones);
    void createTrianglulosSinRepetir(vector<_vertex3f> profile, int numeroDivisiones);
    void createPLY(vector<_vertex3f> profile, int numeroDivisiones);

//    void crearCuerpo(vector<_vertex3f> profile, int numeroDivisiones);
//    void crearTapaSup(vector<_vertex3f> profile, int numeroDivisiones);
//    void crearTapaInf(vector<_vertex3f> profile, int numeroDivisiones);

private:

 bool inf = false;
 bool sup = false;




};

#endif // REVOLUTION_OBJETCT_H
