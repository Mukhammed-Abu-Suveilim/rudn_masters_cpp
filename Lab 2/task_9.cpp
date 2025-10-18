// #### **Задача 9: Модификация данных через ссылки и указатели (Ссылки, указатели)**
// Создайте структуру `Account` с полями: номер счета (`int`) и баланс (`double`).
// 1.  Напишите функцию `void deposit(Account* acc, double amount)`, которая увеличивает баланс счета на указанную сумму, используя указатель.
// 2.  Напишите функцию `void withdraw(Account& acc, double amount)`, которая уменьшает баланс счета на указанную сумму, используя ссылку. Функция должна проверять, достаточно ли средств на счете.
// 3.  Создайте в `main` объект `Account`, продемонстрируйте работу обеих функций.

// **Цель:** Применение ссылок и указателей для модификации полей структур.

#include <iostream>

struct Account {
    int number;
    double balance;
};

// Функция для пополнения счета (через указатель)
void deposit(Account* acc, double amount) {
    if (acc != nullptr && amount > 0) {
        acc->balance += amount;
        std::cout << "Счет " << acc->number << " пополнен на " << amount << ". Новый баланс: " << acc->balance << std::endl;
    }
}

// Функция для снятия средств (через ссылку)
void withdraw(Account& acc, double amount) {
    if (amount > 0) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
            std::cout << "Со счета " << acc.number << " снято " << amount << ". Новый баланс: " << acc.balance << std::endl;
        } else {
            std::cout << "Недостаточно средств на счете " << acc.number << std::endl;
        }
    }
}

int main() {
    Account myAccount = {12345, 1000.0};

    std::cout << "Начальный баланс счета " << myAccount.number << ": " << myAccount.balance << std::endl;

    deposit(&myAccount, 500.0);

    withdraw(myAccount, 200.0);
    withdraw(myAccount, 2000.0); // Попытка снять больше, чем есть на счете

    return 0;
}
