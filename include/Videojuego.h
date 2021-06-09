#ifndef VideoJuego
#define VideoJuego
using namespace std;

class VideoJuego {
private:
    
    string Nombre;
    string Descripcion;
    float CostoVitalicio;
    float CostoMensual;
    float CostoTrimestral;
    float CostoAnual;
    
    vector<Desarrollador*> VectorDePunterosDesarolladores;
    vector<Partida*> VectorDePunterosPartidasDelVideojuego;
    
    //recordar que esto podria llegar a dar algun tipo de problemas si alguien gurdase la direccion de memeoria de los puntajes, ya que cuando se redimensiona vector cambia de lugar en la memoria del vector(pregunta a Paulo si no entienden).
    vector<Puntaje*> VectorDeObjetosPuntaje;
	
public:
	VideoJuego(string Nombre, string Descripcion, float CostoVitalicio, float CostoMensual, float CostoTrimestral, float CostoAnual);

    string getNombre();
    string getDescripcion();
    float getCostoVitalicio();
    float getCostoMensual();
    float getCostoTrimestral();
    float getCostoAnual();
    
    //falta implementra esta 
    //no encuentro donde esta dafinida(no se que hace la funcion)
    sDesarrollador(des:Desarrollador);
    
    bool TodasFinalizadas();
    EliminarPartidas();
    eliminarPuntajes();
    float totalHorasJugadas();
    
    string darEmpresaDesarroladora(); //Caso de uso info videojuego
    float darPromedioPuntaje(); //Caso de uso info videojuego
    void asignar(Puntaje* punt); // Para caso de uso asignar puntaje, crea el puntaje y lo vincula con el jugador.
    ~VideoJuego();
    
};
#endif
