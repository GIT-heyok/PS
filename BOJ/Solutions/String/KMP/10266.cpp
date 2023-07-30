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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
vector<int> pi(1000001);

void failure(vector<int>& s){
    int m = 0;
    int begin = 1;
    while(begin+m<s.size()){
        if(s[begin+m]==s[m]){
            m++;
            pi[begin+m-1]=m;
        }
        else{
            if(m==0)begin++;
            else begin+=m-pi[m-1],m=pi[m-1];
        }
    }
}

bool KMP(vector<int>& a, vector<int>& b){
    int j = 0;
    failure(b);
    for (int i = 0; i < a.size(); i++)
    {
        while(j>0&&a[i]!=b[j]){
            j = pi[j-1];
        }
        if(a[i]==b[j]){
            if(j==b.size()-1){
                return true;
            }
            else{
                j++;
            }
        }
    }
    return false;
}
int main()
{
    FAST
    int n;
    cin >> n;
    vector<int> first(n);
    vector<int> second(n);
    for (int i = 0; i < n; i++)
    {
        cin >> first[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> second[i];
    }
    sort(all(first));
    sort(all(second));
    vector<int> firstReal(2*n-2);
    int prev = first[0];
    for (int i = 1; i < n; i++)
    {
        firstReal[i-1] = first[i]-prev;
        prev= first[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        firstReal[n+i-1] = first[i]+360000-prev;
        prev = first[i]+360000;
    }

    prev = second[0];
    vector<int> secondReal(n-1);
    for (int i = 1; i < n; i++)
    {
        secondReal[i-1] = second[i]-prev;
        prev = second[i];
    }
/*
    for (int i = 0; i < 2*n-2; i++)
    {
        cout<<firstReal[i]<<" ";
    }
    cout<<endl;
    
    for (int i = 0; i < n-1; i++)
    {
        cout<<secondReal[i]<<" ";
    }
*/
    if(KMP(firstReal,secondReal)){
        cout<<"possible"<<endl;
    }
    else cout<<"impossible"<<endl;
}