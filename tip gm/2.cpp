#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <cctype> // Для ispunct и tolower

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    string text;
    getline(cin, text); // Читаем всю строку

    // 1. Заменяем знаки препинания на пробелы
    for (int i = 0; i < text.length(); i++) {
        if (ispunct(text[i])) {
            text[i] = ' ';
        }
    }

    // 2. Приводим все символы к нижнему регистру
    for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }

    // 3. Разбиваем текст на слова и складываем в set
    set<string> uniqueWords;
    string word;
    stringstream ss(text); // Поток для чтения слов из строки

    while (ss >> word) {
        uniqueWords.insert(word); // set сам удалит дубликаты и отсортирует
    }

    // 4. Выводим результат
    for (const string& w : uniqueWords) {
        cout << w << endl;
    }

    return 0;
}
