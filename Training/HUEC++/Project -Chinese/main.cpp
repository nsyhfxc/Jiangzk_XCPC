#include"config.h"
vector<Employee*>employees;
void add_inform()
{
    int ID;
    string name;
    int age;
    char sex;
    string department;
    string level;
    double salary;
    cout << "请输入员工信息:" << endl;
    cout << "编号:";
    cin >> ID;
    cout << "姓名:";
    cin >> name;
    cout << "年龄:";
    cin >> age;
    cout << "性别(M 男性 / F 女性):";
    cin >> sex;
    if(sex != 'M' && sex != 'F')
    {
        cout << "性别输入有误，请重新添加！" << endl;
        return;
    }
    cout << "部门:";
    cin >> department;
    cout << "等级(|| 经理 || 技术人员 || 销售人员 || 销售经理 ||):";
    cin >> level;
    cout << "薪水:";
    cin >> salary;
    int test_id = ID;
    int flag = 0;
    for(vector<Employee*>::iterator it = employees.begin();it != employees.end();it++)
    {
        if((*it)->getID() == test_id)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        cout << "该编号员工已存在,将返回主页面!" << endl;
        return;
    }
    int choice;
    cout << "选择您在录入的员工类型:" << endl;
    cout << "|| 1.经理 || 2.技术人员 || 3.销售人员 || 4.销售经理 ||" << endl;
    cout << "请输入您的选择:";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
        case 1:
            employees.push_back(new Manager(ID,name,age,sex,department,level,salary));
            break;
        case 2:    
            employees.push_back(new Technician(ID,name,age,sex,department,level,salary));
            break;
        case 3:
            employees.push_back(new Salesman(ID,name,age,sex,department,level,salary));
            break;
        case 4:    
            employees.push_back(new SalesManager(ID,name,age,sex,department,level,salary));
            break;
        default:
            cout << "无效输入!" << endl;
            break;
    }
    cout << "您已成功添加该员工!" << endl;
}

void modify_inform()
{
    if(employees.size() == 0)
    {
        cout << "记录为空!" << endl;
        return;
    }
    int ID;
    cout << "请输入您想修改的员工信息的编号:";
    cin >> ID;
    cout << "请问您想修改的内容是否涉及修改员工的部门信息?" << endl;
    cout << "1 是 | 0 否 :";
    int choice;
    cin >> choice;

    int flag = 0;
    if(choice == 0)
    {
        for (auto i = 0; i < int(employees.size()); i++)
        {
            if(employees[i]->getID() == ID)
            {
                flag = 1;
                string name;
                int age;
                char sex;
                string department;;
                string level;
                double salary;

                cout << "请修改:" << endl;
                cout << "姓名:";
                cin >> name;
                cout << "年龄:";
                cin >> age;
                cout << "性别:(M 男性 / F 女性)";
                cin >> sex;
                cout << "部门:";
                cin >> department;
                cout << "等级:";
                cin >> level;
                cout << "薪水:";
                cin >> salary;
                employees[i]->name = name;
                employees[i]->age = age;
                employees[i]->sex = sex;
                employees[i]->department = department;
                employees[i]->level = level;
                employees[i]->salary = salary;
                cout << "员工信息修改完成!" << endl;
            }
        }
        if(flag == 0)
        {
            cout << "查无此人!" << endl;
        }
    }
    if(choice == 1)
    {
        cout << "暂不支持修改员工部门,请尝试删除后重新添加!" << endl;
    }
}

void delete_byid()
{
    int ID;
    cout << "请输入您想要删除的员工编号:";
    cin >> ID;
    int flag = 0;
    for(vector<Employee*>::iterator it = employees.begin();it != employees.end();it++)
    {
        if((*it)->getID() == ID)
        {
            flag = 1;
            employees.erase(it);
            cout << "删除成功!" << endl;
            break;
        }
    }
    if(flag == 0)
    {
        cout << "查无此人!" << endl;
    }
}

void delete_byname()
{
    string name;
    cout << "请输入您想要删除的员工姓名:";
    cin >> name;
    int flag = 0;
    for(vector<Employee*>::iterator it = employees.begin();it != employees.end();it++)
    {
        if((*it)->getname() == name)
        {
            flag = 1;
            employees.erase(it);
            cout << "删除成功!" << endl;
            break;
        }
    }
    if(flag == 0)
    {
        cout << "查无此人!" << endl;
    }
}

void delete_inform()
{
    if(employees.size() == 0)
    {
        cout << "记录为空!" << endl;
        return;
    }
    int choice;
    cout << "请输入您的删除方式:(1 编号 / 2 姓名)" ;
    cin >> choice;
    switch (choice)
    {
        case 1:
            delete_byid();
            break;
        case 2:
            delete_byname();
            break;
        default:
            cout << "无效输入" << endl;
            break;
    }
}

