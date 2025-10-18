// #### **Задача 2: Манипуляции со строками (Строки как массивы, указатели)**
// Напишите программу, которая работает со строкой C-style (`char[]`).
// 1.  Пользователь вводит строку (можно использовать `std::cin.getline`).
// 2.  Программа определяет длину строки *без использования стандартной функции `strlen`*.
// 3.  Программа переворачивает строку *на месте* (in-place), т.е. не создавая новый массив.
// 4.  Программа подсчитывает количество вхождений определенного символа (также введенного пользователем) в строку.

// **Цель:** Понимание строк C-style, арифметики указателей и алгоритмов обработки массивов.

#include <iostream>
#include <string.h>

// Функция для вычисления длины строки без использования strlen
int stringLength(const char* str) {
    int length = 0;
    while (str[length]){length++;}
    return length;
}


void reverseString(char str[])
{
    int length = stringLength(str) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

int countCharacter(char* str, char letter){
    int count = 0; 
    int length = stringLength(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == letter){
            count++;
        }
    }
    return count;    
};

int main() {
    const int MAX_SIZE = 256;
    char inputString[MAX_SIZE];
    char searchChar;
    
    // 1. Ввод строки от пользователя
    std::cout << "Введите строку: ";
    std::cin.getline(inputString, MAX_SIZE);
    
    // 2. Определение длины строки
    int length = stringLength(inputString);
    std::cout << "Длина строки: " << length << std::endl;
    
    // 3. Переворот строки на месте
    std::cout << "Исходная строка: " << inputString << std::endl;
    reverseString(inputString);
    std::cout << "Перевернутая строка: " << inputString << std::endl;
    
    // 4. Подсчет вхождений символа
    std::cout << "Введите символ для поиска: ";
    std::cin >> searchChar;
    
    int charCount = countCharacter(inputString, searchChar);
    std::cout << "Символ '" << searchChar << "' встречается " << charCount << " раз(а)" << std::endl;
    
    return 0;
}

