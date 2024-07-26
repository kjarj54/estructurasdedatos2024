#include<iostream>
using namespace std;
int **v;
int *t;
int main (int argc, char *argv[]) {
	v=new int *[4];
	v[0]=(int*)(2);
	v[1]=(int*)(3);
	v[2]=(int*)(7);
	v[3]=(int*)(11);
	t=new int [4];
	for (int i=0;i<4;i++)
	{
		t[i]=(int)v[i];
		v[i]=new int [4];
		cout<<t[i]<<" ";
	}
	cout<<endl;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			if (j==0)
			{
				v[i][j]=t[i];
			}
			else
			{
				v[i][j]=v[i][j-1]+t[i];	
			}
		}
	}
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			cout.width(4);
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
