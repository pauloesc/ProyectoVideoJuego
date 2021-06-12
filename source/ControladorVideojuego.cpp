#include "../include/ControladorVideojuego.h"



using namespace std;

ControladorVideojuego* ControladorVideojuego::instance = NULL; 
ControladorVideojuego::ControladorVideojuego() {}

ControladorVideojuego* ControladorVideojuego::getInstance() {
 if (instance == NULL)
 instance = new ControladorVideojuego();
 return instance;
} 



void ControladorVideojuego::datosVideojuego(string nombreJuego, string descrip, float costoMensual, float costoTrimestral, float costoAnual, float costoVitalicia){

    this->nombreJuego=nombreJuego;
    this->descrip=descrip;
    this->costoMensual=costoMensual;
    this->costoTrimestral=costoTrimestral;
    this->costoAnual=costoAnual;
    this->costoVitalicia=costoVitalicia;
}

vector<DtCategoria*> ControladorVideojuego::ObtenerCategoriaPlataforma(){
    
    vector<DtCategoria*> colplataforma; 
    int tamCol=Categorias.size();
    for (int i=0; i<tamCol; i++){
        if(Categorias[i]->getTipo()== "plataforma"){  //mirarlo despues en categoria
            colplataforma.push_back(Categorias[i]->ObtenerDataCategoria()); //mirarlo en cat
        }
    }
    return colplataforma;
}

vector<DtCategoria*> ControladorVideojuego::ObtenerCategoriaGenero(){
    
    vector<DtCategoria*> colgenero; 
    int tamCol=Categorias.size();
    for (int i=0; i<tamCol; i++){
        if(Categorias[i]->getTipo()== "genero"){  //mirarlo despues en categoria
            colgenero.push_back(Categorias[i]->ObtenerDataCategoria());
        }
    }
    return colgenero;
}

vector<DtCategoria*> ControladorVideojuego::ObtenerCategoriaOtros(){

    vector<DtCategoria*> colotro; 
    int tamCol=Categorias.size();
    for (int i=0; i<tamCol; i++){
        if(Categorias[i]->getTipo()=="otro"){  //mirarlo despues en categoria
            colotro.push_back(Categorias[i]->ObtenerDataCategoria());
        }
    }
    return colotro;
} 

void ControladorVideojuego::agregarcategoria (string categoria){
    cats.push_back(categoria);
}

DtVideojuego* ControladorVideojuego::ObtenerInfoVideojuego(){
    DtVideojuego* info= new DtVideojuego(nombreJuego, descrip, costoMensual, costoTrimestral, costoAnual, costoVitalicia, cats);
    return info;
}

void ControladorVideojuego::ConfirmarAltavideoJuego(){
    
    Videojuego* nuevo=new Videojuego (nombreJuego, descrip, costoMensual, costoTrimestral, costoAnual, costoVitalicia);
    int tamcats=cats.size();
    int tamCol=Categorias.size();

    for (int i=0; i<tamcats; i++){
        int j=0;
        bool resu=false;
        while ((!resu) && (j<tamCol)){
            if ((Categorias[j]->getNombre())==cats[i]){ //Fijarse en categoria
                Categorias[j]->adicionarVideojuego(nuevo);
                resu=true;
            }
        j++;                      
        }
    }
    ControladorUsuario* cu;
    cu= ControladorUsuario::getInstance();
    Desarrollador* des=cu->darDesarrollador();
    nuevo->setDesarrollador(des);   //fijarse en videojuego
    Videojuegos.push_back(nuevo);
    cats.clear();
}

void ControladorVideojuego::CancelarAltavideoJuego(){//puedo volver todos a cero, pero el que si hay que borrar es el vector
    cats.clear();
}

Videojuego* ControladorVideojuego::darVideojuego(string Juego){
    Videojuego* vid;
    int tamCol=Videojuegos.size();
    int i=0;
    bool resu=false;

    while ((!resu)&& (i<tamCol)){
        if (Videojuegos[i]->getNombre()==Juego){
            resu=true;
            vid=Videojuegos[i];
        }  //ver en videojuego 
        i++;
    }
    return vid;
}

vector<string> ControladorVideojuego::obtenerVideoJuegosConTodasLasPartidasFinalizadas(){
    vector<string> parfin;
    int tamCol=Videojuegos.size();

    for (int i=0; i<tamCol; i++){
        if (Videojuegos[i]->TodasFinalizadas()){
            parfin.push_back(Videojuegos[i]->getNombre());
        }
    }
    return parfin;
}



void ControladorVideojuego::seleccionarVideoJuego(string nomVJ){
    int tamCol=Videojuegos.size();
    int i=0;
    bool resu=false;

    while ((!resu)&& (i<tamCol)){
        if (Videojuegos[i]->getNombre()==nomVJ){
            resu=true;
            vid=Videojuegos[i];
        }  
        i++;
    }
} 

