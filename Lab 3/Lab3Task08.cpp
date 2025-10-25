// ## Задача 8: Множественное наследование

// **Цель:** Изучить множественное наследование и решение проблемы ромбовидного наследования.

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display() const {
        cout << "Имя: " << name << ", Возраст: " << age << endl;
    }
};

class Employee {
protected:
    string position;
    double salary;

public:
    Employee(string pos, double sal) : position(pos), salary(sal) {}
    virtual void work() const {
        cout << "Выполняет работу как сотрудник" << endl;
    }
};

// TODO: Создать класс Teacher, наследующий от Person и Employee
class Teacher : public Person, public Employee {
private:
    string subject;
    int experienceYears;

public:
    // TODO: Создать конструктор
    Teacher(string n, int a, string pos, double sal, string subj) : Person(n, a), Employee(pos, sal), subject(subj) {}
    // TODO: Переопределить методы display() и work()
    void display() const override {
        cout << "Преподаватель: " << name << ", Возраст: " << age 
             << ", Должность: " << position << ", Предмет: " << subject << endl;
    }
    void work() const override {
        cout << name << " преподает предмет: " << subject << endl;
    }
    // TODO: Добавить специфичные методы для Teacher
    void gradeStudents() const {
        cout << name << " проверяет работы студентов" << endl;
    }

    string getSubject() const {
        return subject;
    }
};

class Researcher {
protected:
    string researchArea;
    int publicationsCount;

public:
    Researcher(string area, int publications) 
        : researchArea(area), publicationsCount(publications) {}
    
    void conductResearch() const {
        cout << "Проводит исследования в области: " << researchArea << endl;
    }
};

// TODO: Создать класс Professor, наследующий от Teacher и Researcher
class Professor : public Teacher, public Researcher {
public:
    // TODO: Создать конструктор
    Professor(string n, int a, string pos, double sal, string subj, string area, int publications = 0) : Teacher(n, a, pos, sal, subj), Researcher(area, publications) {}
    // TODO: Переопределить необходимые методы
    void display() const override {
        cout << "Профессор: " << Teacher::name << ", Возраст: " << Teacher::age 
             << ", Должность: " << Teacher::position 
             << ", Предмет: " << getSubject()
             << ", Область исследований: " << researchArea << endl;
    }
    
    void work() const override {
        cout << Teacher::name << " преподает и проводит исследования" << endl;
    }
};

int main() {
    // TODO: Создать объекты Teacher и Professor
    Teacher teacher("Борис Теплов", 35, "Преподаватель", 50000, "Математика");
    Professor prof("Макс Пэйн", 45, "Профессор", 80000, "Физика", "Квантовая механика");
    // Продемонстрировать множественное наследование
    
    cout << "\n--- Teacher ---" << endl;
    teacher.display();
    teacher.work();
    teacher.gradeStudents();
    
    cout << "\n--- Professor ---" << endl;
    prof.display();
    prof.work();
    prof.conductResearch();
    prof.gradeStudents(); // Наследуется от Teacher
    

    Person* personPtr = &teacher;
    Employee* empPtr = &teacher;
    
    cout << "\nTeacher как Person:" << endl;
    personPtr->display();
    
    cout << "\nTeacher как Employee:" << endl;
    empPtr->work();

    Person* personPtr2 = &prof;
    Employee* empPtr2 = &prof;
    Researcher* resPtr = &prof;
    
    cout << "\nProfessor как Person:" << endl;
    personPtr2->display();
    
    cout << "\nProfessor как Employee:" << endl;
    empPtr2->work();
    
    cout << "\nProfessor как Researcher:" << endl;
    resPtr->conductResearch();

    return 0;
}