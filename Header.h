#pragma once
#include <string>
using namespace std;

//функция для перевода числа из 10 в 16 систему счисления
string hex_16(const string& num_str);

//функция для деления числа на 16
void num_conversion(const string& num_str, int& ostat);

//функция для проверки, корректен ли ввод 
bool is_correct(const string& num_str);
