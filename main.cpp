/**
 * @file main.cpp
 * @brief Демонстрационная программа для работы с очередью машин на мойке.
 *
 * В программе создаётся очередь машин в динамической памяти. Три экземпляра класса создаются предварительно.
 * Пользователь может добавлять новые машины, "обслуживать" первую машину в очереди (удалять ее из очереди),
 * проверять текущее количество машин в очереди через интерактивное меню.
 */

#include "CarWashQueue.h"
#include <string>
#include <iostream>

/**
 * @brief Отображает меню..
 *
 * Функция выводит список доступных действий:
 * - Добавить машину в очередь.
 * - Обслужить машину.
 * - Узнать текущее количество машин в очереди.
 * - Завершить работу программы.
 */
void displayMenu() {
    std::cout << "\nCar Wash Queue Menu:\n";
    std::cout << "1. Add a car to the queue\n"; // Добавить машину
    std::cout << "2. Serve a car\n";           // Обслужить машину
    std::cout << "3. Check the queue size\n";  // Проверить размер очереди
    std::cout << "4. Exit\n";                  // Завершить работу
    std::cout << "Choose an option: ";
}

/**
 * @brief Главная функция программы.
 *
 * Основная логика программы:
 * 1. Создание очереди машин в динамической памяти.
 * 2. Добавление трёх предустановленных машин в очередь.
 * 3. Интерактивное меню для взаимодействия с очередью:
 *    - Добавление машин.
 *    - Обслуживание машин.
 *    - Проверка размера очереди.
 *    - Завершение работы.
 * 4. Очистка памяти, выделенной под очередь.
 *
 * @return int Код завершения программы.
 */
int main() {
    // Создание очереди в динамической памяти
    CarWashQueue<std::string>* carQueue = new CarWashQueue<std::string>();
    std::cout << "Car wash queue initialized.\n";

    // Добавление трёх предустановленных машин в очередь
    carQueue->addCar("Tesla Model 3");
    carQueue->addCar("BMW X5");
    carQueue->addCar("Ford Mustang");
    std::cout << "Initial cars added to the queue: Tesla Model 3, BMW X5, Ford Mustang.\n";

    // Переменная для контроля работы программы
    bool running = true;

    while (running) {
        // Отображение меню пользователю
        displayMenu();

        int choice;
        std::cin >> choice; // Считываем выбор пользователя

        switch (choice) {
            case 1: { // Добавление машины в очередь
                std::cin.ignore(); // Очистка буфера ввода
                std::cout << "Enter car name: ";
                std::string carName;
                std::getline(std::cin, carName); // Считывание имени машины
                carQueue->addCar(carName); // Добавление машины в очередь
                std::cout << "Car \"" << carName << "\" added to the queue.\n";
                break;
            }
            case 2: // Обслуживание машины
                try {
                    carQueue->serveCar(); // Удаление первой машины из очереди
                } catch (const std::exception& e) { // Обработка исключения, если очередь пуста
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            case 3: // Проверка размера очереди
                std::cout << "Current queue size: " << carQueue->size() << "\n";
                break;
            case 4: // Завершение работы программы
                running = false; // Установка флага завершения работы
                break;
            default: // Обработка некорректного выбора
                std::cout << "Invalid option. Please try again.\n";
        }
    }

    // Освобождение памяти, выделенной под очередь
    delete carQueue;
    std::cout << "Memory for car wash queue released.\n";

    std::cout << "Program terminated. Goodbye!\n";
    return 0;
}
