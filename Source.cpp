#include "Header.h"
using namespace std;

// преобразования десятичного числа, в его шестнадцатеричное 
void hex_16(const string& num_str, string& hex_str) {
	int len = num_str.length();  //преобразует число в строку 
	int carry = 0;               //хранение текущей суммы, пока не достигнет 16
	hex_str.clear();             //очищение hex_str перед использованием
	

	//перевод числа в 16 систему счисления
	for (int i = 0; i < len; i++){
		carry = carry * 10 + (num_str[i] - '0'); //накапливаем значение в переменной
	
		//пока carry больше или равен 16, продолжаем деление
		while (carry >= 16) {
			int ost = carry % 16;                     //находим остаток от деления
			if (ost < 10) {
				hex_str += (char)(ost + '0');     //записываем разряд (0-9)
			}
			else {
				hex_str += (char)(ost - 10 + 'A');//записываем (А-F)
			}
			carry /= 16;

		}
	}
	
	//записываем оставщиеся значения
	if (carry > 0){
		int ost = carry % 16;
		if (ost<10){
			hex_str += (char)(ost + '0');
		}
		else {
			hex_str += (char)(ost -10 + 'A');
		}
	}
	
	//переворачиваем строку, для правильного порядка 
	reverse(hex_str.begin(), hex_str.end());
}
