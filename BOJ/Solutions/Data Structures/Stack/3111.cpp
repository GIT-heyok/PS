#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

bool isDeleted[300001];

int main(void) {
    FAST
    string n, h;
    cin >> n >> h;
    int nlen = n.length(), hlen = h.length();
    stack<pair<char, int>> stFront, stBack;
    int cnt = 0;
    int l = 0, r = hlen-1;
    while(l<hlen&&r>=0){
        //deleting from front
//        cout<<"idx: "<<l<<" "<<r<<endl;
        if(cnt%2==0){
            stFront.push({h[l],l}); //chr, idx
            if(n[nlen-1]==stFront.top().first&&!isDeleted[l]){ //first char match, should not be deleted
//                cout<<"chr found"<<endl;
                stack<pair<char, int>> st; //variable to store
                bool chk = true; //true if all is matched
                for (int i = 0; i < nlen && !stFront.empty(); ++i) {
                    char curChr = stFront.top().first;
                    int curIdx = stFront.top().second;
                    if(isDeleted[curIdx]){
                        stFront.pop();
                        i--;

                    }
                    else if(curChr==n[nlen-i-1]){
                        st.push(stFront.top());
                        stFront.pop();
                    }
                    else{
                        chk = false;
                        break;
                    }
                }
                if(!chk||st.size()!=nlen){
                    while(!st.empty()){
                        stFront.push(st.top());
                        st.pop();
                    }
                }
                else{
                    cnt++;
                    while(!st.empty()){
                        isDeleted[st.top().second] = true;
                        st.pop();
                    }
                }
            }
            l++;
        }
        else{

            stBack.push({h[r],r}); //chr, idx
//            cout<<"pushed "<<h[r]<<" "<<r<<" to stBack"<<endl;
//            for (int i = 0; i < hlen; ++i) {
//                cout<<isDeleted[i]<<" ";
//            }
//            cout<<endl;
            if(n[0]==stBack.top().first&&!isDeleted[r]){ //first char match, should not be deleted
//                cout<<"chr found"<<endl;
                stack<pair<char, int>> st; //variable to store
                bool chk = true; //true if all is matched
                for (int i = 0; i < nlen && !stBack.empty(); ++i) {
                    char curChr = stBack.top().first;
                    int curIdx = stBack.top().second;
                    if(isDeleted[curIdx]){
//                        cout<<"popped "<<curChr<<" "<<curIdx<<" from stBack (not existent)"<<endl;
                        stBack.pop();
                        i--;
                    }
                    else if(curChr==n[i]){
//                        cout<<"moved "<<stBack.top().first<<" "<<stBack.top().first<<" from stBack to st"<<endl;
                        st.push(stBack.top());
                        stBack.pop();
                    }
                    else{
                        chk = false;
                        break;
                    }
                }
                if(!chk||st.size()!=nlen){
                    while(!st.empty()){
//                        cout<<"moved "<<st.top().first<<" "<<st.top().first<<" from st to stBack"<<endl;
                        stBack.push(st.top());
                        st.pop();
                    }
                }
                else{
                    cnt++;
                    while(!st.empty()){

//                        cout<<"set "<<st.top().first<<" "<<st.top().first<<" as deleted"<<endl;
                        isDeleted[st.top().second] = true;
                        st.pop();
                    }
                }
            }
            else if(isDeleted[r]){

            }
            r--;
        }

    }

    for (int i = 0; i < hlen; ++i) {
        if(!isDeleted[i])cout<<h[i];
    }
    cout<<endl;

}

