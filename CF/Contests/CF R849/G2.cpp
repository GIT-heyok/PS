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
const ll INF = 1234567890123ll;

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        ll c;
        cin >> n >> c;
        priority_queue<pLL, vector<pLL>, greater<pLL>> zeroBased, np1Based;
        bool visited[n+1];
        fill(visited, visited+n+1, false);
        for(int i=1; i<=n; i++){
            ll temp;
            cin >>temp;
            zeroBased.push({i+temp, i});
            np1Based.push({temp+n+1-i, i});
        }
        // cout<<zeroBased.top().first<<" "<<np1Based.top().first<<endl;
        int count = 0;
        ll subSum = 0;
        bool isAtZero = true;
        for(int i=0; i<n; i++){
            ll cost;
            if(isAtZero){
                auto temp = zeroBased.top();
                cost = temp.first;
                int portalLoc = temp.second;
                visited[portalLoc] = true;
                zeroBased.pop();
               
            }
            else{
                auto temp = np1Based.top();
                cost = temp.first;
                int portalLoc = temp.second;
                visited[portalLoc] = true;
                np1Based.pop();
            }
            pLL tempZ = {INF,0}, tempN = {INF,0};
            while(!zeroBased.empty()){
                tempZ = zeroBased.top();
                zeroBased.pop();
                if(!visited[tempZ.second]){
                    break;
                }
            }   
            while(!np1Based.empty()){
                tempN = np1Based.top();
                np1Based.pop();
                if(!visited[tempN.second]){
                    break;
                }
            }   
            if(tempZ<=tempN){
                isAtZero = true;
            }
            else{
                isAtZero = false;
            }
            zeroBased.push(tempZ);
            np1Based.push(tempN);
            
                cout<<tempZ.first<<" "<<tempZ.second<<" "<<tempN.first<<" "<<tempN.second<<endl;
            if(subSum+cost<=c){
                    count++;
                    subSum+=cost;
            }
            else{
                break;
            }
        }
        cout<<count<<endl;
    }
}