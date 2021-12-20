#ifndef REVOLUTION_PLY_H
#define REVOLUTION_PLY_H

#include <revolution_objetct.h>
#include <ply.h>

class _revolution_ply : public _revolution_objetct
{
public:
    _revolution_ply(string name);
    void create(int num);
private:
    _ply *ply;
};

#endif // REVOLUTION_PLY_H
