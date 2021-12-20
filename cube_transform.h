#ifndef CUBE_TRANSFORM_H
#define CUBE_TRANSFORM_H

#include "object3d.h"
#include "cube.h"

class cube_transform : public _object3D
{
private:
    _cube cube;
public:
    cube_transform(float size = 1.0);

};

#endif // CUBE_TRANSFORM_H
