#include<iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
// Numero de nodos
#define V 8
int mat[V][V];
char letra[8]={'A','B','C','D','E','F','G','H'};
int nodos[V]; 
int peso[V];
bool evaluar[V];

int minimoPeso()
{
	int min = 0, minimo;
	
	for (int v = 0; v < V; v++)
		 if (evaluar[v] == false && peso[v] > min)
			 min = peso[v], minimo = v;
			 
			 return minimo;
}

int ImprimeArbol()
{
	printf("Nodos   Peso\n");
	for (int i = 1; i < V; i++)
		 cout<< letra[nodos[i]]<<" - "<< letra[i]<<"    "<< mat[i][nodos[i]]<<endl;
}


void arbolMinimo()
{
	
	
	for (int i = 0; i < V; i++)
	{
		peso[i] = 0;
		evaluar[i] = false;
	}
	
	peso[0] = 0;     
	nodos[0] = -1;
	
	for (int i = 0; i < V; i++)
	{
		int u = minimoPeso();
		evaluar[u] = true;
		for (int v = 0; v < V; v++){
			if (mat[u][v]!=0 && evaluar[v] == false && mat[u][v] >  peso[v]){
				nodos[v]  = u;
				peso[v] = mat[u][v];
			}
		}
	}
	ImprimeArbol();
}




int main()
{
	
	mat[0][2]=6;
	mat[0][4]=16;
	mat[0][6]=16;
	mat[1][4]=5;
	mat[1][6]=5;
	mat[2][1]=4;
	mat[3][0]=5;
	mat[3][1]=5;
	mat[3][2]=3;
	mat[3][5]=2;
	mat[4][5]=5;
	mat[5][7]=4;
	mat[6][3]=2;
	mat[7][4]=5;
	mat[7][6]=5;
	//---------------**
	mat[2][0]=6;
	mat[4][0]=16;
	mat[6][0]=16;
	mat[4][1]=5;
	mat[6][1]=5;
	mat[1][2]=4;
	mat[0][3]=5;
	mat[1][3]=5;
	mat[2][3]=3;
	mat[5][3]=2;
	mat[5][4]=5;
	mat[7][5]=4;
	mat[3][6]=2;
	mat[4][7]=5;
	mat[6][7]=5;
	cout<<"     ";
	for (int i = 0; i < 8; i++) {
		cout.width(4);
		cout<<letra[i];
	}
	cout<<endl;
	for (int i = 0; i < 8; i++) {
		
		for (int j = 0; j < 8; j++) {
			
			if (j==0)
			{
				cout.width(4);
				cout<<letra[i]<<" ";	
			}
			cout.width(4);
			cout<<mat[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	//Arbol Minimo
	//Prim
	arbolMinimo();
	
	return 0;
}
