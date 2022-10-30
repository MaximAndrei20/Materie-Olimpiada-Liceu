#include <fstream>

using namespace std;

ifstream cin("aranjamente.in");
ofstream cout("aranjamente.out");

int n,k,x[10];
bool p[10];

void afisare()
{
    for(int i=1; i<=k; i++)
        cout << x[i] << " ";
    cout << "\n";
}

void back(int pas)
{
    for(int i=1; i<=n; i++)
    {
        if(!p[i])
        {
            p[i]=1;
            x[pas]=i;
            if(pas < k)
                back(pas+1);
            else afisare();
            p[i]=0;
        }
    }
}

int main()
{
    cin >> n >> k;
    back(1);
    return 0;
}
