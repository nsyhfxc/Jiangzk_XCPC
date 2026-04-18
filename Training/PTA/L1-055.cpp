#include<bits/stdc++.h>
using namespace std;
int main() {
    int pa, pb;
    int judge[3];
    cin >> pa >> pb;
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < 3; i++) {
        cin >> judge[i];
        if (judge[i] == 0) cnt_a++;
        else cnt_b++;
    }
    if ((pa > pb && cnt_a >= 1) || (pa < pb && cnt_a == 3)) {
        cout << "The winner is a: " << pa << " + " << cnt_a << endl;
    } else {
        cout << "The winner is b: " << pb << " + " << cnt_b << endl;
    }

    return 0;
}
