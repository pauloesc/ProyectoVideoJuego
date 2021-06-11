# --------------------------------------------------------------------

#FALTA AGREGAR MODULOS DE FABRICA E INTERFACES

#  Makefile de laboratorio cuatro.

#  Laboratorio de Programación 4.
#  InCo-FIng-UDELAR

# Define un conjunto de reglas.
# Cada regla tiene un objetivo, dependencias y comandos.
#objetivo: dependencia1 dependencia2...
#	comando1
#	comando2
#	comando3
# (antes de cada comando hay un tabulador, no espacios en blanco).
# Se invoca con
#make objetivo
# para que se ejecuten los comandos.
#
# Si `objetivo' es un archivo los comandos se ejecutan solo si no está
# actualizado (esto es, si su fecha de actualización es anterior a la de alguna
# de sus dependencias.
# Previamente se aplica la regla de cada dependencia.



# PARA ESTUDIAR USO DE MEMORIA EJECUTAR:
# valgrind --leak-check=yes ./main




# --------------------------------------------------------------------

# Objetivo predeterminado (no se necesita especificarlo al invocar `make').
all: main

# Objetivos que no son archivos.
.PHONY: all clean_bin clean_test clean 

MODULOS = Abandona Categoria ControladorEstadistica ControladorPartida ControladorUsuario ControladorVideojuego ControladorSuscripciones Desarrollador Estadistica Jugador Partida PartidaIndividual PartidaMultijugador Puntaje Reloj Suscripcion SuscripcionTemporal SuscripcionVitalicia TotalHorasJugadas TotalJugadoresSuscriptos Usuario Videojuego DtCategoria DtDesarrollador DtEstadisticaDeSegundoTipo DtFecha DtJugador DtPago DtPartida DtPartidaEnCurso DtPartidaIndividual DtPartidaIndividualEnCurso DtPartidaMultijugador DtPartidaMultijugadorEnCurso DtSuscripcion DtUsuario DtVideojuego DataEstadisticaDeSegundoTipo DataEstadistica DtInfoEspecifica DtVideojuegoResumido

# directorios
HDIR    = include
CPPDIR  = source
ODIR    = obj

TESTDIR = test

# extensión de los archivos
EXT = cpp
# compilador
CC = g++ # gcc -x c 
LD = g++ # gcc
# opciones de compilación
CCFLAGS = -Wall -Werror -I$(HDIR) -O0 -g # -DNDEBUG
# -DNDEBUG
# se agrega esta opción para que las llamadas a assert no hagan nada.



# cadena de archivos, con directorio y extensión
HS   = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.$(EXT))
OS   = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=main
EJECUTABLE=main


$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).$(EXT)
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .c
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
$(ODIR)/%.o: $(CPPDIR)/%.$(EXT) $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(LD) $(CCFLAGS) $^ -o $@




# borra binarios
clean_bin:
	@rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS)

# borra resultados de ejecución y comparación
#clean_test:
#	@rm -f $(TESTDIR)/*.sal $(TESTDIR)/*.diff

# borra binarios, resultados de ejecución y comparación, y copias de respaldo
#clean:clean_test clean_bin
#	@rm -f *~ $(HDIR)/*~ $(CPPDIR)/*~ $(TESTDIR)/*~



check-syntax:
	gcc -o nul -S ${CHK_SOURCES}
