#include <algorithm>
#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

//10870 피보나치 수 5
int getFibonacci(int n){
    if(n == 0) //기저 사례: F_0 = 0
        return 0;
    if(n == 1) //기저 사례: F_1 = 1
        return 1;
    return getFibonacci(n-2) + getFibonacci(n-1); // 점화식 실행: F_n = F_n-1 + F_n-2 (n>=2)
}

int main() {
    FAST
    int n;
    cin >> n;
    cout << getFibonacci(n) << endl;
}

