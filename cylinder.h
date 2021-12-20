#ifndef CYLINDER_H
#define CYLINDER_H


//Cilindro sin tapas
#include "revolution_objetct.h"
class _cylinder : public _revolution_objetct
{
public:

    _cylinder(float Size=1.0);
    void create(int numDiv);

};

#endif // CYLINDER_H
