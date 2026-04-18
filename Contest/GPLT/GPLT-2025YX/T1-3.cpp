#include<bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int face;
    int wealth;
    int health;
    int rating;

    bool operator<(const Person &other) const {
        if (this->rating != other.rating) return this->rating > other.rating;
        return this->name < other.name;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Person> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].face >> arr[i].wealth >> arr[i].health;
        arr[i].rating = arr[i].face * 4 + arr[i].health * 3 + arr[i].wealth * 3;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        cout << arr[i].rating << " " << arr[i].name << endl;
    }
    return 0;
}
