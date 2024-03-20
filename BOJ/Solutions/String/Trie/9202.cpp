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
    vector<Trie *> childs;

public:
    char curChr;

    Trie() {
    }

    ~Trie() {
        for (int i = 0; i < childs.size(); i++)
            delete childs[i];
    }

    void insert(const char *cur) {
        if (*cur == '\0') {
            return;
        }

        int idx = -1;

        for (int i = 0; i < childs.size(); ++i) {
            if(childs[i]->curChr==*cur){
                idx = i;
                break;
            }
        }
        if (idx==-1) {
            Trie* tt = new Trie();
            tt->curChr = *cur;
            childs.push_back(tt);
            idx = childs.size()-1;
        }
        childs[idx]->insert(cur + 1);

    }

    bool find(const char *cur) {
        if (*cur == '\0') return true;

        int idx = -1;

        for (int i = 0; i < childs.size(); ++i) {
            if(childs[i]->curChr==*cur){
                idx = i;
                break;
            }
        }

        if(idx == -1) return false;
        return childs[idx]->find(cur + 1);
    }
};

char arr[4][4];
bool visited[4][4];
string str;
Trie* t;

int dr[8] = {-1,-1,-1,0,0,1,1, 1};
int dc[8] = {-1,-0,1,-1,1,-1,0, 1};
void dfs(int r, int c, int len){
    if(r>=0&&c>=0&&r<4&&c<4&&!visited[r][c]){
        visited[r][c] = true;
        str[len-1] = arr[r][c];
        if(len==8){
            t->insert(str.substr(0, len).c_str());
//            cout<<str.substr(0,len)<<" "<<len<<endl;
            visited[r][c] = false;
            return;
        }
//        cout<<str.substr(0,len)<<" "<<len<<endl;
        t->insert(str.substr(0, len).c_str());
        for (int i = 0; i < 8; ++i) {
            dfs(r+dr[i], c+dc[i], len+1);
        }
        visited[r][c] = false;
    }
}
int main(void) {
    FAST

    int n;
    cin >> n;
//    Trie(true);
    string strArr[n];
    for (int i = 0; i < n; ++i) {
        cin >> strArr[i];
    }
    int b;
    cin >> b;
    str = "aaaaaaaa";
    while(b--){
        t = new Trie();
        for (int i = 0; i < 4; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < 4; ++j) {
                arr[i][j] = s[j];
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                dfs(i,j,1);
            }
        }
        string curStr = "";
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(t->find(strArr[i].c_str())){
                if(strArr[i].length()<3){
                    ans += 0;
                }
                else if(strArr[i].length()<5)
                    ans += 1;
                else if(strArr[i].length()<6)
                    ans += 2;
                else if(strArr[i].length()<7)
                    ans += 3;
                else if(strArr[i].length()<8)
                    ans += 5;
                else
                    ans += 11;
                cnt++;
                if(strArr[i].length()==curStr.length()){
                    if(strArr[i]<curStr)
                        curStr = strArr[i];
                }
                else if(strArr[i].length()>curStr.length())
                    curStr = strArr[i];
            }
        }

        cout<<ans<<" "<<curStr<<" "<<cnt<<endl;
        delete t;
    }
}