void ControladorVideojuego::eliminarVideoJuego(){
    
    int tamCol=Videojuegos.size();
    int i=0;
    bool resu=false;

    while ((!resu)&& (i<tamCol)){
        if (Videojuegos[i]->getNombre()==vid->getNombre()){
            resu=true;
            Videojuegos.erase(Videojuegos.begin()+i);
        }  
        i++;
    }

    tamCol=Categorias.size();
    for (int i=0; i<tamCol; i++){
        Categorias[i]->desvincularVideoJuego(vid); //mirarlo despues en categoria
    }

    
    ControladorPartida* cpar = ControladorPartida::getInstance();
    cpar->eliminarPartidas(vid);

    ControladorUsuario* cu;
    cu= ControladorUsuario::getInstance();
    cu->eliminarSuscripcionesVideoJuego(vid->getNombre());

    vid->eliminarPuntajes(); // ven en videojuego
    delete vid;
    vid=NULL;
}


void ControladorVideojuego::cancelarLaEliminacion(){
    vid=NULL;
}

vector<string> ControladorVideojuego::DarJuegos(string email){
    vector<string> resu;
    int tamCol=Videojuegos.size();
   for (int i=0; i<tamCol; i++){
       if (Videojuegos[i]->esDesarrolador(email))  //ver en videojuego
            resu.push_back(Videojuegos[i]->getNombre());
   }
   return resu;
}



vector<string> ControladorVideojuego::ObtenerCategorias(){
    vector<string> resu;
    int tamCol=Categorias.size();
    for (int i=0; i<tamCol; i++){
           resu.push_back(Categorias[i]->getNombre());
    }
    return resu;
}



void ControladorVideojuego::NuevaCategoria(DtCategoria* datos){
    this->datac = datos;  //asi no uso operador de copia
}

void ControladorVideojuego::ConfirmarCategoria(){
    Categoria* nuevo=new Categoria(datac->getNombreCat(), datac->getDescripcion(), datac->getTipo());
    Categorias.push_back(nuevo);
    delete datac;
}

void ControladorVideojuego::CancelarCategoria(){
    delete datac;
}

//a esta funcion le tuve que cambiar el nombre porque habia otra con el mismo nombre
vector<string> ControladorVideojuego::ObtenerVideoJuegosString(){
    vector<string> resu;
    int tamCol=Videojuegos.size();
    for (int i=0; i<tamCol; i++){
           resu.push_back(Videojuegos[i]->getNombre());
    }
   return resu;
} 

DtInfoEspecifica* ControladorVideojuego::SeleccionarVideojuego(string nombVJ){
    
    DtInfoEspecifica* nuevo;
    int tamCol=Videojuegos.size();
    int i=0;
    bool resu=false;

    while ((!resu)&& (i<tamCol)){
        if (Videojuegos[i]->getNombre()==nombVJ){
            vid=Videojuegos[i]; //para recordarlo en memoria
            resu=true;
            
            string des= Videojuegos[i]->getDescripcion();
            float men= Videojuegos[i]->getCostoMensual();
            float tri= Videojuegos[i]->getCostoTrimestral();
            float anual= Videojuegos[i]->getCostoAnual();
            float vit= Videojuegos[i]->getCostoVitalicio();
            string emp= Videojuegos[i]->darEmpresaDesarroladora();
            float promedio= Videojuegos[i]->darPromedioPuntaje();

            vector<string> cates;
            int tam=Categorias.size();
            for (int j=0; j<tam; j++){
                if (Categorias[i]->esCategoriaDelVideojuego(vid))
                    cates.push_back(Categorias[i]->getNombre());
            }
        
            nuevo= new DtInfoEspecifica(des, men, tri, anual, vit, cates, emp, promedio);
        }
        i++;
    }
   return nuevo;
}

int ControladorVideojuego::MostrarHorasTotalJugadas(){
    int resu=vid->totalHorasJugadas();
    
    vid=NULL;
    
    return resu;
}

vector<DtVideojuegoResumido*> ControladorVideojuego::ObtenerVideoJuegos(){
    vector<DtVideojuegoResumido*> resu;
    int tamCol=Videojuegos.size();
    for (int i=0; i<tamCol; i++){
        DtVideojuegoResumido* nuevo= new DtVideojuegoResumido(Videojuegos[i]->getNombre(), Videojuegos[i]->getDescripcion());
        resu.push_back(nuevo);
    }
    return resu;
}

void ControladorVideojuego::AsignarPuntajeVJ(string nomVJ, int puntaje){
    ControladorUsuario* cu;
    cu= ControladorUsuario::getInstance();
    Jugador* jug=cu->darJugador();
    
    Puntaje* punt= new Puntaje(puntaje,jug);
    
    
    int tamCol=Videojuegos.size();
    int i=0;
    bool resu=false;

    while ((!resu)&& (i<tamCol)){
        if (Videojuegos[i]->getNombre()==nomVJ){
            resu=true;
            Videojuegos[i]->asignar(punt);
        }
    i++;
    }

}

ControladorVideojuego::~ControladorVideojuego() {
    int tamCol=Videojuegos.size();
    for (int i=0; i<tamCol; i++)
        delete Videojuegos[i];
    Videojuegos.clear();

    int tamCol2=Categorias.size();
    for (int i=0; i<tamCol2; i++)
           delete Categorias[i];
    Categorias.clear();
}




