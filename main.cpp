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


void menuParaJugador(IControladorUsuario* IU, IControladorVideojuego* IV, IControladorSuscripciones* IS, IControladorPartida* IP, IControladorEstadistica* IE){

        bool termina = 0;
        while (!termina){

                cout << "Eliga la operacion a realizar: " << '\n';
                cout << "1) Suscribirse a videojuego." << '\n';
                cout << "2) Asignar puntaje a videojuego." << '\n';
                cout << "3) Iniciar partida." << '\n';
                cout << "4) Abandonar partida multijugador." << '\n';
                cout << "5) Finalizar partida." << '\n';
                cout << "6) Ver informaciÃ³n de videojuego." << '\n';
                cout << "7) Salir." << '\n';
                int eleccion;
                cin >> eleccion;
                cout << '\n';

                switch (eleccion) {

                        case 1: {
                                vector<DtSuscripcion*> SuscripcionesActivas;
                                SuscripcionesActivas = IS->obtenerSuscripcionesActivas();

                                int max = SuscripcionesActivas.size();
                                for(int i=0; i< max; i++ ){
                                        cout << SuscripcionesActivas[i] << endl;

                                }

                                vector<DtSuscripcion*> SuscripcionesNoActivas;
                                SuscripcionesNoActivas = IS->obtenerSuscripcionesNoActivas();

                                max = SuscripcionesNoActivas.size();
                                for(int i=0; i < max; i++ ){
                                        cout << SuscripcionesNoActivas[i] << endl;

                                }

                                string nombreVideojego;
                                cout << "Ingrese nombre del videojuego: "<<'\n';
                                cin.ignore();
                                getline(cin,nombreVideojego);
                                cout <<'\n';

                                IV->seleccionarVideoJuego(nombreVideojego);
                                bool puedeSuscribirse = 0;
                                puedeSuscribirse = IS->VerificarSuscripcionVitalicia();

                                //si puede suscribirse
                                if(puedeSuscribirse){

                                        bool cancela=0;
                                        cout << "Usted tiene una suscripcion a dicho juego quiere cancelarla 1 para si, 0 para no: "<<'\n';
                                        cin.ignore();
                                        cin >> cancela;
                                        cout <<'\n';

                                        //si no cancela la suscripcion existente
                                        if(!cancela){
                                                IS->Cancelar();
                                        }

                                        //nosi quiere cancela la suscripcion existente.
                                        else{

                                                string tipoSusc;
                                                cout << "Digite el tipo de suscripcion (mensual)(trimestral)(anual): "<<'\n';
                                                cin.ignore();
                                                getline(cin,tipoSusc);
                                                cout <<'\n';
						
                                                int e;
					        DtPago formaPago;
                                                cout << "seleccione Forma de Pago :  1-Tarjeta 2-Paypal "<<'\n';
						cin >> e;
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
                                                cin.ignore();
                                                cin >>confirSus;
                                                cout <<'\n';

                                                if(confirSus){
                                                        IS->ConfirmarSuscripcion();
                                                }
                                                else{
                                                        IS->Cancelar();
                                                }

                                        }


                                                
                                }
                                //no puede siscribirse
                                else{
                                      IS->Finalizarproceso();
                                }


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
                                cin.ignore();
                                getline(cin,NombreVj);
                                cout <<'\n';

                                int puntaje=0;
                                cout << "Ingrese puntaje : "<<'\n';
                                cin.ignore();
                                cin >> puntaje;
                                cout <<'\n';

                                IV->AsignarPuntajeVJ(NombreVj,puntaje);

                        }
                        break;
                        case 3: {

                                vector<string> ListaVJConSuscrActiva;
                                ListaVJConSuscrActiva = IP->listarVideojuegosConSuscripcionActiva();

                                int max = ListaVJConSuscrActiva.size();
                                for(int i = 0; i< max; i++ ){
                                        cout << ListaVJConSuscrActiva[i] << endl;
                                }

                                string NombreVj;
                                cout << "Nombre del Vj del cual quiere iniciar una partida: "<<'\n';
                                cin.ignore();
                                getline(cin,NombreVj);
                                cout <<'\n';

                                IP->seleccionaVideoJuego(NombreVj);


                                bool TipoPartida;
                                cout << "Presione 1 si quiere iniciar una partida multijugador 0 si induvidual: "<<'\n';
                                cin.ignore();
                                cin >> TipoPartida;
                                cout <<'\n';

                                //si quiere iniciar una partida multijugador
                                if(TipoPartida){

                                        bool EsTransEnVivo;
                                        cout << "Presiona 1 si la partida es transmitida en vivo: "<<'\n';
                                        cin.ignore();
                                        cin >> EsTransEnVivo;
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
                                                cin.ignore();
                                                getline(cin,nomJugadorAgregar);
                                                cout <<'\n';

                                                //no se a que controlador pertenece
                                                //AgregarJugador(nomJugadorAgregar);

                                                
                                                cout << "Quiere ingresar mas jugadores, presione 1 para si, 0 para no: "<<'\n';
                                                cin.ignore();
                                                cin >> agregarJugadores;
                                                cout <<'\n';

                                        }

                                }
                                //si quiere iniciar una partida individual
                                else{

                                        bool EsContinuacion;
                                        cout << "Presiona 1 si la partida es continuacion de otra: "<<'\n';
                                        cin.ignore();
                                        cin >> EsContinuacion;
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

                                                int codigoPartida;
                                                cout << "Ingrese el codigo de la partida que quiere continuar: "<<'\n';
                                                cin.ignore();
                                                cin >> codigoPartida;
                                                cout <<'\n';

                                                IP->PartidaAcontinuar(codigoPartida);

                                        }

                                }

                                int Confirmarr;
                                cout << "Presione 1 para confirmar 0 para cancelar el codigo de la partida que quiere continuar: "<<'\n';
                                cin.ignore();
                                cin >>Confirmarr;
                                cout <<'\n';

                                if(Confirmarr){
                                       IP->IniciarPartida();
                                }
                                else{
                                        IP->CancelarPartida();
                                }

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
                                cin.ignore();
                                cin >> codPartida;
                                cout <<'\n';
                                IP->abandonarPartida(codPartida);

                        }
                        break;
                        case 5: {

                                vector<DtPartidaEnCurso*> PartidaEnCursoDelJugador;
                                PartidaEnCursoDelJugador = IP->obtenerPartidasEnCurso();

                                int max = PartidaEnCursoDelJugador.size();
                                for(int i = 0; i < max ; i++ ){
                                        cout << PartidaEnCursoDelJugador[i] << endl;
                                }

                                int codPartida;
                                cout << "Ingrese le codigo de la partida que quiere finalizar: "<<'\n';
                                cin.ignore();
                                cin >> codPartida;
                                cout <<'\n';
                                IP->finalizarPartida(codPartida);

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
                                cin.ignore();
                                getline(cin,nombreJuego);
                                cout <<'\n';

                                DtInfoEspecifica* datosVj;
                                datosVj = IV->SeleccionarVideojuego(nombreJuego);
                                cout << datosVj;

                        }
                        break;
                        case 7: {
                        termina = 1;
                        }
                        break;
                }
        }
};

