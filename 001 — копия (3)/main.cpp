#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Проверка, все ли цифры различны
bool allDigitsDistinct(int x) {
    if (x == 0) return true; // 0 имеет 0 цифр, все они различны

    unordered_set<int> digits;
    while (x > 0) {
        int digit = x % 10;
        if (digits.count(digit)) {
            return false;
        }
        digits.insert(digit);
        x /= 10;
    }
    return true;
}

// Произведение цифр
int productOfDigits(int x) {
    if (x == 0) return 0;

    int product = 1;
    while (x > 0) {
        product *= (x % 10);
        x /= 10;
    }
    return product;
}

int main() {
    int n;
    cout << "Введите количество чисел (n <= 10000): ";

    if (!(cin >> n) || n < 0 || n > 10000) {
        cout << "Ошибка: n должно быть от 0 до 10000" << endl;
        return 1;
    }

    vector<int> a;
    a.reserve(n * 2); // Резервируем место для возможных дубликатов

    cout << "Введите " << n << " натуральных чисел: ";
    for (int i = 0; i < n; i++) {
        int num;
        if (!(cin >> num) || num <= 0) {
            cout << "Ошибка: числа должны быть натуральными (положительными)" << endl;
            return 1;
        }
        a.push_back(num);
    }

    // Шаг 1: Удаляем числа с различными цифрами
    vector<int> filtered;
    for (int num : a) {
        if (!allDigitsDistinct(num)) {
            filtered.push_back(num);
        }
    }

    // Шаг 2: Дублируем числа, произведение цифр которых кратно 14
    vector<int> result;
    result.reserve(filtered.size() * 2);

    for (int num : filtered) {
        result.push_back(num);
        if (productOfDigits(num) % 14 == 0) {
            result.push_back(num);
        }
    }

    // Вывод
    cout << "Результат: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}