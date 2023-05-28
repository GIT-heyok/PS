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

//USELESS LAZY SEG
struct SegTreeLazy{
    int n;
    vll a , t, lazy;
    SegTreeLazy(int sz){
        n = sz;
        a.resize(n);
        t.resize(4*n);
        lazy.resize(4*n);
    }
    void propagate(int ss ,int se, int idx)
    {
        if(lazy[idx]%2==1)t[idx] = (se-ss+1)-t[idx];
        if(ss!=se)
        {
            lazy[2*idx+1]+= lazy[idx];
            lazy[2*idx+2]+= lazy[idx];
        }
        lazy[idx] = 0 ;
    }
    
    void update(int ss, int se, int qs, int qe, int idx ,ll value)
    {
        if(lazy[idx]!=0)
            propagate(ss, se, idx);
        if(qs>se || qe<ss)
            return;
        if(qs<=ss && qe>=se)
        {
            lazy[idx] = value;
            propagate(ss, se, idx);
            return ;
        }
        int mid = (ss+se)/2;
        update(ss, mid , qs, qe, 2*idx+1 , value);
        update(mid+1, se, qs ,qe ,2*idx+2 , value);
        t[idx] = t[2*idx+1] + t[2*idx+2];
    }
    
    /**interface to call update function
     * l and r in this function is 0-indexed 
     */
    void update(int l, int r, ll val)
    {
        update(0 , n-1, l, r, 0 , val);
    }
    
    ll get(int ss, int se, int qs, int qe, int idx)
    {
        if(lazy[idx]!=0)
            propagate(ss, se, idx);
        if(qs>se || qe<ss)
            return 0;
        if(qs<=ss && qe>=se)
            return t[idx];
    
        int mid = (ss+se)/2;
        return get(ss, mid, qs ,qe , 2*idx+1) + get(mid+1 , se, qs , qe, 2*idx+2);
    }
    
    /**interface to call get function
     * l and r in this function is 0-indexed 
     */
    ll get(int l, int r)
    {
		return get(0 , n-1, l , r , 0); 
        
    }
    void build(int ss, int se, int idx)
    {
        if(ss==se)
        {
            t[idx] = a[ss];
            return;
        }
        int mid= (ss+se)/2;
        build(ss , mid , 2*idx+1);
        build(mid+1, se,2*idx+2);
        t[idx] = t[2*idx+1] + t[2*idx+2];
    }
    
    /**interface to call build function*/
    void build()
    {
        build(0 , n-1, 0);
    }
		
};

//updating only if lazy is an odd number
int main()
{
    FAST
	int  type , l ,r ,q , n;
	ll val , ans;  
		cin >> n >> q;
    	SegTreeLazy seg(n);
	    for(int i=0; i<4*n; i++)
			seg.lazy[i] =0 ;
		for(int i=0; i<n; i++){
            seg.a[i] = 0;
        }
    
		seg.build();
		for(int i=0; i<q; i++)
		{
		    cin >> type >> l >> r;
			if(type==0)
			{
				seg.update(l-1,r-1,1);
			}
			else 
			{
				ans = seg.get(l-1,r-1);
				cout<<ans<<endl;
			}
		}
	
	return 0;
}


