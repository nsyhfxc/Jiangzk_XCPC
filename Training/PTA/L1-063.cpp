#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string,string>>Baby(n);
    for (int i = 0; i < n; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if (a) {
            if (b < 130) {
                Baby[i].first = "duo chi yu!";
            }else if (b == 130) {
                Baby[i].first = "wan mei!";
            }else {
                Baby[i].first = "ni li hai!";
            }
            if (c < 27) {
                Baby[i].second = "duo chi rou!";
            }else if (c == 27) {
                Baby[i].second = "wan mei!";
            }else {
                Baby[i].second = "shao chi rou!";
            }
        }
        if (!a) {
            if (b < 129) {
                Baby[i].first = "duo chi yu!";
            }else if (b == 129) {
                Baby[i].first = "wan mei!";
            }else {
                Baby[i].first = "ni li hai!";
            }
            if (c < 25) {
                Baby[i].second = "duo chi rou!";
            }else if (c == 25) {
                Baby[i].second = "wan mei!";
            }else {
                Baby[i].second = "shao chi rou!";
            }
        }
    }
    for (const auto &[x,y] : Baby) {
        cout << x << " " << y << endl;
    }
    return 0;
}
