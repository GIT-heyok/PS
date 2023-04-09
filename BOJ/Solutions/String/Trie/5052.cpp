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

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e9;

struct trieNode{
    trieNode* node[10];
    bool isEmpty;
    trieNode(string s){
        for (int i = 0; i < 10; i++)
        {
            node[i] = nullptr;
        }
        
        if(s==""){
            isEmpty = true;
        }
        else{
            isEmpty = false;
            int nextLoc = s[0]-'0';
            string temp="";
            for (int i = 1; i < s.length(); i++)
            {
                temp+=s[i];
            }
            node[nextLoc] = new trieNode(temp);   
        }
    }
    bool check(string s){
        if(isEmpty){
            return false;
        }
        else{
            if(s=="")return false;
            int nextLoc = s[0]-'0';
            string temp="";
            for (int i = 1; i < s.length(); i++)
            {
                temp+=s[i];
            }
            if(!node[nextLoc])return true;
            return node[nextLoc]->check(temp);
        }
    }

    void insert(string s){
        if(s=="")return;
        int nextLoc = s[0]-'0';
        string temp="";
        for (int i = 1; i < s.length(); i++)
        {
            temp+=s[i];
        }
        if(!node[nextLoc]){
            node[nextLoc] = new trieNode(temp);
        }
        else{
            node[nextLoc]->insert(temp);
        }
        

    }
};

int main()
{
    FAST
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n ;
        string s;
        cin >> s;
        trieNode tr(s);
        bool chk = true;
        for (int j = 0; j < n-1; j++)
        {
            cin >> s;
            if(tr.check(s)){
                tr.insert(s);
            }
            else{
                chk = false;
                tr.insert(s);
            }
        }
        if(chk)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        

    }
    
}
    

