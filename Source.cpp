#include "Header.h"
using namespace std;

// преобразования десятичного числа, в его шестнадцатеричное 
void hex_16(const string& num_str, string& hex_str) {
	int len = num_str.length();
	int carry = 0;   //õðàíåíèå òåêóùåé ñóììû, ïîêà íå äîñòèãíåò 16
	hex_str.clear(); //î÷èùåíèå hex_str ïåðåä èñïîëüçîâàíèåì
	

	//первод числа в 16 систему счисления
	for (int i = 0; i < len; i++){
		carry = carry * 10 + (num_str[i] - '0');
	
		//ïîêà carry áîëüøå èëè ðàâåí 16, ïðîäîëæàåì äåëåíèå
		while (carry >= 16) {
			int ost = carry % 16;
			if (ost < 10) {
				hex_str += (char)(ost + '0');     //çàïèñûâàåì ðàçðÿä (0-9)
			}
			else {
				hex_str += (char)(ost - 10 + 'A');//çàïèñûâàåì (À-F)
			}
			carry /= 16;

		}
	}
	
	//çàïèñûâàåì îñòàâùèéñÿ ïåðåíîñ 
	if (carry > 0){
		int ost = carry % 16;
		if (ost<10){
			hex_str += (char)(ost + '0');
		}
		else {
			hex_str += (char)(ost -10 + 'A');
		}
	}
	
	//ïåðåâîðà÷èâàåì ñòðîêó, äëÿ ïðàâèëüíîãî ïîðÿäêà 
	reverse(hex_str.begin(), hex_str.end());
}
