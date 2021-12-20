#include "revolution_objetct.h"

void _revolution_objetct::createPLY(vector<_vertex3f> profile, int numeroDivisiones){


    createVertex(profile,numeroDivisiones);
    createTriangles(profile,numeroDivisiones);


}

void _revolution_objetct::createRevolutionObject(vector<_vertex3f> profile, int numDivisiones){
    createVertex(profile,numDivisiones);
    createTriangles(profile,numDivisiones);
    //PrintTriangles();
}

void _revolution_objetct::createRevolutionObject(vector<_vertex3f> profile, int numDivisiones,float sections){
    createVertex(profile,numDivisiones,sections);
    createTriangles(profile,numDivisiones);
    //PrintTriangles();
}

void _revolution_objetct::createPuntosSinRepetir(vector<_vertex3f> profile, int numDivisiones){

    double alpha = (2*M_PI)/numDivisiones;
    double alpha_new = (2*M_PI)/numDivisiones;

    _vertex3f aux;


    Vertices.clear();
    Vertices = profile;



    vector<_vertex3f> vec_aux = profile;
    //PrintPoints(profile);


    if(profile[0].x == 0 and profile[0].z == 0){
        sup = true;
        vec_aux.erase(vec_aux.begin());
        cout << "Tiene tapa sup" << endl;
    }

       int tam = profile.size() ;
       //cout << profile[tam-1].x << " -- " << profile[tam-1].z << endl;
    if( profile[tam-1].x == 0  and profile[tam-1].z == 0){
        inf = true;
        vec_aux.erase(vec_aux.end());
        cout << "Tiene tapa inf " << endl;
       // PrintPoints(vec_aux);
    }

    //vector<_vertex3f> Vertices_aux;

    for(int j = 0; j < numDivisiones-1;j++){ //Menos una division que ya esta, la generatriz
        for(unsigned int i = 0; i < vec_aux.size();i++){
            aux.x = vec_aux[i].x*cos(alpha);
            aux.y = vec_aux[i].y;
            aux.z = -vec_aux[i].x*sin(alpha);
            Vertices.push_back(aux);
        }
        //cout << alpha*180/M_PI << endl;
        alpha+=alpha_new;
    }
    //PrintPoints(Vertices);
}

void _revolution_objetct::createTrianglulosSinRepetir(vector<_vertex3f> profile, int numeroDivisiones){
    int mod = ((profile.size()-2)*numeroDivisiones)+1;
    //int tam = profile.size();
    //Contruccion de la tapa superior
    _vertex3ui taux;
    unsigned int sc;  //Second component
    unsigned int tc;    // Therd component
    //cout << "Modulo "<< mod << endl;
    int a = (profile.size()-2);

    if(sup){
        unsigned int sc = 1;
        unsigned int tc = profile.size();
        for(int i = 0; i <numeroDivisiones; i++){
            taux.x = 0;
            taux.y = sc;
            taux.z = tc;
            Triangles.push_back(taux);
            sc = tc;
            tc+=a;
            tc%=mod;
        }
    }

    if(inf){
        //mod +=1;
        int modC = (((profile.size()-2)*numeroDivisiones)+1); // 7

        sc = profile.size()-2;
        tc = profile.size()+1;

        for(int i = 0; i <numeroDivisiones; i++){
            taux.x = profile.size()-1;
            taux.y = sc;
            taux.z = tc;
            Triangles.push_back(taux);
            sc = tc;
            int a = (profile.size()-2);
            //cout << a << endl;
            tc+=a;
            cout << "Index:"<<i << endl;

            if( i < numeroDivisiones-2)
                tc%=modC+1;
            if(i>=numeroDivisiones-2)
                tc%=modC;
        }

    }

    //PrintTriangles();

}

