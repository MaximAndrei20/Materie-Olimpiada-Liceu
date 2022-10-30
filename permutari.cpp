#include <fstream>

using namespace std;

ifstream cin("permutari.in");
ofstream cout("permutari.out");

int n,x[10],p[10];

void afisare()
{
    for(int i=1; i<=n; i++)
        cout << x[i] << " ";
    cout << "\n";
}

void back(int k)
{
    for(int i=1; i<=n; i++)
        if(!p[i])
    {
        p[i]=1;
        x[k]=i;
        if(k<n)
            back(k+1);
        else
            afisare();
        p[i]=0;
    }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}
