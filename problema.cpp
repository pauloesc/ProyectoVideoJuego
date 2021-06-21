#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "include/Fabrica.h"

#include "include/DtInfoEspecifica.h"
#include "include/DtEstadisticaDeSegundoTipo.h"
#include "include/DtCategoria.h"
#include "include/DtSuscripcion.h"
#include "include/DtPartidaIndividual.h"
#include "include/DtPartidaMultijugador.h"
#include "include/DtPartidaEnCurso.h"
#include "include/DtVideojuego.h"
#include "include/DataEstadistica.h"
#include "include/DtPago.h"
#include "include/Reloj.h"

void cambiarFechaSistema() {
        
        int an, me, di, ho, mi;

        cout << "Es necesario ingresar la fecha y hora del sistema" << '\n';

        cout << "ingrese el año: ";
        cin >> an;
        cin.ignore();
        cout << '\n';

        cout << "ingrese el mes: ";
        cin >> me;
        cin.ignore();
        cout << '\n';

        cout << "ingrese el dia: ";
        cin >> di;
        cin.ignore();
        cout << '\n';

        cout << "ingrese la hora: ";
        cin >> ho;
        cin.ignore();
        cout << '\n';

        cout << "ingrese el minuto: ";
        cin >> mi;
        cin.ignore();
        cout << '\n';
                                
        Reloj::setFecha(di,me,an,ho,mi);

}

