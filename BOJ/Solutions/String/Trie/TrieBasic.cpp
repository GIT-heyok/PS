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
public:

    Trie(char c) {
        finish = false;
        curNode = c;
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
        cout << s[idx] << endl;

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

        children[temp]->insert(s, idx + 1);
    }

    bool find(string &s, int idx) {
        if (idx == s.length()) return finish;

        int temp = -1;
        for (int i = 0; i < children.size(); ++i) {
            if (s[idx] == children[i]->curNode) {
                temp = i;
                break;
            }
        }
        if (temp == -1) return false;
        return children[temp]->find(s, idx + 1);

    }
};

int main(void) {
    FAST
    Trie *t = new Trie(0);
    string s1 = "SSSS";
    t->insert(s1, 0);
    string n = "SS";
    string n1 = "SSSS";
    cout << t->find(s1, 0) << endl;
    cout << t->find(n1, 0) << endl;

}
