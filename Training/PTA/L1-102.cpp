    #include<bits/stdc++.h>
    using namespace std;

    int main() {
        int n;
        cin >> n;
        vector<pair<double, int> > arr(n + 1, {0, 0});
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first;
        }
        int x, y;
        while (cin >> x >> y) {
            if (x == 0 && y == 0) {
                break;
            }
            arr[x].second += y;
        }
        double sum = 0.0;
        for (int i = 1; i <= n; i++) {
            cout << arr[i].second << endl;
            sum += arr[i].first * arr[i].second;
        }
        cout << fixed << setprecision(2) << sum << endl;
        return 0;
    }
