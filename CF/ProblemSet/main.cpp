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
#include <numeric>
 
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
        int n, m;
        cin >> n >> m;
        bool visited[n+1][m+1];
        int arr[n+1][m+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> arr[i][j];
                visited[i][j] = false;   
            }
        }
        ll ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(!visited[i][j]){
                int di = n-i+1;
                int dj = m-j+1;
                if(di==i){
                    if(dj==j){
                        //one pos
                        visited[i][j] = true;
                    }
                    else{
                        //same row
                        visited[i][j] = true;
                        visited[i][dj] = true;
                        int mean = (arr[i][j]+arr[i][dj])/2;
                        ans += abs(arr[i][j]-mean);
                        ans += abs(arr[i][dj]-mean);
                    }
                }
                else{
                    if(dj==j){
                        visited[i][j] = true;
                        visited[di][j] = true;
                        int mean = (arr[i][j]+arr[di][j])/2;
                        ans += abs(arr[i][j]-mean);
                        ans += abs(arr[di][j]-mean);
                    }
                    else{
                        visited[i][j] = true;
                        visited[i][dj] = true;
                        visited[di][j] = true;
                        visited[di][dj] = true;
                        ll mean = ((ll)arr[i][j]+(ll)arr[i][dj]+arr[di][j]+arr[di][dj])/4;
                        ll temp = mean+1;
                        ll ansTemp1 = abs(arr[i][j]-mean)+abs(arr[i][dj]-mean)+abs(arr[di][j]-mean)+abs(arr[di][dj]-mean);
                        ll ansTemp2 = abs(arr[i][j]-temp)+abs(arr[i][dj]-temp)+abs(arr[di][j]-temp)+abs(arr[di][dj]-temp);
                        ans+=min(ansTemp1, ansTemp2);
                    }
                }}
            }
        }
        cout<<ans<<endl;
    }   
    }