/*
paulo
paulo
paulo
*/

void menuParaDesarollador(IControladorUsuario* IU, IControladorVideojuego* IV, IControladorSuscripciones* IS, IControladorPartida* IP, IControladorEstadistica* IE){

        bool termina = 0;
        while (!termina){


                cout << "Eliga la operacion a realizar: " << '\n';
                cout << "1) Agregar categoria." << '\n';
                cout << "2) Publicar videojuego." << '\n';
                cout << "3) Eliminar videojuego." << '\n';
                cout << "4) Seleccionar estadisticas." << '\n';
                cout << "5) Consultar estadÃ­sticas." << '\n';
                cout << "6) Ver iformacion del videojuego." << '\n';
                cout << "7) Salir." << '\n';
                int eleccion;
                cin >> eleccion;
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
                                cin.ignore();
                                getline(cin,nomCategoria);
                                cout <<'\n';
                                
                                string descCategoria;
                                cout << "Ingrese descripcion de la nueva categoria: "<<'\n';
                                cin.ignore();
                                getline(cin,descCategoria);
                                cout <<'\n';
                                
                                string tipoCategoria;
                                cout << "Ingrese tipo de la nueva categoria: "<<'\n';
                                cin.ignore();
                                getline(cin,tipoCategoria);
                                cout <<'\n';
                    
                                //creo una categoria no en memoria dinamica
                                DtCategoria nuevaCat(nomCategoria,descCategoria,tipoCategoria);
                                
                                //creo un punero a es dt cat
                                DtCategoria* catNuevaPuntero = &nuevaCat;
                                IV->NuevaCategoria(catNuevaPuntero);

                                bool confirmar= 0;
                                cout << "Confirmar creacion de categoria: 1 para si, 0 para no "<<'\n';
                                cin >> confirmar;
                                cin.ignore();
                                cout <<'\n';

                                if(confirmar){
                                       IV->ConfirmarCategoria();
                                }
                                else{
                                        IV->ConfirmarCategoria();
                                }

                        }
                        break;

                        case 2: {

                                string vJuego;
                                cout << "Ingrese nombre del nuevo juego: "<<'\n';
                                cin.ignore();
                                getline(cin,vJuego);
                                cout <<'\n';

                                string vDescripcion;
                                cout << "Ingrese descripcion: "<<'\n';
                                cin.ignore();
                                getline(cin,vDescripcion);
                                cout <<'\n';

                                string vCostoMensual;
                                cout << "Ingrese costo mensual: "<<'\n';
                                cin.ignore();
                                cin >> vCostoMensual;
                                cout <<'\n';

                                string vCostoTrimestral;
                                cout << "Ingrese costo trimestral: "<<'\n';
                                cin.ignore();
                                cin >> vCostoTrimestral;
                                cout <<'\n';

                                string vCostoAnual;
                                cout << "Ingrese costo anual: "<<'\n';
                                cin.ignore();
                                cin >> vCostoAnual;
                                cout <<'\n';

                                string vCostoVitalicio;
                                cout << "Ingrese costo vitalicio: "<<'\n';
                                cin.ignore();
                                cin >> vCostoVitalicio;
                                cout <<'\n';
                                
                                vector<DtCategoria*> CategoriaPlataforma;
                                CategoriaPlataforma = IV->ObtenerCategoriaPlataforma();
                              
                                //imprimimos las categorias de tipo plataforma
                                int max = CategoriaPlataforma.size();
                                for( int i=0; i < max; i++ ){
                                        cout << CategoriaPlataforma[i] << endl;
                                }

                                bool auxWhileAgregarCat = 1;
                                while( auxWhileAgregarCat ){

                                        string vNombreCategoria;
                                        cout << "Agrege una categoria (nombre) :"<<'\n';
                                        cin.ignore();
                                        getline(cin,vNombreCategoria);
                                        cout <<'\n';
                                        IV->agregarcategoria(vNombreCategoria);
                                        
                                        cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                        cin.ignore();
                                        cin >> auxWhileAgregarCat;
                                        cout <<'\n';
                                }


                                
                                vector<DtCategoria*> CategoriaGenero;
                                CategoriaGenero = IV->ObtenerCategoriaGenero();
                              
                                //imprimimos las categorias de tipo genero

                                //max ya esta definido
                                int max1 = CategoriaGenero.size();
                                for( int i=0; i < max1 ;i++ ){
                                        cout << CategoriaGenero[i] << endl;
                                }

                                auxWhileAgregarCat = 1;
                                
                                while( auxWhileAgregarCat ){

                                        string vNombreCategoria;
                                        cout << "Agrege una categoria (nombre) :"<<'\n';
                                        cin.ignore();
                                        getline(cin,vNombreCategoria);
                                        cout <<'\n';
                                        IV->agregarcategoria(vNombreCategoria);
                                        
                                        cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                        cin.ignore();
                                        cin >> auxWhileAgregarCat;
                                        cout <<'\n';
                                }


                                vector<DtCategoria*> CategoriaOtro;
                                CategoriaGenero = IV->ObtenerCategoriaOtros();
                              
                                //imprimimos las categorias de tipo otro
                                max = CategoriaOtro.size();
                                for( int i=0; i<max; i++ ){
                                        cout << CategoriaOtro[i] << endl;
                                }

                                auxWhileAgregarCat = 1;
                                cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                cin.ignore();
                                cin >>auxWhileAgregarCat;
                                cout <<'\n';

                                while( auxWhileAgregarCat ){
                                        string vNombrecCategoria;
                                        cout << "Agrege una categoria (nombre) :"<<'\n';
                                        cin.ignore();
                                        getline(cin,vNombrecCategoria);
                                        cout <<'\n';

                                       IV->agregarcategoria(vNombrecCategoria);
                                        
                                        cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                        cin.ignore();
                                        cin >> auxWhileAgregarCat;
                                        cout <<'\n';

                                }
                                DtVideojuego* infoVideojuego;
                                infoVideojuego = IV->ObtenerInfoVideojuego();
                                cout << infoVideojuego << endl;



                        }
                        break;
                        case 3: {

                                vector<string> VideojuegosParaEliminar;
                                VideojuegosParaEliminar = IV->obtenerVideoJuegosConTodasLasPartidasFinalizadas();

                                int max = VideojuegosParaEliminar.size();
                                for( int i = 0; i< max; i++ ){
                                        cout << VideojuegosParaEliminar[i] << endl;
                                }

                                string nomVJ;
                                cout << "Ingrese nombre de la nueva categoria: "<<'\n';
                                cin.ignore();
                                getline(cin,nomVJ);
                                cout <<'\n';

                                IV->seleccionarVideoJuego(nomVJ);

                                bool conf = 0;
                                cout << "Cofirmar eliminacion 1 para si, 0 para no :"<<'\n';
                                cin.ignore();
                                cin >> conf;
                                cout <<'\n';

                                if(conf){
                                        IV->eliminarVideoJuego();
                                }
                                else{
                                        IV->cancelarLaEliminacion();
                                }
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
                                        cin.ignore();
                                        getline(cin,estadisticaNombre);
                                        cout <<'\n';

                                        EstadisticasSeleccionadas.push_back(estadisticaNombre);

                                        cout << "Quiere seleccionar otra estadistica. 1 para si, 0 para no :"<<'\n';
                                        cin.ignore();
                                        cin >> auxWhile;
                                        cout <<'\n';

                                }

                                IE->SeleccionEstadisticas(EstadisticasSeleccionadas);

                                bool confirmar;
                                cout << "Confirmar. 1 para si 0 para no :"<<'\n';
                                cin.ignore();
                                cin >>confirmar;
                                cout <<'\n';

                                if(confirmar){
                                        IE->ConfirmarSeleccionEstaditicas();
                                }
                                else{
                                        IE->CancelarSeleccionEstaditicas();
                                }

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
                                cin.ignore();
                                getline(cin,nombreJuego);
                                cout <<'\n';

                                //podria no ser un vector
                                vector<DtEstadisticaDeSegundoTipo*> datos;
                                datos = IE->SeleccionEstadisticasDeCiertoJuego(nombreJuego);
                                cout << datos[0] << endl;

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
                                cin.ignore();
                                getline(cin,nombreJuego);
                                cout <<'\n';

                                DtInfoEspecifica* datosVj;
                                datosVj = IV->SeleccionarVideojuego(nombreJuego);
                                cout << datosVj << endl;
                                
                                float VMostarTotalHorasJugadas=0;
                                VMostarTotalHorasJugadas = IV->MostrarHorasTotalJugadas();
                                cout << "Total de horas Jugadas: ";
                                cout << VMostarTotalHorasJugadas << endl;

                        }
                        break;
                        case 7: {
                                termina = 1;
                        }
                        break;
                }
        }
};




