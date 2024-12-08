#ifndef CAR_WASH_QUEUE_HPP
#define CAR_WASH_QUEUE_HPP

#include <queue>
#include <string>
#include <stdexcept>
#include <iostream>

/**
 * @file CarWashQueue.h
 * @brief Заголовочный файл, содержащий реализацию шаблонного класса CarWashQueue.
 *
 * Класс CarWashQueue предоставляет базовые операции для управления очередью машин на автомойке.
 */

/**
 * @class CarWashQueue
 * @brief Шаблонный класс для управления очередью машин.
 *
 * Класс предоставляет методы для добавления машин, удаления машины из очереди (обслуживания) и проверки размера очереди.
 *
 * @tparam T Тип данных, хранимых в очереди. Например, `std::string` для хранения названий машин.
 */
template <typename T>
class CarWashQueue {
private:
    std::queue<T> carQueue; ///< Основная очередь, реализованная на основе `std::queue`.

public:
    /**
     * @brief Добавляет машину в очередь.
     *
     * Метод помещает машину в конец очереди.
     *
     * @param car Машина, которую нужно добавить (тип T).
     *
     * Пример:
     * @code
     * CarWashQueue<std::string> queue;
     * queue.addCar("Tesla Model 3");
     * @endcode
     */
    void addCar(const T& car);

    /**
     * @brief Удаляет машину из начала очереди после обслуживания.
     *
     * Метод удаляет первую машину в очереди. Если очередь пуста, выбрасывает исключение.
     *
     * @throws std::runtime_error Если очередь пуста.
     *
     * Пример:
     * @code
     * CarWashQueue<std::string> queue;
     * queue.serveCar();
     * @endcode
     */
    void serveCar();

    /**
     * @brief Возвращает количество машин в очереди.
     *
     * Метод возвращает текущий размер очереди.
     *
     * @return size_t Количество машин в очереди.
     *
     * Пример:
     * @code
     * CarWashQueue<std::string> queue;
     * size_t size = queue.size();
     * @endcode
     */
    size_t size() const;

    /**
     * @brief Деструктор для класса CarWashQueue.
     *
     * Выводит сообщение о разрушении объекта. Не выполняет дополнительных операций,
     * так как `std::queue` автоматически очищается.
     */
    ~CarWashQueue();
};

template <typename T>
void CarWashQueue<T>::addCar(const T& car) {
    // Машина добавляется в конец очереди
    carQueue.push(car);
    // Уведомление о добавлении машины
    std::cout << "Added car to queue: " << car << "\n";
}

template <typename T>
void CarWashQueue<T>::serveCar() {
    // Проверка, пуста ли очередь
    if (carQueue.empty()) {
        throw std::runtime_error("Queue is empty. No car to serve.");
    }
    // Получаем первую машину
    T servedCar = carQueue.front();
    // Удаляем машину из очереди
    carQueue.pop();
    // Уведомление об "обслуживании" машины
    std::cout << "Car served and removed from queue: " << servedCar << "\n";
}

template <typename T>
size_t CarWashQueue<T>::size() const {
    // Возвращаем размер очереди
    return carQueue.size();
}

template <typename T>
CarWashQueue<T>::~CarWashQueue() {
    // Сообщение о разрушении объекта
    std::cout << "CarWashQueue destroyed. Remaining cars in queue: " << carQueue.size() << "\n";
}

#endif // CAR_WASH_QUEUE_HPP
