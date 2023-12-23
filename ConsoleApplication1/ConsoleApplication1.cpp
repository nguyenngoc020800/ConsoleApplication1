
#include <iostream>
#include <iomanip>
using namespace std;

bool checkOperatorVariable(char operatorVariable);
void calc(long double number1, long double number2, char operatorVariable);

int main()
{	
	char operatorVariable;
	cout << "This is simple caculator. Operator?(+, -, *, /): ";
	cin >> operatorVariable;
	bool isValidOperator = checkOperatorVariable(operatorVariable);

	if (!isValidOperator) {
		cout << "Wrong operator!";
		return 1;
	}

	long double n1, n2;
	cout << "Input first number: ";
	cin >> setw(20) >> n1;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid number!" << endl;
		return 1;
	}

	cout << "Input second number: ";
	cin >> setw(20) >> n2;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid number!" << endl;
		return 1;
	}
	
	if (n2 == 0 && operatorVariable == '/') {
		cout << "Cannot divide by the number 0!" << endl;
		return 1;
	}

	calc(n1, n2, operatorVariable);
	return 0;
}

bool checkOperatorVariable(char operatorVariable) {
	char operatorsList[] = { '+', '-', '*', '/' };

	for (char operatorItem : operatorsList) {
		if (operatorItem == operatorVariable) return 1;
	}
	return 0;
}

void calc(long double number1, long double number2, char operatorVariable) {
	switch (operatorVariable)
	{
	case '+':
		cout << setprecision(15) << number1 + number2 << endl;
		break;
	case '-':
		cout << setprecision(15) << number1 + number2 << endl;
		break;
	case '*':
		cout << setprecision(15) << number1 * number2 << endl;
		break;
	case '/':
		cout << setprecision(15) << number1 / number2 << endl;
		break;
	}
}