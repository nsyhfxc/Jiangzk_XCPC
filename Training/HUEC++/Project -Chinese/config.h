#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
class Role{
protected:
    string name;
    int age;
    char sex;
public:
    Role(string na,int ag,char se):name(na),age(ag),sex(se){}
    virtual void display() = 0;
};

class Employee : public Role{
protected:
    int ID;
    string department;
    string level;
    double salary;
public:
    Employee(int id,string na,int ag,char se,string de,string le,double sa):ID(id),Role(na,ag,se),department(de),level(le),salary(sa){}
    int getID()
    {
        return ID;
    }
    string getname()
    {
        return name;
    }
    int getage()
    {
        return age;
    }
    char getsex()
    {
        return sex;
    }
    string getdepartment()
    {
        return department;
    }
    string getlevel()
    {
        return level;
    }
    double getsalary()
    {
        return salary;
    }
    friend void modify_inform();
};

class Technician : public Employee{
public:
    Technician(int id,string na,int ag,char se,string de,string le,double sa):Employee(id,na,ag,se,de,le,sa){}
    void display()override{
        cout << "编号:" << ID << " " << "姓名:" << name << " " << "年龄:" << age << " " << "性别:" << sex << " " << "部门:" << department << " " << "等级:" << level << " " << "薪水:" << salary << endl;
    }
};

class Salesman : virtual public Employee{
public:
Salesman(int id,string na,int ag,char se,string de,string le,double sa):Employee(id,na,ag,se,de,le,sa){}
    void display()override{
        cout << "编号:" << ID << " " << "姓名:" << name << " " << "年龄:" << age << " " << "性别:" << sex << " " << "部门:" << department << " " << "等级:" << level << " " << "薪水:" << salary << endl;
    }
};

class Manager : virtual public Employee{
public:
    Manager(int id,string na,int ag,char se,string de,string le,double sa):Employee(id,na,ag,se,de,le,sa){}
    void display()override{
        cout << "编号:" << ID << " " << "姓名:" << name << " " << "年龄:" << age << " " << "性别:" << sex << " " << "部门:" << department << " " << "等级:" << level << " " << "薪水:" << salary << endl;
    }
};

class SalesManager : public Salesman,public Manager{
public:
    SalesManager(int id,string na,int ag,char se,string de,string le,double sa):Employee(id,na,ag,se,de,le,sa),Salesman(id,na,ag,se,de,le,sa),Manager(id,na,ag,se,de,le,sa){}
    void display()override{
        cout << "编号:" << ID << " " << "姓名:" << name << " " << "年龄:" << age << " " << "性别:" << sex << " " << "部门:" << department << " " << "等级:" << level << " " << "薪水:" << salary << endl;
    }
};