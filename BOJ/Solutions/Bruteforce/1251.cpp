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

string splitAndReverse(string& s, int i, int j){
    string s1 ="", s2 = "", s3="";
    for (int start = 0; start < i; start++)
    {
        s1+=s[start];
    }
    
    for (int start = i; start < j; start++)
    {
        s2+=s[start];
    }

    for (int start = j; start < s.length(); start++)
    {
        s3+=s[start];
    }
    reverse(all(s1));
    reverse(all(s2));
    reverse(all(s3));
    s1+=s2+s3;
    return s1;
}
int main()
{
    FAST 
    string s;
    cin >> s;
    string smallest = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for (int i = 1; i < s.length(); i++)
    {
        for (int j = i+1; j < s.length(); j++)
        {
            string temp = splitAndReverse(s, i, j);
            if(temp<smallest)smallest=temp;
        }   
    }
    cout<<smallest<<endl;
     
}
