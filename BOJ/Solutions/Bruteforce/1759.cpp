#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
bool chr[26];
vector<char> vec;
int l, c;
char arr[15];
void solve(int idx, int depth, int con, int vow){
    if(depth==l){
        if(con>=2&&vow>=1){
            for (int i = 0; i < c; ++i) {
                cout<<arr[i];
            }
            cout<<endl;
        }
        return;
    }
    if(idx==c)return;
    for (int i = idx; i < c; ++i) {
        arr[depth] = vec[i];
        if(vec[i]=='a'||vec[i]=='e'||vec[i]=='i'||vec[i]=='o'||vec[i]=='u'){
            solve(i+1, depth+1, con, vow+1);
        }
        else{
            solve(i+1, depth+1, con+1, vow);
        }
    }
}
int main() {
    FAST
    cin >> l >> c;
    for (int i = 0; i < c; ++i) {
        char temp;
        cin >> temp;
        chr[temp-'a']=true;
    }
    for (int i = 0; i < 26; ++i) {
        if(chr[i]){
            vec.push_back((char)('a'+i));
        }
    }

    solve(0,0,0,0);
}
