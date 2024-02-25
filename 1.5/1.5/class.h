#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

class Student { // класс
public:
    string name; // имя
    int age; // возраст
    string major; // Специальность
    bool tuitionPaid; // Основа обучения (коммерция или нет)
    int semester; // на каком семестру обучается 

    Student() {
        name = "Undefined";
        age = -1;
        major = "Undefined";
        tuitionPaid = false;
        semester = 1;
    }

    Student(string input_name, int input_age, string input_major, bool input_tuitionPaid, int input_semester)
        : name(input_name), age(input_age), major(input_major), tuitionPaid(input_tuitionPaid), semester(input_semester) {}

    void display() {
        cout << "Имя: " << name << endl <<" Возраст: " << age << endl << " Специальность: "  << major << endl << " Основа обучения : " << tuitionPaid << endl << " Семестр: " << semester << endl;
    }

    void payTuition() {
        tuitionPaid = true;
    }

    void advanceSemester() {
        semester++;
    }

    void changeMajor(string newMajor) {
        major = newMajor;
    }
};


void loadFromFile(Student arr[], int size) {
    ifstream file("students.txt");
    for (int i = 0; i < size; i++) {
        string name, major;
        int age, semester;
        bool tuitionPaid;
        file >> arr[i].name >> arr[i].age >> arr[i].major >> arr[i].tuitionPaid >> arr[i].semester;
    }
    file.close();
}

void loadKeyboard(Student arr[], int size) {
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
        cout << "Обучается на коммерции?  (1 - да, 0 нет): ";
        cin >> tuitionPaid;
        cout << "Семестр: ";
        cin >> semester;
        cout << "--------- " << endl;
        arr[i] = Student(name, age, major, tuitionPaid, semester);
    }
}

void printArray(Student arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i].display();
    }
}

void removeElement(Student arr[], int& size, int index) {
 
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

void saveToFile(Student arr[], int size) {
    ofstream file("file_students.txt");
    for (int i = 0; i < size; i++) {
        file << arr[i].name << " " << arr[i].age << " " << arr[i].major << " " << arr[i].tuitionPaid << " " << arr[i].semester << endl;
    }
    file.close();
}

