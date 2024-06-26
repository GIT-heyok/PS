#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

typedef long long ll;

class Trie {
private:
    vector<Trie *> children;
    bool finish;
    char curNode;
    int cnt;
public:

    Trie(char c) {
        finish = false;
        curNode = c;
        cnt = 0;
    }

    ~Trie() {
        for (int i = 0; i < children.size(); i++)
            delete children[i];
    }

    void insert(string &s, int idx) {
        if (idx == s.length()) {
            finish = true;
            return;
        }

        int temp = -1;
        for (int i = 0; i < children.size(); ++i) {
            if (s[idx] == children[i]->curNode) {
                temp = i;
                break;
            }
        }
        if (temp == -1) {
            children.push_back(new Trie(s[idx]));
            temp = children.size() - 1;
        }

        children[temp]->cnt++;
        children[temp]->insert(s, idx + 1);
    }

    int find(string &s, int idx) {
        if (idx == s.length()) return cnt;
        cout<<s[idx]<<" "<<cnt<<endl;
        int temp = -1;
        for (int i = 0; i < children.size(); ++i) {
            if (s[idx] == children[i]->curNode) {
                temp = i;
                break;
            }
        }
        if (temp == -1) return cnt;
        return children[temp]->find(s, idx + 1);

    }
};

int main(void) {
    FAST
    Trie *t = new Trie(0);
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        string s = "";
        for (int j = 0; j < temp; ++j) {
            char ch;
            cin >> ch;
            s+=ch;
        }
        t->insert(s, 0);
    }
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        string s = "";
        for (int j = 0; j < temp; ++j) {
            char ch;
            cin >> ch;
            s+=ch;
        }
        cout<<t->find(s,0)<<endl;
    }

}
