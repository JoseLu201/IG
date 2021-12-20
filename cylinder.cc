#include "cylinder.h"
//Para hacer el reverse de vectores
#include <algorithm>

_cylinder::_cylinder(float size){

    Vertices.resize(4);
    Vertices[0] = _vertex3f(0,size/2,0);
    Vertices[1] = _vertex3f(size/2,size/2,0);
    Vertices[2] = _vertex3f(size/2,-size/2,0);
    Vertices[3] = _vertex3f(0,-size/2,0);
    //_revolution_objetct::createVertex(4,Vertices);

/*
    Vertices.resize(6);
    Vertices[0] = _vertex3f(0,size/2,0);
    Vertices[1] = _vertex3f(size/2,size/2,0);

    Vertices[2] = _vertex3f(size/5,size/7,0);
    Vertices[3] = _vertex3f(size/5,size/-7,0);

    Vertices[4] = _vertex3f(size/2,-size/2,0);
    Vertices[5] = _vertex3f(size,-size/2,0);
    PrintPoints(Vertices);
    _revolution_objetct::createVertex(20,Vertices);*/
/*
    cout << "Cylinder " << endl;
    cout << "Tam triangles " << Triangles.size() << endl;
    for(int i = 0; i< Triangles.size();i++){
        cout <<"Tri"<<i<<" " <<  Triangles[i].x << " " << Triangles[i].y << " " << Triangles[i].z << endl;
    }
    cout << "End printing cylinder " << endl;*/
}

void _cylinder::create(int numDiv){
    vector<_vertex3f> vert;
    float size = 1;
    vert.resize(4);
    vert[0] = _vertex3f(0,size/2,0);
    vert[1] = _vertex3f(size/2,size/2,0);
    vert[2] = _vertex3f(size/2,-size/2,0);
    vert[3] = _vertex3f(0,-size/2,0);
    //std::reverse(vert.begin(), vert.end());

    _revolution_objetct::createRevolutionObject(vert,numDiv);

}


