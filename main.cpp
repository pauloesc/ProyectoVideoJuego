#include <iostream>
#include <vector>
#include <string>

using namespace std;

void menuParaJugador(){

        bool termina = 0;
        while (!termina){

                cout << "Eliga la operacion a realizar: " << '\n';
                cout << "1) Suscribirse a videojuego." << '\n';
                cout << "2) Asignar puntaje a videojuego." << '\n';
                cout << "3) Iniciar partida." << '\n';
                cout << "4) Abandonar partida multijugador." << '\n';
                cout << "5) Finalizar partida." << '\n';
                cout << "6) Ver información de videojuego." << '\n';
                cout << "7) Salir." << '\n';
                int eleccion;
                cin >> eleccion;
                cout << '\n';

                switch (eleccion) {

                        case 1: {
                                vector<DtSuscripcion> SuscripcionesActivas;
                                SuscripcionesActivas = InstanciaControladorSuscripcion.obtenerSuscripcionesActivas();

                                for(int i=0; i< SuscripcionesActivas.size(), i++ ){
                                        cout << SuscripcionesActivas[i] << endl;

                                }

                                vector<DtSuscripcion> SuscripcionesActivas;
                                SuscripcionesNoActivas = InstanciaControladorSuscripcion.obtenerSuscripcionesNoActivas();

                                for(int i=0; i< SuscripcionesActivas.size(), i++ ){
                                        cout << SuscripcionesActivas[i] << endl;

                                }

                                string nombreVideojego;
                                cout << "Ingrese nombre del videojuego: "<<'\n';
                                cin.ignore();
                                getline(cin,nombreVideojego);
                                cout <<'\n';

                                bool puedeSuscribirse = InstanciaControladorSuscripcion.SeleccionarVideojuegoParaSuscr(nombreVideojego);

                                //si puede suscribirse
                                if(puedeSuscribirse){

                                        bool cancela=0;
                                        cout << "Usted tiene una suscripcion a dicho juego quiere cancelarla 1 para si, 0 para no: "<<'\n';
                                        cin.ignore();
                                        getline(cin,cancela);
                                        cout <<'\n';

                                        //si no cancela la suscripcion existente
                                        if(!cancela){
                                                InstanciaControladorSuscripcion.Cancelar() 
                                        }

                                        //nosi quiere cancela la suscripcion existente.
                                        else{

                                                string tipoSusc;
                                                cout << "Digite el tipo de suscripcion (mensual)(trimestral)(anual): "<<'\n';
                                                cin.ignore();
                                                getline(cin,tipoSusc);
                                                cout <<'\n';

                                                string formaPago;
                                                cout << ": "<<'\n';
                                                cin.ignore();
                                                getline(cin,formaPago);
                                                cout <<'\n';

                                                InstanciaControladorSuscripcion.IngresarDatosSuscripcion(tipoSusc,formaPago);

                                                bool confirSus=0;
                                                cout << "Confirmar suscripcion: "<<'\n';
                                                cin.ignore();
                                                getline(cin,confirSus);
                                                cout <<'\n';

                                                if(confirSus){
                                                        InstanciaControladorSuscripcion.ConfirmarSuscripcion();
                                                }
                                                else{
                                                        InstanciaControladorSuscripcion.Cancelar();
                                                }

                                        }


                                                
                                }
                                //no puede siscribirse
                                else{
                                        InstanciaControladorSuscripcion.Finalizarproceso();
                                }


                        }
                        break;
                        case 2: {

                                vector<DataVideoJuegoResumido> VideojuegosDatos;
                                VideojuegosDatos = InstanciaControladorVideojuego.ObtenerVideojuegos();

                                for(int i=0; i< VideojuegosDatos.size(), i++ ){
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
                                getline(cin,puntaje);
                                cout <<'\n';

                                InstanciaControladorVideojuego.AsignarPuntajeVJ(NombreVj,puntaje);

                        }
                        break;
                        case 3: {

                                vector<DataVidestringoJuegoResumido> ListaVJConSuscrActiva;
                                ListaVJConSuscrActiva = InstanciaControladorPartida.listarVideojuegosConSuscripcionActiva();

                                for(int i = 0; i< ListaVJConSuscrActiva.size(); i++ ){
                                        cout << ListaVJConSuscrActiva[i] << endl;
                                }
                                
                                string NombreVj;
                                cout << "Nombre del Vj del cual quiere iniciar una partida: "<<'\n';
                                cin.ignore();
                                getline(cin,NombreVj);
                                cout <<'\n';

                                InstanciaControladorPartida.seleccionaVideoJuego(NombreVj);


                                bool TipoPartida;
                                cout << "Presione 1 si quiere iniciar una partida multijugador 0 si induvidual: "<<'\n';
                                cin.ignore();
                                getline(cin,TipoPartida);
                                cout <<'\n';

                                //si quiere iniciar una partida multijugador
                                if(TipoPartida){

                                        bool EsTransEnVivo;
                                        cout << "Presiona 1 si la partida es transmitida en vivo: "<<'\n';
                                        cin.ignore();
                                        getline(cin,EsTransEnVivo);
                                        cout <<'\n';

                                        InstanciaControladorPartida.IngresarPartidaMultijugador(EsTransEnVivo);

                                        vector<string> ListaJugadoresQuePuedenUnirse;
                                        ListaJugadoresQuePuedenUnirse = InstanciaControladorPartida.ListarJugadoresConSuscripcionActiva();

                                        for(int i = 0; i< ListaJugadoresQuePuedenUnirse.size(); i++ ){
                                                        cout << ListaJugadoresQuePuedenUnirse[i] << endl;
                                                }

                                        bool agregarJugadores = 1;
                                        while(agregarJugadores){
                                                string nomJugadorAgregar;
                                                cout << "Ingrese el nombre de un jugador a ingresar para agregarlo a la partida: "<<'\n';
                                                cin.ignore();
                                                getline(cin,nomJugadorAgregar);
                                                cout <<'\n';
                                                AgregarJugador(nomJugadorAgregar);

                                                
                                                cout << "Quiere ingresar mas jugadores, presione 1 para si, 0 para no: "<<'\n';
                                                cin.ignore();
                                                getline(cin,agregarJugadores);
                                                cout <<'\n';

                                        }

                                }
                                //si quiere iniciar una partida individual
                                else{

                                        bool EsContinuacion;
                                        cout << "Presiona 1 si la partida es continuacion de otra: "<<'\n';
                                        cin.ignore();
                                        getline(cin,EsContinuacion);
                                        cout <<'\n';

                                        InstanciaControladorPartida.ingresarPartidaIndividual(EsContinuacion);

                                        //si quiere iniciar una partida continuacion de otra
                                        if(EsContinuacion){
                                                
                                                vector<DtPartidaIndividual> HistorialPartidaIndiv;
                                                HistorialPartidaIndiv = InstanciaControladorPartida.HistorialDePartidasIndividualesFinalizadas();

                                                for(int i = 0; i< HistorialPartidaIndiv.size(); i++ ){
                                                        cout << HistorialPartidaIndiv[i] << endl;
                                                }

                                                int codigoPartida;
                                                cout << "Ingrese el codigo de la partida que quiere continuar: "<<'\n';
                                                cin.ignore();
                                                getline(cin,codigoPartida);
                                                cout <<'\n';

                                                InstanciaControladorPartida.PartidaAcontinuar(codigoPartida);

                                        }

                                }

                                int Confirmarr;
                                cout << "Presione 1 para confirmar 0 para cancelar el codigo de la partida que quiere continuar: "<<'\n';
                                cin.ignore();
                                getline(cin,Confirmarr);
                                cout <<'\n';

                                if(Confirmarr){
                                       InstanciaControladorPartida.IniciarPartida();
                                }
                                else{
                                        InstanciaControladorPartida.CancelarPartida();
                                }

                        }
                        break;
                        case 4: {}
                        break;
                        case 5: {}
                        break;
                        case 6: {}
                        break;
                        case 7: {}
                        break;
                }
        }

};

void menuParaDesarollador(){

        bool termina = 0;
        while (!termina){


                cout << "Eliga la operacion a realizar: " << '\n';
                cout << "1) Agregar categoria." << '\n';
                cout << "2) Publicar videojuego." << '\n';
                cout << "3) Eliminar videojuego." << '\n';
                cout << "4) Seleccionar estadisticas." << '\n';
                cout << "5) Consultar estadísticas." << '\n';
                cout << "6) Ver iformacion del videojuego." << '\n';
                cout << "7) Salir." << '\n';
                int eleccion;
                cin >> eleccion;
                cout << '\n';

                switch (eleccion) {

                        case 1: {
                                vector<string> nombreCategorias;
                                nombreCategorias = InstanciaControladorVideojuego.ObtenerCategorias();

                                cout << "Nombre de las categorias existentes: "<<'\n';
                 
                                for(int i=0; i< nombreCategorias.size(), i++ ){
                                        cout << nombreCategorias[i] << endl;

                                }

                                

                                string nomCategoria;
                                cout << "Ingrese nombre de la nueva categoria: "<<'\n';
                                cin.ignore();
                                getline(cin,nomCategoria);
                                cout <<'\n';
                                
                                string descCategoria;
                                cout << "Ingrese nombre de la nueva categoria: "<<'\n';
                                cin.ignore();
                                getline(cin,descCategoria);
                                cout <<'\n';
                                
                                string tipoCategoria;
                                cout << "Ingrese nombre de la nueva categoria: "<<'\n';
                                cin.ignore();
                                getline(cin,tipoCategoria);
                                cout <<'\n';
                 
                                InstanciaControladorVideojuego.NuevaCategoria(nomCategoria, descCategoria, tipoCategoria);

                                bool confirmar= 0;
                                cout << "Confirmar creacion de categoria: 1 para si, 0 para no "<<'\n';
                                cin.ignore();
                                getline(cin,confirmar);
                                cout <<'\n';

                                if(confirmar){
                                        InstanciaControladorVideojuego.ConfirmarCategoria()
                                }
                                else{
                                        InstanciaControladorVideojuego.ConfirmarCategoria()
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
                                getline(cin,vCostoMensual);
                                cout <<'\n';

                                string vCostoTrimestral;
                                cout << "Ingrese costo trimestral: "<<'\n';
                                cin.ignore();
                                getline(cin,vCostoTrimestral);
                                cout <<'\n';

                                string vCostoAnual;
                                cout << "Ingrese costo anual: "<<'\n';
                                cin.ignore();
                                getline(cin,vCostoAnual);
                                cout <<'\n';

                                string vCostoVitalicio;
                                cout << "Ingrese costo vitalicio: "<<'\n';
                                cin.ignore();
                                getline(cin,vCostoVitalicio);
                                cout <<'\n';
                                
                                vector<DataCategoria2> CategoriaPlataforma;
                                CategoriaPlataforma = InstanciaControladorVideojuego.ObtenerCategoriaPlataforma();
                              
                                //imprimimos las categorias de tipo plataforma
                                for( int i=0; i<CategoriaPlataforma.size();i++ ){
                                        cout << CategoriaPlataforma[i] << endl;
                                }

                                bool auxWhileAgregarCat = 1;
                                while( auxWhileAgregarCat ){

                                        string vNombrecCategori;
                                        cout << "Agrege una categoria (nombre) :"<<'\n';
                                        cin.ignore();
                                        getline(cin,vNombrecCategoria);
                                        cout <<'\n';
                                        InstanciaControladorVideojuego.agregarcategoria(vNombrecCategori);
                                        
                                        cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                        cin.ignore();
                                        getline(cin,auxWhileAgregarCat);
                                        cout <<'\n';
                                }


                                vector<DataCategoria2> CategoriaGenero;
                                CategoriaGenero = InstanciaControladorVideojuego.ObtenerCategoriaGenero();
                              
                                //imprimimos las categorias de tipo genero
                                for( int i=0; i<CategoriaGenero.size();i++ ){
                                        cout << CategoriaGenero[i] << endl;
                                }

                                auxWhileAgregarCat = 1;
                                
                                while( auxWhileAgregarCat ){

                                        cout << "Agrege una categoria (nombre) :"<<'\n';
                                        cin.ignore();
                                        getline(cin,vNombrecCategoria);
                                        cout <<'\n';
                                        InstanciaControladorVideojuego.agregarcategoria(vNombrecCategori);
                                        
                                        cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                        cin.ignore();
                                        getline(cin,auxWhileAgregarCat);
                                        cout <<'\n';
                                }


                                vector<DataCategoria2> CategoriaOtro;
                                CategoriaGenero = InstanciaControladorVideojuego.ObtenerCategoriaOtro();
                              
                                //imprimimos las categorias de tipo otro
                                for( int i=0; i<CategoriaOtro.size();i++ ){
                                        cout << CategoriaOtro[i] << endl;
                                }

                                auxWhileAgregarCat = 1;
                                cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                cin.ignore();
                                getline(cin,auxWhileAgregarCat);
                                cout <<'\n';

                                while( auxWhileAgregarCat ){

                                        cout << "Agrege una categoria (nombre) :"<<'\n';
                                        cin.ignore();
                                        getline(cin,vNombrecCategoria);
                                        cout <<'\n';

                                        InstanciaControladorVideojuego.agregarcategoria(vNombrecCategori);
                                        
                                        cout << "Desea agregar mas categorias: 1 para si 0 para no "<<'\n';
                                        cin.ignore();
                                        getline(cin,auxWhileAgregarCat);
                                        cout <<'\n';

                                }
                                DtVideoJuego infoVideojuego;
                                infoVideojuego = InstanciaControladorVideojuego.ObtenerInfoVideojuego();
                                cout << infoVideojuego << endl;



                        }
                        break;
                        case 3: {

                                vector<string> VideojuegosParaEliminar;
                                VideojuegosParaEliminar = InstanciaControladorVideojuego.obtenerVideoJuegosConTodasLasPartidasFinalizadas();

                                for( int i = 0; i< VideojuegosParaEliminar.size(); i++ ){
                                        cout << VideojuegosParaEliminar[i] << endl;
                                }

                                InstanciaControladorVideojuego.SeleccionarVideoJuego (nomVJ: string);

                                bool conf = 0;
                                cout << "Cofirmar eliminacion 1 para si, 0 para no :"<<'\n';
                                cin.ignore();
                                getline(cin,conf);
                                cout <<'\n';

                                if(conf){
                                        InstanciaControladorVideojuego.eliminarVideojuego();
                                }
                                else{
                                        InstanciaControladorVideojuego.cancelarLaEliminacion();
                                }
                        }
                        break;
                        case 4: {
                                vector<DataEstadistica> EstadisticasEnElSistema;
                                EstadisticasEnElSistema = InstanciaControladorEstadistica.TiposDeEstadistica();

                                for(int i=0; i< EstadisticasEnElSistema.size() ){
                                        cout << EstadisticasEnElSistema[i] << endl;
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
                                        getline(cin,auxWhile);
                                        cout <<'\n';

                                }

                                InstanciaControladorEstadistica.SeleccionEstadisticas(EstadisticasSeleccionadas);

                                bool confirmar;
                                cout << "Confirmar. 1 para si 0 para no :"<<'\n';
                                cin.ignore();
                                getline(cin,confirmar);
                                cout <<'\n';

                                if(confirmar){
                                        InstanciaControladorEstadistica.ConfirmarSeleccionEstaditicas();
                                }
                                else{
                                       InstanciaControladorEstadistica.CancelarSeleccionEstaditicas();
                                }

                        }
                        break;
                        case 5: {

                                vector<string> JuegosDelDesarollador;
                                JuegosDelDesarollador = InstanciaControladorVideojuego.JuegosDelDesarollador();
                                
                                //imprimo los videojuegos del desarollador
                                for( int i=0; i< JuegosDelDesarollador.size(); i++ ){
                                        cout << JuegosDelDesarollador[i] << endl;
                                }

                                string nombreJuego;
                                cout << "Seleccione un juego. (nombre) :"<<'\n';
                                cin.ignore();
                                getline(cin,nombreJuego);
                                cout <<'\n';

                                DataEstadisticaDeSegundoTipo datos;
                                datos = SeleccionEstadisticasDeCiertoJuego(nombreJuego)

                                cout << datos << endl;

                        }
                        break;
                        case 6: {
                                
                                vector<string> VideojuegosEnSistema;
                                VideojuegosEnSistema = InstanciaControladorVideojuego.ObtenerVideoJuegos();

                                for(int i=0; i< VideojuegosEnSistema.size(); i++){
                                        cout << VideojuegosEnSistema[i] << endl;
                                }

                                string nombreJuego;
                                cout << "Seleccione un juego. (nombre) :"<<'\n';
                                cin.ignore();
                                getline(cin,nombreJuego);
                                cout <<'\n';

                                DataInfoEspecifica datosVj;
                                datosVj = InstanciaControladorVideojuego.SeleccionarVideojuego(nombreJuego);

                                float VMostarTotalHorasJugadas = MostrarTotalHorasJugadas();
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


int main() {

        //no cambiar el nombre de estas cosas
        //no cambiar el nombre de estas cosas
        //no cambiar el nombre de estas cosas
        //no cambiar el nombre de estas cosas
        InstanciaControladorUsuario;
        InstanciaControladorEstadistica;
        InstanciaControladorPartida;
        InstanciaControladorVideojuego;
        InstanciaControladorSuscripcion;
        //no cambiar el nombre de estas cosas
        //no cambiar el nombre de estas cosas
        //no cambiar el nombre de estas cosas
        //no cambiar el nombre de estas cosas

        while (!termina) {

                try {

                        cout << "Eliga la operacion a realizar: " << '\n';
                        cout << "1) Alta de usuario." << '\n';
                        cout << "2) Iniciar sesión." << '\n';
                        cout << "3) Modificar fecha del sistema." << '\n';
                        cout << "4) Cargar datos de prueba." << '\n';
                        cout << "5) Salir." << '\n';

                        cin >> eleccion;
                        cout << '\n';

                        switch (eleccion) {

                        case 1: {

                                string vemail;
                                cout << "ingrese email:" << '\n';
                                cin.ignore();
                                getline(cin, vemail);
                                cout << '\n';

                                string vpassword;
                                cout << "ingrese contrasenia:" << '\n';
                                cin.ignore();
                                getline(cin, vpassword);
                                cout << '\n';

                                InstanciaControladorUsuario.IngresardatosUsuario(vemail, vpassword);

                                bool esDesarollador = 0;
                                cout << "Es un usuario desarollador: 1 para si, 0 para no" << '\n';
                                cin.ignore();
                                getline(cin, esDesarollador);

                                if (esDesarollador) {
                                        InstanciaControladorUsuario.IngresardatosDesarrollador(nomEmpresa: string)
                                } else {

                                        bool auxWhile = 1;
                                        while (auxWhile) {

                                                string vnickname;
                                                cout << "ingrese nickname:" << '\n';
                                                cin.ignore();
                                                getline(cin, vnickname);
                                                cout << '\n';

                                                string vdescripcion;
                                                cout << "ingrese descripcion:" << '\n';
                                                cin.ignore();
                                                getline(cin, vdescripcion);
                                                cout << '\n';

                                                bool verificacion;
                                                verificacion: = InstanciaControladorUsuario.IngresardatosJugador(vnickname, vdescripcion)

                                                //si puede registrarse con ese usuario
                                                if (verificacion) {
                                                        auxWhile = 0;
                                                } else {

                                                        bool vreintenarIngresoDatos;
                                                        cout << "No es posible registar dichs datos quiere volver a intentarlo: 0 para no, 1 para si" << '\n';
                                                        cin.ignore();
                                                        getline(cin, vreintenarIngresoDatos);
                                                        cout << '\n';

                                                        auxWhile = vreintenarIngresoDatos;

                                                }

                                        }

                                }

                                bool vconfirmar;
                                cout << "Desea confirmar inscripcion 1 para si 0 para no:" << '\n';
                                cin.ignore();
                                getline(cin, vconfirmar);
                                cout << '\n';

                                if (vconfirmar) {
                                        InstanciaControladorUsuario.cancelarAltaUsuario()
                                } else {
                                        InstanciaControladorUsuario.ConfirmarAltaUsuario()
                                }
                        }
                        break;

                        case 2: {

                                auxWhile = 1;
                                while (auxWhile) {

                                        string vemail;
                                        cout << "ingrese email : " << '\n';
                                        cin.ignore();
                                        getline(cin, vemail);
                                        cout << '\n';

                                        string passw;
                                        cout << "ingrese contrasenia : " << '\n';
                                        cin.ignore();
                                        getline(cin, passw);
                                        cout << '\n';

                                        bool ingreso = 0;
                                        ingreso: = InstanciaControladorUsuario.IngresarDatos(vemail; passw);

                                        //si no ingreso
                                        if (!ingreso) {
                                                bool reintentar;
                                                cout << "Fallo el ingreso. Quiere reintentar ingresar?: 1 para si 0 para no" << '\n';
                                                cin.ignore();
                                                getline(cin, reintentar);
                                                cout << '\n';

                                                auxWhile = reintentar
                                        }
                                        //si ingreso
                                        else {
                                                auxWhile = 0;
                                        }

                                }
                        }
                        break;

                        case 3: {

                                int an, me, di, ho, mi;

                                cout << "Es necesario ingresar la fecha y hora del sistema" << '\n';

                                cout << "ingrese el año: ";
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

                        }
                        break;

                        case 4: {

                                cout << "CARGA DE DATOS DE PRUEBA";
                                cout << '\n';
                        }
                        break;

                        case 5: {
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