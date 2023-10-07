#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;


int main() {
    FAST
    int n;
    cin >> n;
    int memo[n+1];
    for (int i = 0; i < n + 1; ++i) {
        memo[i] = 10000000;
    }
    memo[n] = 0;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int front = q.front();
        if(front==1)break;
        q.pop();
        if(front%3==0){
            if(memo[front/3]>memo[front]+1){
                q.push(front/3);
                memo[front/3]=memo[front]+1;
            }
        }

        if(front%2==0){
            if(memo[front/2]>memo[front]+1){
                q.push(front/2);
                memo[front/2]=memo[front]+1;
            }
        }

        if(memo[front-1]>memo[front]+1){
            q.push(front-1);
            memo[front-1] = memo[front]+1;
        }

    }

    cout<<memo[1]<<endl;
}

