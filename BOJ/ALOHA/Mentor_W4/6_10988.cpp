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

// 10988 팰린드롬인지 확인하기
//식을 그대로 사용하였다.
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
    string s;
    cin >> s;
    counter = 0; //카운터 초기화
    int val = isPalindrome(s.c_str()); // c_str() 함수는 string을 const char* 형으로 바꿔준다.
    cout<<val<<endl;

}