void display_inform(vector<Employee*>&employees)
{
    if(employees.size() == 0)
    {
        cout << "记录为空!" << endl;
        return;
    }
    for (Employee* emp : employees)
    {
        cout << left
             << "编号:" << setw(3) << emp->getID()
             << " 姓名:" << setw(4) << emp->getname().substr(0, 4)
             << " 年龄:" << setw(2) << emp->getage()
             << " 性别:" << setw(1) << emp->getsex() 
             << " 部门:" << setw(10) << emp->getdepartment()
             << " 等级:" << setw(8) << emp->getlevel()
             << " 薪水:" << fixed << setprecision(2) << setw(6) << emp->getsalary() << endl;
    }
}

void inquire_byid()
{
    int ID;
    cout << "请输入你想要查询的员工编号:";
    cin >> ID;
    int flag = 0;
    for(vector<Employee*>::iterator it = employees.begin();it != employees.end();it++)
    {
        if((*it)->getID() == ID)
        {
            flag = 1;
            (*it)->display();
            break;
        }
    }
    if(flag == 0)
    {
        cout << "查无此人!" << endl;
    }

}

void inquire_byname()
{
    string name;
    cout << "请输入你想查询的员工姓名:";
    cin >> name;
    int flag = 0;
    for(vector<Employee*>::iterator it = employees.begin();it != employees.end();it++)
    {
        if((*it)->getname() == name)
        {
            flag = 1;
            (*it)->display();
            break;
        }
    }
    if(flag == 0)
    {
        cout << "查无此人!" << endl;
    }
}

void inquire_inform()
{
    if(employees.size() == 0)
    {
        cout << "记录为空!" << endl;
        return;
    }
    int choice;
    cout << "请输入你的查询方式:(1 编号 / 2 姓名)" ;
    cin >> choice;
    switch (choice)
    {
        case 1:
            inquire_byid();
            break;
        case 2:
            inquire_byname();
            break;
        default:
            cout << "无效输入!" << endl;
            break;
    }
}

void sum()
{
    int totalEmployees = employees.size();
    int totalMale = 0;
    int totalFemale = 0;
    int totalManagers = 0;
    int totalTechnicians = 0;
    int totalSalesmen = 0;
    int totalSalesManagers = 0;
    for(vector<Employee*>::iterator it = employees.begin();it != employees.end();it++)
    {
        if((*it)->getsex() == 'M')
        {
            totalMale++;
        }
        else
        {
            totalFemale++;
        }

        if(dynamic_cast<SalesManager*>(*it) != NULL)
        {
            // 如果是销售经理，只增加销售经理的计数
            totalSalesManagers++;
        }
        else if(dynamic_cast<Technician*>(*it) != NULL)
        {
            // 如果不是销售经理，再判断是否是技术人员
            totalTechnicians++;
        }
        else if(dynamic_cast<Manager*>(*it) != NULL)
        {
            // 如果不是销售经理也不是技术人员，再判断是否是经理（这里统计的就是“纯”经理）
            totalManagers++;
        }
        else if(dynamic_cast<Salesman*>(*it) != NULL)
        {
            // 如果不是销售经理、技术人员、经理，最后判断是否是销售人员（这里统计的就是“纯”销售人员）
            totalSalesmen++;
        }
    }
    cout << "\t\t\t\t查询结果如下:" << endl;
    cout << "\t\t\t======================================" << endl;
    cout << "\t\t\t\t员工总数:" << totalEmployees << endl;
    cout << "\t\t\t\t男性总数:" << totalMale << endl;
    cout << "\t\t\t\t女性总数:" << totalFemale << endl;
    cout << "\t\t\t\t经理总数:" << totalManagers << endl;
    cout << "\t\t\t\t技术人员总数" << totalTechnicians << endl;
    cout << "\t\t\t\t销售人员总数:" << totalSalesmen << endl;
    cout << "\t\t\t\t销售经理总数:" << totalSalesManagers << endl;
    cout << "\t\t\t======================================" << endl;

}

void save_date(vector<Employee*>&employees)
{
    ofstream file("employees.txt",ios::out|ios::trunc);
    //ofstream file("employees.txt");
	if(!file.is_open())
    {
        cout << "文件打开失败!" << endl;
        return;
    }
    
    for(vector<Employee*>::iterator it = employees.begin();it != employees.end();it++)
    {
        file << (*it)->getID() << " " << (*it)->getname() << " " << (*it)->getage() << " " << (*it)->getsex() << " " << (*it)->getdepartment() << " " << (*it)->getlevel() << " " << (*it)->getsalary() <<endl;
    }
    file.close();
    cout << "员工信息保存成功!" << endl;
}

