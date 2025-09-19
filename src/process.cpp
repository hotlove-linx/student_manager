#include <iostream>
#include <fstream>
#include <algorithm>
#include "rapidjson/document.h"
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

    write_stu_to_file();
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

void load_stu_from_file()
{
    std::fstream in("stu.txt", std::ios::in);
    if (in.is_open())
    {
        std::cout << "load stu info from file" << std::endl;
        std::string stu_str{};
        while (getline(in, stu_str)) // 读取一行学生json数据
        {
            Student stu;
            // 解析json字符串
            rapidjson::Document doc;
            doc.Parse(stu_str.c_str());

            if (doc["name"].IsString())
            {
                stu.name = doc["name"].GetString();
            }

            if (doc["age"].IsInt())
            {
                stu.age = doc["age"].GetInt();
            }
            if (doc["address"].IsString())
            {
                stu.address = doc["address"].GetString();
            }
            if (doc["phone"].IsString())
            {
                stu.phone = doc["phone"].GetString();
            }
            if (doc["email"].IsString())
            {
                stu.email = doc["email"].GetString();
            }
            if (doc["course"].IsString())
            {
                stu.course = doc["course"].GetString();
            }
            if (doc["grade"].IsString())
            {
                stu.grade = doc["grade"].GetString();
            }
            students.push_back(stu);
        }
        std::cout << "load stu info from file success" << std::endl;
    }
    else
    {
        std::cout << "file not exist" << std::endl;
    }
}

void write_stu_to_file()
{
    std::fstream out("stu.txt", std::ios::out | std::ios::app);
    for (const auto &stu : students)
    {
        out << stu.name << " " << stu.age << " " << stu.address << " " << stu.phone << " " << stu.email << " " << stu.course << " " << stu.grade << std::endl;
    }
    out.close();
}