#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<i32>arr;
    i32 sum = 0, mx = -2e9, mn = 2e9;
    for(int i = 1; i <= n; i++) {
        i32 x;
        cin >> x;
        arr.push_back(x);
        sum += x;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    cout << mx << " " << mn << " " << sum / n << endl;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(arr[i] > (2 * sum / n)) {
            cout << (flag ? " " : "") << i + 1;
            flag = true;
        }
    }
    if(flag == false){
    	cout << "Normal" << endl;
	}


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
