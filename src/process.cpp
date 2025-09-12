#include <iostream>
#include <algorithm>
#include "process.h"
std::vector<Student> students{};
void add_stu()
{
    Student stu;
    std::cout << "input stu info" << std::endl;
    std::cout << "name: ";
    std::cin >> stu.name;
    std::cout << "age: ";
    std::cin >> stu.age;
    std::cout << "address: ";
    std::cin >> stu.address;
    std::cout << "phone: ";
    std::cin >> stu.phone;
    std::cout << "email: ";
    std::cin >> stu.email;

    students.push_back(stu);
    show_stu();
}
void del_stu()
{
    std::string name{};
    std::cout << "input stu name to delete" << std::endl;
    std::cin >> name;
    auto it = std::find_if(students.begin(), students.end(), [&name](Student &stu)
                           { return stu.name == name; });

    students.erase(it);
}
void show_stu()
{
    std::cout << "---------------------stu info-----------------------------" << std::endl;
    for (const auto &stu : students)
    {
        std::cout << "name: " << stu.name << std::endl;
        std::cout << "age: " << stu.age << std::endl;
        std::cout << "address: " << stu.address << std::endl;
        std::cout << "phone: " << stu.phone << std::endl;
        std::cout << "email: " << stu.email << std::endl;
        std::cout << "course: " << stu.course << std::endl;
        std::cout << "grade: " << stu.grade << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
    }
}
void search_stu()
{
    std::cout << "input stu name to search" << std::endl;
    std::string name{};
    std::cin >> name;

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->name.find(name) != std::string::npos)
        {
            std::cout << "---------find stu info---------------" << std::endl;
            std::cout << "name: " << it->name << std::endl;
            std::cout << "age: " << it->age << std::endl;
            std::cout << "address: " << it->address << std::endl;
            std::cout << "phone: " << it->phone << std::endl;
            std::cout << "email: " << it->email << std::endl;
            std::cout << "course: " << it->course << std::endl;
        }
    }
}
void modify_stu()
{
    std::cout << "where stu you want to modify" << std::endl;
    std::string name{};
    std::cin >> name;
}