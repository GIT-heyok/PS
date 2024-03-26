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

    ll dist(vector2D r) {
        return (r.x - x) * (r.x - x) + (r.y - y) * (r.y - y);
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

int main(void) {
    FAST
    int n;
    cin >> n;
    vector<vector2D> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].x >> vec[i].y;
    }
    vector2D vectemp, vecPos;
    cin >> vectemp.x >> vectemp.y;
    vecPos = {(ll)1e9+1, vectemp.y};
//    for (int i = 0; i < n; ++i) {
//        cout << vec[i]<<endl;
//    }

//사분면 비교 후 ccw 입히기
    sort(vec.begin(), vec.end(), [&] (vector2D p, vector2D q) {
        vector2D a= p-vectemp;
        vector2D b= q-vectemp;
        if(quad(a)==quad(b)){
            if(a.x*b.y==a.y*b.x){
                return dist(a,{0,0})<dist(b,{0,0});
            }
            return a.x*b.y>a.y*b.x;
        }
        return quad(a)<quad(b);
    });
    // true if p<q

    for (int i = 0; i < n; ++i) {
        cout << vec[i] << endl;
    }
}
