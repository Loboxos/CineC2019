#include  "TAD_RegPeliculas.h"
#include "TAD_Cadena.h"
#include  <stdio.h>
#include <stdlib.h>    
#include <string.h>   
#define cap_max 50

RegPelicula Cargar_una_Peli(int sala){
	RegPelicula Aux;
	fflush(stdin);
	printf("\nIngrese el nombre de la pelicula: ");
	LeeCad(Aux.nom_peli);
	fflush(stdin);
	printf("\nIngrese el genero de la pelicula: ");
	LeeCad(Aux.genero_peli);
	fflush(stdin);
	Aux.num_sala=sala;
	fflush(stdin);
	printf("\nIngrese el precio individual de la entrada: ");
	scanf("%ld",&Aux.precio);
	fflush(stdin);
	Aux.entradas_a_vender=cap_max;
	fflush(stdin);
	Aux.entradas_vendidas=0;
	fflush(stdin);
	return Aux;
}

int compara_NomPeL(RegPelicula Aux1,RegPelicula Aux2){
	return strcmp(Aux1.nom_peli,Aux2.nom_peli);
}
void Mostrar_RegPelicula(RegPelicula Aux){
	printf("\nPelicula: %s ", Aux.nom_peli);  
	printf("\nGenero: %s", Aux.genero_peli);
	printf("\nSala: %d", Aux.num_sala);
	printf("\nPrecio: $%ld",Aux.precio);
	printf("\nEntradas vendidas: %d",Aux.entradas_vendidas);
	printf("\nAsientos disponibles:%d\n",Aux.entradas_a_vender);
}
int retornarsala(RegPelicula Aux){
return Aux.num_sala;
	
}
void mostrar_LCartelera(RegPelicula Aux){
	printf("\nPelicula: %s ", Aux.nom_peli);  
	printf("\nSala: %d", Aux.num_sala);
}
void Modificar_atributos(RegPelicula *Aux){
		printf("\nEl nombre actual de la pelicula es: %s",Aux->nom_peli);
		printf("\nIngrese el nombre correctamente: ");
		fflush(stdin);
		LeeCad(Aux->nom_peli);
		printf("\nEl genero actual de la pelicula es: %s",Aux->genero_peli);
		printf("\nIngrese el genero correctamente: ");
		fflush(stdin);
		LeeCad(Aux->genero_peli);
		printf("\nEl numero actual de la sala es: %d",Aux->num_sala);
		printf("\nIngrese el numero de sala correctamente: ");
		fflush(stdin);
		scanf("%d",&Aux->num_sala);
		printf("\nEl precio actual de las entradas es: %ld",Aux->precio);
		printf("\nIngrese el precio correctamente: ");
		fflush(stdin);
		scanf("%ld",&Aux->precio);
		fflush(stdin);
		Aux->entradas_a_vender=cap_max;
		fflush(stdin);
		Aux->entradas_vendidas=0;
		fflush(stdin);
}
void retornanompeli(RegPelicula Aux,TCad cad){
	strcpy(cad,Aux.nom_peli);
}
