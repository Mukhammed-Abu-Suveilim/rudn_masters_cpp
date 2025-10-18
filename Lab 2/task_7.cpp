// #### **Задача 7: Многоуровневая структура данных (Вложенные структуры, массивы)**
// Создайте программу для учета студентов в группе.
// 1.  Создайте структуру `Date` (день, месяц, год).
// 2.  Создайте структуру `Student`, которая содержит:
//     *   ФИО (`std::string`)
//     *   Дата рождения (`Date`)
//     *   Массив из 5 оценок (за сессию) (`int[5]`)
// 3.  В функции `main` создайте массив из 3-5 студентов и инициализируйте его данными (можно "вшитыми" в код).
// 4.  Реализуйте функции:
//     *   `void printStudent(const Student& s);` // Вывод информации о студенте
//     *   `double getAverageRating(const Student& s);` // Подсчет среднего балла студента
//     *   Выведите список студентов, чей средний балл выше 4.0.

// **Цель:** Работа с составными и вложенными пользовательскими типами данных.

#include <iostream>
#include <string>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    std::string fullName;
    Date birthDate;
    int grades[5];
};

void printStudent(const Student& s) {
    std::cout << "ФИО: " << s.fullName << std::endl;
    std::cout << "Дата рождения: " << s.birthDate.day << "."
              << s.birthDate.month << "." << s.birthDate.year << std::endl;
    std::cout << "Оценки: ";
    for (int grade : s.grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
}

double getAverageRating(const Student& s) {
    double sum = 0;
    for (int grade : s.grades) {
        sum += grade;
    }
    return sum / 5.0;
}

int main() {
    const int numStudents = 3;
    Student students[numStudents] = {
        {
            "Geralt of Rivia",
            {15, 5, 2000},
            {5, 4, 5, 4, 5}
        },
        {
            "Yennefer of Vengerberg",
            {20, 7, 2001},
            {3, 4, 3, 5, 4}
        },
        {
            "Vernon Roche",
            {10, 12, 1999},
            {5, 5, 5, 5, 5}
        }
    };

    std::cout << "Студенты с средним баллом выше 4.0:" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        double avg = getAverageRating(students[i]);
        if (avg > 4.0) {
            printStudent(students[i]);
            std::cout << "Средний балл: " << avg << std::endl << std::endl;
        }
    }

    return 0;
}
