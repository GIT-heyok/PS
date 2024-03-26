#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

typedef long long ll;

class point2D{
public:
    ll x, y;

    point2D(ll a, ll b): x(a), y(b){

    }

};

//should be base vector

class vector2D{
public:
    ll x, y;
    vector2D(point2D p){
        x = p.x;
        y = p.y;
    }
    vector2D(ll a, ll b): x(a), y(b){

    }

    vector2D(): x(0), y(0){

    }
    vector2D operator+(vector2D& vec1) const{
        return vector2D(x+vec1.x, y+vec1.y);
    }

    vector2D operator-(vector2D& vec1){
        return vector2D(x-vec1.x, y-vec1.y);
    }

    bool operator==(vector2D& vec1){
        return x==vec1.x&&y==vec1.y;
    }

    //외적
    ll operator/(vector2D& vec1){
        return x*vec1.y-y*vec1.x;
    }


    ll dist(vector2D r){
        return (r.x-x)*(r.x-x)+(r.y-y)*(r.y-y);
    }

    bool operator<(vector2D vec1) const{
        if(x!=vec1.x){
            return x<vec1.x;
        }
        else{
            return y<vec1.y;
        }
    }

    void print(){
        cout<<x<<" "<<y<<endl;
    }

};

ll ccw(vector2D a, vector2D r, vector2D q){
    vector2D aa = r-a;
    vector2D bb = q-a;
    ll cc = aa/bb;
    return cc;
}

int main(void) {
    FAST
    int n;
    cin >> n;
    vector<vector2D> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].x >> vec[i].y;
    }

    swap(vec[0], *min_element(vec.begin(), vec.end()));
    sort(vec.begin()+1, vec.end(), [&](vector2D p, vector2D q){
        vector2D aa = p-vec[0];
        vector2D bb = q-vec[0];
        ll cc = aa/bb;
        return (cc>0||(cc==0&& p.dist(vec[0])<q.dist(vec[0])));
    });

    vector<vector2D> stackk;
    for (int i = 0; i < vec.size(); ++i) {
        while(stackk.size()>1&&ccw(stackk[stackk.size()-2], stackk[stackk.size()-1], vec[i])<=0){
            stackk.pop_back();
        }
        stackk.push_back(vec[i]);
    }

    vector2D a, b;
    ll dist = 0;
    int j = 0;
    int sSz = stackk.size();
    for (int i = 0; i < sSz; ++i) {
        int ni = (i+1)%sSz;
        int nj = (j+1)%sSz;
        vector2D p = stackk[nj]-stackk[j];
        vector2D q = stackk[ni]-stackk[i];
        dist = max(dist, stackk[i].dist(stackk[j]));
//        cout<<"p: ";
//        p.print();
        while(q/p>0){
//            cout<<"q: ";
//            q.print();
            j=(j+1)%sSz;
            nj = (j+1)%sSz;
            dist = max(dist, stackk[i].dist(stackk[j]));
            p = stackk[nj]-stackk[j];
        }
    }
    cout<<dist<<endl;
}
