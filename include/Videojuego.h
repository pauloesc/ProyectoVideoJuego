#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "Desarrollador.h"
#include "Partida.h"
#include "Puntaje.h"

#include "DtSuscripcion.h"

#include <string>
#include <vector>



class Partida;
class Desarrollador;

using namespace std;

class Videojuego {
private:
    
    string Nombre;
    string Descripcion;
    float CostoVitalicio;
    float CostoMensual;
    float CostoTrimestral;
    float CostoAnual;
    
    Desarrollador* Desarolladores = 0;
    vector<Partida*> VectorDePunterosPartidasDelVideojuego;
    
    //recordar que esto podria llegar a dar algun tipo de problemas si alguien gurdase la direccion de memeoria de los puntajes, ya que cuando se redimensiona vector cambia de lugar en la memoria del vector(pregunta a Paulo si no entienden).
    vector<Puntaje*> VectorDeObjetosPuntaje;
	
public:
	Videojuego(string Nombre, string Descripcion, float CostoVitalicio, float CostoMensual, float CostoTrimestral, float CostoAnual);

    string getNombre();
    string getDescripcion();
    float getCostoVitalicio();
    float getCostoMensual();
    float getCostoTrimestral();
    float getCostoAnual();
    
    void setDesarrollador(Desarrollador* des);
    void AsociarPartida(Partida* p);
    Desarrollador* getDesarrolador();
    bool esDesarrolador(string email);
    
    bool TodasFinalizadas();
    void EliminarPartidas();
    void eliminarPuntajes();
    float totalHorasJugadas();
    
    vector<DtSuscripcion*> crearDtsuscripcion();
    string darEmpresaDesarroladora(); //Caso de uso info videojuego
    float darPromedioPuntaje(); //Caso de uso info videojuego
    void asignar(Puntaje* punt); // Para caso de uso asignar puntaje, crea el puntaje y lo vincula con el jugador.
    ~Videojuego();
    
};
#endif
