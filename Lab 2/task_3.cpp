
// #### **Задача 3: Калькулятор для комплексных чисел (Пользовательские типы данных)**
// Создайте структуру `Complex` для представления комплексного числа (действительная и мнимая части).
// 1.  Напишите функции для основных операций:
//     *   `Complex add(Complex a, Complex b);` // Сложение
//     *   `Complex subtract(Complex a, Complex b);` // Вычитание
//     *   `Complex multiply(Complex a, Complex b);` // Умножение
//     *   `void print(Complex c);` // Вывод в форме `(a + bi)`
// 2.  В функции `main` продемонстрируйте работу всех функций, создав несколько комплексных чисел и выполнив с ними операции.

// **Цель:** Работа со структурами и передача их в функции по значению.

#include <iostream>

// Структура для комплексного числа
struct Complex {
    double real;
    double imag;
};

// Функция сложения комплексных чисел
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Функция вычитания комплексных чисел
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// Функция умножения комплексных чисел
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// Функция вывода комплексного числа
void print(Complex c) {
    if (c.imag >= 0) {
        std::cout << "(" << c.real << " + " << c.imag << "i)";
    } else {
        std::cout << "(" << c.real << " - " << -c.imag << "i)";
    }
}

int main() {
    // Создание комплексных чисел
    Complex a = {3.0, 4.0};
    Complex b = {5.0, -6.0};

    // Демонстрация операций
    Complex sum = add(a, b);
    Complex diff = subtract(a, b);
    Complex prod = multiply(a, b);

    // Вывод результатов
    std::cout << "a = ";
    print(a);
    std::cout << ", b = ";
    print(b);
    std::cout << std::endl;

    std::cout << "Сумма: ";
    print(sum);
    std::cout << std::endl;

    std::cout << "Разность: ";
    print(diff);
    std::cout << std::endl;

    std::cout << "Произведение: ";
    print(prod);
    std::cout << std::endl;

    return 0;
}