void _revolution_objetct::createTriangles(vector<_vertex3f> profile, int numDivisiones){

    Triangles.clear();
    //Triangles.resize(profile.size()*2*numDivisiones);
    _vertex3ui aux, Triangle;
    _vertex3ui aux2;

    int tam = profile.size()-1;
    //int mod = profile.size()*numDivisiones;
    if(profile[0].x == 0 ){
        sup = true;
        //Tapa superior
        //cout << "TIENE TAPA INFERIOR" << endl;
        int mod = numDivisiones * (tam+1);
        for(int i = 0 ; i <numDivisiones;i++){
            aux.x = 0;
            aux.y = ((i*profile.size())+1)%mod;

            aux.z = (((i+1)*profile.size())+1)%mod;
            Triangles.push_back(aux);
        }

    }
    int tapaInf =  profile[tam].x ;
    if(tapaInf == 0){
        inf = true;
        //Tapa inf
       int mod = numDivisiones * (tam+1);
        //cout << "TIENE TAPA INFERIOR" << endl;
        for(int i = 0 ; i <numDivisiones;i++){
            aux.x = tam;
            aux.z = ((tam-1)+profile.size()*i)%mod;
            aux.y = ((tam-1)+profile.size()*(i+1))%mod;
            Triangles.push_back(aux);
        }
    }

        for( int i = 1;i < tam-1;i++){
            for(int j = 0; j < numDivisiones;j++){

                aux.x = j%numDivisiones * (tam+1)+i;
                aux.y = j%numDivisiones * (tam+1)+(i+1);
                aux.z = (j+1)%numDivisiones * (tam+1)+i;
                 Triangles.push_back(aux);
                aux.x = (j+1)%numDivisiones * (tam+1)+i;
                aux.y = j%numDivisiones * (tam+1)+(i+1);
                aux.z = (j+1)%numDivisiones * (tam+1)+(i+1);
                Triangles.push_back(aux);
           }
        }
   //PrintTriangles();
}

void _revolution_objetct::createVertex(vector<_vertex3f> profile,int numDivisionesH ){

    ////createPuntosSinRepetir(profile,numDivisionesH);
    ////createTrianglulosSinRepetir(profile,numDivisionesH);


    double alpha = (2*M_PI)/numDivisionesH;
    double alpha_new = (2*M_PI)/numDivisionesH;

    _vertex3f aux;

    Vertices.clear();
    Vertices = profile;


    //PrintPoints(profile);


//Esta forma crea puntos repetidos

    for(int j = 0; j < numDivisionesH-1;j++){ //Menos una division que ya esta, la generatriz
        for(unsigned int i = 0; i < profile.size();i++){
            aux.x = profile[i].x*cos(alpha);
            aux.y = profile[i].y;
            aux.z = -profile[i].x*sin(alpha);
            Vertices.push_back(aux);

        }
        //cout << alpha*180/M_PI << endl;
        alpha+=alpha_new;
    }


    //Esta forma genera los puntos en otro sentidp
 /*   for(unsigned int i = 0; i < profile.size();i++){
        for(int j = 0; j < numDivisionesH;j++){ //Menos una division que ya esta, la generatriz
            aux.x = profile[i].x*cos(alpha);
            aux.y = profile[i].y;
            aux.z = -profile[i].x*sin(alpha);
            Vertices.push_back(aux);
            //cout << alpha*180/M_PI << endl;
            alpha+=alpha_new;
        }
    }*/


//createTriangles(profile,numDivisionesH);
//PrintTriangles();
//PrintPoints(Vertices);


}

void _revolution_objetct::createVertex(vector<_vertex3f> profile,int numDivisionesH,float section ){

    double alpha = (section)/numDivisionesH;
    double alpha_new = (section)/numDivisionesH;

    _vertex3f aux;

    Vertices.clear();
    Vertices = profile;

    for(int j = 0; j < numDivisionesH-1;j++){ //Menos una division que ya esta, la generatriz
        for(unsigned int i = 0; i < profile.size();i++){
            aux.x = profile[i].x*cos(alpha);
            aux.y = profile[i].y;
            aux.z = -profile[i].x*sin(alpha);
            Vertices.push_back(aux);
        }
        alpha+=alpha_new;
    }
}

