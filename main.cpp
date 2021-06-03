#include "include/Sistema.h"
#include "include/DtJugador.h"
#include "include/DtVideojuego.h"
#include "include/Videojuego.h"
#include "include/DtFechaHora.h"
#include <iostream>
#include <string>
using namespace std;

/*
 cambiar la manera en que se inicializa DtPartidaIndividual
 */



int main() {

	int e,eleccion,edad;
	bool termina = false;
	string nick, cont, nom;
	TipoJuego j;


	Sistema SistemaCentral;
    

    while (!termina) {
        
        try{
        
		cout << "Eliga la operacion a realizar: "<<'\n';
		cout << "1) Alta de usuario." <<'\n';
		cout << "2) Publicar videojuego." <<'\n';
		cout << "3) Suscribirse a videojuego." <<'\n';
		cout << "4) Iniciar partida." <<'\n';
		cout << "5) Finalizar partida." <<'\n';
		cout << "6) Eliminar videojuego." <<'\n';
		cout << "7) Consultar estadísticas" <<'\n';

		cout << "8) Iniciar sesión." <<'\n';
		cout << "9) Agregar categoría." <<'\n';
		cout << "10) Asignar puntaje a videojuego." <<'\n';
		cout << "11) Abandonar partida multijugador." <<'\n';

		cout << "12) Ver información de videojuego." <<'\n';
		cout << "13) Seleccionar estadísticas." <<'\n';

		cin >> eleccion;
		cout <<'\n';


		switch(eleccion) {
			case 1: {
				cout << "ingrese nickname:" <<'\n';
				cin.ignore();
				getline(cin,nick);
				cout <<'\n';
				cout << "ingrese edad:" <<'\n';
				cin >> edad;
				cout <<'\n';
				cout << "ingrese contraseña: " <<'\n';
				cin >> cont;
				cout <<'\n';
				SistemaCentral.agregarJugador(nick,edad,cont);
				cout << "jugador ingresado con exito "<<'\n';
				cout <<'\n'; cout <<'\n';
			}
			break;

			case 2: {
				cout << "ingrese nombre : "<<'\n';
				cin.ignore();
				getline(cin,nom);
				cout <<'\n';
				cout << "seleccione el genero :  1-Accion 2-Aventura 3-Deporte 4-otro"<<'\n';
			
				cin >> e;
				cout <<'\n';
				
				switch(e){
					case 1:
						j = Accion;
					break;
					case 2:
						j = Aventura;
					break;
					case 3:
						j = Deporte;
					break;
					case 4:
						j = Otro;
					break;
				}
				SistemaCentral.agregarVideojuego(nom,j);
				cout << "videojuego ingresado con exito "<<'\n';
				cout <<'\n'; cout <<'\n';
				}
			break;

			case 3: {

                                /*
                pedimos la fecha al momento de agregar una partida
                */
                int an,me,di,ho,mi;
                
                cout << "Es necesario ingresar la fecha y hora del sistema" <<'\n';
                
                cout << "ingrese el año: ";
                cin >> an;
                cout <<'\n';

                cout << "ingrese el mes: ";
                cin >> me;
                cout <<'\n';

                cout << "ingrese el dia: ";
                cin >> di;
                cout <<'\n';

                cout << "ingrese la hora: ";
                cin >> ho;
                cout <<'\n';

                cout << "ingrese el minuto: ";
                cin >> mi;
                cout <<'\n';

                DtFechaHora fechaSis(di,me,an,ho,mi);
                
                /* Fin
                pedimos la fecha al momento de agregar una partida
                */

                string nombreVideojuego;
                cout << "Nombre del videojuego: "<<'\n';
				cin.ignore();
				getline(cin,nombreVideojuego);
				cout <<'\n';
                 
                 
                string nombreJugador;
				cout << "Ingrese nickname del jugador que inicia la partida: "<<'\n';
				getline(cin,nombreJugador);
				cout <<'\n';

				
                int duracion=0;
				cout << "Ingrese la duracion (en horas) "<<'\n';
				cin >> duracion;
				cout <<'\n';

				int tipoPartida = 1;
				cout << "como sera la partida: 1-individual  2-multijugador "<<'\n';
				cin >> tipoPartida;
				cout <<'\n';

				//si es una partida individual
				if (tipoPartida == 1) {
					
                    int esContinuacion = 1;
                    bool esContinuacionBool;
					cout << "es continuacion de una anterior? 1-si 2-no "<<'\n';
					cin >> esContinuacion;
					cout <<'\n';
					
					if (esContinuacion == 1) {
						esContinuacionBool = true;
					}
					else {
						esContinuacionBool = false;
					}

					DtPartida *infoPartida = new DtPartidaIndividual(fechaSis,duracion,esContinuacionBool);
                                        
                    try{
                        //se llama a la funcion que cre la partida
                        //void iniciarPartida(string nickname,string videojuego,DtPartida* datos);
                        SistemaCentral.iniciarPartida(nombreJugador,nombreVideojuego,infoPartida);
                        cout << "partida iniciada con exito "<<'\n';
                        cout <<'\n'; cout <<'\n';
                    }
                    
                    catch (invalid_argument& e) { 
                        cout << e.what() <<endl;                         
                    }
                    
                    
                    delete infoPartida;

				}
				//si es una partida multijugador
				else{

                    int transmitidaEnVivo = 1;
                    bool transmitidaEnVivoBool=0;
					cout << "es transmitida en vivo? 1-si 2-no "<<'\n';
					cin >> transmitidaEnVivo;
					cout <<'\n';
					if (transmitidaEnVivo == 1) {
						transmitidaEnVivoBool = true;
					} else {
						transmitidaEnVivoBool = false;
					}

                    int cantidadJugadores;
					cout << "cuantos jugadores se uniran? "<<'\n';
					cin >> cantidadJugadores;
					cout <<'\n';
                                        

					cout << "debe ingresar los nicknames de los jugadores que se uniran "<<'\n';
					
					string *nombres = new string[cantidadJugadores+1];
                    
                    cin.ignore();
					for (int i = 0; i < cantidadJugadores; i++) {
                        cout <<"Jugador "<<i+1<<": ";
						getline(cin,nombres[i]);
					}
                                       
					cout <<'\n';
					nombres[cantidadJugadores]=nombreJugador;
					cantidadJugadores=cantidadJugadores+1;

					//se crea el datatype que pide la funcion iniciarPartida
                                        
					DtPartida *infoPartida = new DtPartidaMultijugador(fechaSis,duracion,transmitidaEnVivoBool, nombres, cantidadJugadores);
                    delete []nombres;

                    try{
                        SistemaCentral.iniciarPartida(nombreJugador,nombreVideojuego,infoPartida);
                        cout << "partida iniciada con exito "<<'\n';
                        cout <<'\n'; cout <<'\n';
                    }catch (invalid_argument& e) { 
                        cout << e.what() <<endl; 
                        
                    }
                    
                    delete infoPartida;


				}

				}
			break;

			case 4: {
				
				edad = 0; // el compilador detecta que edad tiene basura y por lo tanto no puede usarse en la funcion, no sabe que edad es una variable de retorno
				DtJugador **jj = SistemaCentral.obtenerJugadores(edad);
				imprimirDtJugador(jj,edad);
				cout <<'\n'; cout <<'\n';
				for (int i=0; i<SistemaCentral.getcantjugadores();i++)
                                         delete jj[i];
				delete []jj ;
				 }
			break;

			case 5: {

				int juegos = 0;
				DtVideojuego **vv = SistemaCentral.obtenerVideojuegos(juegos);
				imprimirDtVideojuego(vv,juegos);
				cout <<'\n'; cout <<'\n';
                                for (int i=0; i<SistemaCentral.getcantvideojuegos();i++)
                                         delete vv[i];
				delete []vv;
				}

			break;

			case 6: {
                cin.ignore();
				cout << "de que videojuego desea ver las partidas? ingrese su nombre "<< endl;
				getline(cin,nom);
				cout <<'\n';
				int partidas = 0;
                DtPartida **pp = 0;
                try{
                    pp = SistemaCentral.obtenerPartidas(nom,partidas);
                    imprimirDtPartida(pp,partidas,nom);
                    cout <<'\n'; cout <<'\n';
                    for (int i=0; i<partidas; i++)
                        delete pp[i];
                }
                catch (invalid_argument& e) {
                    cout << e.what() <<endl;
                    
                }

				delete []pp;
				}
			break;

			case 0: {
                                
				termina = true;
			}
			break;

			default: {
				
				termina = true;
				cout << "numero invalido, cerrando sistema..."<<'\n';
				}
			break;


		}
       }
	 
	
	catch (invalid_argument& e) {
            cout << e.what() <<endl;
        }
	}


	
	return 0;
}
