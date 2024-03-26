#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;
ll euclidMnm = 1e18, euclidMxm = 0, manhattanMnm = 1e18, manhattanMxm = 0, chebyshevMnm = 1e18, chebyshevMxm = 0;

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

ll manhattanDist(const vector2D &rhs1, const vector2D &rhs2) {
    return abs(rhs1.x-rhs2.x)+abs(rhs1.y-rhs2.y);
}

ll chebyshevDist(const vector2D &rhs1, const vector2D &rhs2) {
    return max(abs(rhs1.x-rhs2.x),abs(rhs1.y-rhs2.y));
}

inline int quad(vector2D p) {
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

void rotatingCalipers(vector<vector2D> &stars) {
//    cout<<endl;
    swap(stars[0], *min_element(stars.begin(), stars.end()));
    sort(stars.begin() + 1, stars.end(), [&](vector2D p, vector2D q) {
        vector2D aa = p - stars[0];
        vector2D bb = q - stars[0];
        ll cc = aa / bb;
        return (cc > 0 || (cc == 0 && dist(p, stars[0]) < dist(q, stars[0])));
    });

//    for (int i = 0; i < stars.size(); ++i) {
//        cout<<stars[i]<<endl;
//    }

    vector<vector2D> stackk;
    for (int i = 0; i < stars.size(); ++i) {
        while (stackk.size() > 1 && ccw(stackk[stackk.size() - 2], stackk[stackk.size() - 1], stars[i]) <= 0) {
            stackk.pop_back();
        }
        stackk.push_back(stars[i]);
    }

    int j = 0;
    int sSz = stackk.size();
    for (int i = 0; i < sSz; ++i) {
        int ni = (i + 1) % sSz;
        int nj = (j + 1) % sSz;
        vector2D p = stackk[nj] - stackk[j];
        vector2D q = stackk[ni] - stackk[i];
        euclidMxm = max(euclidMxm, dist(stackk[i], stackk[j]));
        manhattanMxm = max(manhattanMxm, manhattanDist(stackk[i], stackk[j]));
        while (q / p > 0) {
            j = (j + 1) % sSz;
            nj = (j + 1) % sSz;
            euclidMxm = max(euclidMxm, dist(stackk[i], stackk[j]));
            manhattanMxm = max(manhattanMxm, manhattanDist(stackk[i], stackk[j]));
            p = stackk[nj] - stackk[j];
        }
    }

}

int main(void) {
    FAST
    int n;
    cin >> n;
    vector<vector2D> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].x >> vec[i].y;
    }
    vector<vector2D> calipers(n);
    for (int i = 0; i < n; ++i) {
        calipers[i] = vec[i];
    }
    rotatingCalipers(calipers);
    sort(vec.begin(), vec.end());
    ll mnmY = 1e18, mxmY = 0;
    for (int i = 0; i < vec.size(); ++i) {
        mnmY = min(mnmY, vec[i].y);
        mxmY = max(mxmY, vec[i].y);
    }
    chebyshevMxm = max(mxmY-mnmY, vec[n-1].x-vec[0].y);
    set<pair<ll, ll>> s1, s2, s3;
    s1.insert({vec[0].y, vec[0].x});
    s1.insert({vec[1].y, vec[1].x});
    s2.insert({vec[0].y, vec[0].x});
    s2.insert({vec[1].y, vec[1].x});
    s3.insert({vec[0].y, vec[0].x});
    s3.insert({vec[1].y, vec[1].x});

    int idx = 0;
    for (int i = 2; i < n; ++i) {
        while(idx<i){
            ll d =vec[i].x - vec[idx].x;
            if(d*d<=euclidMnm)break;
            s1.erase({vec[idx].y,vec[idx].x});
            idx++;
        }
        auto start = s1.lower_bound({vec[i].y-sqrt(euclidMnm),-1e18});
        auto end= s1.upper_bound({vec[i].y+sqrt(euclidMnm),1e18});
        for (auto it=start; it!=end; ++it) {
            euclidMnm = min(euclidMnm, dist(vector2D(it->second, it->first), vec[i]));
        }
        s1.insert({vec[i].y, vec[i].x});
    }
    idx = 0;
    for (int i = 2; i < n; ++i) {
        while(idx<i){
            ll d =vec[i].x - vec[idx].x;
            if(d*d<=manhattanMnm)break;
            s2.erase({vec[idx].y,vec[idx].x});
            idx++;
        }
        auto start = s2.lower_bound({vec[i].y-manhattanMnm,-1e18});
        auto end= s2.upper_bound({vec[i].y+manhattanMnm,1e18});
        for (auto it=start; it!=end; ++it) {
            manhattanMnm = min(manhattanMnm, manhattanDist(vector2D(it->second, it->first), vec[i]));
        }
        s2.insert({vec[i].y, vec[i].x});
    }
    idx = 0;
    for (int i = 2; i < n; ++i) {
        while(idx<i){
            ll d =vec[i].x - vec[idx].x;
            if(d*d<=chebyshevMnm)break;
            s3.erase({vec[idx].y,vec[idx].x});
            idx++;
        }
        auto start = s3.lower_bound({vec[i].y-chebyshevMnm,-1e18});
        auto end= s3.upper_bound({vec[i].y+chebyshevMnm,1e18});
        for (auto it=start; it!=end; ++it) {
            chebyshevMnm= min(chebyshevMnm,chebyshevDist(vector2D(it->second, it->first), vec[i]));
        }
        s3.insert({vec[i].y, vec[i].x});
    }
    cout<<euclidMxm<<endl;
    cout<<euclidMnm<<endl;
    cout<<manhattanMxm<<endl;
    cout<<manhattanMnm<<endl;
    cout<<chebyshevMxm<<endl;
    cout<<chebyshevMnm<<endl;

}
