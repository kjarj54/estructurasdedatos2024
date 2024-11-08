//---------------------------------------------------------------------------


#include <iostream>
#include <conio.h>

//---------------------------------------------------------------------------

using namespace std;
int mat[8][8];
int let[8][8];
int lista[8];
int listamayor[8];
char letra[8]={'A','B','C','D','E','F','G','H'};
int suma=999;
int contp=0;
int cont=0;
void insertar(int x)
{
	lista[contp]=x;
	contp++;
}
int saca()
{
	int aux;
	contp--;
	aux=lista[contp];
	lista[contp]=NULL;
	
	return aux;
}
void Floyd()
{
	
}
void camino(int ini, int fin, int x)
{
	bool band=false;
	for (int i = 0; i < contp; i++) {
		if (ini==lista[i]) {
			band=true;
		}
	}
	insertar(ini);
	if (!band) {
		if (ini==fin) {

				if (x<suma) {
					suma=x;
					for (int i = 0; i < 8; i++) {
						listamayor[i]=-1;
					}
					//cout<<endl;
					for (int i = 0; i < contp; i++) {
						listamayor[i]=lista[i];
						//cout<<letra[listamayor[i]];
						//cout<<listamayor[i];
					}
					//cout<<suma;
				}
		}
		else
		{
			for (int i = 0; i < 8; i++) {
				if (mat[ini][i]>0) {
					camino(i,fin,x+mat[ini][i]);
				}
			}
		}
	}
	saca();
}
int main()
{
	for (int i = 0; i < 8; i++) {
		
		for (int j = 0; j < 8; j++) {
			mat[i][j]=INT_MIN;	
			if (i==j)
			{
				mat[i][j]=INT_MIN;
			}
		}
	}
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
	for (int i = 0; i < 8; i++) {
		
		for (int j = 0; j < 8; j++) {
		   let[i][j]=j;	
		}
	}
	for (int i = 0; i < 8; i++) {
		
		for (int j = 0; j < 8; j++) {
			cout.width(10);
			cout<<letra[let[i][j]];
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"  ";
	for (int i = 0; i < 8; i++) {
		cout.width(10);
		cout<<letra[i];
	}
	cout<<endl;
	for (int i = 0; i < 8; i++) {
	
		for (int j = 0; j < 8; j++) {
			cout.width(10);
			if (j==0)
			{
				cout.width(10);
				cout<<letra[i]<<" ";	
			}
			if (mat[i][j]==INT_MAX)
			{
				cout<<0;
			}
			else
			if (mat[i][j]==INT_MIN)
			{
				cout<<-1;
			}
			else
			cout<<mat[i][j];
		}
		cout<<endl;
	}
	camino(0,5,0);
	cout<<endl<<listamayor[1]<<endl;
	for (int i = 0; i < 8; i++) {
		if (listamayor[i]>=0) {
         	cout.width(4);
			cout<<letra[listamayor[i]];
			cout<<listamayor[i];
		}

	}
	cout<<suma<<endl;
	cout<<cont;
	getch();
	return 0;
}
//---------------------------------------------------------------------------
