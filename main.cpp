#include <iostream>
#include <vector>
#include <string>

using namespace std;


void menuParaDesarollador(){

        while (!termina){


                cout << "Eliga la operacion a realizar: " << '\n';
                cout << "1) Agregar categoria." << '\n';
                cout << "2) Publicar videojuego." << '\n';
                cout << "3) Eliminar videojuego." << '\n';
                cout << "4) Seleccionar estadisticas." << '\n';
                cout << "5) Ver iformacion del videojuego." << '\n';
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

                        }
                }


        }
}


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