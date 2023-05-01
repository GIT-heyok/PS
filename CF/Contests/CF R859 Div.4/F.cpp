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
        int n, m, i1, j1, i2, j2;
        string d;
        cin >> n >> m>>i1>>j1>>i2>> j2>> d;
        // cout<<d<<endl;
        bool memo[n+1][m+1][4];
        

        for (int i = 0; i < n+1; i++)
        {
            for (int j = 0; j < m+1; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    memo[i][j][k]=0;
                }
            }
        }
        int curDir;
        if(d=="DR")curDir=0;
        else if(d=="DL")curDir=1;
        else if(d=="UR")curDir=2;
        else curDir=3;
        // cout<<curDir<<endl;
        int dr[4] = {1,1,-1,-1};
        int dc[4] = {1,-1,1,-1};
        int curR = i1;
        int curC = j1;
        bool reached = false;
        int cnt = 0;
        while(true){
            // cout<<curR<<" "<<curC<<" "<<curDir<<endl;
            if(memo[curR][curC][curDir])break;
            memo[curR][curC][curDir]= true;
            if(curR==i2&&curC==j2){reached=true;break;}
            int nxtDir=curDir;
            if(curDir==0){ //DR
                if(curR==n&&curC==m){
                    nxtDir = 3;//UL
                }
                else if(curR==n){
                    nxtDir = 2;//UR
                }
                else if(curC==m){
                    nxtDir = 1;//DL
                }
            }
            else if(curDir==1){
                if(curR==n&&curC==1){
                    nxtDir = 2;//UR
                }
                else if(curR==n){
                    nxtDir = 3;//UL
                }
                else if(curC==1){
                    nxtDir = 0;//DR
                }
            }
            else if(curDir==2){ //UR
                if(curR==1&&curC==m){
                    nxtDir = 1;//DL
                }
                else if(curR==1){
                    nxtDir = 0;//DR
                }
                else if(curC==m){
                    nxtDir = 3;//UL
                }
            }
            else{ //UL
                if(curR==1&&curC==1){
                    nxtDir = 0;//DR
                }
                else if(curR==1){
                    nxtDir = 1;//DL
                }
                else if(curC==1){
                    nxtDir = 2;//UR
                }
            }
            if(nxtDir!=curDir)cnt++;
            curDir = nxtDir;
            curR = curR+dr[curDir];
            curC = curC+dc[curDir];
        }
        if(reached)cout<<cnt<<endl;
        else cout<<-1<<endl;
        
    }
}