/*
## Задача 1: Базовый класс "Студент"

**Цель:** Реализовать класс с инкапсуляцией данных.
*/


#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    // Приватные поля: имя, возраст, средний балл и массив оценок (5 элементов)
    string name;
    int age;
    static const int MAX_GRADES = 5;
    float grades[MAX_GRADES];

public:
    // Конструктор с параметрами
    Student(string n, int a) : name(n), age(a) {
        // Инициализируем массив оценок нулями
        for(int i = 0; i < MAX_GRADES; i++) {
            grades[i] = 0.0f;
        }
    }
    
    // Геттеры и сеттеры с валидацией
    void setName(string n) { name = n; }
    string getName() const { return name; }
    
    void setAge(int a) { 
        if(a > 0 && a < 120) { // Валидация возраста
            age = a;
        }
    }
    int getAge() const { return age; }
    
    void setGrade(int index, float mark) {
        if(index >= 0 && index < MAX_GRADES && mark >= 2.0f && mark <= 5.0f) {
            grades[index] = mark;
        } else {
            cout << "Ошибка: неверный индекс или оценка\n";
        }
    }
    float getGrade(int index) const {
        if(index >= 0 && index < MAX_GRADES) {
            return grades[index];
        }
        return -1; // Индикатор ошибки
    }
    
    // Метод для расчета среднего балла
    float calculateMeanGrade() const {
        float sum = 0;
        int count = 0;
        for(int i = 0; i < MAX_GRADES; i++) {
            if(grades[i] > 0) { // Учитываем только установленные оценки
                sum += grades[i];
                count++;
            }
        }
        return count > 0 ? sum / count : 0.0f;
    }
    
    // Метод для вывода информации о студенте
    void displayInfo() const {
        cout << "Student's name: " << name << "\n";
        cout << "Student's age: " << age << "\n";
        cout << "Student's average gpa: " << calculateMeanGrade() << "\n";
        cout << "Student's grades: ";
        for(int i = 0; i < MAX_GRADES; i++) {
            cout << grades[i];
            if(i < MAX_GRADES - 1) cout << ", ";
        }
        cout << "\n";
    }
    
    // Метод для проверки стипендии (средний балл >= 4.5)
    bool hasScholarship() const {
        return calculateMeanGrade() >= 4.5f;
    }
};

int main() {
    // Тестирование класса Student
    Student student("Иван Иванов", 20);
    
    // Установка оценок
    student.setGrade(0, 5);
    student.setGrade(1, 4);
    student.setGrade(2, 5);
    student.setGrade(3, 3);
    student.setGrade(4, 4);
    
    student.displayInfo();
    
    if (student.hasScholarship()) {
        cout << "Студент получает стипендию" << endl;
    } else {
        cout << "Стипендия не назначена" << endl;
    }
    
    return 0;
}