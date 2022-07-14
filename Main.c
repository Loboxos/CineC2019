#include "TAD_LisPeliculas.h"
#include <stdio.h>
#include <stdlib.h>


void Menu_Recursivo(TlistReg_Pelicula );

int main(){
	TlistReg_Pelicula Lpeliculas;
	Lpeliculas=inicializarLista();
	Menu_Recursivo(Lpeliculas);
	return 0;
}
	
	void Menu_Recursivo(TlistReg_Pelicula ListPeliculas){
		int opcion;
		//system("cls");
		printf("\n ------- Menu Principal -------\n");
		printf("\n 1 -> Agregar una peliculas a la cartelera");
		printf("\n 2 -> Eliminar una pelicula a la cartelera");
		printf("\n 3 -> Editar datos de una pelicula cargada");
		printf("\n 4 -> Ingresar la cantidad de entradas que se vendieron en una pelicula y modificar la cantidad disponible de lugares en la sala");
		printf("\n 5 -> Ordenar las peliculas alfabeticamente y mostrar");
		printf("\n 0 -> Salir \n");
		printf("\nSu opcion es: ");
		fflush(stdin);
		scanf("%d",&opcion);
		switch(opcion){
		case 1:
			system("cls");
			Agregar_Pelicula(&ListPeliculas);
			system("pause");
			Menu_Recursivo(ListPeliculas);
			break;
		case 2:
			system("cls");
			Sacar_PeliculaxSala(&ListPeliculas);
			system("pause");
			Menu_Recursivo(ListPeliculas);
			break;
		case 3:
			system("cls");
			Modificar_datosPeli(&ListPeliculas );
			system("clear || cls");
			Menu_Recursivo(ListPeliculas);
		    break;
		case 4:
			//system("cls");
			ControlDeEntradas(&ListPeliculas );
			Menu_Recursivo(ListPeliculas);
			break;
		case 5:
			system("cls");
			Mostrar_OrdenadoALF(ListPeliculas );
			system("pause");
			Menu_Recursivo(ListPeliculas);
			break;
		case 0:
			printf("\nMuchas gracias, vuelva pronto.\n\n");
			break;
		default:
			printf("\nOpcion no valida, vuelva a ingresar otra vez.\n\n");
			system("pause");
			Menu_Recursivo(ListPeliculas);
		}
	}
