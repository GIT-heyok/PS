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
const int MAX = 200001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
int main()
{
    FAST
    int R, C, k;
    cin >> R >> C >> k;
    vector<int> graph[k+1];
    pair<pI, pI> bus(k+1);
    for (int i = 1; i <= k; i++)
    {
        int b, sx, sy, dx, dy;
        cin >> b >> sx >> sy >> dx >> dy;
        if(sx>dx)swap(sx, dx); //small first
        if(sy>dy)swap(sy, dy); // small first

        bus[b] = {make_pair(sx,sy), make_pair(dx, dy)};
        for (int j = 1; j < i; j++)
        {
            int s2x = bus[j].first.first;
            int s2y = bus[j].first.second;
            int d2x = bus[j].second.first;
            int d2y = bus[j].second.second;
            bool intersects = false;
            //선분 교차 판정 어케함???????????
            if(sx==dx){ // b is horizontal
                if(s2x==d2x){//j is horizontal
                    if(s2y==sy){
                        if(sx<=s2x){
                            if(dx>=s2x&&dx<=d2x)intersects = true;
                        }
                        else{
                            if(d2x>=sx&&d2x<=dx)intersects=true;   
                        }
                    }
                }
                else{ //j is vertical
                    if()
                }
            }
            else{ // b is vertical

            }
        }
        
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int startIdx = coordMap[{x1, y1}];
    int endIdx = coordMap[{x2, y2}];
    int visited[cnt];
    for (int i = 0; i < cnt; i++)
    {
        visited[i] = inf;
    }

    queue<int> q;
    q.push(startIdx);
    visited[startIdx] = 1;
    while(!q.empty()){
        int cur = q.front();
        cout<<cur<<" "<<visited[cur]<<endl;
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if(visited[next]>visited[cur]+1){
                visited[next] = visited[cur]+1;
                q.push(next);
            }
        }   
    }
    cout<<visited[endIdx]<<endl;
    
}

