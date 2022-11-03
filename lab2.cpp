#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
    string path = "myFile.txt";
    ofstream in;
    string obj;
    string name;
    int score;
public:
    Student () {
       in.open(path, ofstream::app);

       if (!in.is_open()) {
           cout << "Файла нет" << endl;
           exit(0);
       }

       cout << "Введите имя студента: ";
       cin >> name;

       cout << "Введите название предмета: ";
       cin >> obj;

       cout << "Введите оценку: ";
       cin >> score;

       in << '\n';
       in << name << " || " << obj << " || " << score;
       cout << "Успешная запись!";
    }
    Student(int score) {}
    ~Student () {
        in.close();
    }
};

class File {
    string path = "myFile.txt";
    string str = "";
    ifstream out;
public:
    File() {
       out.open(path);

       if(!out.is_open()) {
           cout << "Файла нет" << endl;
           exit(0);
       }
    }

    void OpenFile() {
        while(getline(out, str)) {
            cout << str << endl;
        }
    }

    void Calc() {
        int count = 0;
        while (getline(out, str)) {
            cout << str << endl;

            for (int i = 0; i < str.length(); i++) {
                if (str[i] == '2') {
                    count++;
                }
            }
        }
        cout << "Всего двоек: " << count << endl;
    }

    ~File() {
        out.close();
    }
};

void Menu() {
    int action;
    File arrFile[2];


    while (true) {
        cout << "Выберите действие: " << endl << "1. Открытие файла" << endl << "2. Добавление нового студента" << endl << "3. Счение файла" << endl << "4. Выход" << endl;
        cin >> action;

        if (action > 4 || action <= 0) {
            cout << "Выберите корректное действие!" << endl;
            continue;
        }

        if (action == 1) {
            arrFile[0].OpenFile();
        } else if (action == 2) {
            Student student;
        } else if (action == 3) {
            arrFile[1].Calc();
        } else if (action == 4) {
            cout << "Вы вышли из программы!" << endl;
            exit(0);
        }
        return;
    }
}

int main() {

    Menu();
}