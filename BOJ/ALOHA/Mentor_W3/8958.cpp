#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    FAST
    int TC; // 테스트 케이스이다.
    cin >> TC;
    while(TC--){ // C++에서는 0은 거짓을 뜻한다. 이렇게 하면 TC번 반복하는 반복문이 된다.
        string s;
        cin >> s; // OX가 여러개 적힌 한줄을 불러온다.
        int totalScore = 0; // 총 점수이다.
        int combo = 0;
        for (int i = 0; i < s.length(); ++i) { // s의 길이만큼 반복한다.
            if(s[i]=='O'){ // 문자열은 배열과 같다. 비교할때 작은 따옴표를 사용하는것에 주의하자.
                combo++; // 콤보는 연속한 개수이다.
                totalScore += combo; // 연속한 개수만큼 추가해준다.
            }
            else{
                combo = 0; // 연속한 개수가 사라졌다.
            }
        }
        cout << totalScore << endl;
    }
}
