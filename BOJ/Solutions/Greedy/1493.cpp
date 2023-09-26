#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
typedef long long ll;
ll n;
ll box[31];
ll realBox[31];
void cutTheBox(ll l, ll w, ll h){
    if(l==0||w==0||h==0)return;
    // cout<<l<<" "<<w<<" "<<h<<endl;
    ll mxm = min(l, min(w, h));
    ll idx = 0;
    for (; idx < 32; idx++)
    {
        if(mxm<(1<<idx)){
            idx--;
            break;
            
        }
    }
    ll i = 1<<idx;
    box[idx]+=(l/i)*(w/i)*(h/i);
    ll lL = l-(l/i)*i;
    ll lW = w-(w/i)*i;
    ll lH = h-(h/i)*i;
    ll rL = l-lL;
    ll rW = w-lW;
    ll rH = h-lH;
    cutTheBox(lL, lW, lH);
    cutTheBox(rL, lW, lH);
    cutTheBox(lL, rW, lH);
    cutTheBox(lL, lW, rH);
    cutTheBox(rL, rW, lH);
    cutTheBox(rL, lW, rH);
    cutTheBox(lL, rW, rH);
}
int main() {    
    FAST
    ll l, w, h;
    cin >> l >> w >> h;
    cutTheBox(l,w,h);
    ll m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int typ, amt;
        cin >> typ >> amt;
        realBox[typ] = amt;
    }
    ll ans = 0;
    // for (int i = 0; i < 31; i++)
    // {
    //     cout<<box[i]<<" ";
    // }
    // cout<<endl;

    // for (int i = 0; i < 31; i++)
    // {
    //     cout<<realBox[i]<<" ";
    // }
    // cout<<endl;
    bool chk = false;
    for (int i = 31; i >= 0; i--)
    {
        if(box[i]>realBox[i]){
            if(i==0){
                chk = true;
            }
            else{
                box[i]-=realBox[i];
                box[i-1]+=box[i]*8;
                ans+=realBox[i];
            }
        }
        else if(box[i]==realBox[i]){
            ans+=realBox[i];
        }
        else{
            ans+=box[i];
        }
        
    }
    if(chk)cout<<-1<<endl;
    else cout<<ans<<endl;
    
    
}
