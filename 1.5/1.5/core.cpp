#include "class.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;
    cout << "Введите количество элементов класса: ";
    cin >> size;

    int choice_1, choice_2, choice_3;
    cout << "Введите 1 для массива объектов, 2 для массива указателей: ";
    cin >> choice_1;

    if (choice_1 == 1) {
        Student* StudArr = new Student[size];

        cout << "Как заполнить массив объектов? 1 - из файла 2 - ручной ввод: ";
        cin >> choice_2;

        if (choice_2 == 1) {
            loadFromFile(StudArr, size);
        }

        else {
            loadKeyboard(StudArr, size);
        }

        cout << "Массив объектов:" << endl;
        printArray(StudArr, size);

        cout << "Добавить или удалить элемент массива? 1 - удалить 2 - добавить: ";
        cin >> choice_3;

        if (choice_3 == 1) {
            int index;
            cout << "Введите индекс удаляемого элемента: " << endl;
            cout << "Всего индексов - " << size << endl;
            cin >> index;
            removeElement(StudArr, size, index);
            cout << "Массив объектов после удаления: " << endl;
            printArray(StudArr, size);
            saveToFile(StudArr, size);
        }

        else {
            Student NewElementStudArrRedux = { "Михаил" , 21 , "Строитель", 0, 4 };
            int NewSize = size + 1;
            Student* StudArrRedux = new Student [NewSize];
            for (int i = 0; i < size; i++) {
                StudArrRedux[i] = StudArr[i];
            }

            StudArrRedux[size] = NewElementStudArrRedux;

            cout << "Массив объектов после добавления: " << endl;
            printArray(StudArrRedux, NewSize);
            saveToFile(StudArrRedux, NewSize);
        }
    }




    if (choice_1 == 2) {
        Student* StudArr = new Student[size];
        cout << "Как заполнить массив указателей? 1 - из файла 2 - ручной ввод: ";
        cin >> choice_2;

        if (choice_2 == 1) {
            loadFromFile(StudArr, size);
        }

        else {
            loadKeyboard(StudArr, size);
        }

        Student** StudArrPtr = new Student * [size];
        for (int i = 0; i < size; i++) {
            StudArrPtr[i] = &StudArr[i];
        }

        cout << "Массив объектов:" << endl;
        printArray (*StudArrPtr, size);

        cout << "Добавить или удалить элемент массива? 1 - удалить 2 - добавить: ";
        cin >> choice_3;

        if (choice_3 == 1) {
            int index;
            cout << "Введите индекс удаляемого элемента: " << endl;
            cout << "Всего индексов - " << size << endl;
            cin >> index;
            removeElement(*StudArrPtr, size, index);

            cout << "Массив объектов после удаления: " << endl;
            printArray(*StudArrPtr, size);
            saveToFile(*StudArrPtr, size);
        }

        else {
            Student NewElementStudArrRedux = {"Михаил", 21, "Строитель", 1, 4};
            int NewSize = size + 1;

            Student* StudArrRedux = new Student  [NewSize];
            for (int i = 0; i < size; i++) {
                StudArrRedux[i] = StudArr[i];
            }

            StudArrRedux[size] = NewElementStudArrRedux;

            cout << "Массив объектов после добавления: " << endl;
            printArray(StudArrRedux, NewSize);
            saveToFile(StudArrRedux, NewSize);

        }
    }
    return 0;
}

    