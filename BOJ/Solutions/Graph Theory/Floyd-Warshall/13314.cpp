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

const int MAX = 101;
const ll INF = 1e16;
const int inf = 1e7;
const ll MOD = 1e9;
int main(){
    FAST
    //error is generated when the minimum distance is at mth line!
    cout<< 100 << endl;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if(i==99||j==99||(i==j)){
                cout<<0<<" ";
            }
            else{
                cout<<9<<" ";
            }
        }
        cout<<endl;
        
    }
    

    
    
    

    
}