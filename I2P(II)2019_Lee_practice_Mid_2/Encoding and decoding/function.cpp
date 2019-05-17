#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "function.h"

void RleCodec::encode()
{
    std::stringstream os;
    int cnt = 0;
    char pre = code_str[0];
    char output;

    for (auto c : code_str) {
        if (cnt == 26) {
            os << 'Q' << 'Z' << pre;
            cnt = 1;
            pre = c;
        }
        else if (c == pre) {
            cnt ++;
        }
        else {
            output = 'A' - 1 + cnt;
            os << 'Q' << output << pre;
            pre = c;
            cnt = 1;
        }
    }
    output = 'A' - 1 + cnt;
    os << 'Q' << output << pre;
    code_str = os.str();
    encoded = true;
}

void RleCodec::decode()
{
	std::stringstream os;
	std::string int_str;
	char q = 'A';
	char number = ' ';
	int cnt = 0;
	for (auto c : code_str) {
        if (q=='A') {
            q = c;
		}else if(number == ' '){
            number = c;
		}
        else {
            int_str.push_back(c);
			int cnt = 0;
            cnt = number - 'A' +1;
            for (int i=0; i<cnt; ++i)
					os << c;
			int_str.clear();
			number = ' ';
			q = 'A';
		}
	}

	code_str = os.str();
	encoded = false;
}
