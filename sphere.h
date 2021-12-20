#ifndef SPHERE_H
#define SPHERE_H

#include "revolution_objetct.h"

class _sphere : public _revolution_objetct
{
public:
    _sphere(float size=1.0);
    void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius);
    void create(int numDiv);
};

#endif // SPHERE_H
