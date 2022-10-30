#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream f("heap.in");
ofstream g("heap.out");

bool P[101];
int n,m,nrCTC=0;
vector <int> G[105],GT[105];
stack <int> S;
bool onStack[101];
int ids[102],low[102],id=0;

void dfs(int nod);

int main()
{
    f >> n >> m;
    for(int i=1, x, y; i<=m; i++)
        f >> x >> y, G[x].push_back(y);
    for(int i=1; i<=n; i++)
        if(!P[i])
            dfs(i);
    g << nrCTC;
    return 0;
}

void dfs(int nod)
{
    P[nod]=1;
    S.push(nod);
    onStack[nod]=1;
    ids[nod]=low[nod]= ++id;

    for(auto nxt : G[nod])
    {
        if(!P[nxt])
            dfs(nxt);
        if(onStack[nxt])
            low[nod]=min(low[nod],low[nxt]);
    }
    if(ids[nod]==low[nod])
    {
        while(S.top()!=nod)
        {
            auto x=S.top();
            low[x]=ids[nod];
            onStack[x]=0;
            S.pop();
        }
        nrCTC++;
    }
}
