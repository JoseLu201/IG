#ifndef PLY_H
#define PLY_H

#include "object3d.h"
#include "file_ply_stl.h"
#include "revolution_objetct.h"

using namespace std;

class _ply : public _object3D
{

private:
    vector<float> coordinates;
    vector<unsigned int> position;


public:

    //_revolution_objetct r;
    _ply(string nombre_archivo);
    void create(int numDivisiones);


};
#endif // PLY_H
