#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
int main(){
    FAST
    bool isPrime[1000001];

    fill(isPrime, isPrime+1000001, 1);
    isPrime[0] =false;
    isPrime[1] = false;
    for(int i=2; i*i<=1000000; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=1000000; j+=i){
                isPrime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    if(n<=7){
        cout<<-1<<endl;
    }
    else{
        for(int i=n/2; i>=4; i--){
            int a = i;
            int b = n-i;
            int n1 = -1, n2 = -1, n3=-1, n4=-1;
            for(int j=2; j<a; j++){
                if(isPrime[j]&&isPrime[a-j]){
                    n1 = j;
                    n2=a-j;
                    break;
                }   
            }
            for(int j=2; j<b; j++){
                if(isPrime[j]&&isPrime[b-j]){
                    n3=j;
                    n4=b-j;
                    break;
                }
            }
            if(n1!=-1&&n3!=-1){
                cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<endl;
                break;
            }
        }
    }
}