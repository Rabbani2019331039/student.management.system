#include<iostream>
#include<string>
#include<vector>

#define sp " "
using namespace std;
class Address;
class Person;
class Grades;
class Student;
class Courses;
class Teacher;


class Address{
    string houseNo, postCode;
    string policeStation, postOffice, street, district, country;
public:
    //constructor
    Address(){
        houseNo = postCode = "";
        policeStation = postOffice = street = district = country = "";
    }
    Address(const Address &a){
        houseNo = a.houseNo;
        postCode = a.postCode;
        policeStation = a.policeStation;
        postOffice = a.postOffice;
        street = a.street;
        district = a.district;
        country = a.country;
    }

    void takeInput(){
        cout<<"Give address"<<endl;
        cout<<"Example: "<< "2/5 Deshgram, Mirpur, Mirpur 1216, Dhaka, Bangladesh"<<endl;
        cin>>houseNo>> street>> policeStation>> postOffice>> postCode>> district>> country;
    }

    void display(){
        cout<<houseNo<<sp<< street <<sp<< policeStation <<sp<< postOffice <<sp<< postCode <<sp<< district <<sp<< country;
    }
};

class Person: public Address
{
public:
    string name;
    string email;
    string phone_num;
    Address address;

    Person(){
        name = "";
        email = "";
        phone_num = "";
        address = Address();
    }
    Person(const Person &p){
        name = p.name;
        email = p.email;
        phone_num = p.phone_num;
        address = p.address;
    }
    Person(string name,string email, string phone_num, Address &address)//constructor
    {
        name = name;
        email = email;
        phone_num = phone_num;
        address = Address(address);
    }
    void input1()
    {
        cout<<"Enter the name : "; cin>>name;
        cout<<"Enter email address : "; cin>>email;
        cout<<"Enter phone number : "; cin>>phone_num;
        address.takeInput();
    }
    void display1()
    {
       cout<<"Name : "<<name<<endl;
       cout<<"Email : "<<email<<endl;
       cout<<"Phone number : "<<phone_num<<endl;
       address.display();
    }
};

class Student:public Person//inheritance
{

    public:
    Grades *grade;
    Person person;
    int reg_num,exam_roll;
    vector<Courses> courses;

    Student(){
        reg_num = exam_roll = 0;
    }
    Student(const Student &s){
        reg_num = s.reg_num;
        exam_roll = s.exam_roll;
        person = s.person;
    }
    Student(int reg_num, int exam_roll, Person &person)
    {
        reg_num = reg_num;
        exam_roll = exam_roll;
        person = Person(person);
    }
    void stu_list();//full id
    void edit_list();
    void showInfo(){
        cout<<"Name : "<<person.name<<endl;
        cout<<"Email : "<<person.email<<endl;
        cout<<"Registration number : "<<reg_num<<endl;
        cout<<"Exam roll : "<<exam_roll<<endl;
        cout<<"Phone number : "<<person.phone_num<<endl;
        person.address.display();

    }

    void editInfo(){

    }
};

class Teacher:public Person
{
    public:
    int phone_num;
    Person person;
    vector<Courses> courses;
    Teacher(){
        phone_num = 0;
    }
    Teacher(const Teacher &t){
        phone_num = t.phone_num;
        person = t.person;
    }
    Teacher(int phone_num, Person &person)
    {
        phone_num = phone_num;
        person = Person(person);
    }
    void teacher_list();
    void edit_teacher_list();
    void setGrade(Grades grade, Student &student, Courses &course, int mark){
        grade.course = &course;
        grade.student = &student;
        grade.marks = mark;
    }
};

class Courses
{
    public:
    Grades *grade;
    string courseName;
    string courseCode;
    int minStudent = 10;//minimum 10 students must enroll
    int num_stu;//number of students attended the course
    vector<Student> students;
    vector<Teacher> teachers;

    Courses(){
        courseName = "";
        courseCode = "";
        minStudent = 10;
        num_stu = 0;
    }
    Courses(const Courses &c){
        courseName = c.courseName;
        courseCode = c.courseCode;
        minStudent = c.minStudent;
        num_stu = c.num_stu;
    }
    Courses(string courseName, string courseCode)
    {
        courseName = courseName;
        courseCode = courseCode;
    }

    bool isCourseCancelled(){
        if(num_stu < minStudent){
            return true;
        }
        else{
            return false;
        }
    }
    void showInfo(){
        cout<<"Course Name : "<<courseName<<endl;
        cout<<"Course Code : "<<courseCode<<endl;
        cout<<"Number of students : "<<num_stu<<endl;
        for(auto student:students){
            cout<<student.person.name<<endl;
            student.grade->display();
        }
    }
    void course_list();
    void edit_course_list();
};
void Courses::course_list()//koyta course ache
{

}

class Grades//association?
{
    public:
    float marks;
    Student *student;
    Courses *course;

    Grades(){
        marks = 0;
        student = NULL;
        course = NULL;
    }
    Grades(const Grades &g){
        marks = g.marks;
        student = g.student;
        course = g.course;
    }
    Grades(float marks, Student *student, Courses *course)
    {
        marks = marks;
        student = student;
        course = course;
    }

    void display(){
        cout<<"Marks : "<<marks<<endl;
    }
    void get_marks();
    void show_marks();
    void search_result();
};


void enroll(Courses &c, Student &s)
{
    c.num_stu++;
    s.courses.push_back(c);
    c.students.push_back(s);
}

void enroll(Courses &c, Teacher &t)
{
    t.courses.push_back(c);
    c.teachers.push_back(t);
}


int main()
{

    Student s1 = Student();
    Teacher t1 = Teacher();
    Courses c1 = Courses("math","MATH101");
    s1.person.name = "toti";
    t1.person.name = "jafor";
    enroll(c1,s1);
    enroll(c1,t1);
    t1.setGrade(Grades(100, &s1, &c1),s1,c1,100);


    return 0;
}
