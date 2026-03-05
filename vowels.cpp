#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int countVowels(const string& str) { // Функция для подсчёта количества гласных букв в строке
    int vowelCount = 0; // Счётчик гласных
    const string vowels = "aeiouyAEIOUY"; // Строка содержащая все гласные английского языка

    for (int i = 0; i < str.length(); i++) {
        char letter = str[i];
        if (vowels.find(letter) != string::npos) { // Проверка принадлежности буквы к гласным
            vowelCount++; // Увеличение счётчика, если символ найден в строке с гласными
        }
    }
    return vowelCount;
}

bool EnglishCheck(const string& str) { // Функция для проверки корректности введённых символов
    for (int i = 0; i < str.length(); i++) {
        char letter = str[i];
        if (letter == ' ' || ispunct(letter) || isdigit(letter)) { // Пропуск пробелов и знаков препинания
            continue;
        }
        if (!(letter >= 'A' && letter <= 'Z') && !(letter >= 'a' && letter <= 'z')) { // Проверка букв на английские
            return false; // Найден неанглийский символ
        }
    }
    return true; // Все буква английские
}
int main() {
    setlocale(LC_ALL, "rus");  // Включение поддержки русского языка

    string input;

    cout << "Введите строку для подсчета гласных: ";
    getline(cin, input);
    if (!EnglishCheck(input)) { // Проверка введённой строки на корректность введённых символов
        cout << "Строка содержит неанглийские символы" << endl;
    }
    else {
        cout << "Исходная строка: " << input << endl;
    cout << "Количество гласных: " << countVowels(input) << endl;
    }
    return 0;
}
