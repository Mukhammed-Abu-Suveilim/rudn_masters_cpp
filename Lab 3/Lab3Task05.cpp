// ## Задача 5: Композиция - Библиотека и Книги

// **Цель:** Продемонстрировать отношение "композиция" между классами.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    int year;
    bool isAvailable;

public:
    // TODO: Создать конструктор, геттеры, сеттеры
    Book(string t, string a, string i, int y) 
        : title(t), author(a), isbn(i), year(y), isAvailable(true) {}
    
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    int getYear() const { return year; }
    bool getAvailability() const { return isAvailable; }
    
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setYear(int y) { year = y; }
    // TODO: Методы borrow() и returnBook() для изменения статуса доступности
    void borrow() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Книга \"" << title << "\" успешно взята в аренду" << endl;
        } else {
            cout << "Книга \"" << title << "\" уже арендована" << endl;
        }
    }

     void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Книга \"" << title << "\" успешно возвращена" << endl;
        } else {
            cout << "Книга \"" << title << "\" уже доступна в библиотеке" << endl;
        }
    }
    // TODO: Метод displayInfo() для вывода информации о книге
    void displayInfo() const {
        cout << "Название: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Год издания: " << year << endl;
        cout << "Статус: " << (isAvailable ? "Доступна" : "Арендована") << endl;
        cout << "------------------------" << endl;
    }
};

class Library {
private:
    string name;
    string address;
    vector<Book> books;

public:
    Library(string n, string addr) : name(n), address(addr) {}
    
    // TODO: Добавить методы:
    // - addBook(const Book& book)
    // - removeBook(const string& isbn)
    // - findBook(const string& title) const
    // - borrowBook(const string& isbn)
    // - returnBook(const string& isbn)
    // - displayAllBooks() const
    // - displayAvailableBooks() const
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Книга \"" << book.getTitle() << "\" добавлена в библиотеку" << endl;
    }

    void removeBook(const string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getISBN() == isbn) {
                cout << "Книга \"" << it->getTitle() << "\" удалена из библиотеки" << endl;
                books.erase(it);
                return;
            }
        }
        cout << "Книга с ISBN " << isbn << " не найдена" << endl;
    }
    Book* findBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    void borrowBook(const string& isbn) {
        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                book.borrow();
                return;
            }
        }
        cout << "Книга с ISBN " << isbn << " не найдена" << endl;
    }

    void returnBook(const string& isbn) {
        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                book.returnBook();
                return;
            }
        }
        cout << "Книга с ISBN " << isbn << " не найдена" << endl;
    }

    void displayAllBooks() const {
        cout << "\n=== Все книги в библиотеке \"" << name << "\" ===" << endl;
        cout << "Адрес: " << address << endl;
        cout << "Общее количество книг: " << books.size() << endl;
        cout << "==============================" << endl;
        
        if (books.empty()) {
            cout << "Библиотека пуста" << endl;
            return;
        }
        
        for (const auto& book : books) {
            book.displayInfo();
        }
    }

    void displayAvailableBooks() const {
        cout << "\n=== Доступные книги в библиотеке \"" << name << "\" ===" << endl;
        
        bool foundAvailable = false;
        for (const auto& book : books) {
            if (book.getAvailability()) {
                book.displayInfo();
                foundAvailable = true;
            }
        }
        
        if (!foundAvailable) {
            cout << "Нет доступных книг" << endl;
        }
    }
    int getTotalBooks() const {
        return books.size();
    }
    
    int getAvailableBooksCount() const {
        int count = 0;
        for (const auto& book : books) {
            if (book.getAvailability()) {
                count++;
            }
        }
        return count;
    }
    
    void displayLibraryInfo() const {
        cout << "\n=== Информация о библиотеке ===" << endl;
        cout << "Название: " << name << endl;
        cout << "Адрес: " << address << endl;
        cout << "Всего книг: " << getTotalBooks() << endl;
        cout << "Доступно книг: " << getAvailableBooksCount() << endl;
        cout << "Арендовано книг: " << (getTotalBooks() - getAvailableBooksCount()) << endl;
    }
};

int main() {
    // TODO: Создать библиотеку
    // Добавить несколько книг
    // Продемонстрировать работу всех методов
    Library library("Центральная городская библиотека", "ул. Ленина, 25");

    // Book expamples where generated by ai
    Book book1("Война и мир", "Лев Толстой", "978-5-389-07435-4", 1869);
    Book book2("Преступление и наказание", "Федор Достоевский", "978-5-699-40445-2", 1866);
    Book book3("Мастер и Маргарита", "Михаил Булгаков", "978-5-17-067842-0", 1967);
    Book book4("1984", "Джордж Оруэлл", "978-5-04-103630-9", 1949);
    
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);

    library.displayLibraryInfo();
    library.displayAllBooks();

    library.borrowBook("978-5-389-07435-4"); // Война и мир
    library.borrowBook("978-5-699-40445-2"); // Преступление и наказание
    library.borrowBook("978-5-389-07435-4"); // Попробуем взять уже арендованную
   
    library.displayAvailableBooks();


    Book* foundBook = library.findBook("1984");
    if (foundBook) {
        cout << "Найдена книга:" << endl;
        foundBook->displayInfo();
    } else {
        cout << "Книга не найдена" << endl;
    }

    library.returnBook("978-5-389-07435-4"); // Война и мир
    library.removeBook("978-5-17-067842-0"); // Мастер и Маргарита
    library.displayLibraryInfo();
    library.displayAllBooks();



    return 0;
}

