#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

// Функция для проверки, является ли символ буквой
bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Функция для проверки, является ли символ строчной буквой
bool isLower(char c) {
    return (c >= 'a' && c <= 'z');
}

// Функция для шифрования текста
void encrypt(char arr[], int length, int shift) {
    for (int i = 0; i < length && arr[i] != '\0'; i++) {
        if (isAlpha(arr[i])) {
            char base = isLower(arr[i]) ? 'a' : 'A';
            arr[i] = base + (arr[i] - base + shift) % 26;
        }
    }
}

// Функция для дешифрования текста
void decrypt(char arr[], int length, int shift) {
    for (int i = 0; i < length && arr[i] != '\0'; i++) {
        if (isAlpha(arr[i])) {
            char base = isLower(arr[i]) ? 'a' : 'A';
            arr[i] = base + (arr[i] - base - shift + 26) % 26;
        }
    }
}

// Функция для проверки строки на наличие только алфавитных символов
bool isValidString(const char arr[]) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (!isAlpha(arr[i])) {
            return false; // Найден неалфавитный символ
        }
    }
    return true; // Все символы - буквы
}

// Функция для безопасного ввода строки с проверкой на алфавитные символы
bool readString(char arr[], int maxLength) {
    while (true) {
        int i = 0;
        char c;

        cout << "Введите строку (только английские буквы) или 'q' для выхода: ";

        // Читаем посимвольно пока не достигнем максимальной длины или символа новой строки
        while (i < maxLength - 1) {
            c = cin.get();
            if (c == '\n') {
                break; // Завершаем ввод при нажатии Enter
            }
            arr[i] = c;
            i++;
        }
        arr[i] = '\0'; // Добавляем нуль-терминатор в конец строки

        // Очищаем буфер от лишних символов, если пользователь ввел больше maxLength
        if (i == maxLength - 1) {
            while (cin.get() != '\n') {
                // Просто читаем и игнорируем остальные символы
            }
        }

        // Проверяем, не ввел ли пользователь 'q' для выхода
        if (arr[0] == 'q' && arr[1] == '\0') {
            return false; // Пользователь хочет выйти
        }

        // Проверяем, что строка содержит только алфавитные символы
        if (isValidString(arr)) {
            return true; // Строка корректна
        }
        else {
            cout << "Ошибка! Строка должна содержать только английские буквы (a-z, A-Z)." << endl;
            cout << "Пожалуйста, введите строку заново." << endl;
        }
    }
}

// Функция для проверки ввода операции
char readOperation() {
    char operation;
    while (true) {
        cout << "Выберите операцию (e - шифрование, d - дешифрование): ";
        cin >> operation;

        // Очищаем буфер на случай, если ввели больше одного символа
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (operation == 'e' || operation == 'E' || operation == 'd' || operation == 'D') {
            return operation;
        }
        else {
            cout << "Ошибка! Введите только 'e' для шифрования или 'd' для дешифрования." << endl;
        }
    }
}

// Общая функция для ввода целых чисел с проверкой
int readPositiveInt(const char* prompt, const char* errorMessage) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Ошибка! Введите целое число." << endl;
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
        }
        else if (value <= 0) {
            cout << errorMessage << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
            return value;
        }
    }
}

int main() {
    // setlocale(LC_ALL, "");
    // Установка UTF-8 кодировки для консоли
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Главный цикл программы
    while (true) {
        // Ввод данных с проверками 
        char operation = readOperation();
        int length = readPositiveInt("Введите длину строки: ", "Ошибка! Длина должна быть больше 0.");

        // Создаем массив символов
        char* arr = new char[length + 1]; // +1 для нуль-терминатора

        // Ввод строки с возможностью выхода
        if (!readString(arr, length + 1)) {
            cout << "Выход из программы." << endl;
            delete[] arr; // Освобождаем память перед выходом
            break;
        }

        int shift = readPositiveInt("Введите сдвиг: ", "Ошибка! Сдвиг должен быть больше 0.");

        // Вывод исходной строки
        cout << "Исходная строка: " << arr << endl;

        // Выполняем выбранную операцию
        if (operation == 'e' || operation == 'E') {
            encrypt(arr, length, shift);
            cout << "Зашифрованная строка: " << arr << endl;
        }
        else if (operation == 'd' || operation == 'D') {
            decrypt(arr, length, shift);
            cout << "Дешифрованная строка: " << arr << endl;
        }

        // Освобождаем память перед следующей итерацией
        delete[] arr;

        cout << endl;
        cout << "Хотите продолжить? Введите 'q' для выхода или любую другую букву для продолжения: ";

        // Проверяем, хочет ли пользователь продолжить
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'q' || choice == 'Q') {
            cout << "Выход из программы." << endl;
            break;
        }

        cout << "Продолжаем работу..." << endl << endl;
    }

    return 0;
}