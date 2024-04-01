#include <algorithm>
#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

void indentation(int n){ // n*4번의 _을 출력하는 코드
    for (int i = 0; i < n; ++i) {
        cout<<"____";
    }
}

void recursion(int depth, int maxDepth){ // depth: 얼마나 깊이 들어갔는가
    if(maxDepth==depth) { // 종료 조건: n이 줄어들다가 0이 될때 출력 후 종료한다.
        indentation(depth);
        cout << "\"재귀함수가 뭔가요?\"" << endl;
        indentation(depth);
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
        indentation(depth);
        cout << "라고 답변하였지." << endl;
    }
    else{
        // 재귀 전의 글귀들
    cout<<"위"<<endl;

        // 이제 재귀할 시간! depth를 depth+1로 변경 (1단계 깊이 들어간다) maxDepth는 유지해준다.
        recursion(depth+1, maxDepth);

    cout<<"아래"<<endl;
    }
}
int main() {
    FAST
    int n;
    cin >> n;
    //재귀와 관련 없는 바깥 부분.
//    cout<< "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."<<endl;
    recursion(0, n); //재귀 실행
}

