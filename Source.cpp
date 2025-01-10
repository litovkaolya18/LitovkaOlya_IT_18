#include "Header.h"
#include <iostream>
using namespace std;

//функция для деления числа на 16
void num_conversion(string& num_str, int& ostat) {
	string result;      //для хранения частного (целочисленный остаток деления числа на 16)
	int carry = 0;     //для накопления остатка

	// Преобразуем строку в десятичное число
	for (char digit : num_str) { //Проходит по каждому символу (цифре) в строке num_str
		int ct = carry * 10 + (digit - '0'); //преобразовываем в целое число

		if (result.length() > 0 || ct >= 16) {
			result += to_string(ct / 16);
		}
		carry = ct % 16;
	}

	if (result.empty()) {
		result = "0"; // Если результат пуст, значит число было 0
	}

	num_str = result; // Обновляем значение числа
	ostat = carry;
}


//функция для перевода числа из 10 в 16 систему счисления
string hex_16(const string& num_str) {
	if (num_str == "0") {
		return "0"; // Если введено 0
	}
	string hex_result; // Переменная для хранения шестнадцатеричного числа(пустая строка)
	int ostat; //использоваться для хранения остатка при делении на 16

	string temp_number = num_str; // Временная переменная для деления

	while (temp_number != "0") {
		num_conversion(temp_number, ostat); // Делим число на 16
		// Добавляем остаток к результату
		if (ostat < 10) {
			hex_result = static_cast<char>('0' + ostat) + hex_result; // Цифры от 0 до 9
		}
		else {
			hex_result = static_cast<char>('A' + (ostat - 10)) + hex_result; // Цифры от A до F
		}
	}

	return hex_result; // Возвращаем результат

}

//функция для проверки, корректен ли ввод 
bool is_correct(const string& num_str) {
	//проверка на пустую строку
	if (num_str.empty()) return false;

	//если встречаем нецифровой символ, то false 
	for (char ch : num_str) {
		if (!isdigit(ch)) return false;
	}
	return true;
}


