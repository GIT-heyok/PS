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


int main(){
    FAST
    int n;
    cin >> n;
    priority_queue<int,vector<int>, less<int>> left;
    priority_queue<int,vector<int>, greater<int>> right;
    for(int i=0; i<n; i++){
        int temp;
        cin >>temp;
        if(i==0){
            left.push(temp);
            cout<<temp<<endl;
        }
        else{ //for immutability: mid value is at left
            int curAns = left.top();
            if(temp<=curAns){
                left.push(temp);
            }
            else{
                right.push(temp);
            }
            int ls = left.size(), rs = right.size();
            if(ls-rs==2){
                int mov = left.top();
                left.pop();
                right.push(mov);
            }
            else if(ls-rs==1){
                //okay
            }
            else if(ls==rs){
                //okay
            }
            else if(ls-rs==-1||ls-rs==-2){
                int mov = right.top();
                right.pop();
                left.push(mov);
            }
            cout<<left.top()<<endl;
        }
    }
}


