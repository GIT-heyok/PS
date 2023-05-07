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
const int MAX = 50001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
using namespace std;

int kth(std::vector<int> &a, int k){
    int start = 0;
    int end = a.size()-1;
    k--;
    while(start<end){
        int i = start;
        int j = end;
        int mid = a[(i+j)/2];
        while(i<j){
            if(a[i]>=mid){
                swap(a[i], a[j]);
                j--;
            }
            else i++;
        }
        if(a[i]>mid)i--;
        if(k<=i)end=i;
        else start=i+1;
    }
    return a[k];
}
int main()
{
    FAST
    vector<int> a = {500000000,4};
    for (int i = 1; i <= a.size(); i++)
    {
        cout<<kth(a, i)<<endl;
    }
    
}

