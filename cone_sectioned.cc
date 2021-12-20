#include "cone_sectioned.h"

//_cone_sectioned::_cone_sectioned()
//{

//}

void _cone_sectioned::create(int num){
    vector<_vertex3f> vert;
    float size = 1;
    vert.resize(5);
    vert[0] = _vertex3f(0,size/2,0);
    vert[1] = _vertex3f(size/5,size/2,0);
    vert[2] = _vertex3f(size/2,size/7,0);
    vert[3] = _vertex3f(size/2,-size/2,0);
    vert[4] = _vertex3f(0,-size/2,0);

    _revolution_objetct::createRevolutionObject(vert,num);
}

