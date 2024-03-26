#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;

/**
 * @author: hyeok2044
 */
class vector2D {
public:
    ll x, y;

    //constructor
    vector2D(ll a, ll b) : x(a), y(b) {}

    vector2D() : x(0), y(0) {}

    // start of comparator
    bool operator==(const vector2D &rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator<(const vector2D &rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }

    bool operator>(const vector2D &rhs) const {
        return x != rhs.x ? x > rhs.x : y > rhs.y;
    }

    bool operator>=(const vector2D &rhs) const {
        return x != rhs.x ? x > rhs.x : y >= rhs.y;
    }

    bool operator<=(const vector2D &rhs) const {
        return x != rhs.x ? x < rhs.x : y <= rhs.y;
    }
    // end of comparator

    // start of operators
    // 덧셈
    vector2D operator+(const vector2D &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    // 뺄셈
    vector2D operator-(const vector2D &rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    // scalar product
    vector2D operator*(const ll rhs) const {
        return {x * rhs, y * rhs};
    }

    // cross product
    ll operator/(vector2D &vec1) const {
        return x * vec1.y - y * vec1.x;
    }

    friend ostream &operator<<(ostream &os, const vector2D &rhs);

};

ostream &operator<<(ostream &os, const vector2D &rhs) {
    os << rhs.x << " " << rhs.y;
    return os;
}

ll dist(const vector2D &rhs1, const vector2D &rhs2) {
    return (rhs1.x - rhs2.x) * (rhs1.x - rhs2.x) + (rhs1.y - rhs2.y) * (rhs1.y - rhs2.y);
}

inline int quad (vector2D p) {
    if (p.x > 0 and p.y > 0) return 0;
    if (p.x <= 0 and p.y > 0) return 1;
    if (p.x <= 0 and p.y <= 0) return 2;
    if (p.x > 0 and p.y <= 0) return 3;
}

ll ccw(vector2D a, vector2D r, vector2D q) {
    vector2D aa = r - a;
    vector2D bb = q - a;
    ll cc = aa / bb;
    return (cc > 0) - (cc < 0);
}
ll rotatingCalipers(vector<vector2D> &stars){
//    cout<<endl;
    swap(stars[0], *min_element(stars.begin(), stars.end()));
    sort(stars.begin()+1, stars.end(), [&](vector2D p, vector2D q){
        vector2D aa = p-stars[0];
        vector2D bb = q-stars[0];
        ll cc = aa/bb;
        return (cc>0||(cc==0&& dist(p, stars[0])<dist(q, stars[0])));
    });

//    for (int i = 0; i < stars.size(); ++i) {
//        cout<<stars[i]<<endl;
//    }

    vector<vector2D> stackk;
    for (int i = 0; i < stars.size(); ++i) {
        while(stackk.size()>1&&ccw(stackk[stackk.size()-2], stackk[stackk.size()-1], stars[i])<=0){
            stackk.pop_back();
        }
        stackk.push_back(stars[i]);
    }

    ll distMx = 0;
    int j = 0;
    int sSz = stackk.size();
    for (int i = 0; i < sSz; ++i) {
        int ni = (i+1)%sSz;
        int nj = (j+1)%sSz;
        vector2D p = stackk[nj]-stackk[j];
        vector2D q = stackk[ni]-stackk[i];
        distMx = max(distMx, dist(stackk[i],stackk[j]));
        while(q/p>0){
            j=(j+1)%sSz;
            nj = (j+1)%sSz;
            distMx = max(distMx, dist(stackk[i],stackk[j]));
            p = stackk[nj]-stackk[j];
        }
    }
    return distMx;

}
int main(void) {
    FAST
    int n, T;
    cin >> n >> T;
    int l, r;
    l = 0;
    r = T;
    vector<pair<vector2D,vector2D>> vec(n);
    for (int i = 0; i < n; ++i) {
        vector2D star, differential;
        cin >> star.x >> star.y >> differential.x >> differential.y;
        vec[i] = {star, differential};
    }

    int idx = 0;
    ll ans = 1e18;
    while(r-l>10){
        int q1 = (2*l+r)/3;
        int q2 = (l+r*2)/3;
        vector<vector2D> stars(n);
        for (int i = 0; i < n; ++i) {
            stars[i] = vec[i].first + vec[i].second*q1;
        }
        ll res1 = rotatingCalipers(stars);
//        cout<<q1<<" : "<<res1<<endl;
        for (int i = 0; i < n; ++i) {
            stars[i] = vec[i].first + vec[i].second*q2;
        }
        ll res2 = rotatingCalipers(stars);
//        cout<<q2<<" : "<<res2<<endl;
        if(res1>res2){
            l = q1;
        }
        else{
            r = q2;
        }

    }
    vector<vector2D> stars(n);
    for (int j = l; j <= r; ++j) {
        for (int i = 0; i < n; ++i) {
            stars[i] = vec[i].first + vec[i].second*j;
        }
        ll res1 = rotatingCalipers(stars);
        if(ans>res1){
            idx = j;
            ans = res1;
        }

    }
    cout<<idx<<endl<<ans<<endl;
}
