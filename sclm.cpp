#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("inaltime.in");
ofstream g("inaltime.out");

int n,k, t[102],niv[101];

void dfs(int x,int nivel)
{
    nivel++;
    for (int i=1; i<=n; i++)
        if(t[i]==x)
        {
            niv[i]=nivel;
            dfs(i,nivel);
        }
}

int rad;

int main()
{
    f >> n;

    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    > q;

    for(int i=1; i<=n; i++)
    {
        f >> t[i];
        if(t[i]==0)
            rad=i;
    }
    niv[rad]=0;

    dfs(rad,1);

    for(int i=1; i<=n; i++)
            q.push(make_pair(niv[i],i));
    int prev=0;
    g << q.top().second << " ";
    q.pop();
    while(!q.empty())
    {
        if(prev!=q.top().first)
            g << "\n", prev=q.top().first;
        g << q.top().second << " ";
        q.pop();
    }
    return 0;
}
