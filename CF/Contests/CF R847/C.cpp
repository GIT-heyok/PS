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
        vector<int> vec(n-1);
        int missing = n*(n+1)/2;
        for(int i=0; i<n-1; i++){
            cin >> vec[i];
            missing -=vec[i];
        }
        int dump;
        for(int i=0; i<n-3; i++){ // next n-3 lines are not needed
            for(int j=0; j<n-1; j++){
                cin >> dump;
            }
        }

        vector<int> clue1(n-1);
        vector<int> clue2(n-1);
        int index1 = -1;
        int index2 = -1;
        for(int i=0; i<n-1; i++){
            cin >> clue1[i];
            if(clue1[i]==missing){
                index1=i;
            }
        }
        for(int i=0; i<n-1; i++){
            cin >> clue2[i];
            if(clue2[i]==missing){
                index2=i;
            }
        }

        if(index1==0&&index2==0){//seems like in front 
            cout<<missing<<" ";
            for(int i: vec)cout<<i<<" ";
            cout<<endl;
        }
        else{
            int nextToindex;
            if(index1==0){
            int secondd = clue2[index2-1];
                nextToindex = secondd;
            
 
            }
            else if(index2==0){
            int firstt = clue1[index1-1];
                nextToindex = firstt;
            }
            else{
            int firstt = clue1[index1-1];
            int secondd = clue2[index2-1];
            nextToindex = 0;
            for(int i=0; i<n-1; i++){ //search for latterone
                if(vec[i]==firstt){
                    nextToindex = secondd;
                    break;
                }
                else if(vec[i]==secondd){
                    nextToindex = firstt;
                    break;   
                }
            }
                
            }
            // cout<<nextToindex<<endl;
           for(int i=0; i<n-1; i++){
                cout<<vec[i]<<" ";
                if(nextToindex==vec[i]){
                    cout<<missing<<" ";
                }
            }
            cout<<endl;
        }

    }
}