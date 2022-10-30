#include <iostream>

using namespace std;

int n,m,a[105][105];

int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int ii,jj;
        cin >> ii >> jj;
        a[ii][jj]=1;
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(a[i][j]==0)
                    a[i][j]=a[i][k]*a[k][j];
    for(int i=1; i<=n; i++, cout << "\n")
            for(int j=1; j<=n; j++)
                cout << a[i][j] << " ";
    return 0;
}
