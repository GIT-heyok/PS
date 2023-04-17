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
const ll MOD = 1e6;

/*
1. indexed from 0 to n,
index 0 is considered as an empty string.
Therefore, the value of memo[0][i]=i and memo[i][0]=i
for all values.
2. if s1[i]==s2[j], memo[i][j]=memo[i-1][j-1]
else memo[i][j] = min(memo[i-1][j], memo[i][j-1], memo[i-1][j-1])
*/

int main(){
    FAST
    string input, target;
    cin >> input >> target;
    int in_sz = input.length(), tar_sz = target.length();
    int memo[in_sz+1][tar_sz+1];
    for (int i = 0; i <= in_sz; i++)
    {
        memo[i][0]=i;
    }
    for (int j = 0; j <= tar_sz; j++)
    {
        memo[0][j]=j;
    }
    for (int i = 1; i <= in_sz; i++)
    {
        for (int j = 1; j <= tar_sz; j++)
        {
            if(input[i-1]==target[j-1]){
                memo[i][j] = memo[i-1][j-1];
            }
            else{
                memo[i][j] = min(memo[i-1][j-1], min(memo[i-1][j], memo[i][j-1]))+1;
            }
        }   
    }
    cout<<memo[in_sz][tar_sz]<<endl;
    
    
    
}