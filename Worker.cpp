#include <iostream>
#include <string.h>
#include "Worker.h"

using namespace std;

// конструктор по умолчанию
Worker::Worker()
{
    this->name = "None";
    this->post = "None";
    this->year = "None";

    cout << "Вызван конструктор по умолчанию класса Worker" << endl;
}

// конструктор с параметром
Worker::Worker(string name, string post, string year)
{
    this->name = name;
    this->post = post;
    this->year = year;

    cout << "Вызван конструктор с параметром класса Worker" << endl;
}

// конструктор копирования
Worker::Worker(const Worker &w)
{
    this->name = w.name;
    this->post = w.post;
    this->year = w.year;

    cout << "Вызван конструктор копирования класса Worker" << endl;
}

// деструктор
Worker::~Worker()
{
    cout << "Вызван деструктор класса Worker" << endl;
}

// метод извлечения полей
void Worker::Extract()
{
    cout << *this;
}

// метод получения полей
void Worker::Get()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice; // переменная выбора поля
    cout << "\nЧто хотите получить?\n" <<
                "1 - ФИО\n" <<
                "2 - Должность\n" <<
                "3 - Год устройства\n" <<
                "4 - Все поля" << endl;
    cout << "Выбор: ";
    cin >> choice; // ввод

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1") cout << "ФИО: " << this->name << endl;
    else if (choice == "2") cout << "Должность: " << this->post << endl;
    else if (choice == "3") cout << "Год устройства: " << this->year << endl;
    else if (choice == "4") cout << "ФИО: " << this->name << " | Должность: " << this->post << " | Год устройства: " << this->year << endl;
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
}

// метод получения информации о поезде
void Worker::GetInformatio()
{
    cout << "ФИО: " << this->name << " | Должность: " << this->post << " | Год устройства: " << this->year << endl;
}

// метод получения поля времени (для сортировки)
string Worker::GetName()
{
    return this->name;
}

// метод получения пункта назначения
string Worker::GetPost()
{
    return this->post;
}

// метод получения номера поезда
string Worker::GetYear()
{
    return this->year;
}

// метод установки значения
void Worker::Set()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    cin >> *this;
}

void Worker::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nЧто хотите получить?\n" <<
                "1 - ФИО\n" <<
                "2 - Должность\n" <<
                "3 - Год устройства\n" << endl;
    cout << "Выбор: ";
    cin >> choice;

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "ФИО: ";
        getline(cin, this->name);
    }

    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "Должность: ";
        getline(cin, this->post);
    }

    else if (choice == "3")
    {
        getline(cin, choice);

        cout << "Год трудоустройства";
        getline(cin, this->year);
    }

    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
}

// перегрузка оператора вывода
std::ostream &operator<< (std::ostream &stream, Worker &w) // перегрузка оператора извлеченния
{
    stream << "\nВсе поля класса:" << endl;
    stream << w.name << endl;
    stream << w.post << endl;
    stream << w.year << endl;

    return stream;
}

// перегрузка оператора ввода
std::istream &operator>> (std::istream &stream, Worker &w) // перегрузка оператора вставки
{
    string buf;

    cout << "\nВставка значений:" << endl;
    cout << "ФИО: ";
    getline(stream, buf);
    w.name = buf;

    cout << "Должность: ";
    getline(stream, buf);
    w.post = buf;

    cout << "Год трудоустройства: ";
    getline(stream, buf);
    w.year = buf;

    return stream;
}
