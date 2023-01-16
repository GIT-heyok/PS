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

struct point2D{
    ll x, y;
    point2D(){
        x = 0;
        y = 0;
    }
    point2D(ll a, ll b):x(a), y(b){};
    
    void debg(){
        cout<<"x: "<<x<<" y: "<<y<<endl;
    } 
};

struct vector2D{
    point2D p1, p2;
    ll x,y;
    vector2D(point2D pp1, point2D pp2):p1(pp1), p2(pp2){
        x = pp2.x-pp1.x;
        y = pp2.y-pp1.y;
    }
    
    vector2D(){
        p1 = point2D();
        p2 = point2D();
        x= 0, y=0;
    }
    ld dist(){
        return sqrt(x*x+y*y);
    }
};


//-1 no 0 180 1 yes 
int isCCW(point2D p1, point2D p2, point2D p3){
    vector2D v1 = vector2D(p1, p2);
    vector2D v2 = vector2D(p2, p3);
    ll val = v1.x*v2.y-v2.x*v1.y;
    if(val>0)return 1;
    else if(val<0)return -1;
    else return 0;
}

int main()
{
    FAST
    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin >> x1>>y1;
    cin >> x2>>y2;
    cin >> x3>>y3;
    cout<<isCCW(point2D(x1,y1),point2D(x2,y2),point2D(x3,y3))<<endl;
}