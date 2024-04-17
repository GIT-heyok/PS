#include <algorithm>
#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

// 2742 기찍 N
void recursion(int idx, int maxN){ // idx: 현재의 인덱스, maxN: 마지막 인덱스
    if(idx==maxN) {
        cout<<idx<<endl; //마지막 인덱스일때는 그 다음을 호출하지 않는다.
    }
    else{
        //잘 보면 알겠지만 전 코드에서 이 두줄끼리만 바뀌었다. 순서가 중요하다.
        recursion(idx + 1, maxN); // 출력 후 그다음으로 넘어간다.
        cout<<idx<<endl; // 출력한다
    }
}

int main() {
    FAST
    int n;
    cin >> n;
    recursion(1,n);
}

