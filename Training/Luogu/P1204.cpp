#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1000005;
int diff[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mnt = MAXN, mxt = 0;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        mnt = min(mnt, start);
        mxt = max(mxt, end);
        diff[start]++;
        diff[end]--;
    }

    int max_milk = 0;
    int max_idle = 0;

    int current_milk_len = 0;
    int current_idle_len = 0;
    int active_farmers = 0;

    // 从第一个人开始挤奶的时间遍历到最后一个人结束的时间
    for (int i = mnt; i < mxt; i++) {
        active_farmers += diff[i];

        if (active_farmers > 0) {
            // 当前有人在挤奶
            current_milk_len++;
            max_milk = max(max_milk, current_milk_len);
            current_idle_len = 0; // 重置无人时间
        } else {
            // 当前没人在挤奶
            current_idle_len++;
            max_idle = max(max_idle, current_idle_len);
            current_milk_len = 0; // 重置有人时间
        }
    }

    cout << max_milk << " " << max_idle << endl;

    return 0;
}
