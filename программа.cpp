#include <iostream>
#include <cctype>
#include <windows.h>
#include "Header.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string num;     //используем строку для ввода числа
	string hex_str; // строка для хранения результата
	cout << "Здравствуй пользователь! Эта программа переводит многозначное десятичное число в 16 систему счисления.\n";

	cout << "Пожалуйста, введите многозначное число(без пробелов): ";
	cin >> num;

	//проверка на коректность ввода
	while (!is_correct(num)) {
		cout << "Ошибка: некорректный ввод. Попробуйте снова." << endl;
		cout << "Введите многозначное число(без пробелов и лишних знаков): ";
		cin >> num;
	}

	string hex_result = hex_16(num); // Преобразование в шестнадцатеричное

	cout << "Переведённое число в 16 системе счисления: " << hex_result << endl;
	cout << "Количество цифр в исходном числе: " << num.size() << endl;
	cout << "Количество цифр в переведённом числе: " << hex_result.size() << endl;

	return 0;
}

