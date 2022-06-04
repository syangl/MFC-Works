#include <iostream>
#include <string>
#include <stack>

using namespace std;

string result = "";
string pre;

stack<double> nu;
stack<string> op;

double toDouble(string num)
{
	bool minus = false;      //标记是否是负数
    string real = num;       //real表示num的绝对值
    if (num.at(0) == '-')
    {
        minus = true;
        real = num.substr(1, num.size()-1);
    }

    char c;
    int i = 0;
    double result = 0.0 , dec = 10.0;
    bool isDec = false;       //标记是否有小数
    unsigned long size = real.size();
    while(i < size)
    {
        c = real.at(i);
        if (c == '.')
        {//包含小数
            isDec = true;
            i++;
            continue;
        }
        if (!isDec)
        {
            result = result*10 + c - '0';
        }
        else
        {//识别小数点之后都进入这个分支
            result = result + (c - '0')/dec;
            dec *= 10;
        }
        i++;
    }

    if (minus == true) {
        result = -result;
    }

    return result;
}

string toString(double& number)
{
	return to_string((long double)number);
}

//使用操作数栈nu和运算符栈op实现中序表达式计算
void caculate(string& btn,string& str)
{// 根据不同按钮执行不同运算逻辑
	if (btn == "1" || btn == "2" || btn == "3"
		|| btn == "4" || btn == "5" || btn == "6"
		|| btn == "7" || btn == "8" || btn == "9"
		|| btn == "0" || btn == "." || btn == "+" || btn == "-"
		|| btn == "*" || btn == "/" || btn == "(" || btn == ")" || btn == "=") {
		if (btn == "1" || btn == "2" || btn == "3"
			|| btn == "4" || btn == "5" || btn == "6"
			|| btn == "7" || btn == "8" || btn == "9" 
			|| btn == "0" || btn == ".") {
			result += btn;
			str += btn;
			pre = btn;
		}
		else if (btn == "+" || btn == "-" || btn == "*" || btn == "/" || btn == "(" || btn == ")" || btn == "=") {
			if (btn != "=") {
				str += btn;
			}

			if (pre == "1" || pre == "2" || pre == "3"
				|| pre == "4" || pre == "5" || pre == "6"
				|| pre == "7" || pre == "8" || pre == "9"
				|| pre == "0" || pre == ".") {
				double num = toDouble(result);
				nu.push(num);
				result = "";
			}
			pre = btn;

			if ((btn == "(" || op.empty()) && btn != "=") {
				op.push(btn);
			}
			else if (btn == ")" && !op.empty()) {
				while (true) {

					string tmp;
					tmp = (string)op.top();
					op.pop();
					if (tmp == "(") {
						break;
					}
					double a = 0.0, b =0.0;
					if (!nu.empty()){
						a = (double)nu.top();
						nu.pop();
					}
					if (!nu.empty()){
						b = (double)nu.top();
						nu.pop();
					}
					if (tmp == "+") {
						double m = a + b;
						nu.push(m);
					}
					else if (tmp == "-") {
						double m = b - a;
						nu.push(m);
					}
					else if (tmp == "*") {
						double m = a * b;
						nu.push(m);
					}
					else if (tmp == "/") {
						double m = b / a;
						nu.push(m);
					}

				}

			}
			else if ((btn == "+" || btn == "-" || btn == "*" || btn == "/") && !op.empty()) {
				string tmp;
				tmp = (string)op.top();
				if (btn == "*" || btn == "/") {
					if (tmp == "+" || tmp == "-" || tmp == "(") {
						op.push(btn);
					}
					else {
						tmp = (string)op.top();
						op.pop();
						double a = 0.0, b =0.0;
						if (!nu.empty()){
							a = (double)nu.top();
							nu.pop();
						}
						if (!nu.empty()){
							b = (double)nu.top();
							nu.pop();
						}
						if (tmp == "*") {
							double m = a * b;
							nu.push(m);
						}
						else {
							double m = b / a;
							nu.push(m);
						}
						op.push(btn);
					}
				}
				else {
					if (tmp == "(") {
						op.push(btn);
					}
					else {
						tmp = (string)op.top();
						op.pop();
						double a = 0.0, b =0.0;
						if (!nu.empty()){
							a = (double)nu.top();
							nu.pop();
						}
						if (!nu.empty()){
							b = (double)nu.top();
							nu.pop();
						}
						if (tmp == "+") {
							double m = a + b;
							nu.push(m);
						}
						else if (tmp == "-") {
							double m = b - a;
							nu.push(m);
						}
						else if (tmp == "*") {
							double m = a * b;
							nu.push(m);
						}
						else if (tmp == "/") {
							double m = b / a;
							nu.push(m);
						}
						op.push(btn);
					}
				}

			}//等于出结果
			else if (btn == "=") {
				while (!op.empty()) {
					string tmp;
					tmp = (string)op.top();
					op.pop();
					double a=0.0, b=0.0;
					if (!nu.empty()){
						a = (double)nu.top();
						nu.pop();
					}
					if (!nu.empty()){
						b = (double)nu.top();
						nu.pop();
					}
					if (tmp == "+") {
						double m = a + b;
						nu.push(m);
					}
					else if (tmp == "-") {
						double m = b - a;
						nu.push(m);
					}
					else if (tmp == "*") {
						double m = a * b;
						nu.push(m);
					}
					else if (tmp == "/") {
						double m = b / a;
						nu.push(m);
					}
				}
				if(!nu.empty())
				{
					double number = (double)nu.top();
					nu.pop();
					str = toString(number);
					result = "";
				}else{
					str = "0";
					result = "";
				}
			}

		}

	}//清零
	else if (btn == "C") {
		str = "";
		result = "";
		pre = "start";
		while (!nu.empty()) {
			nu.pop();
		}
		while (!op.empty()) {
			op.pop();
		}

	}//删除delete
	else if (btn == "del") {
		if (op.empty() || (string)op.top() == "(") {
			string tmp;
			tmp = result;
			result = "";
			int count = tmp.length() - 1;
			for (int i = 0; i < count; i++) {
				result += tmp[i];
			}
			str = result;
		}
	}
}