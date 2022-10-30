#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#define Inf 0x3f3f3f3f

using namespace std;
using PI=pair<int,int> ;

ifstream f("dijkstra2.in");
ofstream g("dijkstra2.out");

vector <PI> G[100002];

int n,m,start;
int D[100002];
void dijkstra(int start);

int main()
{
    f >> n >> m >> start;
    for(int k=1,i,j,w; k<=m; k++)
    {
        f >> i >> j >> w;
        G[i].push_back({j,w});
        G[j].push_back({i,w});
    }
    for(int i=1; i<=n; i++)
        D[i]=Inf;
    dijkstra(start);
    for(int i=1; i<=n; i++)
        if(D[i]==Inf)
            g << "-1 ";
        else g << D[i] << " ";
    return 0;
}

void dijkstra(int start)
{
    priority_queue<PI, vector<PI>, greater<PI> > Q;
    D[start]=0;
    Q.push({0,start});
    while(!Q.empty())
    {
        int x=Q.top().first;
        int y=Q.top().second;
        Q.pop();
        if(x>D[y]) continue;
        for(auto nxt : G[y])
        {
            int nodnou=nxt.first;
            int costnou=nxt.second;
            if(D[nodnou]>D[y]+costnou)
            {
                D[nodnou]=D[y]+costnou;
                Q.push({D[nodnou],nodnou});
            }
        }
    }
}
