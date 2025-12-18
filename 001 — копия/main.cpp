#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// Исправленная функция для получения первой цифры
int firstDigit(int x) {
    // Обрабатываем случай x = 0
    if (x == 0) return 0;

    // Берем абсолютное значение на случай отрицательных чисел
    x = abs(x);

    // Извлекаем первую цифру
    while (x >= 10) {
        x /= 10;
    }
    return x;
}

// Исправленная функция для вычисления произведения цифр
int productOfDigits(int x) {
    // Обрабатываем случай x = 0
    if (x == 0) return 0;

    x = abs(x);
    int product = 1;
    while (x > 0) {
        int digit = x % 10;
        if (digit == 0) {
            return 0;  // Если есть хотя бы один ноль, произведение сразу 0
        }
        product *= digit;
        x /= 10;
    }
    return product;
}

int main() {
    int n;

    // Проверка ввода
    cout << "Введите количество чисел (n <= 1000): ";
    if (!(cin >> n) || n < 0 || n > 1000) {
        cout << "Ошибка: n должно быть от 0 до 1000" << endl;
        return 1;
    }

    // Используем vector вместо статического массива
    vector<int> a(n);

    // Ввод чисел с проверкой
    cout << "Введите " << n << " натуральных чисел: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> a[i]) || a[i] <= 0) {
            cout << "Ошибка: числа должны быть натуральными (положительными)" << endl;
            return 1;
        }
    }

    // Оптимизированная сортировка с предварительным вычислением значений
    vector<tuple<int, int, int>> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = make_tuple(
            firstDigit(a[i]),      // первая цифра
            productOfDigits(a[i]), // произведение цифр
            a[i]                   // само число
        );
    }

    // Сортировка кортежей (лексикографическое сравнение)
    sort(data.begin(), data.end());

    // Восстановление отсортированного массива
    for (int i = 0; i < n; i++) {
        a[i] = get<2>(data[i]);
    }

    // Вывод результата
    cout << "Результат: ";
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}