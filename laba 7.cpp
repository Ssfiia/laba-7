#include <iostream>
#include <vector>
#include <Windows.h>
#include "Header.h"
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
    int choice;
    do {
        cout << "\n ВЫБОР ЗАДАНИЯ " << endl;
        cout << "1. Sort3: Отсортировать массив по убыванию" << endl;
        cout << "2. ExamTaskC15: Фитнес-центр" << endl;
        cout << "3. Five15: Результаты ЕГЭ" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:{
            int n;
            do {
                cout << "Введите размерность массива: ";
                cin >> n;
                if (n <= 0)
                    cout << "Размерность должна быть натуральным числом!\n";
            } while (n <= 0);
            vector<float> op(n);
            for (int i = 0; i < n; i++) {
                cout << "Введите число: ";
                cin >> op[i];
            }
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            Sort3(op, filename);
            cout << endl;
            break;
            }
        case 2:
            int k;
            cout << "Введите код клиента (10-99), про которого хотите узнать информацию: ";
            cin >> k;
            do {
                if (k < 10 || k > 99) {
                    cout << "Код клиента должен быть в диапазоне 10-99!\n Введите ещё раз: ";
                    cin >> k;
                }
            } while (k < 10 || k > 99);
            ExamTaskC15(k);
            break;
        case 3: {
            string inFile, outFile;
            cout << "Введите имя входного файла: ";
            cin >> inFile;
            cout << "Введите имя выходного файла: ";
            cin >> outFile;
            Five15(inFile, outFile);
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}
