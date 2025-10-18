/*
Задача 1: Анализ температурных данных (Массивы, базовые типы)
Напишите программу, которая:

Запрашивает у пользователя количество дней N для анализа.
Создает массив для хранения дневных температур (тип double).
Заполняет массив значениями, введенными пользователем.
Вычисляет и выводит:
Среднюю температуру за период.
Минимальную и максимальную температуру.
Количество дней, когда температура была ниже средней.
Цель: Закрепление работы со статическими массивами, циклами и базовыми арифметическими операциями.
*/

#include <iostream>

double CalculateAveTemp(double temp_data[], int NumOfDays){
    // Calculate average temperature
    double sumOfTemp = 0.0;
    for (int day = 0; day < NumOfDays; day++){
        sumOfTemp += temp_data[day];
    }
    double aveTemp = sumOfTemp / NumOfDays;
    return aveTemp;
}

double CalculateMinTemp(double temp_data[], int NumOfDays){
    // Calculate min temperature
    double minTemp = temp_data[0];
    for (int day = 0; day < NumOfDays; day++){
        if (temp_data[day] < minTemp){
            minTemp = temp_data[day];
        }
    }
    return minTemp;
}

double CalculateMaxTemp(double temp_data[], int NumOfDays){
    // Calculate min temperature
    double maxTemp = temp_data[0];
    for (int day = 0; day < NumOfDays; day++){
        if (temp_data[day] > maxTemp){
            maxTemp = temp_data[day];
        }
    }
    return maxTemp;
}

int CountLessThanAve(double temp_data[], int NumOfDays, double aveTemp){
    // Count days below average
    int countBelowAverage = 0;
    for (int i = 0; i < NumOfDays; i++) {
        if (temp_data[i] < aveTemp){
            countBelowAverage++;
        }
    }
    return countBelowAverage;
}

int main() {
    int NumOfDays;
    std::cout << "Enter the number of days: ";
    std::cin >> NumOfDays;
    
    double temp_data[NumOfDays];
    
    // Fill array with user input
    for (int i = 0; i < NumOfDays; i++){
        std::cout << "Enter temperature for day " << (i + 1) << ": ";
        std::cin >> temp_data[i];
    }
        
    double aveTemp = CalculateAveTemp(temp_data, NumOfDays);
    double minTemp = CalculateMinTemp(temp_data, NumOfDays);
    double maxTemp = CalculateMaxTemp(temp_data, NumOfDays);
    int countBelowAverage = CountLessThanAve(temp_data, NumOfDays, aveTemp);


    // Output results
    std::cout << "\nResults:" << std::endl;
    std::cout << "Average temperature: " << aveTemp << std::endl;
    std::cout << "Minimum temperature: " << minTemp << std::endl;
    std::cout << "Maximum temperature: " << maxTemp << std::endl;
    std::cout << "Days below average: " << countBelowAverage << std::endl;

    return 0;
}