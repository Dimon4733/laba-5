#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <clocale> 

using namespace std;

int main() {
    int n;
    setlocale(LC_ALL, "Russian");
    // Безопасный ввод с проверкой
    cout << "Введите количество чисел (n <= 10000): ";
    if (!(cin >> n) || n < 0 || n > 10000) {
        cout << "Ошибка ввода! n должно быть от 0 до 10000" << endl;
        return 1;
    }

    // Используем vector вместо массива в стеке
    vector<int> a(n);

    // Ввод последовательности
    cout << "Введите " << n << " натуральных чисел: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> a[i]) || a[i] <= 0) {
            cout << "Ошибка: числа должны быть натуральными (положительными)" << endl;
            return 1;
        }
    }

    // Более эффективная проверка дубликатов
    unordered_set<int> seen;
    bool hasDuplicate = false;

    for (int num : a) {
        if (seen.count(num)) {
            hasDuplicate = true;
            break;
        }
        seen.insert(num);
    }

    // Если есть дубликаты, сортируем по невозрастанию последней цифры
    if (hasDuplicate) {
        sort(a.begin(), a.end(), [](int x, int y) {
            // Берем абсолютное значение для работы с отрицательными числами
            return (abs(x) % 10) > (abs(y) % 10);
            });
    }

    // Вывод
    cout << "Результат: ";
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}