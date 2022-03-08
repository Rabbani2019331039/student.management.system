#include<iostream>
#include<string>
using namespace std;
class Person
{
    string name;
    string email;
    //string phone_num;
public:
    Person(string name,string email)//constructor
    {
        name=name;
        email=email;
    }
    void input1()
    {
        cout<<"Enter the name : "; cin>>name;
        cout<<"Enter email address : "; cin>>email;
        //cout<<"Enter phone number : "; cin>>phone_num;
    }
    void display1()
    {
       cout<<"Name : "<<name<<endl;
       cout<<"Email : "<<email<<endl;
       //cout<<"Phone number : "<<phone_num<<endl;
    }
};

class Student:public Person//inheritance
{
    int reg_num,exam_roll;
public:
    void stu_list();//full id
    void edit_list();
};

class Teacher:public Person
{
    int phone_num;
public:
    void teacher_list();
    void edit_teacher_list();
};

class Courses
{
    string name;
    string code;
    int minStudent;//minimum 10 students must enroll
    //int num_stu;//number of students attended the course
public:
    void course_list();
    void edit_course_list();
};
void Courses::course_list()//koyta course ache
{

}

class Grades//association?
{
    float marks;
public:
    void get_marks();
    void show_marks();
    void search_result();
};

int main()
{
    return 0;
}
