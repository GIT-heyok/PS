#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;



class Trie {
public:
    vector<Trie *> childs;
    char currentChr;
    bool finish;
    Trie() {
        finish = false;
    }

    ~Trie() {
        for (int i = 0; i < childs.size(); ++i) {
            delete childs[i];
        }
        childs.clear();
    }

    void insert(string &s, int idx) {
//        cout<<"inserted "<<s[idx]<<endl;
        if (idx == s.length()-1) {
//            cout<<"finish"<<endl;
            finish = true;
            return;
        }

        int curChildIdx = -1;
        for (int i = childs.size() - 1; i >= 0; --i) {
            if (childs[i]->currentChr == s[idx + 1]) {
                curChildIdx = i;
                break;
            }
        }

        if (curChildIdx == -1) {
            childs.push_back(new Trie());
            curChildIdx = childs.size() - 1;
            childs[curChildIdx]->currentChr = s[idx + 1];
        }

        childs[curChildIdx]->insert(s, idx + 1);
    }
};

Trie* t1 = new Trie();
Trie* t2 = new Trie();
bool t1Arr[2001], t2Arr[2001];

int main(void) {
    FAST
    int c, n;
    cin >> c >> n;
    for (int i = 0; i < c; ++i) {
        string s;
        cin >> s;
        t1->insert(s, -1);
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        t2->insert(s, -1);
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length()+1; ++j) {
            t1Arr[j] = false;
            t2Arr[j] = false;
            
        }
        Trie* curNode = t1;
        for (int j = 0; j < s.length(); ++j) {
            int nodeIdx = -1;
            for (int k = 0; k < curNode->childs.size(); ++k) {
                if(curNode->childs[k]->currentChr==s[j]){
//                    cout<<curNode->childs[k]->currentChr<<" found"<<endl;
                    nodeIdx = k;
                    break;
                }
            }
            if(nodeIdx==-1){
                break;
            }
            if(curNode->childs[nodeIdx]->finish)t1Arr[j] = true;
            curNode = curNode->childs[nodeIdx];
        }

        curNode = t2;
        for (int j = s.length()-1; j >= 0; --j) {
            int nodeIdx = -1;
            for (int k = 0; k < curNode->childs.size(); ++k) {
                if(curNode->childs[k]->currentChr==s[j]){
                    nodeIdx = k;
                    break;
                }
            }
            if(nodeIdx==-1){
                break;
            }
//            cout<<nodeIdx<<" "<<t2->childs[nodeIdx]->currentChr<<" "<<curNode->finish<<endl;
            if(curNode->childs[nodeIdx]->finish)t2Arr[j] = true;
            curNode = curNode->childs[nodeIdx];
        }
//        cout<<s<<endl;
//        for (int j = 0; j < s.length()+1; ++j) {
//            cout<<t1Arr[j]<<" ";
//        }
//        cout<<endl;
//        for (int j = 0; j < s.length()+1; ++j) {
//            cout<<t2Arr[j]<<" ";
//        }
//        cout<<endl;
        bool chk = false;
        for (int j = 0; j < s.length(); ++j) {
            if(t1Arr[j]&&t2Arr[j+1]){
                chk = true;
            }
        }
        if(chk){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }



}
