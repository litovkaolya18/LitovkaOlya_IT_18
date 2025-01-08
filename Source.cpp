#include "Header.h"
using namespace std;


void hex_16(const string& num_str, string& hex_str) {
	int len = num_str.length();
	int carry = 0;   //�������� ������� �����, ���� �� ��������� 16
	hex_str.clear(); //�������� hex_str ����� ��������������
	

	//������� ����� � ����������������� ������� 
	for (int i = 0; i < len; i++){
		carry = carry * 10 + (num_str[i] - '0');
	
		//���� carry ������ ��� ����� 16, ���������� �������
		while (carry >= 16) {
			int ost = carry % 16;
			if (ost < 10) {
				hex_str += (char)(ost + '0');     //���������� ������ (0-9)
			}
			else {
				hex_str += (char)(ost - 10 + 'A');//���������� (�-F)
			}
			carry /= 16;

		}
	}
	
	//���������� ���������� ������� 
	if (carry > 0){
		int ost = carry % 16;
		if (ost<10){
			hex_str += (char)(ost + '0');
		}
		else {
			hex_str += (char)(ost -10 + 'A');
		}
	}
	
	//�������������� ������, ��� ����������� ������� 
	reverse(hex_str.begin(), hex_str.end());
}