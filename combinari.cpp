#include <fstream>

using namespace std;

ifstream cin("combinari.in");
ofstream cout("combinari.out");

int n,k,x[20];

void afisare()
{
    for(int i=1; i<=k; i++)
        cout << x[i] << " ";
    cout << "\n";
}

void back(int pas)
{
    for(int i=x[pas-1]+1; i<=n-k+pas; i++)
    {
        x[pas]=i;
        if(pas<k)
            back(pas+1);
        else afisare();
    }
}

int main()
{
    cin >> n >> k;
    back(1);
    return 0;
}
