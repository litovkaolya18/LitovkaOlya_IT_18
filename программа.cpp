#include <iostream> 
#include <cctype> 
#include <windows.h> 
#include "Header.h" 
using namespace std;

//проверка, является ли строка числом 
bool is_correct(const string& str) {
	for (char ch : str) {
		if (!isdigit(ch)) {
			return false; //если встречаем нецифровой символ, то false 
		}
	}
	return !str.empty(); //возвращаем true, если строка не пуста 
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string num;     //используем строку для ввода числа 
	string hex_str; // строка для хранения результата 
	cout << "Здравствуй пользователь. Эта программа переводит многозначное число в 16 систему счисления.\n";

	while (true) {

		cout << "Пожалуйста, введите многозначное число: ";
		cin >> num;

		//проверка на коректность ввода 
		if (is_correct(num)) {
			hex_16(num, hex_str); //Преобразует число в 16 сс 
			cout << "Переведённое число в 16 системе счисления: " << hex_str << endl;
			cout << "Количество цифр в исходном числе: " << num.size() << endl;
			cout << "Количество цифр в переведённом числе: " << hex_str.size() << endl;
			break; //выходим из цикла после успешного завершения 
		}
		else {
			cout << "Ошибка: некорректный ввод. Попробуйте снова." << endl;
		}
	}
	return 0;
}
