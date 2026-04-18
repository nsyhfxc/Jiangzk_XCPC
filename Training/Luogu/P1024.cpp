#include<bits/stdc++.h>
using namespace std;
double a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    auto func = [&](double x)->double {
        return a * x * x * x + b * x * x + c * x + d;
    };
    auto find = [&](double l, double r)->double {
        while (r - l > 0.0001) {
            double mid = (l + r) / 2;
            if (func(mid) * func(r) < 0) {
                l = mid;
            }else {
                r = mid;
            }
        }
        return l;
    };
    for (int i = -100; i <= 100; i++) {
        if (func(i) == 0) {
            cout << fixed << setprecision(2) << (double)i << " ";
        }
        if (func(i) * func(i + 1) < 0) {
            cout << fixed << setprecision(2) << (double)find(i, i + 1) << " ";
        }
    }
}
