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
        int n;
        cin >> n;
        int cnt = 0;
        int aw=0, ab=0, bw=0, bb=0; 
        bool isWhite = true;
        for (int i = 1; n>0; i++)
        {
            int left = min(n, i);

            if(i%4==1||i%4==0){
                if(isWhite){
                    aw+=(left+1)/2;
                    ab+=left/2;
                }
                else{
                    aw+=left/2;
                    ab+=(left+1)/2;
                }
                n-=left;
            }
            else{
               if(isWhite){
                    bw+=(left+1)/2;
                    bb+=left/2;
                }
                else{
                    bw+=left/2;
                    bb+=(left+1)/2;
                }
                n-=left;
            }
            if(i%2){
                isWhite = !isWhite;
            }
        }
        cout<< aw << " "<<ab<<" "<<bw<<" "<<bb<<endl;
        
    }
}