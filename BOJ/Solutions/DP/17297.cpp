#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;

const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 10007;

vector<ll> messiNumber;
string ss=" ";
//Generate a messi number and subtract whenever possible
int main()
{
    FAST;
    ss+="Messi Gimossi ";
    messiNumber.push_back(0);      
    messiNumber.push_back(6);      
    messiNumber.push_back(14);
    while(true){
        ll cursz = messiNumber.size();
        ll nextMn = messiNumber[cursz-1]+messiNumber[cursz-2];
        messiNumber.push_back(nextMn);
        if(nextMn>(1LL<<31))break;
    }      
    int n;
    cin >> n;
        for (int i = messiNumber.size()-1; i >=2; i--)
        {
            if(n>messiNumber[i]){
                n-=messiNumber[i];
            }
        }
        if(n==6||n==14){
            cout<<"Messi Messi Gimossi"<<endl;
        }
        else{
            cout<<ss[n]<<endl;
        }
        
}