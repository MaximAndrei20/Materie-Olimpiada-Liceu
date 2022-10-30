#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const int Nmax=1e3;
void dp(int amax, int bmax, int A[], int B[], int D[][Nmax+25])
{
    for(int i=1; i<=amax; i++)
        for(int j=1; j<=bmax; j++)
            (A[i] == B[j]) ? D[i][j]=D[i-1][j-1]+1 : max(D[i-1][j], D[i][j-1]);
}

int n, m, A[Nmax+25], B[Nmax+25], best[Nmax+25], D[Nmax+25][Nmax+25];

int main()
{
    fast();
    f >> n >> m;
    for(int i=1; i<=n; i++)
        f >> A[i];
    for(int i=1; i<=m; i++)
        f >> B[i];
    dp(n,m,A,B,D);
    int i=n, j=m, cnt=0;
    while(i)
    {
        if(A[i]==B[j])
            best[++cnt]=A[i], i--, j--;
        else if(D[i-1][j]<D[i][j-1])
            j--;
        else i--;
    }
    for(int i=1; i<=n; i++, cout << "\n")
        for(int j=1; j<=m; j++)
            cout << D[i][j] << " ";
    g << cnt << "\n";
    for(i=cnt; i>=1; i--)
        g << best[i] << " ";
    return 0;
}