void menuParaJugador(IControladorUsuario* IU, IControladorVideojuego* IV, IControladorSuscripciones* IS, IControladorPartida* IP, IControladorEstadistica* IE){

        bool termina = 0;
        while (!termina){

                cout << "Eliga la operacion a realizar: " << '\n';
                cout << "1) Suscribirse a videojuego." << '\n';
                cout << "2) Asignar puntaje a videojuego." << '\n';
                cout << "3) Iniciar partida." << '\n';
                cout << "4) Abandonar partida multijugador." << '\n';
                cout << "5) Finalizar partida." << '\n';
                cout << "6) Ver información de videojuego." << '\n';
                cout << "7) Cambiar fecha del sistema." << '\n';
                cout << "8) Salir." << '\n';
                int eleccion;
                cin >> eleccion;
                cin.ignore();
                cout << '\n';

                switch (eleccion) {

                        case 1: {
                                cout << "Sus suscripciones activas:" << '\n';
                                vector<DtSuscripcion*> SuscripcionesActivas;
                                SuscripcionesActivas = IS->obtenerSuscripcionesActivas();

                                int max = SuscripcionesActivas.size();
                                for(int i=0; i< max; i++ ){
                                        cout << SuscripcionesActivas[i] << endl;

                                }

                                cout << '\n' << '\n';
                                cout << "Sus suscripciones no activas:" << '\n';
                                vector<DtSuscripcion*> SuscripcionesNoActivas;
                                SuscripcionesNoActivas = IS->obtenerSuscripcionesNoActivas();

                                max = SuscripcionesNoActivas.size();
                                for(int i=0; i < max; i++ ){
                                        cout << SuscripcionesNoActivas[i] << endl;

                                }

                                string nombreVideojego;
                                cout << "Ingrese nombre del videojuego: "<<'\n';
                                getline(cin,nombreVideojego);
                                cout <<'\n';

                                IS->SeleccionarVideojuego(nombreVideojego);
                                bool tieneVitalicia = 0;
                                tieneVitalicia = IS->VerificarSuscripcionVitalicia();

                                //si puede suscribirse
                                if(!tieneVitalicia){

                                        bool activa = IS->VerificarSuscripcionActiva();
                                        bool cancela=1;
                                        
                                        if (activa) { 
                                                cout << "Usted tiene una suscripcion a dicho juego quiere cancelarla 1 para si, 0 para no: "<<'\n';
                                                cin >> cancela;
                                                cin.ignore();
                                                cout <<'\n';
                                        }
                                         //si no cancela la suscripcion existente
                                        if(!cancela){
                                                IS->Cancelar();
                                        
                                        } else {
                                        //quiere cancelar su suscripcion activa no vitalicia, o no tiene suscripcion activa

                                                string tipoSusc;
                                                cout << "Digite el tipo de suscripcion (mensual)(trimestral)(anual)(vitalicia): "<<'\n';
                                                getline(cin,tipoSusc);
                                                cout <<'\n';
						
                                                int e;
					        DtPago formaPago;
                                                cout << "seleccione Forma de Pago :  1-Tarjeta 2-Paypal "<<'\n';
						cin >> e;
                                                cin.ignore();
						cout <<'\n';
				
						switch(e){
							case 1:
							    formaPago = tarjeta;
							    break;
							case 2:
							    formaPago = paypal;
							   break;

						}
						


                                                IS->IngresarDatosSuscripcion(tipoSusc,formaPago);

                                                bool confirSus=0;
                                                cout << "Confirmar suscripcion: 1 para si 0 para no "<<'\n';
                                                cin >>confirSus;
                                                cin.ignore();
                                                cout <<'\n';

                                                if(confirSus){
                                                        IS->ConfirmarSuscripcion();
                                                }
                                                else{
                                                        IS->Cancelar();
                                                }

                                        }


                                                
                                }
                                //no puede suscribirse
                                else{
                                      IS->Finalizarproceso();
                                }

                                //borrado de memoria de datatypes
                                int maxuu = SuscripcionesActivas.size();
                                for(int i=0; i < maxuu; i++){
                                        delete SuscripcionesActivas[i];
                                }
                                
                                maxuu = SuscripcionesNoActivas.size();
                                for(int i=0; i < maxuu; i++){
                                        delete SuscripcionesNoActivas[i];
                                }

                                SuscripcionesActivas.clear();
                                SuscripcionesNoActivas.clear();

                        }
                        break;
                        case 2: {

                                vector<DtVideojuegoResumido*> VideojuegosDatos;
                                VideojuegosDatos = IV->ObtenerVideoJuegos();

                                int max = VideojuegosDatos.size();
                                for(int i=0; i< max; i++ ){
                                        cout << VideojuegosDatos[i] << endl;
                                }

                                string NombreVj;
                                cout << "Nombre del Vj: "<<'\n';
                                getline(cin,NombreVj);
                                cout <<'\n';

                                int puntaje=0;
                                cout << "Ingrese puntaje : "<<'\n';
                                cin >> puntaje;
                                cin.ignore();
                                cout <<'\n';

                                IV->AsignarPuntajeVJ(NombreVj,puntaje);


                                //borrado de memoria de datatypes
                                int maxuu = VideojuegosDatos.size();
                                for(int i=0; i < maxuu; i++){
                                        delete VideojuegosDatos[i];
                                }
                                VideojuegosDatos.clear();

                        }
                        break;
                        case 3: {
                                vector<DtPartidaIndividual*> HistorialPartidaIndiv;
                                vector<string> ListaVJConSuscrActiva;
                                ListaVJConSuscrActiva = IP->listarVideojuegosConSuscripcionActiva();

                                int max = ListaVJConSuscrActiva.size();
                                for(int i = 0; i< max; i++ ){
                                        cout << ListaVJConSuscrActiva[i] << endl;
                                }

                                string NombreVj;
                                cout << "Nombre del videojuego del cual quiere iniciar una partida: "<<'\n';
                                getline(cin,NombreVj);
                                cout <<'\n';

                                IP->seleccionaVideoJuego(NombreVj);


                                bool TipoPartida;
                                cout << "Presione 1 si quiere iniciar una partida multijugador 0 si induvidual: "<<'\n';
                                cin >> TipoPartida;
                                cin.ignore();
                                cout <<'\n';

                                //si quiere iniciar una partida multijugador
                                if(TipoPartida){

                                        bool EsTransEnVivo;
                                        cout << "Presiona 1 si la partida es transmitida en vivo, 0 si no: "<<'\n';
                                        cin >> EsTransEnVivo;
                                        cin.ignore();
                                        cout <<'\n';

                                        IP->ingresarPartidaMultijugador(EsTransEnVivo);

                                        vector<string> ListaJugadoresQuePuedenUnirse;
                                        ListaJugadoresQuePuedenUnirse = IP->ListarJugadoresConSuscripcionActiva();


                                        int max = ListaJugadoresQuePuedenUnirse.size();
                                        for(int i = 0; i< max; i++ ){
                                                        cout << ListaJugadoresQuePuedenUnirse[i] << endl;
                                                }


                                        bool agregarJugadores = 1;
                                        
                                        while(agregarJugadores){
                                                string nomJugadorAgregar;
                                                cout << "Ingrese el nombre de un jugador a ingresar para agregarlo a la partida: "<<'\n';
                                                getline(cin,nomJugadorAgregar);
                                                cout <<'\n';

                                                IP->AgregarJugador(nomJugadorAgregar);

                                                
                                                cout << "Quiere ingresar mas jugadores, presione 1 para si, 0 para no: "<<'\n';
                                                cin >> agregarJugadores;
                                                cin.ignore();
                                                cout <<'\n';

                                        }

                                }
                                //si quiere iniciar una partida individual
                                else{
                                        bool puede = false;
                                        while (!puede) { 

                                                bool EsContinuacion;
                                                cout << "Presiona 1 si la partida es continuacion de otra, y 0 si no: "<<'\n';
                                                cin >> EsContinuacion;
                                                cin.ignore();
                                                cout <<'\n';

                                                IP->ingresarPartidaIndividual(EsContinuacion);

                                                //si quiere iniciar una partida continuacion de otra
                                                if(EsContinuacion){

                                                        vector<DtPartidaIndividual*> HistorialPartidaIndiv;
                                                        HistorialPartidaIndiv = IP->HistorialDePartidasIndividualesFinalizadas();

                                                        int max = HistorialPartidaIndiv.size();
                                                        for(int i = 0; i< max; i++ ){
                                                                cout << HistorialPartidaIndiv[i] << endl;
                                                        }

                                                        if (max != 0) { 
                                                                int codigoPartida;
                                                                cout << "Ingrese el codigo de la partida que quiere continuar: "<<'\n';
                                                                cin >> codigoPartida;
                                                                cin.ignore();
                                                                cout <<'\n';

                                                                IP->PartidaAcontinuar(codigoPartida);
                                                                puede = true;
                                                        } else {
                                                                cout << "Error, no hay partidas individuales finalizadas para este videojuego "<<'\n';
                                                               
                                                        }
                                                } else {
                                                        puede = true;
                                                }
                                        }
                                }

                                int Confirmarr;
                                cout << "Presione 1-confirmar o  0-cancelar: "<<'\n';
                                cin >>Confirmarr;
                                cin.ignore();
                                cout <<'\n';

                                if(Confirmarr){
                                       IP->IniciarPartida();
                                }
                                else{
                                        IP->CancelarPartida();
                                }

                                //borrado de memoria de datatypes
                                int maxuu = HistorialPartidaIndiv.size();
                                for(int i=0; i < maxuu; i++){
                                        delete HistorialPartidaIndiv[i];
                                }
                                HistorialPartidaIndiv.clear();

                        }
                        break;
                        case 4: {
                                
                                vector<DtPartidaMultijugador*> Info;
                                Info = IP->obtenerPartidasEnCursoUnido();

                                int max = Info.size();
                                for(int i = 0; i< max; i++ ){
                                        cout << Info[i] << endl;
                                }


                                int codPartida;
                                cout << "Ingrese le codigo de la partida que quiere abandonar: "<<'\n';
                                cin >> codPartida;
                                cin.ignore();
                                cout <<'\n';
                                IP->abandonarPartida(codPartida);

                                //borrado de memoria de datatypes
                                int maxuu = Info.size();
                                for(int i=0; i < maxuu; i++){
                                        delete Info[i];
                                }
                                Info.clear();

                        }
                        break;
                        case 5: {

                                vector<DtPartidaEnCurso*> PartidaEnCursoDelJugador;
                                PartidaEnCursoDelJugador = IP->obtenerPartidasEnCurso();

                                int max = PartidaEnCursoDelJugador.size();
                                for(int i = 0; i < max ; i++ ){
                                        cout << PartidaEnCursoDelJugador[i] << endl;
                                }
                                if (max==0){
                                    cout << "No hay partidas que pueda finalizar "<<'\n';
                                }
                                else{
                                    int codPartida;
                                    cout << "Ingrese le codigo de la partida que quiere finalizar: "<<'\n';
                                    cin >> codPartida;
                                     cin.ignore();
                                    cout <<'\n';
                                    IP->finalizarPartida(codPartida);
                                }

                                //borrado de memoria de datatypes
                                int maxuu = PartidaEnCursoDelJugador.size();
                                for(int i=0; i < maxuu; i++){
                                        delete PartidaEnCursoDelJugador[i];
                                }
                                PartidaEnCursoDelJugador.clear();

                        }
                        break;
                        case 6: {

                                vector<DtVideojuegoResumido*> VideojuegosEnSistema;
                                VideojuegosEnSistema = IV->ObtenerVideoJuegos();

                                int max = VideojuegosEnSistema.size();
                                for(int i=0; i< max; i++){
                                        cout << VideojuegosEnSistema[i] << endl;
                                }

                                string nombreJuego;
                                cout << "Seleccione un juego. (nombre) :"<<'\n';
                                getline(cin,nombreJuego);
                                cout <<'\n';

                                DtInfoEspecifica* datosVj;
                                datosVj = IV->SeleccionarVideojuego(nombreJuego);
                                cout << datosVj;


                                //borrado de memoria de datatypes
                                int maxuu = VideojuegosEnSistema.size();
                                for(int i=0; i < maxuu; i++){
                                        delete VideojuegosEnSistema[i];
                                }
                                VideojuegosEnSistema.clear();

                        }
                        break;
                       
                        case 7: {
                                cambiarFechaSistema();
                        }
                        break;
               
                        case 8: {
                                termina = true;
                        }
                        break;
                }
        }
};


