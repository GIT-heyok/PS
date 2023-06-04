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
//#define endl '\n'
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
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e9 + 7;
/*
    There are at most 26 gems.
    first, check for which set the gem is included in for A and B;
    this process can be shortened with randomization.'
    second, if there is a new set of gem, ask.
    if found 1, break and print 1
    else print 0
*/

int main() {
    FAST
    srand(unsigned(time(0)));
    int n, s;
    cin >> n >> s;
    int A[26], B[26];
    int cntA = 0, cntB = 0;
    bool chk = false;
    for (int i = 1; i <= n; i++)
    {
        bool chkNewA = true;
        vector<int> vecA, vecB;
        for (int j = 0; j < cntA; j++)
        {
            vecA.push_back(j);
        }
        for (int j = 0; j < cntB; j++)
        {
            vecB.push_back(j);   
        }
        
        random_shuffle(all(vecA));
        random_shuffle(all(vecB));
        for (int j:vecA)
        {
            cout<<"? A "<<A[j]<<" A "<<i<<endl;
            int temp;
            cin >> temp;
            if(temp==1){
                chkNewA = false;
                break; 
            }
        }
        if(chkNewA){
            A[cntA] = i;
            cntA++;
        }
        bool chkNewB = true;
        for (int j:vecB)
        {
            cout<<"? B "<<B[j]<<" B "<<i<<endl;
            int temp;
            cin >> temp;
            if(temp==1){
                chkNewB = false;
                break; 
            }
        }
        
        if(chkNewB){
            B[cntB] = i;
            cntB++;
        }
        for (int j = cntA-(chkNewA); j < cntA; j++)
        {
            for (int l = 0; l < cntB; l++)
            {
                cout<<" ? A "<<A[j]<<" B "<<B[l]<<endl;
                int temp;
                cin >> temp;
                if(temp==1)chk = true;
            }
            
        }
               
        for (int j = cntB-(chkNewB); j < cntB; j++)
        {
            for (int l = 0; l < cntA; l++)
            {
                cout<<" ? A "<<A[l]<<" B "<<B[j]<<endl;
                int temp;
                cin >> temp;
                if(temp==1)chk = true;
            }
            
        }
        if(chk)break;
        
    }
    cout<<"! "<<chk<<endl;
    
}
