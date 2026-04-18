#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int a,b;
    cin >> a >> b;
    cout << b - a << endl;
    if(b - a > 250){
    	cout << "jiu ting tu ran de..." << endl; 
	}else if(b - a <= 0){
		cout << "hai sheng ma?" << endl;
	}else cout << "nin tai cong ming le!" << endl;
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
