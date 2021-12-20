#include "sphere.h"

void _sphere::drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_LINE_LOOP);
        for(i = 0; i <= lineAmount;i++) {
            _vertex3f aux;


                aux.x = x + (radius * cos(i *  twicePi / lineAmount));
                aux.y = y + (radius* sin(i * twicePi / lineAmount));
            aux.z = 0;
            Vertices.push_back(aux);        }
    glEnd();
}
_sphere::_sphere(float size)
{
    int v = 4;
    Vertices.clear();
    _vertex3f aux;
    float alpha = M_PI/v;

    for(int i = 0; i <= v; i++){
        aux.x = size/2*sin(alpha*i);
        aux.y = size/2*cos(alpha*i);
        aux.z = 0;
        Vertices.push_back(aux);
    }


   // _revolution_objetct::createVertex(10,Vertices);
    //drawHollowCircle(2,0,1);
    _revolution_objetct::createRevolutionObject(Vertices,3);
}

void _sphere::create(int numDiv){

    vector<_vertex3f> vert;
    float size = 1;
    int v = 20;
    _vertex3f aux;
    float alpha = M_PI/v;

    for(int i = 0; i <= v; i++){
        aux.x = size/2*sin(alpha*i);
        aux.y = size/2*cos(alpha*i);
        aux.z = 0;
        vert.push_back(aux);
    }
    //cout << "Verticesss" << endl;
    //cout << vert[vert.size()]._0;
    _revolution_objetct::createRevolutionObject(vert,numDiv);

}
