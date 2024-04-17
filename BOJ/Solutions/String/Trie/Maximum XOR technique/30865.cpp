#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
int nn, m, k;
typedef long long ll;
int xorVal;

class Trie {
private:
    //0,1
    Trie * childs[2];
    int cnt;
    int finished;

public:

    Trie() {
        for (int i = 0; i < 2; ++i) {
            childs[i] = nullptr;
        }
        cnt = 0;
        finished = false;
    }

    ~Trie() {
        for (int i = 0; i < 2; i++)
            if(childs[i])
                delete childs[i];
    }

    void insert(int n, int depth, int diff) {
        if (depth == -1) {
            finished+=diff;
            return;
        }
        int curDiv = 1<<depth;

        if (childs[n/curDiv] == nullptr) {
//            cout<<"created"<<n<<" "<<depth<<" "<<n/curDiv<<endl;
            childs[n/curDiv] = new Trie();
        }
        childs[n/curDiv]->cnt = childs[n/curDiv]->cnt+diff;
        childs[n/curDiv]->insert(n%curDiv, depth-1, diff);

    }

    // xorVal에 유동적으로 저장되어야함.

    void find(int n, int depth, int i) {
        if(depth==-1)return;
        int curDiv = 1 << depth;
        bool curPtr = n/curDiv;
        int lower = 0;
        if(childs[!curPtr]!= nullptr)
            lower = childs[!curPtr]->cnt;
        if(i>lower) // smaller
            childs[curPtr]->find(n%curDiv, depth-1, i-lower);
        else if(i==lower){ //i, lower 가 둘 다 0일 수도 있음.
            if(childs[!curPtr]!= nullptr&&childs[!curPtr]->cnt>0){ // 큰 거 우선?
                childs[!curPtr]->find(n%curDiv, depth-1, i);
                xorVal+=curDiv;
            }
            else{
                childs[curPtr]->find(n%curDiv, depth-1, i-lower);
            }
        }
        else{
            childs[!curPtr]->find(n%curDiv, depth-1, i);
            xorVal+=curDiv;
        }
//        cout<<n<<" "<<depth<<" "<<i<<" "<<xorVal<<endl;
    }

};


int main(void) {
    FAST
    cin >> nn;
    Trie* t = new Trie();
    int arr[nn+1];
    for (int i = 1; i <= nn; ++i) {
        cin >> arr[i];
        t->insert(arr[i], 31, 1);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            t->insert(arr[b], 31, -1); // destroy
            arr[b] = c;
            t->insert(c, 31, 1); // append new
        }
        else{
            xorVal = 0;
            t->find(c, 31, b);
            cout<<xorVal<<endl;
        }
    }

}
