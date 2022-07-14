#include "TAD_Cadena.h"
#include <stdio.h>
#include <string.h>

void LeeCad(TCad C){	
	char c;
	int j=0;
	c=getchar();
	while (c!=EOF && c!='\n' && j<TamMax-1)
	{ 
		C[j]=c;
		j++;
		c=getchar(); 
	}
	C[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}
	
	
void MostrarCad(TCad C){
		printf("%s", C);
}
int ComparaCad(TCad C1, TCad C2){
			return strcmp(C1,C2);
		}

