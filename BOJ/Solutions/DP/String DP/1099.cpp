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

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 9901;

/*
base case: dp[0]=0, else inf
1. dp[i]: minimum answer till i,
if nothing is correct, dp[i]=inf
else dp[i]=max(dp[i], dp[i-s]+edit(s))
2. should be cautious of string cause index 
has to start with 0 but dp is 1
*/
int main(){
    FAST
    string orig;
    cin >> orig;
    int n;
    cin >> n;
    string needles[n];
    for (int i = 0; i < n; i++)
    {
        cin >> needles[i];
    }
    int alphaChk[n][26]; //number of alphabets
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            alphaChk[i][j]=0;
        }
        for (int j = 0; j < needles[i].length(); j++)
        {
            alphaChk[i][needles[i][j]-'a']++;
        }   
    }
    
    int orsz = orig.length();
    int memo[orsz+1];
    fill(memo, memo+orsz+1, inf);
    memo[0]=0;
    for (int i = 1; i <= orsz; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int lastIdx = i-needles[j].length()-1;
            //cout<<i<<" "<<j<<" "<<lastIdx<<endl;
            if(lastIdx>=-1){
                int tempAlpha[26];
                for (int k = 0; k < 26; k++)
                {
                    tempAlpha[k]=alphaChk[j][k];
                }
               // cout<<endl;
                bool chk = true;
                int editSz = 0;
                int cntt=needles[j].length()-1;
                for (int k = i-1; k >lastIdx; k--)
                {
                    //cout<<needles[j][cntt]<<" "<<orig[k]<<endl;
                    if(needles[j][cntt]!=orig[k])editSz++;
                    tempAlpha[orig[k]-'a']--;
                    //cout<<orig[k]<<":"<<tempAlpha[orig[k]-'a']<<endl;
                    if(tempAlpha[orig[k]-'a']<0){
                        chk=false;
                    }
                    cntt--;
                }
                if(chk){
                    //cout<<needles[j]<<endl;
                    memo[i] = min(memo[i], memo[lastIdx+1]+editSz);
                }
                
            }
        }
       // cout<<memo[i]<<" ";
    }
    if(memo[orsz]!=inf){
        cout<<memo[orsz]<<endl;
    }
    else cout<<-1<<endl;
    
}