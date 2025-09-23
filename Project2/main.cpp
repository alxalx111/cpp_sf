#include <iostream>
#include <limits>
using namespace std;

// ������� ��� ���������� ����������
long long factorial(int n) {
	if (n < 0) {
		return -1; // ��������� �������������� ����� �� ���������
	}
	if (n == 0 || n == 1) {
		return 1;
	}

	long long result = 1;
	for (int i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}

// ������� ��� ���������� � �������
long long power(int base, int exponent) {
	if (exponent < 0) {
		return -1; // ������������� ������� �� ��������������
	}
	if (exponent == 0) {
		return 1;
	}

	long long result = 1;
	for (int i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}


int main()
{
	setlocale(LC_ALL, "");

	char operation;
	int num1, num2;
	long long result;

	cout << "=== ������������� ����������� ===" << endl;
	cout << "��������� ��������: + - * / ! ^" << endl;
	cout << "(! - ���������, ^ - ���������� � �������)" << endl;
	cout << "=================================" << endl;

	while (true) {
		cout << "\n�������� �������� (q ��� ������): ";
		cin >> operation;

		// ����� �� ���������
		if (operation == 'q' || operation == 'Q') {
			cout << "����� �� ���������. �� ��������!" << endl;
			break;
		}

		// ��������� �������� ���������� (������� ���� �����)
		if (operation == '!') {
			cout << "������� ����� ��� ���������� ����������: ";
			cin >> num1;

			// �������� �� ���������� ����
			if (cin.fail()) {
				cout << "������: ������� ����� �����!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			result = factorial(num1);

			if (result == -1) {
				cout << "������: ��������� ��������� ������ ��� ��������������� ����� �����!" << endl;
			}
			else {
				cout << num1 << "! = " << result << endl;
			}
		}
		// ��������� ��������� �������� (������� ��� �����)
		else if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^') {
			cout << "������� ������ �����: ";
			cin >> num1;
			cout << "������� ������ �����: ";
			cin >> num2;

			// �������� �� ���������� ����
			if (cin.fail()) {
				cout << "������: ������� ����� �����!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			switch (operation) {
			case '+':
				result = num1 + num2;
				cout << num1 << " + " << num2 << " = " << result << endl;
				break;

			case '-':
				result = num1 - num2;
				cout << num1 << " - " << num2 << " = " << result << endl;
				break;

			case '*':
				result = num1 * num2;
				cout << num1 << " * " << num2 << " = " << result << endl;
				break;

			case '/':
				if (num2 == 0) {
					cout << "������: ������� �� ���� ����������!" << endl;
				}
				else {
					// ��� �������������� �������
					if (num1 % num2 == 0) {
						result = num1 / num2;
						cout << num1 << " / " << num2 << " = " << result << endl;
					}
					else {
						// ���� ��������� �� �����, ������� ��� �����
						cout << num1 << " / " << num2 << " = " << (double)num1 / num2 << endl;
					}
				}
				break;

			case '^':
				if (num2 < 0) {
					cout << "������: ������� ������ ���� ���������������!" << endl;
				}
				else {
					result = power(num1, num2);
					if (result == -1) {
						cout << "������: ���������������� ��������!" << endl;
					}
					else {
						cout << num1 << " ^ " << num2 << " = " << result << endl;
					}
				}
				break;

			default:
				cout << "������: ����������� ��������!" << endl;
				break;
			}
		}
		else {
			cout << "������: ����������� ��������! ��������� ��������: + - * / ! ^" << endl;
		}

		// ������� ������ �����
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return 0;

}