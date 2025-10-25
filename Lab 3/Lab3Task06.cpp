// ## Задача 6: Статические члены и константы

// **Цель:** Изучить работу со статическими членами класса.


#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;
    static int totalAccounts;           // Общее количество счетов
    static double totalBankBalance;     // Общий баланс банка
    const double MIN_BALANCE = 10.0;    // Минимальный баланс

public:
    // TODO: Создать конструктор с параметрами
    // В конструкторе увеличивать totalAccounts и добавлять баланс к totalBankBalance
    BankAccount(string accNum, string owner, double initialBalance) 
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {
        totalAccounts++;
        totalBankBalance += balance;
        cout << "Создан счет №" << accountNumber << " для " << ownerName << endl;
    }
    // TODO: Создать деструктор
    // В деструкторе уменьшать totalAccounts и вычитать баланс из totalBankBalance
    ~BankAccount() {
        totalAccounts--;
        totalBankBalance -= balance;
        cout << "Закрыт счет №" << accountNumber << " для " << ownerName << endl;
    }
    // TODO: Реализовать методы:
    // - deposit(double amount)
    // - withdraw(double amount) с проверкой минимального баланса
    // - displayAccountInfo() const
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            totalBankBalance += amount;
            cout << "На счет " << accountNumber << " внесено: " << amount << endl;
            cout << "Текущий баланс: " << balance << endl;
        } else {
            cout << "Ошибка: сумма для пополнения должна быть положительной" << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Ошибка: сумма для снятия должна быть положительной" << endl;
            return false;
        }
        
        if (balance - amount >= MIN_BALANCE) {
            balance -= amount;
            totalBankBalance -= amount;
            cout << "Со счета " << accountNumber << " снято: " << amount << endl;
            cout << "Текущий баланс: " << balance << endl;
            return true;
        } else {
            cout << "Ошибка: недостаточно средств. Минимальный баланс: " << MIN_BALANCE << endl;
            cout << "Запрошено: " << amount << ", доступно: " << (balance - MIN_BALANCE) << endl;
            return false;
        }
    }

     void displayAccountInfo() const {
        cout << "\n=== Информация о счете ===" << endl;
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << balance << endl;
        cout << "Минимальный баланс: " << MIN_BALANCE << endl;
        cout << "==========================" << endl;
    }

    string getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }
    double getMinBalance() const { return MIN_BALANCE; }
    
    // TODO: Статические методы:
    // - static int getTotalAccounts()
    // - static double getTotalBankBalance()
    // - static double getAverageBalance()
    static int getTotalAccounts() {
        return totalAccounts;
    }
    
    static double getTotalBankBalance() {
        return totalBankBalance;
    }
    
    static double getAverageBalance() {
        if (totalAccounts > 0) {
            return totalBankBalance / totalAccounts;
        }
        return 0.0;
    }
    
    static void displayBankStatistics() {
        cout << "\n=== Банковская статистика ===" << endl;
        cout << "Общее количество счетов: " << getTotalAccounts() << endl;
        cout << "Общий баланс банка: " << getTotalBankBalance() << endl;
        cout << "Средний баланс на счету: " << getAverageBalance() << endl;
        cout << "=============================" << endl;
    }
};

// TODO: Инициализировать статические переменные
int BankAccount::totalAccounts = 0;
double BankAccount::totalBankBalance = 0.0;

int main() {
    // TODO: Создать несколько счетов
    // Продемонстрировать работу статических методов
    // Показать, что статические переменные общие для всех объектов
    BankAccount::displayBankStatistics();

    BankAccount account1("ACC001", "Иван Иванов", 1000.0);
    BankAccount account2("ACC002", "Петр Петров", 500.0);
    BankAccount account3("ACC003", "Мария Сидорова", 1500.0);

    BankAccount::displayBankStatistics();

    account1.deposit(200.0);
    account2.withdraw(100.0);
    account3.withdraw(1495.0);

    BankAccount::displayBankStatistics();

    account1.displayAccountInfo();
    account2.displayAccountInfo();
    account3.displayAccountInfo();


    cout << "\n=== Демонстрация общих статических данных ===" << endl;
    cout << "Через account1: " << account1.getTotalAccounts() << " счетов" << endl;
    cout << "Через account2: " << account2.getTotalAccounts() << " счетов" << endl;
    cout << "Через класс: " << BankAccount::getTotalAccounts() << " счетов" << endl;
    cout << "Все три способа показывают одинаковый результат!" << endl;

    BankAccount* tempAccount = new BankAccount("ACC999", "Временный клиент", 300.0);
    BankAccount::displayBankStatistics();


    delete tempAccount;
    BankAccount::displayBankStatistics();

    return 0;
}