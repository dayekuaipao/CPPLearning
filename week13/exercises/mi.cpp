#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
    string name;
    char gender;
    int age;
public:
    Person(const string& nam,char g,int a):name(nam),gender(g),age(a){cout<<"Person constructor"<<endl;}
};
class vTeacher:virtual public Person
{
protected:
    string title;
public:
    vTeacher(const string& nam,char g,int a,const string& t):Person(nam,g,a),title(t){cout<<"vTeacher constructor"<<endl;}
};
class vStudent:virtual public Person
{
protected:
    float score;
public:
    vStudent(const string& nam,char g,int a,float s):Person(nam,g,a),score(s){cout<<"vStudent constructor"<<endl;}
};
class vGraduate:public vStudent,public vTeacher
{
private:
    float wage;
public:
    vGraduate(const string& nam,char g,int a,const string& t,float s,float w):Person("bao",'f',18),vStudent(nam,g,a,s),vTeacher("liu",'m',17,t),wage(w){cout<<"vGraduate constructor"<<endl;}
    void show()
    {
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
        cout<<"gender:"<<gender<<endl;
        cout<<"score:"<<score<<endl;
        cout<<"title:"<<title<<endl;
        cout<<"wage:"<<wage<<endl;
    }
};
class Teacher:public Person
{
protected:
    string title;
public:
    Teacher(const string& nam,char g,int a,const string& t):Person(nam,g,a),title(t){cout<<"Teacher constructor"<<endl;}
};
class Student:public Person
{
protected:
    float score;
public:
    Student(const string& nam,char g,int a,float s):Person(nam,g,a),score(s){cout<<"Student constructor"<<endl;}
};
class Graduate:public Teacher,public Student
{
private:
    float wage;
public:
    Graduate(const string& nam,char g,int a,const string& t,float s,float w):Teacher(nam,g,a,t),Student("cheng",'m',16,s),wage(w){cout<<"Graduate constructor"<<endl;}
    void show()
    {
        cout<<"name:"<<Teacher::name<<endl;
        cout<<"age:"<<Teacher::age<<endl;
        cout<<"gender:"<<Teacher::gender<<endl;
        cout<<"score:"<<score<<endl;
        cout<<"title:"<<title<<endl;
        cout<<"wage:"<<wage<<endl;
    }
};
int main()
{
    vGraduate zhang("zhang",'f',24,"lecturer",0.0,10000.0);
    Graduate yang("yang",'m',26,"professor",100.0,100000.0);
    zhang.show();
    yang.show();
}