void menuParaDesarollador(IControladorUsuario* IU, IControladorVideojuego* IV, IControladorSuscripciones* IS, IControladorPartida* IP, IControladorEstadistica* IE){

        bool termina = 0;
        while (!termina){


                cout << "Eliga la operacion a realizar: " << '\n';
                cout << "1) Agregar categoria." << '\n';
                cout << "2) Publicar videojuego." << '\n';
                cout << "3) Eliminar videojuego." << '\n';
                cout << "4) Seleccionar estadisticas." << '\n';
                cout << "5) Consultar estadi­sticas." << '\n';
                cout << "6) Ver informacion del videojuego." << '\n';
                cout << "7) Cambiar fecha del sistema." << '\n';
                cout << "8) Salir." << '\n';
                int eleccion;
                cin >> eleccion;
                cin.ignore();
                cout << '\n';

                switch (eleccion) {

                        case 1: {
                                vector<string> nombreCategorias;
                                nombreCategorias = IV->ObtenerCategorias();

                                cout << "Nombre de las categorias existentes: "<<'\n';
                 
                                int maxx = nombreCategorias.size();
                                for(int i=0; i < maxx; i++ ){
                                        cout << nombreCategorias[i] << endl;
                                }

                                string nomCategoria;
                                cout << "Ingrese nombre de la nueva categoria: "<<'\n';
                               
                                getline(cin,nomCategoria);
                                cout <<'\n';
                                
                                string descCategoria;
                                cout << "Ingrese descripcion de la nueva categoria: "<<'\n';
                            
                                getline(cin,descCategoria);
                                cout <<'\n';
                                
                                
                                string tipoCategoria;
                                cout << "Ingrese tipo de la nueva categoria: genero, plataforma u otro "<<'\n';
                                getline(cin,tipoCategoria);
                                cout <<'\n';
                    
                                //creo una categoria no en memoria dinamica
                                DtCategoria* nuevaCat = new DtCategoria(nomCategoria,descCategoria,tipoCategoria);
                                
                                //creo un punero a es dt cat
                   
                                IV->NuevaCategoria(nuevaCat);

                                bool confirmar= 0;
                                cout << "Confirmar creacion de categoria: 1 para si, 0 para no "<<'\n';
                                cin >> confirmar;
                                cin.ignore();
                                cout <<'\n';

                                if(confirmar){
                                       IV->ConfirmarCategoria();
                                }
                                else{
                                        IV->CancelarCategoria();
                                }

                                //borrado de memoria de datatypes
                                nombreCategorias.clear();


                        }
                        break;

                        case 2: {

                                string vJuego;
                                cout << "Ingrese nombre del nuevo juego: "<<'\n';     
                                getline(cin,vJuego);
                                 cout <<'\n';

                                string vDescripcion;
                                cout << "Ingrese descripcion: "<<'\n';
                                getline(cin,vDescripcion);
                                cout <<'\n';

                                float vCostoMensual;
                                cout << "Ingrese costo mensual: "<<'\n';
                                cin >> vCostoMensual;
                                cin.ignore();
                                cout <<'\n';

                                float vCostoTrimestral;
                                cout << "Ingrese costo trimestral: "<<'\n';
                                cin >> vCostoTrimestral;
                                cin.ignore();
                                cout <<'\n';

                                float vCostoAnual;
                                cout << "Ingrese costo anual: "<<'\n';
                                cin >> vCostoAnual;
                                cin.ignore();
                                cout <<'\n';

                                float vCostoVitalicio;
                                cout << "Ingrese costo vitalicio: "<<'\n';
                                cin >> vCostoVitalicio;
                                cin.ignore();
                                cout <<'\n';
                                
                                IV->datosVideojuego(vJuego, vDescripcion, vCostoMensual, vCostoTrimestral, vCostoAnual, vCostoVitalicio);
                                vector<DtCategoria*> CategoriaPlataforma;
                                CategoriaPlataforma = IV->ObtenerCategoriaPlataforma();
                              
                                //imprimimos las categorias de tipo plataforma
                                cout << "Categorías de tipo plataforma " << '\n';
                                int max = CategoriaPlataforma.size();
                                for( int i=0; i < max; i++ ){
                                        cout << CategoriaPlataforma[i] << endl;
                                }

                                bool auxWhileAgregarCat = 1;
                                
                                while( auxWhileAgregarCat){

                                        string vNombreCategoria;
                                        cout << "Agrege una categoria de tipo plataforma (nombre) :"<<'\n';
                                        getline(cin,vNombreCategoria);
                                        cout <<'\n';
                                        IV->agregarcategoria(vNombreCategoria);
                                        
                                        cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                        cin >> auxWhileAgregarCat;
                                        cin.ignore();
                                        cout <<'\n';
                                }


                                
                                vector<DtCategoria*> CategoriaGenero;
                                CategoriaGenero = IV->ObtenerCategoriaGenero();
                              
                                //imprimimos las categorias de tipo genero
                                cout << "Categorías de tipo genero " << '\n';
                                //max ya esta definido
                                int max1 = CategoriaGenero.size();
                                for( int i=0; i < max1 ;i++ ){
                                        cout << CategoriaGenero[i] << endl;
                                }

                                auxWhileAgregarCat = 1;
                                
                                while( auxWhileAgregarCat ){

                                        string vNombreCategoria;
                                        cout << "Agrege una categoria de tipo genero (nombre) :"<<'\n';
                                        getline(cin,vNombreCategoria);
                                        cout <<'\n';
                                        IV->agregarcategoria(vNombreCategoria);
                                        
                                        cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                        cin >> auxWhileAgregarCat;
                                        cin.ignore();
                                        cout <<'\n';
                                }


                                vector<DtCategoria*> CategoriaOtro;
                                CategoriaOtro = IV->ObtenerCategoriaOtros();
                              
                                //imprimimos las categorias de tipo otro
                                cout << "Categorías de tipo otro " << '\n';
                                max = CategoriaOtro.size();
                                for( int i=0; i<max; i++ ){
                                        cout << CategoriaOtro[i] << endl;
                                }

                                auxWhileAgregarCat = 1;
                                cout << "Desea agregar categorias de tipo otro: 1 para si 0 para no "<<'\n';
                                cin >>auxWhileAgregarCat;
                                cin.ignore();
                                cout <<'\n';

                                while( auxWhileAgregarCat ){
                                        string vNombrecCategoria;
                                        cout << "Agrege una categoria (nombre) :"<<'\n';
                                        
                                        getline(cin,vNombrecCategoria);
                                        cout <<'\n';

                                       IV->agregarcategoria(vNombrecCategoria);
                                        
                                        cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                       
                                        cin >> auxWhileAgregarCat;
                                        cin.ignore();
                                        cout <<'\n';

                                }
                                DtVideojuego* infoVideojuego;
                                infoVideojuego = IV->ObtenerInfoVideojuego();
                                cout << infoVideojuego << endl;

                                bool confirmar = 0;
                                cout << "Confirmar creacion de videojuego: 1 para si, 0 para no " << '\n';
                                cin >> confirmar;
                                cin.ignore();
                                cout << '\n';

                                if (confirmar) {
                                    IV->ConfirmarAltavideoJuego();
                                }
                                else {
                                    IV->CancelarAltavideoJuego();
                                }

                                //borrado de memoria de datatypes
                                int maxuu = CategoriaPlataforma.size();
                                for(int i=0; i < maxuu; i++){
                                        delete CategoriaPlataforma[i];
                                }
                                CategoriaPlataforma.clear();

                                //borrado de memoria de datatypes
                                maxuu = CategoriaGenero.size();
                                for(int i=0; i < maxuu; i++){
                                        delete CategoriaGenero[i];
                                }
                                CategoriaGenero.clear();

                                //borrado de memoria de datatypes
                                maxuu = CategoriaOtro.size();
                                for(int i=0; i < maxuu; i++){
                                        delete CategoriaOtro[i];
                                }
                                CategoriaOtro.clear();

                        }
                        break;
                        case 3: {

                                vector<string> VideojuegosParaEliminar;
                                VideojuegosParaEliminar = IV->obtenerVideoJuegosConTodasLasPartidasFinalizadas();

                                int max = VideojuegosParaEliminar.size();
                                
                                if (max != 0) { 

                                        for( int i = 0; i< max; i++ ){
                                                cout << VideojuegosParaEliminar[i] << endl;
                                        }

                                        string nomVJ;
                                        cout << "Ingrese nombre de la el videojuego a eliminar: "<<'\n';
                                        getline(cin,nomVJ);
                                        cout <<'\n';

                                        IV->seleccionarVideoJuego(nomVJ);

                                        bool conf = 0;
                                        cout << "Confirmar eliminacion 1 para si, 0 para no :"<<'\n';
                                        cin >> conf;
                                        cin.ignore();
                                        cout <<'\n';

                                        if(conf){
                                                IV->eliminarVideoJuego();
                                        }
                                        else{
                                                IV->cancelarLaEliminacion();
                                        }
                                } else {
                                        cout << "No hay videojuegos que pueda eliminar" <<'\n';
                                        IV->cancelarLaEliminacion();
                                }
                       
                                VideojuegosParaEliminar.clear();

                        }
                        break;
                        case 4: {
                                vector<DataEstadistica> EstadisticasEnElSistema;
                                EstadisticasEnElSistema = IE->TiposDeEstadistica();

                                int max = EstadisticasEnElSistema.size();
                                for(int i=0; i< max; i++ ){
                                        //le paso de dir de memoria no el objeto
                                        cout << &EstadisticasEnElSistema[i] << endl;
                                }

                                vector<string> EstadisticasSeleccionadas;
                                bool auxWhile = 1;
                                while(auxWhile){

                                        string estadisticaNombre;
                                        cout << "Agrege una estadistica (nombre) :"<<'\n';
                                        getline(cin,estadisticaNombre);
                                        cout <<'\n';

                                        EstadisticasSeleccionadas.push_back(estadisticaNombre);

                                        cout << "Quiere seleccionar otra estadistica. 1 para si, 0 para no :"<<'\n';
                                        cin >> auxWhile;
                                        cin.ignore();
                                        cout <<'\n';

                                }

                                IE->SeleccionEstadisticas(EstadisticasSeleccionadas);

                                bool confirmar;
                                cout << "Confirmar. 1 para si 0 para no :"<<'\n';
                                cin >>confirmar;
                                cin.ignore();
                                cout <<'\n';

                                if(confirmar){
                                        IE->ConfirmarSeleccionEstaditicas();
                                }
                                else{
                                        IE->CancelarSeleccionEstaditicas();
                                }

                                EstadisticasEnElSistema.clear();

                        }
                        break;
                        case 5: {

                                vector<string> JuegosDelDesarollador;
                                JuegosDelDesarollador = IE->JuegosDelDesarollador();
                                
                                //imprimo los videojuegos del desarollador
                                int max = JuegosDelDesarollador.size();
                                for( int i=0; i< max; i++ ){
                                        cout << JuegosDelDesarollador[i] << endl;
                                }

                                string nombreJuego;
                                cout << "Seleccione un juego. (nombre) :"<<'\n';
                                getline(cin,nombreJuego);
                                cout <<'\n';

                                //podria no ser un vector
                                vector<DtEstadisticaDeSegundoTipo*> datos;
                                datos = IE->SeleccionEstadisticasDeCiertoJuego(nombreJuego);

                                max = datos.size();
                                for (int i = 0; i < max; i++)
                                {
                                        cout << datos[i] << endl;
                                }

                                //borrado de memoria de datatypes
                                int maxuu = datos.size();
                                for(int i=0; i < maxuu; i++){
                                        delete datos[i];
                                }
                                datos.clear();

                                JuegosDelDesarollador.clear();

                        }
                        break;
                        case 6: {
                                
                                vector<DtVideojuegoResumido*> VideojuegosEnSistema;
                                VideojuegosEnSistema = IV->ObtenerVideoJuegos();

                                int max = VideojuegosEnSistema.size();
                                for(int i=0; i< max; i++){
                                        cout << VideojuegosEnSistema[i] << endl;
                                }

                                string nombreJuego;
                                cout << "Seleccione un juego. (nombre) :"<<'\n';
                                getline(cin,nombreJuego);
                                cout <<'\n';

                                DtInfoEspecifica* datosVj;
                                datosVj = IV->SeleccionarVideojuego(nombreJuego);
                                cout << datosVj;
                                
                                float VMostarTotalHorasJugadas=0;
                                VMostarTotalHorasJugadas = IV->MostrarHorasTotalJugadas();
                                cout << "Total de horas Jugadas: ";
                                cout << VMostarTotalHorasJugadas << endl;
                                cout << endl;


                                //borrado de memoria de datatypes
                                int maxuu = VideojuegosEnSistema.size();
                                for(int i=0; i < maxuu; i++){
                                        delete VideojuegosEnSistema[i];
                                }
                                VideojuegosEnSistema.clear();

                                delete datosVj;


                        }
                        break;
                        case 7: {
                                cambiarFechaSistema();
                        }
                        break;
               
                        case 8: {
                                termina = true;
                        }
                }
        }
};






