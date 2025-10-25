
// ## Задача 7: Дружественные функции и операторы

// **Цель:** Изучить использование дружественных функций и перегрузку операторов.

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}
    
    // TODO: Геттеры и сеттеры
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
    
    void setReal(double r) { real = r; }
    void setImaginary(double i) { imaginary = i; }
    // TODO: Перегрузить операторы:
    // - Complex operator+(const Complex& other) const
    // - Complex operator-(const Complex& other) const
    // - Complex operator*(const Complex& other) const
    // - bool operator==(const Complex& other) const
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }
    
    Complex operator*(const Complex& other) const {
        // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
        return Complex(real * other.real - imaginary * other.imaginary,
                      real * other.imaginary + imaginary * other.real);
    }
    
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }
    
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
    
    // Унарный минус
    Complex operator-() const {
        return Complex(-real, -imaginary);
    }
    
    // Составные операторы присваивания
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }
    
    Complex& operator-=(const Complex& other) {
        real -= other.real;
        imaginary -= other.imaginary;
        return *this;
    }
    
    Complex& operator*=(const Complex& other) {
        double newReal = real * other.real - imaginary * other.imaginary;
        double newImaginary = real * other.imaginary + imaginary * other.real;
        real = newReal;
        imaginary = newImaginary;
        return *this;
    }
    
    // TODO: Сделать дружественными:
    // - friend ostream& operator<<(ostream& os, const Complex& c)
    // - friend istream& operator>>(istream& is, Complex& c)
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
    friend double magnitude(const Complex& c);
    friend Complex conjugate(const Complex& c);

    void display() const {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

ostream& operator<<(ostream& os, const Complex& c) {
    if (c.imaginary >= 0) {
        os << c.real << " + " << c.imaginary << "i";
    } else {
        os << c.real << " - " << -c.imaginary << "i";
    }
    return os;}

    istream& operator>>(istream& is, Complex& c) {
    cout << "Введите действительную часть: ";
    is >> c.real;
    cout << "Введите мнимую часть: ";
    is >> c.imaginary;
    return is;}

    // Дружественная функция для вычисления модуля комплексного числа
    double magnitude(const Complex& c) {
        return sqrt(c.real * c.real + c.imaginary * c.imaginary);
    }

    // Дружественная функция для вычисления сопряженного числа
    Complex conjugate(const Complex& c) {
        return Complex(c.real, -c.imaginary);
    }


int main() {
    // TODO: Создать несколько комплексных чисел
    // Продемонстрировать работу перегруженных операторов
    // Показать ввод/вывод через перегруженные операторы << и >>
    Complex c1(3.0, 4.0);
    Complex c2(1.5, -2.5);
    Complex c3;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex product = c1 * c2;
    Complex neg = -c1;
    
    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << product << endl;
    cout << "-c1 = " << neg << endl;
    
    cout << "\n=== Составные операторы ===" << endl;
    Complex c4 = c1;
    c4 += c2;
    cout << "c1 += c2: " << c4 << endl;

    c4 = c1;
    c4 *= c2;
    cout << "c1 *= c2: " << c4 << endl;

    Complex c5(3.0, 4.0);
    cout << "c1 = " << c1 << endl;
    cout << "c5 = " << c5 << endl;
    cout << "c1 == c5: " << (c1 == c5 ? "true" : "false") << endl;
    cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << endl;
    cout << "c1 != c2: " << (c1 != c2 ? "true" : "false") << endl;

    Complex c6;
    cin >> c6;
    cout << "Вы ввели: " << c6 << endl;

    Complex numbers[] = {Complex(1, 1), Complex(2, -3), Complex(0, 5)};
    const int size = sizeof(numbers) / sizeof(numbers[0]);

    Complex total;
    for (int i = 0; i < size; ++i) {
        cout << "numbers[" << i << "] = " << numbers[i] << " ";
        total += numbers[i];
    }
    cout << "Сумма всех чисел: " << total << endl;



    return 0;
}