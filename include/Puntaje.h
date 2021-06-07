#ifndef Puntaje
#define Puntaje
using namespace std;

class Puntaje {
private:
    
    int Puntos=0;
    Videojuego* vidj=0;
	
public:
	Puntaje(int Puntos, Videojuego* punteroVj);
    
    int getPuntos();
    Videojuego* getVideoJuego();
    
    setPuntos(int p);
    setVideoJuego(Videojuego* vj);

    ~Puntaje();
    
};
#endif