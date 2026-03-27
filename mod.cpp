#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include "Header.h"
void Sort3(std::vector<float>& op, const std::string& filename) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	using namespace std;
	vector<float>  a = op;
	int n = op.size();
	ofstream ofile(filename);
	if (!ofile.is_open())
		cout << "Ошибка открытия файла!\n";
	ofile << "Исходный массив :";
	cout << "Исходный массив :";
	for (int i = 0; i < n; i++) {
		ofile << a[i] << " ";
		cout << a[i] << " ";
	}
	ofile << endl << endl;
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		bool f = false;
		for (int j = n-1; j > i; j--) {
			if (a[j] > a[j-1]) {
				float t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;
				f = true;
			}
		}
		ofile << "После итерации: ";
		cout << "После итерации: ";
		for (int j = 0; j <= i; j++) {
			ofile << a[j] << " ";
			cout << a[j] << " ";
		}
		ofile << "|";
		cout << "|";
		for (int j = i + 1; j < n; j++) {
			ofile << a[j] << " ";
			cout << a[j] << " ";
		}
		ofile << endl;
		cout << endl;
		if (!f) break;
	}
	ofile << endl;
	cout << endl;
	ofile << "Отсортированный массив :";
	cout << "Отсортированный массив :";
	for (int i = 0; i < n; i++) {
		ofile << a[i] << " ";
		cout << a[i] << " ";
	}
}
void ExamTaskC15(int k) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
    int n;
    cout << "Введите количество клиентов: ";
    cin >> n;
    int maxProd[11] = { 0 };
    int maxMonth[11] = { 0 };
    bool data[11] = { false };
    bool client = false;

    if (n > 0) {
        for (int i = 0; i < n; i++) {
            C15 inf;
            cout << "Введите данные (код клиента (10-99), продолжительность (1-30), год (2000-2010), месяц (1-12)): ";
            cin >> inf.code >> inf.prod >> inf.year >> inf.month;
            do {
                if (!(inf.code >= 10 && inf.code <= 99)) {
                    cout << "Код клиента должен быть в диапазоне 10-99! \nВведите код клиента ещё раз: ";
                    cin >> inf.code;
                }
            } while (!(inf.code >= 10 && inf.code <= 99));

            do {
                if (!(inf.prod >= 1 && inf.prod <= 30)) {
                    cout << "Продолжительность должна быть в диапазоне 1-30! \nВведите продолжительность ещё раз: ";
                    cin >> inf.prod;
                }
            } while (!(inf.prod >= 1 && inf.prod <= 30));

            do {
                if (!(inf.year >= 2000 && inf.year <= 2010)) {
                    cout << "Год должен быть в диапазоне 2000-2010! \nВведите год ещё раз: ";
                    cin >> inf.year;
                }
            } while (!(inf.year >= 2000 && inf.year <= 2010));

            do {
                if (!(inf.month >= 1 && inf.month <= 12)) {
                    cout << "Месяц должен быть в диапазоне 1-12! \nВведите месяц ещё раз: ";
                    cin >> inf.month;
                }
            } while (!(inf.month >= 1 && inf.month <= 12));
            if (k == inf.code) {
                client = true;
                int dat = inf.year - 2000;
                if (!data[dat]) {
                    maxProd[dat] = inf.prod;
                    maxMonth[dat] = inf.month;
                    data[dat] = true;
                }
                else if (inf.prod > maxProd[dat]) {
                    maxProd[dat] = inf.prod;
                    maxMonth[dat] = inf.month;
                }
                else if (inf.prod == maxProd[dat] && inf.month < maxMonth[dat]) {
                    maxMonth[dat] = inf.month;
                }
            }
        }
        if (!client) {
            cout << "\nНет данных про этого клиента!\n";
            return;
        }
        int prod[11];
        int years[11];
        int months[11];
        int dataK = 0;
        for (int i = 0; i < 11; i++) {
            if (data[i]) {
                prod[dataK] = maxProd[i];
                years[dataK] = 2000 + i;
                months[dataK] = maxMonth[i];
                dataK++;
            }
        }
        if (dataK == 0) {
            cout << "\nНет данных!\n";
            return;
        }
        for (int i = 0; i < dataK - 1; i++) {
            int bestI = i;
            for (int j = i + 1; j < dataK; j++) {
                if (prod[j] > prod[bestI]) {
                    bestI = j;
                }
                else if (prod[j] == prod[bestI] && years[j] < years[bestI]) {
                    bestI = j;
                }
            }
            if (bestI != i) {
                int t = prod[i];
                prod[i] = prod[bestI];
                prod[bestI] = t;
                t = years[i];
                years[i] = years[bestI];
                years[bestI] = t;
                t = months[i];
                months[i] = months[bestI];
                months[bestI] = t;
            }
        }
        cout << "\nРезультаты для клиента " << k << ":" << endl;
        for (int i = 0; i < dataK; i++) {
            cout << "Продолжительность: " << prod[i] << " " << "Год: " << years[i] << " " << "Месяц: " << months[i] << endl;
        }
    }
    else {
        cout << "\nНет данных!\n";
    }
}

