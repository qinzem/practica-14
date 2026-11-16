#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> mainStack; // Основной стек для всех элементов
    stack<int> minStack;  // Вспомогательный стек для минимумов

public:
    // 1. Добавление элемента в вершину
    void push(int value) {
        mainStack.push(value);

        // Если стек минимумов пуст или новый элемент меньше/равен текущему минимуму
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    // 2. Извлечение элемента из вершины
    void pop() {
        if (mainStack.empty()) {
            cout << "Стек пуст, нечего удалять!" << endl;
            return;
        }

        // Если удаляемый элемент совпадает с текущим минимумом, удаляем и его
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        mainStack.pop();
    }

    // 3. Проверка на пустоту
    bool empty() {
        return mainStack.empty();
    }

    // Дополнительная функция: поиск минимума за O(1)
    int getMin() {
        if (minStack.empty()) {
            cout << "Стек пуст!" << endl;
            return -1; // Или можно выбросить исключение
        }
        return minStack.top();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    
    MinStack st;

    // Тестирование
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Текущий минимум: " << st.getMin() << endl; // Должно быть 2

    st.pop(); // Удаляем 2
    cout << "После удаления 2, минимум: " << st.getMin() << endl; // Должно быть 3

    st.pop(); // Удаляем 7
    cout << "После удаления 7, минимум: " << st.getMin() << endl; // Должно быть 3

    st.pop(); // Удаляем 3
    cout << "После удаления 3, минимум: " << st.getMin() << endl; // Должно быть 5

    st.pop(); // Удаляем 5

    if (st.empty()) {
        cout << "Стек пуст." << endl;
    }

    return 0;
}
