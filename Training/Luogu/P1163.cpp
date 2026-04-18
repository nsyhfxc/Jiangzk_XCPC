#include<bits/stdc++.h>
using namespace std;

int main() {
    int w0, w, m;
    cin >> w0 >> w >> m;
    double l = 0.00,r = 3.00;
    auto check = [&](double mid)->bool {
        double t = w0;
        for (int i = 0;i < m;i++) {
            t += mid * t;
            t -= w;
        }
        return t > 0;
    };
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(1) << l * 100 << endl;
    return 0;
}
