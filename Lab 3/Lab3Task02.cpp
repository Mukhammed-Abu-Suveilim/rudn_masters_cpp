// ## Задача 2: Наследование - Академические работники

// **Цель:** Создать иерархию классов с использованием наследования.


#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string address;

public:
    Person(string n, int a, string addr) : name(n), age(a), address(addr) {}
    virtual void displayInfo() const {
        cout << "Имя: " << name << ", Возраст: " << age << ", Адрес: " << address << endl;
    }
    virtual ~Person() {}

};

class Student : public Person {
private:
    string studentId;
    double averageGrade;

public:
    // TODO: Создать конструктор
    Student(string n, int a, string addr, string studID, double aveGPA) : Person(n, a, addr), studentId(studID), averageGrade(aveGPA) {} 
    // TODO: Переопределить displayInfo()
    void displayInfo() const override {
        cout << "Student's name: " << name << "\n";
        cout << "Student's age: " << age << "\n";
        cout << "Student's address: " << address << '\n';
        cout << "Student's ID: " << studentId << '\n';
        cout << "Student's average grade: " << averageGrade << '\n';
    }
    // TODO: Добавить методы для работы с оценками
    void setAverageGrade(double grade) {
        averageGrade = grade;
    }
    
    double getAverageGrade() const {
        return averageGrade;
    }
    
    string getStudentId() const {
        return studentId;
    }

};

class Professor : public Person {
private:
    string department;
    double salary;
    int yearsOfExperience;

public:
    // TODO: Создать конструктор
    Professor(string n, int a, string addr, string dept, double sal, int exp) : Person(n, a, addr), department(dept), salary(sal), yearsOfExperience(exp) {}
    // TODO: Переопределить displayInfo()
    void displayInfo() const override {
        cout << "Professor's name: " << name << "\n";
        cout << "Professor's age: " << age << "\n";
        cout << "Professor's address: " << address << '\n';
        cout << "Department: " << department << '\n';
        cout << "Salary: " << salary << '\n';
        cout << "Years of experience: " << yearsOfExperience << '\n';
        cout << "Bonus: " << calculateExperienceBonus() << '\n';
    }
    // TODO: Добавить метод для расчета надбавки за стаж
    double calculateExperienceBonus() const {
        return yearsOfExperience * 1000; // Example: 1000 per year
    }
    void setSalary(double sal) {
        salary = sal;
    }
    
    double getSalary() const {
        return salary;
    }
    
    int getYearsOfExperience() const {
        return yearsOfExperience;
    }
};

int main() {
    // Тестирование иерархии классов
    Student student("Петр Петров", 20, "ул. Студенческая, 15", "S12345", 4.3);
    Professor prof("Доктор Иванов", 45, "ул. Академическая, 10", "Компьютерные науки", 50000, 15);
    
    student.displayInfo();
    prof.displayInfo();
    
    return 0;
}
