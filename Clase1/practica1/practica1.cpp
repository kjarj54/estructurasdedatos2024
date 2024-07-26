#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int **v;

    v = new int *[4];

    v[0] = (int *)2;
    v[1] = (int *)3;
    v[2] = (int *)7;
    v[3] = (int *)11;

    for (int i = 0; i < 4; i++)
    {
        cout << v[i] << endl;
    }

     
    int *t;
    t = new int [4];

    for (int i = 0; i < 4; i++)
    {
        t[i] = v[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                t[i][j] = v[i];  
            }
            else
            {
                t[i][j] = v[i] * (j + 1);  
            }
        }
        
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    



    return 0;
}
