#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
using namespace std;
#define MAX 1000001
struct QUERY {
    int Left, Right, Index;
};

int N, M, S, I, J;
int A[MAX];
vector<QUERY> Query;
int Value, Left, Right;
vector<int> Answer, Count;


bool Comp(QUERY A, QUERY B) {
    if (A.Left / S != B.Left / S) {
        return (A.Left / S < B.Left / S);
    }
    return (A.Right < B.Right);
}

void settings() {
    S = sqrt(N);
    sort(Query.begin(), Query.end(), Comp);
    Answer.resize(M);
    Count.resize(MAX);
    Left = Query[0].Left;
    Right = Query[0].Right;
    for (int i = Left; i <= Right; i++) {
        if (Count[A[i]] == 0) {
            Value++;
        }
        Count[A[i]]++;
    }
    Answer[Query[0].Index] = Value;
    for (int i = 1; i < M; i++) {
        int NowL = Query[i].Left;
        int NowR = Query[i].Right;

        while (NowL < Left) {
            Left--;
            if (Count[A[Left]] == 0) {
                Value++;
            }
            Count[A[Left]]++;
        };

        while (NowL > Left) {
            Count[A[Left]]--;
            if (Count[A[Left]] == 0) {
                Value--;
            }
            Left++;
        };

        while (NowR > Right) {
            Right++;
            if (Count[A[Right]] == 0) {
                Value++;
            }
            Count[A[Right]]++;
        };

        while (NowR < Right) {
            Count[A[Right]]--;
            if (Count[A[Right]] == 0) {
                Value--;
            }
            Right--;
        };

        Answer[Query[i].Index] = Value;
    }
}

int main()
{
    FAST
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> I >> J;
        Query.push_back({ I - 1,J - 1,i });
    }
    settings();
    for (int i = 0; i < M; i++) {
        cout << Answer[i] << "\n";
    }
}


