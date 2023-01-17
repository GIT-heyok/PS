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

bool isPalindrome(string& s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int memo[2501];
int dp(string& s, int k){
    if(memo[k]!=-1){
        return memo[k];
    }
    else{
        int& temp = memo[k] = INF;
        if(isPalindrome(s, 0, k)){
            temp = min(temp,1);
        }
        for(int i=0; i<k; i++){
            if(isPalindrome(s, i+1, k)){
                temp = min(temp, 1+dp(s, i));
            }
        }
        return temp;
    }
   
}
int main(){
    FAST
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++){
        memo[i] = -1;
    }
    cout<<dp(s, s.length()-1)<<endl;
}