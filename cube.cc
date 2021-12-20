#include "cube.h"

_cube::_cube(float size)
{
    Vertices.resize(8);

    Vertices[0] = _vertex3f(-size,-size,-size);
    Vertices[1] = _vertex3f(-size,-size,size);
    Vertices[2] = _vertex3f(size,-size,-size);
    Vertices[3] = _vertex3f(size,-size,size);
    Vertices[4] = _vertex3f(size,size,-size);
    Vertices[5] = _vertex3f(size,size,size);
    Vertices[6] = _vertex3f(-size,size,-size);
    Vertices[7] = _vertex3f(-size,size,size);
    /*
    Vertices[0] = _vertex3f(-size,-size,size);
    Vertices[1] = _vertex3f(size,-size,size);
    Vertices[2] = _vertex3f(size,-size,-size);
    Vertices[3] = _vertex3f(size,size,-size);
    Vertices[4] = _vertex3f(size,size,size);
    Vertices[5] = _vertex3f(-size,size,-size);
    Vertices[6] = _vertex3f(-size,size,size);
    Vertices[7] = _vertex3f(-size,-size,-size);
*/
    Triangles.resize(12);
    Triangles[0] = _vertex3ui(1,3,7);
    Triangles[1] = _vertex3ui(3,5,7);
    Triangles[2] = _vertex3ui(3,2,5);
    Triangles[3] = _vertex3ui(2,4,5);
    Triangles[4] = _vertex3ui(2,4,6);
    Triangles[5] = _vertex3ui(2,6,0);
    Triangles[6] = _vertex3ui(6,1,0);
    Triangles[7] = _vertex3ui(6,7,1);
    Triangles[8] = _vertex3ui(5,4,6);
    Triangles[9] = _vertex3ui(5,6,7);
    Triangles[10] = _vertex3ui(1,3,2);
    Triangles[11] = _vertex3ui(1,2,0);
/*

    Triangles[0] = _vertex3ui(6,0,1);
    Triangles[1] = _vertex3ui(1,4,6);

    Triangles[2] = _vertex3ui(4,1,2);
    Triangles[3] = _vertex3ui(4,2,3);

    Triangles[4] = _vertex3ui(4,3,5);
    Triangles[5] = _vertex3ui(5,6,4);

    Triangles[6] = _vertex3ui(5,6,0);
    Triangles[7] = _vertex3ui(0,7,5);

    Triangles[8] = _vertex3ui(0,1,2);
    Triangles[9] = _vertex3ui(0,2,7);

    Triangles[10] = _vertex3ui(7,2,3);
    Triangles[11] = _vertex3ui(5,7,3);
*/
}
