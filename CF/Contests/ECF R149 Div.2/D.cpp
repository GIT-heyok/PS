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
        cin >> n;
        string s;
        cin >> s;
        vector<int> ans(n);
        if(s[0]==')'){
            for (int i = 0; i < s.length(); i++)
            {
                if(s[i]=='(')s[i]=')';
                else s[i]='(';
            }
            
        }
        int curVal = 0;
        bool plus = true;
        bool hasMinus = false;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='('){
                curVal++;
            }else{
                curVal--;
            }
            if(curVal<0){
                plus = false;
                hasMinus = true;
            }
            else if(curVal>0){
                plus = true;
            }
            if(plus){
                ans[i] = 1;
            }
            else{
                ans[i] = 2;
            }
        }
        if(curVal!=0)cout<<-1<<endl;
        else{
            if(hasMinus)cout<<2<<endl;
            else cout<<1<<endl;
            for (int i = 0; i < n; i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
            
        }
        
    }
}