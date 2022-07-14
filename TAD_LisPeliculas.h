#ifndef TAD_LISPELICULAS_H
#define TAD_LISPELICULAS_H
#include "TAD_RegPeliculas.h"
#define TamMaxV 30
typedef RegPelicula Tlist_Peliculas[TamMaxV];

typedef struct{
	Tlist_Peliculas pelicula;
	int Tam;
}TlistReg_Pelicula;

TlistReg_Pelicula inicializarLista();
void Agregar_Pelicula(TlistReg_Pelicula* );
void Sacar_PeliculaxSala(TlistReg_Pelicula *);
void Mostrar_OrdenadoALF(TlistReg_Pelicula );
void Modificar_datosPeli(TlistReg_Pelicula *);
void ControlDeEntradas(TlistReg_Pelicula *);


#endif
