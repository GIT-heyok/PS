#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

// 23304 아카라카
bool isPalindrome(int l, int r, string &s) { // 팰린드롬을 확인한다. 안쪽이 회문이고 양쪽 껍질이 같다면 그것도 회문이다.
    if (l >= r)return true; // 한글자 이하의 문자열은 모두 회문이다.
    if (s[l] != s[r])return false; // 껍질이 다르다면 회문이 아니다.
    return isPalindrome(l + 1, r - 1, s); // 안쪽 문자열을 확인해준다.
}

bool isAKARAKAPalindrome(int l, int r, string &s) { // 다른 부분은 다 같지만 마지막 줄이 다르다.
    if (l >= r) return true;
    if (s[l] != s[r])return false;
    return isAKARAKAPalindrome(l, (l + r - 1) / 2, s) && isAKARAKAPalindrome((l + r) / 2 + 1, r, s) &&
           isPalindrome(l + 1, r - 1, s); // 문제에서 AKARAKA 회문은 회문이면서 (isPalindrome), 접두사와 접미사가 AKARAKA 회문이다.
           // 이를 재귀적으로 구현해준다.
}

int main() {
    FAST
    string s;
    cin >> s;
    if (isAKARAKAPalindrome(0, s.length() - 1, s))
        cout << "AKARAKA" << endl;
    else
        cout << "IPSELENTI" << endl;
}

