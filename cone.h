#ifndef CONE_H
#define CONE_H

#include "revolution_objetct.h"

class _cone : public _revolution_objetct
{
public:
   _cone(float size=1.0);
   void create(int numDiv);
};

#endif // CONE_H
