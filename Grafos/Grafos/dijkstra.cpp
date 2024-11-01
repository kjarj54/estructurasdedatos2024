//#include <values>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define N 5
#define INF 999
using namespace std;
int minimo(int,int);
void mostrar(int [N][N]);

int main()
{
	int A[N][N]={ INF,  10, INF,  30, 100,
					  INF, INF,  50, INF, INF,
					  INF, INF, INF, INF,  10,
					  INF, INF,  20, INF,  60,
					  INF, INF, INF, INF, INF };

	int D[N][N],i,j,vi,min,ve,S[N]={0,0,0,0,0};

	system("CLS");
	vi=1;
	S[vi-1]=1;


	for(i=0;i<N;i++)
		D[0][i]=A[vi-1][i];

	for(j=0;j<N-1;j++)
	{
		min=INF;
		ve=0;
		for(i=0;i<N;i++)
		{
			if(D[j][i]<min && S[i]==0)
			{
				min=D[j][i];
				ve=i;
			}
		}

		S[ve]=1;

		// para mostrar S

		cout << "S = { ";
		for(i=0;i<N;i++)
		{
			if(S[i])
				cout << (i+1) << " ";
		}
		cout << "}" << endl;
		cout << "-------------------------------------" << endl;

		for(i=0;i<N;i++)
		{
			cout << "D[" << (i+1) << "] = min(D[" << (i+1);
			cout << "], D[" << (j+1) << "] + C[" << (j+1);
			cout << ", " << (i+1) << "])" << endl;
			cout << "           ";
			if(D[j][i]>=INF)
				cout << "INF";
			else
				cout << " " <<D[j][i];

			cout << "        ";
			if(D[j][ve]+A[ve][i]>=INF)
				cout << "INF";
			else
				cout << " " << D[j][ve]+A[ve][i];
			D[j+1][i]=minimo(D[j][i],D[j][ve]+A[ve][i]);

			cout << " => D[" << (i+1) << "] = ";
			if(D[j+1][i]>=INF)
				cout << "INF" << endl;
			else
				cout << D[j+1][i] << endl;

		}
	}

	cout << "Resultados parciales en D" << endl;

	mostrar(D);
	getchar();
	return 0;

}

int minimo(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}

void mostrar(int D[N][N])
{
	int i,j;

	cout << "\t";
	for(i=0;i<N;i++)
		cout << (i+1) << "\t";

	cout << endl;

	for(j=0;j<N;j++)
	{
		cout << (j+1) << "\t";
		for(i=0;i<N;i++)
		{
			if(D[j][i]==INF)
				cout << "INF\t";
			else
				cout << D[j][i] << "\t";
		}
		cout << endl;
	}
}

