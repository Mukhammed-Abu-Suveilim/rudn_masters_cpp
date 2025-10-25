// ## Задача 3: Полиморфизм - Геометрические фигуры

// **Цель:** Реализовать полиморфное поведение с виртуальными функциями.


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    string name;

public:
    Shape(string n, string c) : name(n), color(c) {}
    virtual ~Shape() {}
    
    // TODO: Объявить чисто виртуальные методы:
    // - calculateArea()
    // - calculatePerimeter()
    // - draw()
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void draw() const = 0;
    
    
    virtual void displayInfo() const {
        cout << "Фигура: " << name << ", Цвет: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string c, double r) : Shape("Круг", c), radius(r) {}
    
    // TODO: Реализовать виртуальные методы
    // Площадь круга: π * r²
    // Периметр круга: 2 * π * r
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
    
    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }
    
    void draw() const override {
        cout << "Рисуем круг радиусом " << radius << " цветом " << color << endl;
    }

    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Радиус: " << radius << endl;
        cout << "Площадь: " << calculateArea() << endl;
        cout << "Периметр (длина окружности): " << calculatePerimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(string c, double w, double h) : Shape("Прямоугольник", c), width(w), height(h) {}
    
    // TODO: Реализовать виртуальные методы
    double calculateArea() const override {
        return width * height;
    }
    
    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
    
    void draw() const override {
        cout << "Рисуем прямоугольник " << width << "x" << height << " цветом " << color << endl;
    }

    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Ширина: " << width << ", Высота: " << height << endl;
        cout << "Площадь: " << calculateArea() << endl;
        cout << "Периметр: " << calculatePerimeter() << endl;
    }

};

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(string col, double a, double b, double c) : Shape("Треугольник", col), sideA(a), sideB(b), sideC(c) {}
    
    // TODO: Реализовать виртуальные методы
    // Площадь по формуле Герона
    double calculateArea() const override {
        // Формула Герона
        double s = calculatePerimeter() / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }
    
    double calculatePerimeter() const override {
        return sideA + sideB + sideC;
    }
    void draw() const override {
        cout << "Рисуем треугольник со сторонами " << sideA << ", " 
             << sideB << ", " << sideC << " цветом " << color << endl;
    }
    
    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Стороны: " << sideA << ", " << sideB << ", " << sideC << endl;
        cout << "Площадь: " << calculateArea() << endl;
        cout << "Периметр: " << calculatePerimeter() << endl;
    }

};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Circle("Красный", 5.0));
    shapes.push_back(new Rectangle("Синий", 4.0, 6.0));
    shapes.push_back(new Triangle("Зеленый", 3.0, 4.0, 5.0));
    
    // TODO: Продемонстрировать полиморфизм - вывести информацию
    // о всех фигурах через указатель на базовый класс
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "\n--- Фигура " << i + 1 << " ---" << endl;
        shapes[i]->displayInfo();
        shapes[i]->draw();
        cout << endl;
    }

    double totalArea = 0.0;
    for (auto shape : shapes) {
        totalArea += shape->calculateArea();
    }
    cout << "Общая площадь всех фигур: " << totalArea << endl;
    
    // Очистка памяти
    for (auto shape : shapes) {
        delete shape;
    }
    
    return 0;
}