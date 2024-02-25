#include <iostream>  
#include <fstream>  // Ввод-вывод из/в файл
#include <string>  
#include <windows.h>  // Для работы с функциями Windows API

using namespace std;  

class Student {  // Определение класса
public:
    string name;  // Имя студента
    int age;  // Возраст студента
    string major;  // Специальность студента
    bool tuitionPaid;  // Оплата обучения (коммерция или нет)
    int semester;  // Текущий семестр обучения

    Student() {  // Конструктор класса по умолчанию
        name = "Undefined";
        age = -1;
        major = "Undefined";
        tuitionPaid = false;
        semester = 1;
    }

    // Параметризированный конструктор класса
    Student(string input_name, int input_age, string input_major, bool input_tuitionPaid, int input_semester)
        : name(input_name), age(input_age), major(input_major), tuitionPaid(input_tuitionPaid), semester(input_semester) {}

    void display() {  // Вывод данных о студенте
        cout << "Имя: " << name << endl << " Возраст: " << age << endl << " Специальность: " << major << endl << " Оплата обучения: " << tuitionPaid << endl << " Семестр: " << semester << endl;
    }

    void payTuition() {  // Метод оплаты обучения
        tuitionPaid = true;
    }

    void advanceSemester() {  // Метод перехода на следующий семестр
        semester++;
    }

    void changeMajor(string newMajor) {  // Метод смены специальности
        major = newMajor;
    }
};

void loadFromFile(Student arr[], int size) {  // Загрузка данных из файла в массив
    ifstream file("students.txt");
    for (int i = 0; i < size; i++) {
        string name, major;
        int age, semester;
        bool tuitionPaid;
        file >> arr[i].name >> arr[i].age >> arr[i].major >> arr[i].tuitionPaid >> arr[i].semester;
    }
    file.close();
}

void loadKeyboard(Student arr[], int size) {  // Ввод данных в массив через клавиатуру
    for (int i = 0; i < size; i++) {
        string name, major;
        int age, semester;
        bool tuitionPaid;
        cout << "Имя: ";
        cin >> name;
        cout << "Возраст: ";
        cin >> age;
        cout << "Специальность: ";
        cin >> major;
        cout << "Оплачивает обучение? (1 для да, 0 для нет): ";
        cin >> tuitionPaid;
        cout << "Семестр: ";
        cin >> semester;
        cout << "--------- " << endl;
        arr[i] = Student(name, age, major, tuitionPaid, semester);
    }
}

void printArray(Student arr[], int size) {  // Вывод массива студентов
    for (int i = 0; i < size; i++) {
        arr[i].display();
    }
}

void removeElement(Student arr[], int& size, int index) {  // Удаление элемента из массива
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void saveToFile(Student arr[], int size) {  // Сохранение данных массива студентов в файл
    ofstream file("file_students.txt");
    for (int i = 0; i < size; i++) {
        file << arr[i].name << " " << arr[i].age << " " << arr[i].major << " " << arr[i].tuitionPaid << " " << arr[i].semester << endl;
    }
    file.close();
}