void read_data(vector<Employee*>&employees)
{
    ifstream file("employees.txt");
    if(!file.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    cout << "文件读取成功！" << endl;
    string line;
    while(getline(file,line))
    {
        stringstream ss(line);
        int ID;
        string name;
        int age;
        char sex;
        string department;;
        string level;
        double salary;
        ss >> ID >> name >> age >> sex >> department >> level >> salary;
        if(level == "经理")
        {
            Manager* manager = new Manager(ID,name,age,sex,department,level,salary);
            employees.push_back(manager);
        }
        else if(level == "销售经理")
        {
            SalesManager* salesmanager = new SalesManager(ID,name,age,sex,department,level,salary);
            employees.push_back(salesmanager);
        }
        else if(level == "技术人员")
        {
            Technician* technician = new Technician(ID,name,age,sex,department,level,salary);
            employees.push_back(technician);
        }
        else if(level == "销售人员")
        {
            Salesman* salesman = new Salesman(ID,name,age,sex,department,level,salary);
            employees.push_back(salesman);
        }
    }
}

bool compareSalaryAsc(Employee* a, Employee* b) {
    if (a->getsalary() == b->getsalary()) {
        return a->getID() < b->getID();
    }
    return a->getsalary() < b->getsalary();
}

bool compareSalaryDesc(Employee* a, Employee* b) { 
    if (a->getsalary() == b->getsalary()) {
        return a->getID() < b->getID();
    }
    return a->getsalary() > b->getsalary();
}


void sort_by_salary() {
    if (employees.empty()) {
        cout << "员工列表为空！" << endl;
        return;
    }
    int choice;
    cout << "请选择排序方式:" << endl;
    cout << "1. 按薪水升序排序" << endl;
    cout << "2. 按薪水降序排序" << endl;
    cin >> choice;

    if (choice == 1) {
        sort(employees.begin(), employees.end(), compareSalaryAsc);
    } else if (choice == 2) {
        sort(employees.begin(), employees.end(), compareSalaryDesc);
    } else {
        cout << "无效输入!" << endl;
    }
}

bool compareIdAsc(Employee* a, Employee* b) {
    return a->getID() < b->getID();
}

bool compareIdDesc(Employee* a, Employee* b) {
    return a->getID() > b->getID();
}

void sort_by_id() {
    if (employees.empty()) {
        cout << "员工列表为空！" << endl;
        return;
    }

    int choice;
    cout << "请选择排序方式：" << endl;
    cout << "1. 按编号升序排序" << endl;
    cout << "2. 按编号降序排序" << endl;
    cin >> choice;

    if (choice == 1) {
        sort(employees.begin(), employees.end(), compareIdAsc);
    } else if (choice == 2) {
        sort(employees.begin(), employees.end(), compareIdDesc);
    } else {
        cout << "无效输入！" << endl;
    }
}


int main()
{
    while(true)
    {
        cout << endl;
        cout << "\t\t\t======== 员工管理系统 ================" << endl;
        cout << "\t\t\t\t1. 添加员工信息" << endl;
        cout << "\t\t\t\t2. 修改员工信息" << endl;
        cout << "\t\t\t\t3. 删除员工信息" << endl;
        cout << "\t\t\t\t4. 显示员工信息" << endl;
        cout << "\t\t\t\t5. 查询员工信息" << endl;
        cout << "\t\t\t\t6. 统计员工数量" << endl;
        cout << "\t\t\t\t7. 保存文件" << endl;
        cout << "\t\t\t\t8. 读取文件" << endl;
        cout << "\t\t\t\t9. 员工薪水排序" << endl;
        cout << "\t\t\t\t10. 员工编号排序" << endl;
        cout << "\t\t\t\t0. 退出" << endl;
        cout << "\t\t\t======================================" << endl;
        cout << endl;
        cout << "请输入你的选择(0-10):";
        
        int seclected_number;
        cin >> seclected_number;
        cout << endl;
        switch(seclected_number)
        {
            case 1:
                add_inform();
                break;
            case 2:
                modify_inform();
                break;
            case 3:
                delete_inform();
                break;
            case 4:
                display_inform(employees);
                break;
            case 5:
                inquire_inform();
                break;
            case 6:
                sum();
                break;
            case 7:
                save_date(employees);
                break;
            case 8:
                read_data(employees);
                break;
            case 0:
                cout << "程序已结束！" << endl;
                exit(0);
                return 0;
            case 9:
                sort_by_salary();
                display_inform(employees);
                break;
            case 10:
                sort_by_id();
                display_inform(employees);
                break;
            default:
                cout << "无效输入,请重新输入！" << endl;
                break;
        }
    }
    return 0;
}
