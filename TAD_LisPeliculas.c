#include "TAD_LisPeliculas.h"
#include <stdio.h>
#define cap_max 50
TlistReg_Pelicula inicializarLista(){
	TlistReg_Pelicula Aux;
	Aux.Tam=0;
	return Aux;
}
int busbin_rec(Tlist_Peliculas pelicula,int ini,int fin ,int buscado){
	int m=(ini+fin)/2;
	
	if (ini>fin) 
		return -1;
	else 
		if(retornarsala(pelicula[m]) == buscado)
		return m;
		else 
			if (buscado > retornarsala(pelicula[m]))
	           return busbin_rec(pelicula,m+1,fin,buscado);
	        else 
				return busbin_rec(pelicula,ini,m-1,buscado);
	
}
void ordenarbaraja(TlistReg_Pelicula *Aux){
	int j,tam;
	tam=Aux->Tam;
	j=tam-1;
	fflush(stdin);
	Aux->pelicula[0]=Aux->pelicula[tam];
	fflush(stdin);
	while (retornarsala(Aux->pelicula[0])<retornarsala(Aux->pelicula[j])){
		Aux->pelicula[j+1]=Aux->pelicula[j];
		j--;
	}
	Aux->pelicula[j+1]=Aux->pelicula[0];
	}

	
void Agregar_Pelicula(TlistReg_Pelicula *Aux){
	int salaingresada,pos;	
	    Aux->Tam+=1;
		do{
		printf("\ningrese un nro de sala: ");
		scanf("%d",&salaingresada);
        pos=busbin_rec(Aux->pelicula,1,Aux->Tam,salaingresada);
		if (pos==-1){
			printf("Ingrese la nueva pelicula:\n\n");
			Aux->pelicula[Aux->Tam]=Cargar_una_Peli(salaingresada);	
			printf("Nueva pelicula agregada.\n\n");
			ordenarbaraja(Aux);
		}else 
			printf("sala duplicada");
		}while (pos>0);
		
	
}
void Eliminar_Recu(Tlist_Peliculas Aux,int Tam,int pos){
	
	    if (pos!=Tam){
			Aux[pos]=Aux[pos+1];
			Eliminar_Recu(Aux,Tam,pos+1);
		}
	}

void Sacar_PeliculaxSala(TlistReg_Pelicula *Aux){
		int salaingresada,pos;
		printf("ingrese sala a eliminar:");
		scanf("%d",&salaingresada);
		pos=busbin_rec(Aux->pelicula,1,Aux->Tam,salaingresada);
		if (pos>0){
			Eliminar_Recu(Aux->pelicula,Aux->Tam,pos);
			Aux->Tam=Aux->Tam-1;
		}
		else printf("la sala no se encuentra");
}
		



void Ordenar_PeliculasALFqsort(Tlist_Peliculas a,int ini,int fin){
	int izq,der,med;
	TCad nom1,nom2;
	RegPelicula piv;
	if (ini<fin)
	{
		piv=a[ini];
		izq=ini;
		der=fin;
		while (izq<der)
		{
			retornanompeli(a[der],nom1);
			retornanompeli(piv,nom2);
			while(der>izq && (ComparaCad(nom1,nom2)>0)){
				der--;
				retornanompeli(a[der],nom1);
			}
			if(der>izq)
			{
				a[izq]=a[der];
				izq++;
			}
			retornanompeli(a[izq],nom1);
			
			while (izq<der && (ComparaCad(nom1,nom2)<0)){
				izq++;
				retornanompeli(a[izq],nom1);
			}
				if(izq<der)
			{
				a[der]=a[izq];
				der--;
			}
		}
		a[der]=piv;
		med=der;
		Ordenar_PeliculasALFqsort(a,ini,med-1);
	Ordenar_PeliculasALFqsort(a,med+1,fin);
    }
}
	
	

void Mostrar_OrdenadoALF(TlistReg_Pelicula Aux){
	int i;
	Ordenar_PeliculasALFqsort(Aux.pelicula,1,Aux.Tam);
	for(i=1;i<=Aux.Tam;i++)
		Mostrar_RegPelicula(Aux.pelicula[i]);
}
int pelicula_a_editar(int N){ 
		int pel,band=0;
		do{
			fflush(stdin);
			printf("\nElija el numero de pelicula que desea editar: ");
			scanf("%d",&pel);
			
			if(pel<0 || pel>N) 
			band = 1;
			while(band){
				printf("ERROR! Ingrese una opcion valida: ");
				scanf("%d",&pel);
				fflush(stdin);
				if(pel>0 && pel<N) band = 0;
			}
		}while(pel<0 || pel>N);
		return pel;
	}
		
	

void mostrar_Cartelera(Tlist_Peliculas Aux,int tam){
			int i;
			for (i=1;i<=tam;i++){
				printf("\nOpcion %d_",i);
				mostrar_LCartelera(Aux[i]);
			}
		}

void Modificar_datosPeli(TlistReg_Pelicula *Aux){
	int op;
	mostrar_Cartelera(Aux->pelicula,Aux->Tam);
	fflush(stdin);
	op=pelicula_a_editar(Aux->Tam);
	fflush(stdin);
	Modificar_atributos(&Aux->pelicula[op]);
}

void Modificar_Entradas(RegPelicula *Aux,int Pos,int Asientos,int CantEntrV){
		if(CantEntrV<Asientos){
			fflush(stdin);
			
			//printf("%d",Aux[Pos].entradas_vendidas);
			Aux[Pos].entradas_vendidas = CantEntrV + Aux[Pos].entradas_vendidas;
			//printf("%d",Aux[Pos].entradas_vendidas);
			Asientos=cap_max-Aux[Pos].entradas_vendidas;
			Aux[Pos].entradas_a_vender=Asientos;
			printf("Asientos disponibles: \n || %d ||",Asientos);
			printf("\nLa cantidad de entradas vendidas son: %d\n",Aux[Pos].entradas_vendidas);
		}
		else{ 
			printf("Capacidad superada\n");
		}
	}
void ControlDeEntradas(TlistReg_Pelicula *Aux){
int CantEntrV,AsientDisp,Pos,salaingresada; 
mostrar_Cartelera(Aux->pelicula,Aux->Tam);
 fflush(stdin);
   printf("\nSeleccionar pelicula por sala:"); 
	scanf("%d",&salaingresada);
	 Pos=busbin_rec(Aux->pelicula,1,Aux->Tam,salaingresada);
	 printf("\nIngresar cant de entradas vendidas: ");
	 scanf("%d",&CantEntrV);
	 AsientDisp=cap_max-CantEntrV;
	 Modificar_Entradas(Aux->pelicula,Pos,AsientDisp,CantEntrV);
	 
}	 
