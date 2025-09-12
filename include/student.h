#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student
{
public:
    std::string name;
    int age;
    std::string address;
    std::string phone;
    std::string email;
    std::string course;
    std::string grade;
    Student() {};
    Student(std::string name, int age, std::string address, std::string phone, std::string email, std::string course, std::string grade)
        : name(name), age(age), address(address), phone(phone), email(email), course(course), grade(grade) {
          };
};
#endif
