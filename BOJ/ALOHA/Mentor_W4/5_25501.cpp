#include <algorithm>
#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int counter;

// 25501 재귀의 귀재
//식을 그대로 사용하되, 카운터만 붙여주었다.
int recursion(const char *s, int l, int r){
    counter++; //식이 호출 되었다: 1회 카운트
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        string s;
        cin >> s;
        counter = 0; //카운터 초기화
        int val = isPalindrome(s.c_str()); // c_str() 함수는 string을 const char* 형으로 바꿔준다.
        cout<<val<<" "<<counter<<endl;
    }
}
