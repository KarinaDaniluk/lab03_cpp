#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<int> data;
    int lowerBound;
    int upperBound;

public:
    // Конструктор класу
    Vector(int lower, int upper) : lowerBound(lower), upperBound(upper) {
        // Ініціалізація вектора з вказаними межами індексів
        data.resize(upper - lower + 1);
    }

    // Оператор доступу до елементу за індексом
    int& operator[](int index) {
        // Перевірка виходу за межі індексів
        if (index < lowerBound || index > upperBound) {
            std::cerr << "Помилка: ви вийшли за межі індексів" << std::endl;
            exit(1);
        }
        return data[index - lowerBound];
    }

    // Оператор додавання двох векторів
    Vector operator+(const Vector& other) const {
        // Перевірка на співпадіння меж індексів
        if (lowerBound != other.lowerBound || upperBound != other.upperBound) {
            std::cerr << "Помилка: межі індексів векторів не збігаються" << std::endl;
            exit(1);
        }
        Vector result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = data[i - lowerBound] + other.data[i - lowerBound];
        }
        return result;
    }

    // Оператор віднімання двох векторів
    Vector operator-(const Vector& other) const {
        // Перевірка на співпадіння меж індексів
        if (lowerBound != other.lowerBound || upperBound != other.upperBound) {
            std::cerr << "Помилка: межі індексів векторів не збігаються" << std::endl;
            exit(1);
        }
        Vector result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = data[i - lowerBound] - other.data[i - lowerBound];
        }
        return result;
    }

    // Оператор множення вектора на скаляр
    Vector operator*(int scalar) const {
        Vector result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = data[i - lowerBound] * scalar;
        }
        return result;
    }

    // Оператор ділення вектора на скаляр
    Vector operator/(int scalar) const {
        if (scalar == 0) {
            std::cerr << "Помилка: ділення на нуль" << std::endl;
            exit(1);
        }
        Vector result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = data[i - lowerBound] / scalar;
        }
        return result;
    }

    // Функція друку всього вектора
    void print() const {
        std::cout << "Вектор: [ ";
        for (int i = lowerBound; i <= upperBound; ++i) {
            std::cout << data[i - lowerBound] << " ";
        }
        std::cout << "]" << std::endl;
    }

    // Функція друку елементу вектора по індексу
    void printElement(int index) const {
        // Перевірка виходу за межі індексів
        if (index < lowerBound || index > upperBound) {
            std::cerr << "Помилка: ви вийшли за межі індексів" << std::endl;
            exit(1);
        }
        std::cout << "Елемент[" << index << "]: " << data[index - lowerBound] << std::endl;
    }
};

int main() {
    // Приклад використання класу Vector
    Vector vec1(1, 5);
    Vector vec2(1, 5);

    // Заповнення векторів
    for (int i = 1; i <= 5; ++i) {
        vec1[i] = i;
        vec2[i] = 2 * i;
    }

    // Виконання операцій
    Vector sum = vec1 + vec2;
    Vector diff = vec1 - vec2;
    Vector scaled = vec1 * 2;
    Vector quotient = vec2 / 2;

    // Виведення результатів
    std::cout << "Сума:" << std::endl;
    sum.print();
    std::cout << "Різниця:" << std::endl;
    diff.print();
    std::cout << "Масштабований вектор:" << std::endl;
    scaled.print();
    std::cout << "Результат ділення:" << std::endl;
    quotient.print();

    // Друкуємо окремі елементи
    vec1.printElement(3);
    vec2.printElement(4);

    return 0;
}
