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

void Alguno()
{
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i <5; i++) {
			for (int j = 0; j < 5; j++) {
					if ((mat[i][k]!=INT_MAX&&mat[i][k]!=INT_MIN) && (mat[k][j]!=INT_MAX&&mat[i][k]!=INT_MIN))
					{
							if (mat[i][j]>(mat[i][k]+mat[k][j]))
							{
								mat[i][j]=mat[i][k]+mat[k][j];
								let[i][j]=k;
							}
					}
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 5; i++) {
		
		for (int j = 0; j <5; j++) {
			mat[i][j]=INT_MAX;	
			if (i==j)
			{
				mat[i][j]=0;
			}
		}
	}
	mat[0][1]=4;
	mat[0][2]=8;
	mat[1][0]=4;
	mat[1][2]=1;
	mat[1][3]=2;
	mat[2][0]=8;
	mat[2][3]=4;
	mat[2][4]=2;
	mat[3][1]=2;
	mat[3][2]=4;
	mat[3][4]=7;
	mat[4][3]=7;
	mat[4][2]=2;
	
	for (int i = 0; i < 5; i++) {
		
		for (int j = 0; j < 5; j++) {
		   let[i][j]=j;	
		}
	}
	for (int i = 0; i <5; i++) {
		
		for (int j = 0; j < 5; j++) {
			cout.width(10);
			cout<<letra[let[i][j]];
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"  ";
	for (int i = 0; i < 5; i++) {
		cout.width(10);
		cout<<letra[i];
	}
	cout<<endl;
	for (int i = 0; i <5; i++) {
	
		for (int j = 0; j < 5; j++) {
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
	Alguno();
	cout<<"Floyd"<<endl;
	for (int i = 0; i < 5; i++) {
		
		for (int j = 0; j < 5; j++) {
			cout.width(10);
			cout<<letra[let[i][j]];
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"  ";
	for (int i = 0; i < 5; i++) {
		cout.width(10);
		cout<<letra[i];
	}
	cout<<endl;
	for (int i = 0; i < 5; i++) {
		
		for (int j = 0; j < 5; j++) {
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
	getch();
	return 0;
}
//---------------------------------------------------------------------------
