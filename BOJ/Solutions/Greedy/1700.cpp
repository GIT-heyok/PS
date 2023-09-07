#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    bool isOpen[k+1];
    int dataStructure[k+1];
    int order[k];
    
    for (int i = 0; i < k; i++)
    {
        cin >> order[i];
    }
    int ans = 0;

    memset(isOpen, 0, sizeof(isOpen));
    memset(dataStructure, 0, sizeof(dataStructure));

    for (int i = 0; i < k; i++)
    {
        int current = order[i];
        int nextOccurrence = (1<<29);
        for (int j = k-1; j >= i+1; j--)
        {
            if(order[j]==current)nextOccurrence = j;
        }
        
        if(isOpen[current]){
            dataStructure[current] = nextOccurrence;
        }
        else{
            int openCnt = 0;
            int latestOccurrence = -1;
            int latestOccurrenceIndex = -1;
            for (int j = 1; j <= k; j++)
            {
                openCnt +=isOpen[j];
                if(isOpen[j]&&dataStructure[j]>latestOccurrence){
                    latestOccurrence = dataStructure[j];
                    latestOccurrenceIndex = j;
                }
            }

            dataStructure[current] = nextOccurrence;
            if(openCnt==n){
                ans++;
                isOpen[current] = true;
                isOpen[latestOccurrenceIndex] = false;
            }
            else{
                isOpen[current] = true;
            }
            
        }
    }
        cout<<ans<<endl;
/*

    for (int i = 0; i <= k; i++)
    {
        cout<<dataStructure[i]<<endl;
    }
*/
    
    
    
}