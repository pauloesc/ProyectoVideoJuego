#ifndef Puntaje
#define Puntaje
using namespace std;

class Puntaje {
private:
    
    int Puntos=0;
    Jugador* vidj=0;
	
public:
	Puntaje(int Puntos, Jugador* punteroVj);
    
    int getPuntos();
    Jugador* getJugador();
    
    setPuntos(int p);
    setJugador(Jugador* vj);

    ~Puntaje();
    
};
#endif