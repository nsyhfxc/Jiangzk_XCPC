#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct Point {
    i32 x, y;
};

i32 cp(Point p0, Point p1, Point p2) {
    return abs((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}

int main() {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    i32 min = -1;
    for (int i = 0; i < n; i++) {
        vector<Point> others;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            others.push_back({pts[j].x - pts[i].x, pts[j].y - pts[i].y});
        }
        sort(others.begin(), others.end(), [](const Point &a, const Point &b) {
            return atan2(a.y, a.x) < atan2(b.y, b.x);
        });
        int m = others.size();
        for (int j = 0; j < m; j++) {
            const i32 cur = abs(others[j].x * others[(j + 1) % m].y - others[(j + 1) % m].x * others[j].y);
            if (min == -1 || cur < min) {
                min = cur;
            }
            if (min == 0) break;
        }
        if (min == 0) break;
    }

    cout << fixed << setprecision(3) << static_cast<double>(min) / 2.0 << endl;
    return 0;
}
