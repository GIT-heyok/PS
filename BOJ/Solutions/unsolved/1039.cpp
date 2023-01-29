#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
int main(){
    FAST
    int n, k;
    cin >> n >> k;
    /*operation is impossible only when:
    n is one digit,
    n is #00000 (k>=1)
    */

        //zero count;
        int zero=0, others = 0;
        vi dig;
        while(n>0){
            if(n%10==0){zero++;
                dig.push_back(0);
            }
            else {others++;
                dig.push_back(n%10);
            }
            n/=10;
        }
        if(others==1){
            cout<<-1<<endl;
        }
        else{
            bool hasEqual = false;
            int totdigits = zero+others;
            reverse(all(dig));
            //digits done
            int index = 0;
            for(int i=0; i<totdigits&&index<k; i++){
                if(i==0){
                    int minIndex = 0, minValue = dig[0];
                    for(int j=totdigits; j>=i+1; j--){
                        if(dig[j]>0&&dig[j]>minValue){
                            minIndex = j;
                            minValue = dig[j];
                        }
                        else if(dig[j]>0&&dig[j]==minValue){
                            hasEqual = true;
                        }
                    }
                    if(minIndex!=0){
                        dig[minIndex] = dig[0];
                        dig[0] = minValue;
                        index++;
                    }
                }
                else{
                    int minIndex = i, minValue = dig[i];
                    for(int j=totdigits-1; j>=i+1; j--){
                        if(dig[j]>minValue){
                            minIndex = j;
                            minValue = dig[j];
                        }
                        else if(dig[j]>0&&dig[j]==minValue){
                            hasEqual = true;
                        }
                    }
                    if(minIndex!=i){
                        dig[minIndex] = dig[i];
                        dig[i] = minValue;
                        index++;
                    }
                }
            } 
            if(index<k){
                bool needChange = (k-index)%2;
                if(needChange){
                    swap(dig[totdigits-1],dig[totdigits-2]);
                }
            }
            for(int i: dig){
                cout<<i;
            }
            cout<<endl;
        }
   
}