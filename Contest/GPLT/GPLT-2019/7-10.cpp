#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 定义人物结构体
struct Person {
    int id;
    string name; // First Name
    bool gender; // true: male, false: female
    int father_id = -1; // 父亲ID，-1表示未知或不在名单内
};

int main() {
    // 优化I/O操作
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Person> people(N);
    // 映射 First Name -> ID，用于查找父亲
    map<string, int> name_to_id;
    // 映射 标准化后的全名Key -> ID，用于处理查询
    map<string, int> full_name_to_id;

    // 临时存储每个人的原始姓氏，用于后续建立父子关系
    vector<string> surnames(N);

    for (int i = 0; i < N; ++i) {
        string name, surname;
        cin >> name >> surname;
        surnames[i] = surname;

        bool is_male = false;
        string base_surname = ""; // 用于构建查询Key的“标准姓”

        // 判断是否为维京人及其性别
        if (surname.size() >= 4 && surname.substr(surname.size() - 4) == "sson") {
            is_male = true;
            // 维京男性的姓是 父亲名 + sson
            base_surname = surname.substr(0, surname.size() - 4);
        } else if (surname.size() >= 7 && surname.substr(surname.size() - 7) == "sdottir") {
            is_male = false;
            // 维京女性的姓是 父亲名 + sdottir
            base_surname = surname.substr(0, surname.size() - 7);
        } else {
            // 非维京人，根据后缀判断性别 (假设是 'm' 或 'f')
            if (surname.back() == 'm') is_male = true;
            else is_male = false;
            // 非维京人的姓在查询时不带后缀
            base_surname = surname.substr(0, surname.size() - 1);
        }

        // 构建用于查询的唯一Key: "First Name + 标准姓"
        // 对于维京人，标准姓其实就是父亲的名字
        // 对于非维京人，标准姓是去掉m/f后的姓
        string key = name + " " + base_surname;

        full_name_to_id[key] = i;
        name_to_id[name] = i; // 记录First Name对应的ID

        people[i] = {i, name, is_male, -1};
    }

    // 建立父子关系
    for (int i = 0; i < N; ++i) {
        string surname = surnames[i];
        string father_first_name = "";

        // 只有维京人的姓包含父亲名字信息
        if (surname.size() >= 4 && surname.substr(surname.size() - 4) == "sson") {
            father_first_name = surname.substr(0, surname.size() - 4);
        } else if (surname.size() >= 7 && surname.substr(surname.size() - 7) == "sdottir") {
            father_first_name = surname.substr(0, surname.size() - 7);
        }

        // 如果解析出了父亲的名字，尝试在名单中查找
        if (!father_first_name.empty()) {
            if (name_to_id.count(father_first_name)) {
                people[i].father_id = name_to_id[father_first_name];
            }
        }
    }

    int M;
    cin >> M;
    while (M--) {
        string n1, s1, n2, s2;
        cin >> n1 >> s1 >> n2 >> s2;

        // 构建查询Key
        string key1 = n1 + " " + s1;
        string key2 = n2 + " " + s2;

        // 检查两人是否在名单内
        if (!full_name_to_id.count(key1) || !full_name_to_id.count(key2)) {
            cout << "NA" << endl;
            continue;
        }

        int id1 = full_name_to_id[key1];
        int id2 = full_name_to_id[key2];

        // 检查性别
        if (people[id1].gender == people[id2].gender) {
            cout << "Whatever" << endl;
            continue;
        }

        // 检查五代以内（实际上是3代以内）是否有公共祖先
        // 题目定义：公共祖先必须比曾祖父辈分高（即第4代及以上）才算“无公共祖先”
        // 所以如果在第1, 2, 3代有交集，则输出 No

        set<int> ancestors1;
        int curr = id1;
        // 向上找3代：父(1), 祖父(2), 曾祖父(3)
        for (int k = 0; k < 3; ++k) {
            if (people[curr].father_id == -1) break;
            curr = people[curr].father_id;
            ancestors1.insert(curr);
        }

        bool found_common = false;
        curr = id2;
        for (int k = 0; k < 3; ++k) {
            if (people[curr].father_id == -1) break;
            curr = people[curr].father_id;
            if (ancestors1.count(curr)) {
                found_common = true;
                break;
            }
        }

        if (found_common) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}
