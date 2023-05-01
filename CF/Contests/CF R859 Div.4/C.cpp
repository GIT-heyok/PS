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
        cin >> n ;
        string s;
        cin >> s;
        int alphabet[26];
        fill(alphabet, alphabet+26, -1);
        bool chk = true;
        for (int i = 0; i < n; i++)
        {
            if(i%2==0){
                if(alphabet[s[i]-'a']==-1){
                    alphabet[s[i]-'a'] = 0;
                }
                if(alphabet[s[i]-'a']!=0)chk=false;
            }
            else{
                if(alphabet[s[i]-'a']==-1)alphabet[s[i]-'a']=1;
                if(alphabet[s[i]-'a']!=1)chk=false;
            }
        }
        if(chk)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
}