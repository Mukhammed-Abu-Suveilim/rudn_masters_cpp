// #### **Задача 10: Поиск и сортировка в массиве структур (Сложные типы данных, алгоритмы)**
// Используйте структуру `Book` из Задачи 5.
// 1.  Создайте динамический массив книг (можно инициализировать данными напрямую в коде).
// 2.  Напишите функцию `void sortBooksByYear(Book* books, int size)`, которая сортирует массив книг по году издания (по возрастанию) с использованием простого алгоритма (например, пузырьковой сортировки).
// 3.  Напишите функцию `Book* findBookByAuthor(Book* books, int size, const std::string& author)`, которая возвращает указатель на первую найденную книгу указанного автора. Если книга не найдена, функция должна возвращать `nullptr`.
// 4.  Продемонстрируйте сортировку и поиск в функции `main`.

// **Цель:** Интеграция знаний: динамические структуры, пользовательские типы, указатели и написание простых алгоритмов.

#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
    double price;
};

// Функция для сортировки книг по году издания (пузырьковая сортировка)
void sortBooksByYear(Book* books, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (books[j].year > books[j + 1].year) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

// Функция для поиска книги по автору
Book* findBookByAuthor(Book* books, int size, const std::string& author) {
    for (int i = 0; i < size; ++i) {
        if (books[i].author == author) {
            return &books[i];
        }
    }
    return nullptr;
}

// Функция для вывода информации о книге
void printBook(const Book& book) {
    std::cout << "Название: " << book.title << ", Автор: " << book.author
              << ", Год: " << book.year << ", Цена: " << book.price << std::endl;
}

// Функция для вывода всех книг
void printBooks(Book* books, int size) {
    for (int i = 0; i < size; ++i) {
        printBook(books[i]);
    }
}


int main() {
    const int size = 4;
    Book* books = new Book[size]{
        {"A Gentleman in Moscow", "Amor Towles", 2016, 500.0},
        {"Мастер и Маргарита", "Михаил Булгаков", 1967, 450.0},
        {"1984", "Джордж Оруэлл", 1949, 350.0},
        {"The Ones Who Walk Away from Omelas", "Ursula K. Le Guin", 1973, 400.0}
    };

    std::cout << "Исходный список книг:" << std::endl;
    printBooks(books, size);

    // Сортировка по году издания
    sortBooksByYear(books, size);
    std::cout << "\nСписок книг после сортировки по году издания:" << std::endl;
    printBooks(books, size);

    // Поиск книги по автору
    std::string author = "Михаил Булгаков";
    Book* foundBook = findBookByAuthor(books, size, author);
    if (foundBook != nullptr) {
        std::cout << "\nНайдена книга автора " << author << ":" << std::endl;
        printBook(*foundBook);
    } else {
        std::cout << "\nКнига автора " << author << " не найдена." << std::endl;
    }

    // Поиск несуществующего автора
    author = "Иван Тургенев";
    foundBook = findBookByAuthor(books, size, author);
    if (foundBook != nullptr) {
        std::cout << "\nНайдена книга автора " << author << ":" << std::endl;
        printBook(*foundBook);
    } else {
        std::cout << "\nКнига автора " << author << " не найдена." << std::endl;
    }

    delete[] books; // Освобождение памяти
    return 0;
}
