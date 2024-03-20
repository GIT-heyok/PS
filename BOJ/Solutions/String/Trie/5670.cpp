#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

typedef long long ll;


int n, answer;
vector<string> dict;

class Trie {
private:
    Trie *childs[26];
    int child_cnt;
    bool isRoot, finish;

public:
    Trie(bool isroot) {
        for (int i = 0; i < 26; i++) childs[i] = NULL;
        finish = false;
        isRoot = isroot;
        child_cnt = 0;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (childs[i] != NULL) delete childs[i];
    }

    void insert(const char *cur) {
        if (*cur == '\0') {
            finish = true;
            return;
        }
        int pos = *cur - 'a';

        if (childs[pos] == NULL) {
            childs[pos] = new Trie(false);
            child_cnt++;
        }

        childs[pos]->insert(cur + 1);
    }

    void find(const char *cur) {
        if (*cur == '\0') return;
        int pos = *cur - 'a';

        if (isRoot) answer++;
        else {
            if (child_cnt > 1) answer++;
            else if (finish) answer++;
        }

        childs[pos]->find(cur + 1);
    }
};

int main(void) {
    FAST

    while (cin >> n) {

        Trie t = Trie(true);
        string arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            t.insert(arr[i].c_str());
        }
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            answer = 0;
            t.find(arr[i].c_str());
            sum+=answer;
        }
        cout << fixed << setprecision(2) << sum / n << endl;
    }
}
