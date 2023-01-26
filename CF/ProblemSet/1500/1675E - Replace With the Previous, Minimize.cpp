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
const int INF = 1234567890;

int main(){

    
    FAST
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vi vec(26,INF);
        string s;
        cin >> s;
        vec[0] = 0;
        for(int i=0; i<n; i++){
            vec[s[i]-'a']=min(i+1, vec[s[i]-'a']);
        }
        int indexDone = min(k, 25);
    
        for(int i=0; i<indexDone; i++){
            int minVal = INF;
            int minValIndex = -1;
            for(int j=0; j<26; j++){
                if(vec[j]!=0){
                    if(minVal>vec[j]){
                        minValIndex = j;
                        minVal = vec[j];
                    }
                }
            }
            if(minValIndex==-1){
                break;
            }
            else{
                vec[minValIndex] = 0;
                if(vec[minValIndex-1]!=0){
                    vec[minValIndex-1] = minVal;

                }
            }
        }
        int prev = 0;
        for(int i=0; i<26; i++){
            if(vec[i]==0){
                vec[i] = prev;
            }
            else{
                vec[i] = i;
                prev  = vec[i];
            }
        }
        for(int i=0; i<n; i++){
            cout<<(char)(vec[s[i]-'a']+'a');
        }
        cout<<endl;

    }
}