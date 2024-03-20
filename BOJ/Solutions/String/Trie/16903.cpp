#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;

class Trie {
private:
    //0,1
    Trie * childs[2];
    int cnt;
public:

    Trie() {
        cnt = 0;
        for (int i = 0; i < 2; ++i) {
            childs[i] = nullptr;
        }
    }

    ~Trie() {
        for (int i = 0; i < 2; i++)
            if(childs[i])
                delete childs[i];
    }

    void insert(int n, int depth, int delta) {
        if (depth == -1) {
            return;
        }
        int curDiv = 1<<depth;
        if (childs[n/curDiv] == nullptr) {
//            cout<<"created"<<n<<" "<<depth<<" "<<n/curDiv<<endl;
            childs[n/curDiv] = new Trie();
        }
        childs[n/curDiv]->cnt+=delta;
//        cout<<depth<<" "<<n/curDiv*curDiv<<" "<<cnt<<endl;
        childs[n/curDiv]->insert(n%curDiv, depth-1, delta);

    }

    int find(int n, int depth) {
        if(depth==-1)return 0;
        int curDiv = 1 << depth;
        bool curPtr = n/curDiv;
//        cout<<depth<<" "<<cnt<<endl;
//        cout<<n<<" "<<curPtr<<" "<<curDiv<<endl;
        if(childs[!curPtr]!= nullptr&&childs[!curPtr]->cnt>0)
            return curDiv+childs[!curPtr]->find(n%curDiv, depth-1);
        else return childs[curPtr]->find(n%curDiv, depth-1);
    }
};


int main(void) {
    FAST

    int n;
    cin >> n;

    Trie* t = new Trie();
    t->insert(0,31,1);
    for (int i = 0; i < n; ++i) {
        int type, x;
        cin >> type >> x;
        if(type==1){
            t->insert(x,31,1);
        }
        else if(type==2){
            t->insert(x,31,-1);
        }
        else{
            cout<<t->find(x, 31)<<endl;
        }
    }
}
