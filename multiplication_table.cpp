#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n, m;
    if (argc >= 3) {
        try {
            n = stoi(argv[1]);
            m = stoi(argv[2]);
        } catch (const invalid_argument&) {
            cerr << "Ошибка: введите целые числа." << endl;
            return 1;
        }
    } else {
        cout << "Введите количество строк (N): ";
        cin >> n;
        cout << "Введите количество столбцов (M): ";
        cin >> m;
        
        if (cin.fail()) {
            cerr << "Ошибка: введите целые числа." << endl;
            return 1;
        }
    }

    if (n <= 0 || m <= 0) {
        cerr << "Размеры таблицы должны быть положительными." << endl;
        return 1;
    }

    int max_val = n * m;
    int col_width = static_cast<int>(to_string(max_val).length()) + 1;

    cout << "\nТаблица умножения:" << endl;

    // Верхний заголовок
    cout << setw(col_width) << " ";
    for (int j = 1; j <= m; ++j) {
        cout << setw(col_width) << j;
    }
    cout << endl;

    // Разделитель
    cout << string(col_width * (m + 1), '-') << endl;

    // Тело таблицы
    for (int i = 1; i <= n; ++i) {
        cout << setw(col_width - 1) << left << i << "|";
        for (int j = 1; j <= m; ++j) {
            cout << setw(col_width) << right << i * j;
        }
        cout << endl;
    }

    return 0;
}