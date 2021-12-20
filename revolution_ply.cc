#include "revolution_ply.h"

_revolution_ply::_revolution_ply(string name)
{
    this->ply = new _ply(name);
    //_ply::_ply(name);
}

void _revolution_ply::create(int num){

    //PrintPoints(this->ply->Vertices);
    _revolution_objetct::createPLY(this->ply->Vertices,num);
}
