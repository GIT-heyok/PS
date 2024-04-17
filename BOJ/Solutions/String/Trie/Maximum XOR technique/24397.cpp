#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
int nn, m, k;
typedef long long ll;

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

    void insert(int n, int depth) {
        if (depth == -1) {
            finished++;
            return;
        }
        int curDiv = 1<<depth;

        if (childs[n/curDiv] == nullptr) {
//            cout<<"created"<<n<<" "<<depth<<" "<<n/curDiv<<endl;
            childs[n/curDiv] = new Trie();
        }
        childs[n/curDiv]->cnt = childs[n/curDiv]->cnt+1;
        childs[n/curDiv]->insert(n%curDiv, depth-1);

    }

    int find(int n, int depth) {
        if(depth==-1)return finished;
        int curDiv = 1 << depth;
        bool curPtr = n/curDiv;
//        cout<<n<<" "<<curPtr<<" "<<curDiv<<endl;

        if((k&(1<<depth))==0){ //k에는 0비트만 존재한다.
            if(curPtr){ //n의 비트는 1비트다. 1비트를 따라 내려가지 않으면 안된다.
                int sum = 0;
                if(childs[1]!= nullptr)
                    sum += childs[1]->find(n%curDiv, depth-1);
                else sum += finished;
//                cout<<depth<<"k"<<0<<" n"<<1<<" "<<sum<<endl;
                return sum;
            }
            else{ //n의 비트는 0비트다. 내려가자.
                int sum = 0;
                if(childs[curPtr]!= nullptr)
                    sum+= childs[curPtr]->find(n%curDiv, depth-1);
                else
                    sum+=finished;
//                cout<<depth<<"k"<<0<<" n"<<0<<" "<<sum<<endl;
                return sum;
            }
        }
        else{ //k의 현재 비트는 1비트이다.
//            cout<<(k&(1<<depth))<<endl;
            if(curPtr){ //n의 비트는 1비트다. 1비트를 골라서 재귀적으로 해결, 0비트로 내려가면 무조건 작거나 같으므로 전체 sum을 해준다.
                int sum = 0;
                if(childs[0]!= nullptr)
                    sum += childs[0]->find(n%curDiv, depth-1);
                if(childs[1]!= nullptr)
                    sum += childs[1]->cnt;
//                cout<<depth<<"k"<<1<<" n"<<1<<" "<<sum<<endl;
                return sum;
            }
            else{ //n의 비트는 관계 없다. 아래 노드들의 전체 합을 구해준다.
                int sum = 0;
                if(childs[1]!= nullptr)
                    sum += childs[1]->find(n%curDiv, depth-1);
                if(childs[0]!= nullptr)
                    sum += childs[0]->cnt;
//                cout<<depth<<"k"<<1<<" n"<<0<<" "<<sum<<endl;
                return sum;
            }
        }
    }
};


int main(void) {
    FAST
    cin >> nn >> m >> k;
    int arr[nn];
    int arr2[m];
    Trie* t = new Trie();
    k--;
    for (int i = 0; i < nn; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }
    for (int i = 0; i < m; ++i) {
        t->insert(arr2[i],30);
    }
    ll sum = 0;
    for (int i = 0; i < nn; ++i) {
        sum += t->find(arr[i],30);
//        cout<<arr[i]<<" "<<sum<<endl;

    }
    cout<<sum<<endl;
}
