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
const int inf = 1234567890;
const ll MOD = 1000;

int main(){
    FAST
    int n, k;
    cin >> n >> k;
    bool memo[n+1][n+1][n+1][k+1];
    memset(memo, false, sizeof(memo));
    memo[0][0][0][0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a < n+1; a++)
        {
            for (int b = 0; b < n+1; b++)
            {
                for (int j = 0; j < k+1; j++)
                {
                    if(memo[i][a][b][j]){
                        if(a+1<=n){
                            memo[i+1][a+1][b][j]=true;
                        }
                        if(b+1<=n&&j+a<=k)
                            memo[i+1][a][b+1][j+a]=true;
                        if(j+a+b<=k)
                            memo[i+1][a][b][j+a+b]=true;
                    }
                }
                
            }
            
        }
        
    } //Generate memo array

    bool chk = false;
    int aTemp = -1, bTemp = -1;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if(memo[n][i][j][k]){
                chk = true;
                aTemp = i;
                bTemp = j;
            }
        }
    } //checking if string exists;

    if(!chk){
        cout<<-1<<endl;
    }
    else{
        int curDepth = n;
        string ans = "";
        int curK = k;
        while(curDepth>0){
            if(aTemp-1>=0&&memo[curDepth-1][aTemp-1][bTemp][curK]){
                ans+="A";
                aTemp--;                
            }
            else if(bTemp-1>=0&&memo[curDepth-1][aTemp][bTemp-1][curK-aTemp]){
                ans+="B";
                bTemp--;
                curK-=aTemp;
            }
            else{
                ans+="C";
                curK-=aTemp+bTemp;
            }
            curDepth--;
        }
        reverse(all(ans));
        cout<<ans<<endl;
    } //reconstruct
    
    
}