int main() {

        IControladorUsuario* IU = Fabrica::getIUsuario();
        IControladorVideojuego* IV = Fabrica::getIVideojuego();
        IControladorSuscripciones* IS = Fabrica::getISuscripcion();
        IControladorPartida* IP = Fabrica::getIPartida();
        IControladorEstadistica* IE = Fabrica::getIEstadistica();

        bool termina = 0;
        while (!termina) {

                try {

                        cout << "Eliga la operacion a realizar: " << '\n';
                        cout << "1) Alta de usuario." << '\n';
                        cout << "2) Iniciar sesión." << '\n';
                        cout << "3) Cargar datos de prueba." << '\n';
                        cout << "4) Salir." << '\n';

                        int eleccion;
                        cin >> eleccion;
                        cin.ignore();
                        cout << '\n';

                        switch (eleccion) {

                        case 1: {


                                string vemail;
                                cout << "Ingrese email:" << '\n';
                                cin >> vemail;
                                cin.ignore();
                                cout << '\n';

                                string vpassword;
                                cout << "ingrese contraseña:" << '\n';
                                getline(cin,vpassword);
                                cout << '\n';

                                IU->IngresardatosUsuario(vemail,vpassword);

                                int tipoUsuario;
                                cout << "Tipo de usuario a registrar: 1: Desarollador, 2: Jugador" << '\n';
                                cin >> tipoUsuario;
                                cin.ignore();

                                bool verificacion=0;
                                if (tipoUsuario==1) {
                                        string nomEmpresa;
                                        cout << "Ingrese el nombre de su empresa: " << '\n';
                                        getline(cin, nomEmpresa);
                                        IU->IngresardatosDesarrollador(nomEmpresa);

                                } else {

                                        bool auxWhile = 1;
                                
                                        while (auxWhile) {

                                                string vnickname;
                                                cout << "ingrese nickname:" << '\n';
                                                getline(cin, vnickname);
                                                cout << '\n';

                                                string vdescripcion;
                                                cout << "ingrese descripcion:" << '\n';
                                                getline(cin, vdescripcion);
                                                cout << '\n';

                                                
                                                verificacion = IU->IngresardatosJugador(vnickname, vdescripcion);

                                                //si puede registrarse con ese usuario
                                                if (verificacion) {
                                                        auxWhile = 0;
                                                } else {

                                                        bool vreintenarIngresoDatos;
                                                        cout << "nickname existente, quiere volver a intentarlo: 0 para no, 1 para si" << '\n';
                                                        cin >> vreintenarIngresoDatos;
                                                        cin.ignore();
                                                        cout << '\n';

                                                        auxWhile = vreintenarIngresoDatos;

                                                }

                                        }

                                }
                                
                                if (verificacion || (tipoUsuario == 1)) { 
                                    bool vconfirmar;
                                    cout << "Desea confirmar inscripcion 1 para si 0 para no:" << '\n';
                                    cin >> vconfirmar;
                                    cin.ignore();
                                    cout << '\n';

                                    if (!vconfirmar) {
                                            IU->cancelarAltaUsuario();
                                    } else {
                                            IU->ConfirmarAltaUsuario();
                                    }
                                }
                        }
                        break;
//
                        case 2: {

                                bool auxWhile = 1;
                                bool ingreso = 0;
                                while (auxWhile) {

                                        string vemail;
                                        cout << "ingrese email : " << '\n';
                                        getline(cin, vemail);
                                        cout << '\n';

                                        string passw;
                                        cout << "ingrese contraseña : " << '\n';
                                        getline(cin, passw);
                                        cout << '\n';

                                        ingreso = IU->ingresarDatos(vemail, passw);
                                       

                                        //si no ingreso
                                        if (!ingreso) {
                                                bool reintentar;
                                                cout << "Fallo el ingreso. Quiere reintentar ingresar?: 1 para si 0 para no" << '\n';
                                                cin >> reintentar;
                                                cin.ignore();
                                                cout << '\n';

                                                auxWhile = reintentar;
                                        }
                                        //si ingreso
                                        else {
                                                auxWhile = 0;
                                        }

                                }
                       
                                // si logró iniciar sesión
                                if (ingreso) {
                                    if (IU->esUsuarioEnLineaJugador()) {
                                        menuParaJugador(IU, IV, IS, IP, IE);
                                    } else {
                                        menuParaDesarollador(IU, IV, IS, IP, IE);
                                    }
                                }

                        }
                        break;

                        case 3: {
                                
                                //DATOS DE PRUEBA
                                cout << "CARGA DE DATOS DE PRUEBA";
                                cout << '\n';


                                //desarrolladores
                                IU->IngresardatosUsuario("mojang@mail.com","123");
                                IU->IngresardatosDesarrollador("MojangStudios");
                                IU->ConfirmarAltaUsuario();


                                //jugadores
                                IU->IngresardatosUsuario("ari@mail.com","123");
                                IU->IngresardatosJugador("ari","");
                                IU->ConfirmarAltaUsuario();



                                //categorias
                                DtCategoria* c;

                                c = new DtCategoria("PC","Juegos de pc","plataforma");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();

                                c = new DtCategoria("Supervivencia","Juegos de Supervivencia","genero");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();


                                c = new DtCategoria("E","Su contenido esta dirigido para todo público","otro");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();


                                //videojuegos
                                bool basura;
                                basura = IU->ingresarDatos("mojang@mail.com","123");
                                IV->datosVideojuego("Minecraft","des3",2.f,5.f,20.f,40.f);
                                IV->agregarcategoria("PC");
                                IV->agregarcategoria("Supervivencia");
                                IV->agregarcategoria("E");
                                IV->ConfirmarAltavideoJuego();


                                //suscripciones
                                basura =IU->ingresarDatos("ari@mail.com","123");
                                IS->SeleccionarVideojuego("Minecraft");
                                IS->IngresarDatosSuscripcion("anual",tarjeta);
                                Reloj::setFecha(11,6,2021,9,0);
                                IS->ConfirmarSuscripcion();


                                //partidas individuales
                                int cod=0;
                                basura =IU->ingresarDatos("ari@mail.com","123");
                                IP->seleccionaVideoJuego("Minecraft");
                                IP->ingresarPartidaIndividual(false);
                                Reloj::setFecha(12,6,2021,16,0);
                                IP->IniciarPartida();
                                //cod = IP->IniciarPartidaConCodigo();
                     

                                // el compilador quiere que use la basura
                                if (basura && cod){     
                                }

                        }
                        break;

                        case 4: {
                            cout << "Chau";
                            cout << '\n';
                            termina = 1;
                                
                        }
                        break;


                        default: {

                                termina = true;
                                cout << "numero invalido, cerrando sistema..." << '\n';
                        }
                        break;
                        }
                } catch (invalid_argument & e) {
                        cout << e.what() << endl;
                }
        }

        delete IU;
        delete IV;
        delete IS;
        delete IP;
        delete IE;

        Reloj::Destructor();

        return 0;


}
