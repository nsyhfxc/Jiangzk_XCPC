#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    while(n--){
    	int x;
    	cin >> x;
    	if(x < 1700){
    		cnt++;
		}
	}
	cout << cnt << endl;
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
