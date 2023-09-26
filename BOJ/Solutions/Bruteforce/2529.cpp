#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int n;

string mnm="9999999999", mxm;
int ans[10];
bool chk[10];
bool isLarger[9];

void dfs(int depth){
    if(depth==n+1){
        string s; 
        for (int i = 0; i <= n; i++)
        {
            s += (char)(ans[i]+'0');
        }
        if(mnm>s)mnm = s;
        if(mxm<s)mxm = s;

        //cout<<s<<endl;
        return ;
    }
    for (int i = 0; i < 10; i++)
    {
        if(depth>=1){
            if(!chk[i]){
                if(isLarger[depth-1]){
                    if(ans[depth-1]>i){
                        ans[depth] = i;
                        chk[i] = true;
                        dfs(depth+1);
                        chk[i] = false;
                    }
                }
                else{
                    if(ans[depth-1]<i){
                        ans[depth] = i;
                        chk[i] = true;
                        dfs(depth+1);
                        chk[i] = false;
                    }
                }
            }
        }
        else{
            chk[i] = true;
            ans[depth] = i;
            dfs(depth+1);
            chk[i] = false;
        }

    }
    
}
int main() {    
    FAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        isLarger[i] =  s==">";
    }
    dfs(0);
    cout<<mxm<<endl;
    cout<<mnm<<endl;
}