void menuParaJugador(){}

int main() {


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
                        cout << '\n';

                        IControladorUsuario* IU = Fabrica::getIUsuario();
                        IControladorVideojuego* IV = Fabrica::getIVideojuego();
                        IControladorSuscripciones* IS = Fabrica::getISuscripcion();
                        IControladorPartida* IP = Fabrica::getIPartida();
                        IControladorEstadistica* IE = Fabrica::getIEstadistica();

                        switch (eleccion) {

                        case 1: {


                                string vemail;
                                cout << "Ingrese email:" << '\n';
                                cin >> vemail;
                                cout << '\n';

                                string vpassword;
                                cout << "ingrese contrasenia:" << '\n';
                                cin >> vpassword;
                                cout << '\n';

                                IU->IngresardatosUsuario(vemail,vpassword);

                                int tipoUsuario = 0;
                                cout << "Tipo de usuario a registrar: 1: Desarollador, 2: Jugador" << '\n';
                                cin >> tipoUsuario;

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

                                                bool verificacion=0;
                                                verificacion = IU->IngresardatosJugador(vnickname, vdescripcion);

                                                //si puede registrarse con ese usuario
                                                if (verificacion) {
                                                        auxWhile = 0;
                                                } else {

                                                        bool vreintenarIngresoDatos;
                                                        cout << "nickname existente, quiere volver a intentarlo: 0 para no, 1 para si" << '\n';
                                                        cin >> vreintenarIngresoDatos;
                                                        cout << '\n';

                                                        auxWhile = vreintenarIngresoDatos;

                                                }

                                        }

                                }
                                if (verificacion || (tipoUsuario == 1)) { 
                                    bool vconfirmar;
                                    cout << "Desea confirmar inscripcion 1 para si 0 para no:" << '\n';
                                    cin >> vconfirmar;
                                    cout << '\n';

                                    if (!vconfirmar) {
                                            IU->cancelarAltaUsuario();
                                    } else {
                                            IU->ConfirmarAltaUsuario();
                                    }
                                }
                        }
                        break;

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

                                        bool ingreso = IU->ingresarDatos(vemail, passw);
                                       

                                        //si no ingreso
                                        if (!ingreso) {
                                                bool reintentar;
                                                cout << "Fallo el ingreso. Quiere reintentar ingresar?: 1 para si 0 para no" << '\n';
                                                cin >> reintentar;
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
                                        menuParaJugador();
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
                                IU->IngresardatosUsuario("ironhide@mail.com","123");
                                IU->IngresardatosDesarrollador("Ironhide Game Studio");
                                IU->ConfirmarAltaUsuario();

                                IU->IngresardatosUsuario("epic@mail.com","123");
                                IU->IngresardatosDesarrollador("Epic Games");
                                IU->ConfirmarAltaUsuario();

                                IU->IngresardatosUsuario("mojang@mail.com","123");
                                IU->IngresardatosDesarrollador("Mojang Studios");
                                IU->ConfirmarAltaUsuario();

                                IU->IngresardatosUsuario("ea@mail.com","123");
                                IU->IngresardatosDesarrollador("EA Sports");
                                IU->ConfirmarAltaUsuario();


                                //jugadores
                                IU->IngresardatosUsuario("gamer@mail.com","123");
                                IU->IngresardatosJugador("gamer","");
                                IU->ConfirmarAltaUsuario();

                                IU->IngresardatosUsuario("ari@mail.com","123");
                                IU->IngresardatosJugador("ari","");
                                IU->ConfirmarAltaUsuario();

                                IU->IngresardatosUsuario("ibai@mail.com","123");
                                IU->IngresardatosJugador("ibai","");
                                IU->ConfirmarAltaUsuario();

                                IU->IngresardatosUsuario("camila@mail.com","123");
                                IU->IngresardatosJugador("camila","");
                                IU->ConfirmarAltaUsuario();


                                //categorias
                                DtCategoria* c;

                                c = new DtCategoria("PC","Juegos de pc","plataforma");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();

                                c = new DtCategoria("PS4","Juegos de PS4","plataforma");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();

                                c = new DtCategoria("Xbox One","Juegos de Xbox One","plataforma");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();

                                c = new DtCategoria("Deporte","Juegos de Deporte","genero");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();

                                c = new DtCategoria("Supervivencia","Juegos de Supervivencia","genero");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();

                                c = new DtCategoria("Estrategia","Juegos de Estrategia","genero");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();

                                c = new DtCategoria("Teen","Su contenido está dirigido a jóvenes de 13 años en adelante","otro");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();

                                c = new DtCategoria("E","Su contenido esta dirigido para todo público","otro");
                                IV->NuevaCategoria(c);
                                IV->ConfirmarCategoria();


                                //videojuegos
                                bool basura;
                                
                                basura = IU->ingresarDatos("ironhide@mail.com","123");
                                IV->datosVideojuego("KingdomRush","des1",1.f,2.f,7.f,14.f);
                                IV->agregarcategoria("PC");
                                IV->agregarcategoria("PS4");
                                IV->agregarcategoria("Estrategia");
                                IV->agregarcategoria("E");
                                IV->ConfirmarAltavideoJuego();

                                basura = IU->ingresarDatos("epic@mail.com","123");
                                IV->datosVideojuego("Fortnite","des2",3.f,8.f,30.f,60.f);
                                IV->agregarcategoria("PC");
                                IV->agregarcategoria("PS4");
                                IV->agregarcategoria("Xbox One");
                                IV->agregarcategoria("Supervivencia");
                                IV->agregarcategoria("Teen");
                                IV->ConfirmarAltavideoJuego();

                                basura = IU->ingresarDatos("mojang@mail.com","123");
                                IV->datosVideojuego("Minecraft","des3",2.f,5.f,20.f,40.f);
                                IV->agregarcategoria("PC");
                                IV->agregarcategoria("Supervivencia");
                                IV->agregarcategoria("E");
                                IV->ConfirmarAltavideoJuego();

                                basura = IU->ingresarDatos("ea@mail.com","123");
                                IV->datosVideojuego("FIFA 21","igual a todos los FIFA",3.f,8.f,28.f,50.f);
                                IV->agregarcategoria("PC");
                                IV->agregarcategoria("PS4");
                                IV->agregarcategoria("Xbox One");
                                IV->agregarcategoria("Deporte");
                                IV->agregarcategoria("E");
                                IV->ConfirmarAltavideoJuego();


                                //suscripciones
                                DtFecha* f;

                                basura =IU->ingresarDatos("gamer@mail.com","123");
                                IS->SeleccionarVideojuego("KingdomRush");
                                IS->IngresarDatosSuscripcion("trimestral",paypal);
                                f = new DtFecha(1,6,2021,9,0);
                                IS->ConfirmarSuscripcion(f);

                                basura =IU->ingresarDatos("gamer@mail.com","123");
                                IS->SeleccionarVideojuego("Fortnite");
                                IS->IngresarDatosSuscripcion("trimestral",tarjeta);
                                f = new DtFecha(2,6,2021,11,0);
                                IS->ConfirmarSuscripcion(f);

                                basura =IU->ingresarDatos("ari@mail.com","123");
                                IS->SeleccionarVideojuego("Fortnite");
                                IS->IngresarDatosSuscripcion("mensual",paypal);
                                f = new DtFecha(4,6,2021,9,0);
                                IS->ConfirmarSuscripcion(f);

                                basura =IU->ingresarDatos("ari@mail.com","123");
                                IS->SeleccionarVideojuego("Minecraft");
                                IS->IngresarDatosSuscripcion("anual",tarjeta);
                                f = new DtFecha(11,6,2021,9,0);
                                IS->ConfirmarSuscripcion(f);

                                basura =IU->ingresarDatos("ibai@mail.com","123");
                                IS->SeleccionarVideojuego("Fortnite");
                                IS->IngresarDatosSuscripcion("mensual",tarjeta);
                                f = new DtFecha(3,6,2021,7,0);
                                IS->ConfirmarSuscripcion(f);

                                basura =IU->ingresarDatos("ibai@mail.com","123");
                                IS->SeleccionarVideojuego("Minecraft");
                                IS->IngresarDatosSuscripcion("vitalicia",tarjeta);
                                f = new DtFecha(21,12,2020,15,0);
                                IS->ConfirmarSuscripcion(f);


                                //puntajes
                                basura =IU->ingresarDatos("gamer@mail.com","123");
                                IV->AsignarPuntajeVJ("KingdomRush",4);

                                basura =IU->ingresarDatos("gamer@mail.com","123");
                                IV->AsignarPuntajeVJ("Fortnite",5);

                                basura =IU->ingresarDatos("ari@mail.com","123");
                                IV->AsignarPuntajeVJ("Fortnite",5);

                                basura =IU->ingresarDatos("ari@mail.com","123");
                                IV->AsignarPuntajeVJ("Minecraft",3);


                                //partidas individuales
                                int cod;

                                basura =IU->ingresarDatos("gamer@mail.com","123");
                                IP->seleccionaVideoJuego("KingdomRush");
                                IP->ingresarPartidaIndividual(false);
                                Reloj::setFecha(2,6,21,9,0);
                                cod = IP->IniciarPartidaConCodigo();
                                Reloj::setFecha(2,6,21,10,0);

                                basura =IU->ingresarDatos("gamer@mail.com","123");
                                IP->seleccionaVideoJuego("KingdomRush");
                                IP->ingresarPartidaIndividual(true);
                                IP->PartidaAcontinuar(cod);
                                Reloj::setFecha(3,6,21,15,0);
                                cod = IP->IniciarPartidaConCodigo();
                                Reloj::setFecha(2,6,21,16,0);
                                IP->finalizarPartida(cod);

                                basura =IU->ingresarDatos("ari@mail.com","123");
                                IP->seleccionaVideoJuego("Minecraft");
                                IP->ingresarPartidaIndividual(false);
                                Reloj::setFecha(12,6,21,9,0);
                                IP->IniciarPartida();
                               

                                //partidas multijugador
                                


                                /*
                                int an, me, di, ho, mi;

                                cout << "Es necesario ingresar la fecha y hora del sistema" << '\n';

                                cout << "ingrese el aÃ±o: ";
                                cin >> an;
                                cout << '\n';

                                cout << "ingrese el mes: ";
                                cin >> me;
                                cout << '\n';

                                cout << "ingrese el dia: ";
                                cin >> di;
                                cout << '\n';

                                cout << "ingrese la hora: ";
                                cin >> ho;
                                cout << '\n';

                                cout << "ingrese el minuto: ";
                                cin >> mi;
                                cout << '\n';
                                */

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


        return 0;


}
