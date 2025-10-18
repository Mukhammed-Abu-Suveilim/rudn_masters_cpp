// #### **Задача 5: Динамический массив структур (Динамическая память, структуры)**
// Создайте структуру `Book`, которая содержит поля: название (`std::string`), автор (`std::string`), год издания (`int`), цена (`double`).
// 1.  Запросите у пользователя количество книг `N` в библиотеке.
// 2.  **Динамически** выделите память под массив из `N` структур `Book`.
// 3.  Заполните массив данными, введенными пользователем.
// 4.  Реализуйте функцию `void printBooks(Book* books, int size)`, которая выводит информацию о всех книгах.
// 5.  Напишите функцию, которая находит и выводит самую дорогую книгу в массиве.
// 6.  Не забудьте освободить динамически выделенную память.

// **Цель:** Комбинация динамического управления памятью и пользовательских типов данных.


#include <iostream>
#include <string>
#include <limits>

struct Book {
    std::string title;
    std::string author;
    int year;
    double price;
};

void printBooks(Book* books, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Книга " << i + 1 << ":" << std::endl;
        std::cout << "  Название: " << books[i].title << std::endl;
        std::cout << "  Автор: " << books[i].author << std::endl;
        std::cout << "  Год издания: " << books[i].year << std::endl;
        std::cout << "  Цена: " << books[i].price << std::endl;
    }
}

void printMostExpensiveBook(Book* books, int size) {
    if (size == 0) {
        std::cout << "Нет книг в библиотеке." << std::endl;
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (books[i].price > books[maxIndex].price) {
            maxIndex = i;
        }
    }

    std::cout << "Самая дорогая книга:" << std::endl;
    std::cout << "  Название: " << books[maxIndex].title << std::endl;
    std::cout << "  Автор: " << books[maxIndex].author << std::endl;
    std::cout << "  Год издания: " << books[maxIndex].year << std::endl;
    std::cout << "  Цена: " << books[maxIndex].price << std::endl;
}

int main() {
    int N;
    std::cout << "Введите количество книг: ";
    std::cin >> N;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера

    Book* books = new Book[N];

    for (int i = 0; i < N; ++i) {
        std::cout << "Введите название книги " << i + 1 << ": ";
        std::getline(std::cin, books[i].title);
        std::cout << "Введите автора книги " << i + 1 << ": ";
        std::getline(std::cin, books[i].author);
        std::cout << "Введите год издания книги " << i + 1 << ": ";
        std::cin >> books[i].year;
        std::cout << "Введите цену книги " << i + 1 << ": ";
        std::cin >> books[i].price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
    }

    printBooks(books, N);
    printMostExpensiveBook(books, N);

    delete[] books; // Освобождение памяти

    return 0;
}
