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
const int MAX = 100;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
bool chk[201][201][201];
int a, b, c;
void dfs(int aCur, int bCur, int cCur){
    // cout<<aCur<<" "<<bCur<<" "<<cCur<<endl;
    if(!chk[aCur][bCur][cCur]){
        chk[aCur][bCur][cCur] = true;
        //AtoB
        if(bCur+aCur<=b){
            dfs(0,aCur+bCur, cCur);
        }
        else{
            dfs(aCur-(b-bCur),b,cCur);
        }

        //AtoC

        if(cCur+aCur<=c){
            dfs(0,bCur, aCur+cCur);
        }
        else{
            dfs(aCur-(c-cCur),bCur,c);
        }
        //BtoA

        if(aCur+bCur<=a){
            dfs(aCur+bCur,0,cCur);
        }
        else{
            dfs(a,bCur-(a-aCur),cCur);
        }
        //BtoC

        if(bCur+cCur<=c){
            dfs(aCur,0,bCur+cCur);
        }
        else{
            dfs(aCur,bCur-(c-cCur),c);
        }
        //CtoA

        if(aCur+cCur<=a){
            dfs(aCur+cCur,bCur,0);
        }
        else{
            dfs(a,bCur,cCur-(a-aCur));
        }
        //CtoB

        if(bCur+cCur<=b){
            dfs(aCur,bCur+cCur,0);
        }
        else{
            dfs(aCur,b,cCur-(b-bCur));
        }
    }
}
int main()
{
    FAST
    cin >> a >> b>> c;
    dfs(0,0,c);
    for (int i = 0; i <= c; i++)
    {
        bool chkk = false;
        for (int j = 0; j <= b; j++)
        {
                if(chk[0][j][i]){chkk=true;}
            
        }
        if(chkk)cout<<i<<" ";
    }
    cout<<endl;
    
}