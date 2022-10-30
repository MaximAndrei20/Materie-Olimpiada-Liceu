#include <bits/stdc++.h>

using namespace std;

ifstream f("aint.in");
ofstream g("aint.out");

const int Nmax=1e5, Inf=0x3f3f3f3f;
int aint[4*Nmax+2],n,m;

void buildAint(int nod, int st, int dr)
{
    if(st==dr)
    {
        f >> aint[nod];
        return;
    }
    int m=(st+dr) >> 1;
    buildAint(nod*2,st,m);
    buildAint(nod*2+1,m+1,dr);

    aint[nod]=min(aint[nod*2],aint[nod*2+1]);
}

void updateAint(int nod, int st, int dr, int poz, int val)
{
    if(st==dr)
    {
        aint[nod]=val;
        return;
    }
    int m=(st+dr) >> 1;
    if(poz<=m)
        updateAint(nod*2,st,m,poz,val);
    else updateAint(nod*2+1,m+1,dr,poz,val);

    aint[nod]=min(aint[nod*2],aint[nod*2+1]);
}

int queryAint(int nod, int st, int dr, int a, int b)
{
    if(a<=st && b>=dr)
        return aint[nod];
    int m=(st+dr) >> 1;
    int ans=Inf;
    if(a<=m)
        ans=min(ans,queryAint(nod*2,st,m,a,b));
    if(m+1<=b)
        ans=min(ans,queryAint(nod*2+1,m+1,dr,a,b));
    return ans;
}

int main()
{
    f >> n >> m;
    buildAint(1,1,n);
    while(m--)
    {
        int op,a,b;
        f >> op >> a >> b;
        if(op==1)
            updateAint(1,1,n,a,b);
        else if(op==2)
            g << queryAint(1,1,n,a,b) << "\n";
    }
    return 0;
}
