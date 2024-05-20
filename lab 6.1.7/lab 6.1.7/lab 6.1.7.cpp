#include <iostream>

class Person {
public:
    std::string name;
    int age;
};

class Employee : virtual public Person {
public:
    int employeeId;
    double salary;
    std::string department;
};

class Student : virtual public Person {
public:
    int studentId;
    double GPA;
};

class Intern : public Employee, public Student {
public:
    int internId;
    std::string internshipProgram;
};

class Teacher : public Employee {
public:
    int teacherId;
    std::string subject;
};

class PartTimeStudent : public Student, public Intern {
public:
    int partTimeStudentId;
    std::string partTimeProgram;
};

class Researcher : public Intern {
public:
    int researcherId;
    std::string researchTopic;
};

int main() {
    setlocale(LC_CTYPE, "uk_UA");
    Person objPerson;
    Employee objEmployee;
    Student objStudent;
    Intern objIntern;
    Teacher objTeacher;
    PartTimeStudent objPartTimeStudent;
    Researcher objResearcher;

    std::cout << "Розмір об’єкта Людина: " << sizeof(objPerson) << std::endl;
    std::cout << "Розмір об’єкта Робочий: " << sizeof(objEmployee) << std::endl;
    std::cout << "Розмір об’єкта Студент: " << sizeof(objStudent) << std::endl;
    std::cout << "Розмір об’єкта Інтерн: " << sizeof(objIntern) << std::endl;
    std::cout << "Розмір об’єкта Вчитель: " << sizeof(objTeacher) << std::endl;
    std::cout << "Розмір об’єкта Заочний студент: " << sizeof(objPartTimeStudent) << std::endl;
    std::cout << "Розмір об’єкта Дослідник: " << sizeof(objResearcher) << std::endl;

    return 0;
}