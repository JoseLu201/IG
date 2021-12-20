#include "cone.h"

_cone::_cone(float size)
{   cout << size <<endl;
   /* Vertices.resize(3);
    Vertices[0] = _vertex3f(0,size/2,0);
    Vertices[1] = _vertex3f(size/2,-size/2,0);
    Vertices[2] = _vertex3f(0,-size/2,0);
   _revolution_objetct::createRevolutionObject(Vertices,4);*/
}

void _cone::create(int numDiv){
    vector<_vertex3f> vert;
    float size = 1;
    vert.resize(3);
    vert[0] = _vertex3f(0,size/2,0);
    vert[1] = _vertex3f(size/2,-size/2,0);
    vert[2] = _vertex3f(0,-size/2,0);


    _revolution_objetct::createRevolutionObject(vert,numDiv);

}
