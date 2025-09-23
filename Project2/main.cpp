#include <iostream>
#include <limits>
using namespace std;

// Функция для вычисления факториала
long long factorial(int n) {
	if (n < 0) {
		return -1; // Факториал отрицательного числа не определен
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

// Функция для возведения в степень
long long power(int base, int exponent) {
	if (exponent < 0) {
		return -1; // Отрицательная степень не поддерживается
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

	cout << "=== ИНТЕРАКТИВНЫЙ КАЛЬКУЛЯТОР ===" << endl;
	cout << "Доступные операции: + - * / ! ^" << endl;
	cout << "(! - факториал, ^ - возведение в степень)" << endl;
	cout << "=================================" << endl;

	while (true) {
		cout << "\nВыберите операцию (q для выхода): ";
		cin >> operation;

		// Выход из программы
		if (operation == 'q' || operation == 'Q') {
			cout << "Выход из программы. До свидания!" << endl;
			break;
		}

		// Обработка операции факториала (требует одно число)
		if (operation == '!') {
			cout << "Введите число для вычисления факториала: ";
			cin >> num1;

			// Проверка на корректный ввод
			if (cin.fail()) {
				cout << "Ошибка: введите целое число!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			result = factorial(num1);

			if (result == -1) {
				cout << "Ошибка: факториал определен только для неотрицательных целых чисел!" << endl;
			}
			else {
				cout << num1 << "! = " << result << endl;
			}
		}
		// Обработка остальных операций (требуют два числа)
		else if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^') {
			cout << "Введите первое число: ";
			cin >> num1;
			cout << "Введите второе число: ";
			cin >> num2;

			// Проверка на корректный ввод
			if (cin.fail()) {
				cout << "Ошибка: введите целые числа!" << endl;
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
					cout << "Ошибка: деление на ноль невозможно!" << endl;
				}
				else {
					// Для целочисленного деления
					if (num1 % num2 == 0) {
						result = num1 / num2;
						cout << num1 << " / " << num2 << " = " << result << endl;
					}
					else {
						// Если результат не целый, выводим как дробь
						cout << num1 << " / " << num2 << " = " << (double)num1 / num2 << endl;
					}
				}
				break;

			case '^':
				if (num2 < 0) {
					cout << "Ошибка: степень должна быть неотрицательной!" << endl;
				}
				else {
					result = power(num1, num2);
					if (result == -1) {
						cout << "Ошибка: неподдерживаемая операция!" << endl;
					}
					else {
						cout << num1 << " ^ " << num2 << " = " << result << endl;
					}
				}
				break;

			default:
				cout << "Ошибка: неизвестная операция!" << endl;
				break;
			}
		}
		else {
			cout << "Ошибка: неизвестная операция! Доступные операции: + - * / ! ^" << endl;
		}

		// Очистка буфера ввода
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return 0;

}