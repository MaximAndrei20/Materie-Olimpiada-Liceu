#include <iostream>
#include <fstream>

using namespace std;

ifstream f("roy-floyd.in");
ofstream g("roy-floyd.out");

int n,m,inf=0x3F3F3F3F,a[103][103];

int main()
{
    f >> n >> m;
    for(int q=1; q<=m; q++)
    {
        int i,j,c;
        f >> i >> j >> c;
        a[i][j]=c;
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(a[i][j]==0 && i!=j)
                    a[i][j]=inf;
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
            }
    for(int i=1; i<=n; i++, g << "\n")
        for(int j=1; j<=n; j++)
        {
            if(a[i][j]==inf)
                a[i][j]=-1;
            g << a[i][j] << " ";
        }
    return 0;
}
