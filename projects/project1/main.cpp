#include "number.h"
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
    cout << "start" << endl;

    while(true) {
        cout << "input operator: +, -, *:";
        string str1, str2, op;
        Number data1, data2;
        cin >> op;
        cout << "input number1:";
        cin >> str1;
        cout << "input number2:";
        cin >> str2;
        if(data1.fromString(str1) && data2.fromString(str2)) {
            if(op.length() == 1) {
                switch(op[0]) {
                case '+': {
                    cout << (data1 + data2).standardise().toString() << endl;
                    break;
                }
                case '-': {
                    cout << (data1 - data2).standardise().toString() << endl;
                    break;
                }
                case '*': {
                    cout << (data1 * data2).standardise().toString() << endl;
                    break;
                }
                default: {
                    cout << "invalid operator" << endl;
                    break;
                }
                }
            } else {
                cout << "invalid operator" << endl;
            }
        }
    }
}