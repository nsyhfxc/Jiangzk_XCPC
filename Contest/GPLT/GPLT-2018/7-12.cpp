#include<bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
typedef pair<double, int> P;
const int maxn = 1005;
int n, m, sex[maxn], a, b;
vector<int> p[maxn];
double rx[maxn], ry[maxn];

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    sex[x] = f;
    return x;
}

inline void out(int x) {
    if (x > 9) out(x / 10);
    putchar(x % 10 + '0');
}

inline void put(int &x, int &y) {
    if (sex[x] < 0) putchar('-');
    out(x);
    putchar(' ');
    if (sex[y] < 0) putchar('-');
    out(y);
    putchar('\n');
}

bool cmp(const P &x, const P &y) {
    if (x.fi == y.fi) {
        if (x.sc == a || x.sc == b) return true;
        if (y.sc == a || y.sc == b) return false;
        return x.sc < y.sc;
    }
    return x.fi > y.fi;
}

inline void deal(int x, vector<P> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (i && v[i].fi < v[i - 1].fi) break;
        put(x, v[i].sc);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        p[i].resize(k);
        for (int j = 0; j < k; j++) p[i][j] = read();
    }
    a = read(), b = read();
    for (int i = 0; i < m; i++)
        for (int &x: p[i]) {
            if (x == a) for (int &y: p[i]) rx[y] += 1.0 / p[i].size();
            if (x == b) for (int &y: p[i]) ry[y] += 1.0 / p[i].size();
        }
    vector<P> pa, pb;
    for (int i = 0; i < n; i++) {
        if ((sex[i] ^ sex[a]) < 0) pa.push_back(P(rx[i], i));
        if ((sex[i] ^ sex[b]) < 0) pb.push_back(P(ry[i], i));
    }
    sort(pa.begin(), pa.end(), cmp);
    sort(pb.begin(), pb.end(), cmp);
    if (pa.size() && pb.size() && pa[0].sc == b && pb[0].sc == a) put(a, b);
    else {
        deal(a, pa);
        deal(b, pb);
    }
    return 0;
}
