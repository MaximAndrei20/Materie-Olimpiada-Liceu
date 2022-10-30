#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("kruskal.in");
ofstream g("kruskal.out");

struct muchie{
    int i,j,w;
};

muchie M[1002], A[1002];
int n,m,T[1002],cnt=0,S=0;
int comp(muchie a, muchie b) {return a.w<b.w;}
void init(){for(int i=1;i<=n; i++)T[i]=i;}
void kruskal();
int radacina(int a);
void leaga(int a,int b){T[a]=T[b];}

int main()
{
    f >> n >> m;
    for(int i=1, x, y, w; i<=m; i++)
    {
        f >> x >> y >> w;
        M[i].i=x;
        M[i].j=y;
        M[i].w=w;
    }
    sort(M+1,M+m+1,comp);
    init();
    kruskal();
    g << S << "\n";
    for(int i=1; i<n; i++)
        g << A[i].i << " " << A[i].j << "\n";
    return 0;
}

void kruskal()
{
    int r1,r2;
    for(int i=1; i<=m; i++)
    {
        r1=radacina(M[i].i);
        r2=radacina(M[i].j);
        if(r1!=r2)
        {
            S+=M[i].w;
            A[++cnt]=M[i];
            leaga(r1,r2);
        }
    }
}

int radacina(int a)
{
    if(a==T[a]) return a;
    return T[a]=radacina(T[a]);
}
