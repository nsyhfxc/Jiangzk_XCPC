#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    stack<int> st;
    i32 water = 0;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && h[i] > h[st.top()]) {
            int bottom = st.top();
            st.pop();
            if (st.empty()) break;
            int left = st.top();
            int waterh = min(h[left], h[i]) - h[bottom];
            int waterw = i - left - 1;

            water += static_cast<i32>(waterh) * waterw;
        }
        st.push(i);
    }

    cout << water << endl;

    return 0;
}
