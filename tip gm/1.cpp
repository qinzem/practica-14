#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    string s;
    getline(cin, s); // Считываем строку целиком

    stack<char> st;       // Стек для открывающих скобок
    bool isCorrect = true; // Флаг: true = всё хорошо, false = ошибка

    // Проходим по строке по одному символу
    for (int i = 0; i < s.length(); i++) {
        char c = s[i]; // Текущий символ

        if (c == '(') {
            // Если открывающая — кладем в стек
            st.push(c);
        } 
        else if (c == ')') {
            // Если закрывающая — проверяем, есть ли что закрывать
            if (st.empty()) {
                // Стек пуст, значит скобка лишняя
                isCorrect = false;
                break; // Дальше проверять нет смысла
            } else {
                // В стеке есть открывающая — удаляем её
                st.pop();
            }
        }
    }

    // После цикла проверяем, не осталось ли незакрытых скобок
    if (!st.empty()) {
        isCorrect = false;
    }

    // Выводим результат
    if (isCorrect == true) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
