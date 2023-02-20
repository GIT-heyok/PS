#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
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
const int MAX = 500001;
const ll INF = 1234567890ll;

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin >> s;
        int valA = 0;
        int valB = 0;
        vi vecA(26,0), vecB(26,0);
        //
        for(int i=0; i<n; i++){
            vecB[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(vecB[i]>0)valB++;
        }
        int ans = valB;
        for(int i=0;i<n; i++){
            int curLetter = s[i]-'a';
            vecB[curLetter]--;
            if(vecB[curLetter]==0)valB--;
            vecA[curLetter]++;
            if(vecA[curLetter]==1)valA++;
            ans = max(valA+valB, ans);
        }
        cout<<ans<<endl;
    }
}