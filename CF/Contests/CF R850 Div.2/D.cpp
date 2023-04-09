#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 500001;
const ll INF = 1234567890ll;


int parse(int w, int i){
        if(w==0){
            if(i==0){
                return 0;
            }
            else if(i==1){
                return 1;
            }
            else if(i==2){
                return 2;
            }
            else{
                return 3;
            }
        }
        else if(w==1){
            if(i==0){
                return 4;
            }
            else if(i==1){
                return 5;
            }
            else{
                return 6;
            }
        }
        else if(w==2){
            if(i==0){
                return 7;
            }
            else{
                return 8;
            }
        }
        else{
            return 9;
        }
}
string makeAns(int n, string s1,int tt, string s2){
    string temp;
    temp+=to_string(n);
    temp+=" ";
    temp+=s1;
    temp+= " ";
    temp+=to_string(tt);
    temp+=" ";
    temp+=s2;
    temp+=" ";
    return temp;
}
int main(){
    FAST
    int T;
    cin >> T;
    
    while(T--){
        queue<int> arr[10];
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            int w=0, ii=0;
            for (int j = 0; j < 3; j++)
            {
                if(s[i]=='w')w++;
                if(s[i]=='i')ii++;
            }
            arr[parse(w, ii)].push(i);
            
        }
        vector<string> ans;
        while(!arr[0].empty()){
            int now = arr[0].front();
            arr[0].pop();
            if(!arr[3].empty()){
                int temp = arr[3].front();
                arr[3].pop();
                ans.push_back(makeAns(now, "n",temp,"i"));
                arr[1].push(now);
                arr[2].push(temp);
                continue;
            }
            if(!arr[9].empty()){
                int temp=arr[9].front();
                arr[9].pop();
                ans.push_back(makeAns(now, "n",temp,"w"));
                arr[4].push(now);
                arr[8].push(temp);
                continue;
            }
            if(!arr[6].empty()){
                int temp=arr[6].front();
                arr[6].pop();
                ans.push_back(makeAns(now, "n",temp,"i"));
                arr[1].push(now);
                arr[5].push(temp);
                continue;
            }
            if(!arr[8].empty()){
                int temp=arr[8].front();
                arr[8].pop();
                ans.push_back(makeAns(now, "n",temp,"w"));
                arr[4].push(now);
                arr[5].push(temp);
                continue;
            }
            
        }
        //0 finish
        while(!arr[3].empty()){
            int now = arr[3].front();
            arr[3].pop();
            if(!arr[9].empty()){
                int temp=arr[9].front();
                arr[9].pop();
                ans.push_back(makeAns(now, "i",temp,"w"));
                arr[6].push(now);
                arr[8].push(temp);
                continue;
            }
            if(!arr[4].empty()){
                int temp=arr[4].front();
                arr[4].pop();
                ans.push_back(makeAns(now, "i",temp,"n"));
                arr[2].push(now);
                arr[5].push(temp);
                continue;
            }
            if(!arr[8].empty()){
                int temp=arr[8].front();
                arr[8].pop();
                ans.push_back(makeAns(now, "i",temp,"w"));
                arr[6].push(now);
                arr[5].push(temp);
                continue;
            }
        }
            //0, 3 finish
            while(!arr[9].empty()){
                int now = arr[9].front();
                arr[9].pop();
                if(!arr[1].empty()){
                    int temp=arr[1].front();
                    arr[1].pop();
                    
                ans.push_back(makeAns(now, "w",temp,"n"));
                    arr[8].push(now);
                    arr[5].push(temp);
                    continue;
                }
                if(!arr[2].empty()){
                    int temp=arr[2].front();
                    arr[2].pop();
                   
                ans.push_back(makeAns(now, "w",temp,"i"));
                    arr[9].push(now);
                    arr[5].push(temp);
                    continue;
                }
                
            }
            //0, 3, 9 finish
            while(!arr[1].empty()){
                int now = arr[1].front();
                arr[1].pop();
                if(!arr[8].empty()){
                    int temp=arr[8].front();
                    arr[8].pop();
                    
                ans.push_back(makeAns(now, "n",temp,"w"));
                    arr[5].push(now);
                    arr[5].push(temp);
                    continue;
                }
                if(!arr[6].empty()){
                    int temp=arr[6].front();
                    arr[6].pop();
                    
                ans.push_back(makeAns(now, "n",temp,"i"));
                    arr[5].push(now);
                    arr[8].push(temp);
                    continue;
                }
            }
            //0,3,9,1 finish
            while(!arr[2].empty()){
                int now = arr[2].front();
                arr[2].pop();
                if(!arr[7].empty()){
                    int temp=arr[7].front();
                    arr[7].pop();
                    
                ans.push_back(makeAns(now, "i",temp,"w"));
                    arr[5].push(now);
                    arr[5].push(temp);
                    continue;
                }
            }
            //0,3,9,1,8,2,7 finish
            while(!arr[4].empty()){
                int now = arr[4].front();
                arr[4].pop();
                if(!arr[6].empty()){
                    int temp=arr[6].front();
                    arr[6].pop();
                    
                ans.push_back(makeAns(now, "n",temp,"i"));
                    arr[5].push(now);
                    arr[5].push(temp);
                    continue;
                }
            }
        cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
        
    }
}