#include "ply.h"



_ply::_ply(string nombre_archivo){
    _file_ply archivo_ply;
    if(archivo_ply.open(nombre_archivo)){

        //Nota como los pasa por referencia sabemos que los datos estan copiados en esos vectores
        archivo_ply.read(coordinates,position);
        archivo_ply.close();

        Vertices.clear();
        //Tenemos que recorrer las posiciones de 3 en 3, (x,y,z)
        Vertices.resize(coordinates.size()/3);

        for(unsigned int i = 0; i < Vertices.size();i++)
            Vertices[i] = _vertex3f(coordinates[i*3],coordinates[(i*3)+1],coordinates[(i*3)+2] );


        //Ahora para formar triangulos leemos los puntos de 3 en 3
        Triangles.clear();
        Triangles.resize((position.size()/3));

        for(unsigned int i = 0; i < Triangles.size();i++)
            Triangles[i] = _vertex3ui((int ) position[i*3],(int ) position[(i*3)+1],(int ) position[(i*3)+2]);


    }else
        cerr <<"Error al leer al archivo "<<endl; 

}





