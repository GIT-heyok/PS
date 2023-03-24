struct segtree{
    int n;
    vll a , t;
    segtree(int sz){
        n = sz;
        a.resize(n);
        t.resize(4*n);
    }
    
    void update(int ss, int se, int ii, int idx ,ll value)
    {
        // cout<<idx<<" "<<t[idx]<<endl;
        if(ii>se || ii<ss)
            return;
        if(ii==ss&&ss==se){
            t[idx] = value;
            return;
        }
        int mid = (ss+se)/2;
        update(ss, mid , ii, 2*idx+1 , value);
        update(mid+1, se, ii ,2*idx+2 , value);
        t[idx] = min(t[2*idx+1],t[2*idx+2]);
    }
    
    /**interface to call update function
     * l and r in this function is 0-indexed 
     */
    void update(int ii, ll val)
    {
        update(0 , n-1, ii, 0 , val);
    }
    
    ll get(int ss, int se, int qs, int qe, int idx)
    {
        if(qs>se || qe<ss) //out of bound
            return INF;
        if(qs<=ss&&qe>=se){
            return t[idx];
        }
        int mid = (ss+se)/2;
        return min(get(ss, mid, qs, qe , 2*idx+1),get(mid+1 , se, qs, qe, 2*idx+2));
    }
    
    /**interface to call get function
     * l and r in this function is 0-indexed 
     */
    ll get(int l, int  r)
    {
		return get(0 , n-1, l, r , 0); 
        
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
        t[idx] = min(t[2*idx+1], t[2*idx+2]);
    }
    
    /**interface to call build function*/
    void build()
    {
        build(0 , n-1, 0);
    }
		
};


