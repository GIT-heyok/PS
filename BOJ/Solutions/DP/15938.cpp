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

//const int MAX = 1121;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e9+7;

int equalize(int a, int b, int c){
    return a-b+c;
}
int main(){
    FAST
    int xs, ys, T;
    cin >> xs >> ys >> T;
    int MAX = 2*T+1; 
    int arr[MAX][MAX]; // original: (T,T), from 0~2*T
    int xh, yh;
    cin >> xh >> yh;
    //0: obstacle 1: passable 2: destination
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = 1;
        }
        
    }
    
    //equalize and put in array
    xh = equalize(xh, xs, T);
    yh = equalize(yh, ys, T);
    if(xh>=0&&xh<MAX&&yh>=0&&yh<MAX)
    arr[xh][yh]=2;

    //obstacles
    int obsz;
    cin >>obsz;
    for (int i = 0; i < obsz; i++)
    {
        int x, y;
        cin >> x >> y;
        x=equalize(x, xs, T);
        y=equalize(y, ys, T);
        if(x>=0&&x<MAX&&y>=0&&y<MAX)arr[x][y]=0;
    }
    
    
    ll memoPrev[MAX][MAX];
    ll memoAfter[MAX][MAX];
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            memoAfter[i][j]=0;
        }
    }
    memoAfter[T][T]=1;
    
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};

    while(T--){
        //initialization
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                memoPrev[i][j] = memoAfter[i][j];
                memoAfter[i][j]=0;
            }
            
        }
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                //house=contain the previous answer
                if(arr[i][j]==2)memoAfter[i][j]=memoPrev[i][j];
                
                for (int k = 0; k < 4; k++)//direction movement
                {
                    int tempr = i+dr[k];
                    int tempc = j+dc[k];
                    //within range?
                    if(tempr>=0&&tempr<MAX&&tempc>=0&&tempc<MAX){
                        //source is neither house nor wall
                        if(arr[tempr][tempc]!=0&&arr[tempr][tempc]!=2)
                            memoAfter[i][j]+=memoPrev[tempr][tempc];
                            memoAfter[i][j]%=MOD;
                    }
                }
                
            }
            
        }
    }
    if(xh>=0&&xh<MAX&&yh>=0&&yh<MAX)
    cout<<memoAfter[xh][yh]<<endl;
    else
    cout<<0<<endl;
}