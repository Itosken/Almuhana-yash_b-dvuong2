#include<iostream>
#include<stack>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

string infixToPostfix(string exp);
double evaluatePostfix(string exp);
string postfixToPrefix(string exp);

int main()

{
	string str, tempStr;
	ifstream inFile;

	cout << "Infix" << setw(31) << "Prefix" << setw(26) << "Postfix" << setw(23) << "Value\n";

	inFile.open("C:\\Users\\student\\Desktop\\in.txt");
	while (!inFile.eof())
	{
		getline(inFile, str);
		cout << left << setw(30) << str << setw(25) << postfixToPrefix(infixToPostfix(str)) << setw(25) << infixToPostfix(str) << setw(25) << evaluatePostfix(infixToPostfix(str)) << endl;
	}
	inFile.close();
	return 0;
}



string infixToPostfix(string exp)
{
	
	stack<char> s;
	string PostStr="";
	char token;
	int length = exp.length();
	for (int i = 0; i < length; i++)
	{
		token = exp[i];
		if (token >= 'A' && token <= 'Z')
			PostStr = PostStr + token;
		else if (token == '+' || token == '/' || token == '*' || token == '-' || token == '(')
		{
			if (s.empty()) {}
			else if ((s.top() != '(' && (token == '+' || token == '-')) ||
				((s.top() == '*' || s.top() == '/') && (token == '*' || token == '/')))
			{
				PostStr = PostStr + s.top();
				s.pop();
			}
			s.push(token);
		}
		else if (token == ')')
		{
			while (s.top() != '(')
			{
				PostStr = PostStr + s.top();
				s.pop();
			}
			s.pop();
		}
	}

	while (!s.empty())
	{
		PostStr = PostStr + s.top();
		s.pop();
	}

	return PostStr;
}



string postfixToPrefix(string exp)
{
	stack<string> S;
	string x, y, PreStr;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] >= 'A' && exp[i] <= 'Z')
		{
			PreStr = exp[i];
			S.push(PreStr);
		}
		else
		{	x = S.top();
			S.pop();
			y = S.top();
			S.pop();
			S.push(exp[i] + y + x);
		} 
	}
	return S.top();
}



double evaluatePostfix(string PostStr) 
{
	stack<double> s;
	double firstNum, secondNum, val = 0.0;
	for (int i = 0; i < PostStr.length(); i++)
	{
		if ((PostStr[i] >= 'A') && (PostStr[i] <= 'Z'))
		s.push(PostStr[i] - 'A' + 2.0);
	
		else if (PostStr[i] == '+' || PostStr[i] == '-' || PostStr[i] == '*' || PostStr[i] == '/')
		{	
			firstNum = s.top();
			s.pop();
			secondNum = s.top();
			s.pop();
			switch (PostStr[i])
			{
			case'+': val = secondNum + firstNum; break;
			case'-': val = secondNum - firstNum; break;
			case'*': val = secondNum * firstNum; break;
			case'/': val = secondNum / firstNum; break;
			}
			s.push(val);
		}
	}

	val = s.top();
	return val;
}






