// ## Задача 9: Шаблоны классов

// **Цель:** Изучить создание и использование шаблонных классов.


#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class Stack {
private:
    vector<T> elements;
    int capacity;

public:
    Stack(int size = 10) : capacity(size) {}
    
    // TODO: Реализовать методы:
    // - void push(const T& element)
    // - T pop()
    // - T top() const
    // - bool isEmpty() const
    // - bool isFull() const
    // - int size() const
    
    void display() const {
        cout << "Стек: ";
        for (const auto& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

template<typename T>
class Queue {
private:
    vector<T> elements;
    int capacity;

public:
    Queue(int size = 10) : capacity(size) {}
    
    // TODO: Реализовать методы:
    // - void enqueue(const T& element)
    // - T dequeue()
    // - T front() const
    // - bool isEmpty() const
    // - bool isFull() const
    // - int size() const
};

int main() {
    // TODO: Протестировать Stack и Queue с разными типами данных:
    // - int
    // - double
    // - string
    
    return 0;
}