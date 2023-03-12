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
    int T=1;
    // cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        int oneCnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = s[j]-'0';
                if(arr[i][j]==1)oneCnt++;
            }
        }
        int minimum =0, maximum = 0;
        
        for (int i = 0; i < n; i++)
        {
            int prev = arr[i][0];
            for (int j = 1; j < m; j++)
            {
                if(prev==1&&arr[i][j]==1){
                    // cout<<i<<" "<<j<<endl;
                    minimum = min(n*m/4, minimum+1);
                    prev = arr[i][j+1];
                    j++;
                }
                else{

                    prev = arr[i][j];
                }
            }   
        }
        int oc = oneCnt;
        oc-=minimum*2;
        minimum+=oc;
        bool visited[n][m];
        fill(&visited[0][0], &visited[n-1][m], false);
        //0 see look back or front
        int clr = n*m/4;

        oc = oneCnt;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if(clr<=0)break;
                else if(!visited[i][j-1]){
                    if(arr[i][j]==0){
                        visited[i][j-1] = true;
                        visited[i][j] = true;
                        clr--;
                        if(arr[i][j-1]==1){
                            oc--;
                            maximum++;
                        }
                    }
                    else if(arr[i][j-1]==0){
                        // cout<<i<<" "<<j<<endl;
                        visited[i][j-1] = true;
                        visited[i][j] = true;
                        clr--;
                            oc--;
                            maximum++;
                    }   
                }
                else if(j!=m-1&&!visited[i][j+1]){
                    if(arr[i][j]==0){
                        visited[i][j+1] = true;
                        visited[i][j] = true;
                        clr--;
                        if(arr[i][j+1]==1){
                            oc--;
                            maximum++;
                        }
                        j++;
                    }
                    if(arr[i][j+1]==0){
                        // cout<<i<<" "<<j<<endl;
                        visited[i][j+1] = true;
                        visited[i][j] = true;
                        clr--;
                        if(arr[i][j]==1){
                            oc--;
                            maximum++;}
                        j++;
                    }
                }
            }
        }
         
        oc-=clr*2;
        maximum+=clr;
        maximum+=oc;
        cout<<minimum<<" "<<maximum<<endl;
        
        
        
    }
}