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
const int MAX = 16;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
bool horizontal[10][3] = {
    {1,0,1},
    {0,0,0},
    {1,1,1},
    {1,1,1},
    {0,1,0},
    {1,1,1},
    {1,1,1},
    {1,0,0},
    {1,1,1},
    {1,1,1}
};

bool vertical[10][4] = {
    {1,1,1,1},
    {0,1,0,1},
    {0,1,1,0},
    {0,1,0,1},
    {1,1,0,1},
    {1,0,0,1},
    {1,0,1,1},
    {0,1,0,1},
    {1,1,1,1},
    {1,1,0,1},
};


int main()
{
    FAST
    int s;
    string n;
    cin >> s >> n;
    for (int i = 0; i < n.length(); i++)
    {
        cout<<" ";
        for (int j = 0; j < s; j++)
        {
            if(horizontal[n[i]-'0'][0])cout<<"-";
            else cout<<" ";
        }
        cout<<"  ";
    }
    cout<<endl;
    for (int k = 0; k < s; k++)
    {
    for (int i = 0; i < n.length(); i++)
    {
            if(vertical[n[i]-'0'][0])cout<<"|";
            else cout<<" ";
            for (int j = 0; j < s; j++)
            {
                cout<<" ";
            }
            
            if(vertical[n[i]-'0'][1])cout<<"|";
            else cout<<" ";
            cout<<" ";
        
    }cout<<endl;
    }

    for (int i = 0; i < n.length(); i++)
    {
        cout<<" ";
        for (int j = 0; j < s; j++)
        {
            if(horizontal[n[i]-'0'][1])cout<<"-";
            else cout<<" ";
        }
        cout<<"  ";
    }
    cout<<endl;
    
    for (int k = 0; k < s; k++)
    {
    for (int i = 0; i < n.length(); i++)
    {
            if(vertical[n[i]-'0'][2])cout<<"|";
            else cout<<" ";
            for (int j = 0; j < s; j++)
            {
                cout<<" ";
            }
            
            if(vertical[n[i]-'0'][3])cout<<"|";
            else cout<<" ";
            cout<<" ";
        
    }cout<<endl;
    }

    for (int i = 0; i < n.length(); i++)
    {
        cout<<" ";
        for (int j = 0; j < s; j++)
        {
            if(horizontal[n[i]-'0'][2])cout<<"-";
            else cout<<" ";
        }
        cout<<"  ";
    }
    cout<<endl;
    
}