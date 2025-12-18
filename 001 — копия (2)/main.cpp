#include <iostream>
#include <climits>  // для INT_MAX
#include <vector>

using namespace std;

int main() {
    int n, m;

    // Ввод размеров с проверкой
    cout << "Введите количество строк и столбцов (n, m <= 100): ";
    if (!(cin >> n >> m) || n <= 0 || m <= 0 || n > 100 || m > 100) {
        cout << "Ошибка: n и m должны быть от 1 до 100" << endl;
        return 1;
    }

    // Используем vector для безопасности
    vector<vector<int>> a(n, vector<int>(m));

    // Ввод матрицы
    cout << "Введите матрицу " << n << "x" << m << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!(cin >> a[i][j])) {
                cout << "Ошибка ввода элемента [" << i << "][" << j << "]" << endl;
                return 1;
            }
        }
    }

    // Поиск столбца с минимальной суммой
    int minSum = INT_MAX;  // Корректная инициализация
    int minCol = 0;

    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
            minCol = j;
        }
    }

    cout << "Столбец с минимальной суммой: " << minCol + 1
        << " (сумма = " << minSum << ")" << endl;

    // Увеличение элементов выбранного столбца на 3
    for (int i = 0; i < n; i++) {
        a[i][minCol] += 3;
    }

    // Вывод матрицы
    cout << "\nИзмененная матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}