// Функция для вывода информации о книге
void printBook(const Book& book) {
    std::cout << "Название: " << book.title << ", Автор: " << book.author
              << ", Год: " << book.year << ", Цена: " << book.price << std::endl;
}