bool ras(const Student& a, const Student& b) {
    if (a.score < b.score) {
        return true;
    }
    else if (a.score > b.score) {
        return false;
    }
    else {
        if (a.surname > b.surname) {
            return true;
        }
        else {
            return false;
        }
    }
}
void BinarySort(std::vector<Student>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        Student key = arr[i]; 
        int low = 0;
        int high = i - 1;
        int insert = i;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ras(key, arr[mid])) {
                high = mid - 1;
                insert = mid;
            }
            else {
                low = mid + 1;
                insert = mid + 1;
            }
        }
        for (int j = i - 1; j >= insert; j--) {
            arr[j + 1] = arr[j];
        }
        arr[insert] = key;
    }
}
void Five15(const std::string& infilename, const std::string& outfilename) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
    ifstream inFile(infilename);
    if (!inFile.is_open()) {
        cout << "Не удалось открыть входной файл!" << endl;
    }
    vector<Student> students;
    Student temp;
    int lineN = 0;
    bool hasErrors = false;
    while (inFile >> temp.surname >> temp.score) {
        lineN++;
        bool onlyNumbers = false;
        for (int i = 0; i < temp.surname.size(); i++) {
            if (temp.surname[i] > '0' && temp.surname[i] < '9') {
                onlyNumbers = true;
                break;
            }
        }
        if (onlyNumbers && !temp.surname.empty()) {
            cout << "Ошибка: фамилия '" << temp.surname
                << "' содержит цифры!" << endl;
            continue;
        }
        if (temp.score < 0 || temp.score > 100) {
            cout << "Ошибка в строке " << lineN
                << ": балл " << temp.score << " у ученика '" << temp.surname
                << "' выходит за допустимые пределы (0-100)!" << endl;
            continue;
        }
        students.push_back(temp);
    }
    inFile.close();
    BinarySort(students);
    ofstream outFile(outfilename);
    if (!outFile.is_open()) {
        cout << "Не удалось создать выходной файл!" << endl;
    }
    for (int i = 0; i < students.size(); i++) {
        const Student& student = students[i];
        outFile << student.surname;
        int spaces = 15 - student.surname.size();
        for (int i = 0; i < spaces; i++) outFile << ' ';
        if (student.score < 100) outFile << ' ';
        if (student.score < 10) outFile << ' ';
        outFile << student.score << endl;
    }
    outFile.close();
    cout << "Данные отсортированы и записаны в файл" << endl;
    cout << "\nРезультат:" << endl;
    for (int i = 0; i < students.size(); i++) {
        const Student& student = students[i];
        cout << student.surname;
        int spaces = 15 - student.surname.size();
        for (int i = 0; i < spaces; i++) cout << ' ';
        if (student.score < 100) cout << ' ';
        if (student.score < 10) cout << ' ';
        cout << student.score << endl;
    }
}