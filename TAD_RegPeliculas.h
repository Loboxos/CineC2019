#ifndef TAD_REGPELICULAS_H
#define TAD_REGPELICULAS_H
#include "TAD_Cadena.h"

typedef struct{             
	TCad nom_peli,genero_peli;
	int num_sala;
	long precio;
	int entradas_vendidas,entradas_a_vender;
}RegPelicula;

RegPelicula Cargar_una_Peli(int );
int compara_NomPeL(RegPelicula,RegPelicula);
void Mostrar_RegPelicula(RegPelicula);
void modificar_CantDISPdeAsientos(RegPelicula);
int retornarsala(RegPelicula);
void mostrar_LCartelera(RegPelicula );
void Modificar_atributos(RegPelicula *);
void retornanompeli(RegPelicula ,TCad);
#endif
