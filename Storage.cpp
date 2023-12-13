#include <iostream>
#include <string>
#include <algorithm>
#include "Storage.h"
#include "Worker.h"

using namespace std;

// конструктор по умолчанию
Store::Store()
{
    this->array = new Worker*[1]; // выделяем память
    this->countElement = 0; // кол-во элементов = 0
    cout << "Вызван конструктор по умолчанию класса Store" << endl;
}

// конструктор с параметром
Store::Store(int size)
{
    this->array = new Worker*[size]; // выделяем память под размер
    this->countElement = 0; // кол-во элементов = 0
    cout << "Вызван конструктор c параметром класса Store" << endl;
}

// конструктор копирования
Store::Store(const Store &s)
{
    this->countElement = s.countElement; // копируем кол-во элементов
    this->array = new Worker*[this->countElement]; // выделяем необходимое кол-во памяти

    for (int id = 0; id < this->countElement; id++) this->array[id] = s.array[id]; // копируем каждое значение

    cout << "Вызван конструктор копирования класса Store" << endl;
}

// деструктор
Store::~Store()
{
    delete array; // освобождаем выделенную память
    cout << "Вызван деструктор класса Store" << endl;
}

// сортировка массива
void Store::SortedArray()
{
    // метод сортировки - Пузырьком
    for (int id1 = 0; id1 < countElement; id1++) // кол-во итераций = кол-ву элементов
    {
        for (int id2 = 0; id2 < countElement - 1; id2++) // перебираем элементы не доходя до последнего
        {
            if (array[id2]->GetName() > array[id2+1]->GetName()) // если текущий больше последуещего, то меняем их местами
            {
                Worker *buf = array[id2];
                array[id2] = array[id2+1];
                array[id2+1] = buf;
            }
        }
    }
}

// поиск по номеру поезда
void Store::FindYear()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    string findYear; // переменная, которая хранит значения стажа
    cout << "\nЧтобы узнать информацию о людях, введите стаж: ";
    getline(cin, findYear); // ввод

    int flagFind = 0; // флаг, есть ли найденные люди по стажу

    cout << "\n~Информация о людях~" << endl;

    for (int id = 0; id < countElement; id++) // перебираем все элементы
    {

        if (stoi(findYear) < 2023 - stoi(array[id]->GetYear())) // если превышения стажа есть
        {
            flagFind = 1; // меняем флаг, так как нашли человека
            cout << array[id]->GetName() << endl; // выводим человека
        }
    }

    if (!flagFind) cout << "\nТаких людей нет!" << endl; // если людей нет
}

// извлечение всех значений
void Store::ExtractField()
{
    for (int id = 0; id < countElement; id++) array[id]->Extract(); // выводим все значения
}

// получение полей
void Store::GetFiel()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice; // переменная выбора элемента
    cout << "\nВведите номер элемента, поля которого вы хотите вывести: ";
    cin >> choice; // ввод

    // проверка на правильность ввода (работа с исключительной ситуацией)
    try
    {
        // если в строке есть буквы, выкидываем ошибку
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // если в строке есть буквы, выкидываем ошибку
        if (!all_of(choice.begin(), choice.end(), ::isdigit)) throw "Error";
    }
    catch(const char*mssg) // обработка ошибки
    {
        cout << "Неверный ввод!" << endl;
        exit(0);
    }

    // если выбор элемента превышает значения кол-ва элементов или меньше 0, то ошибка
    if (choice > to_string(countElement) or choice < "0")
    {
        cout << "Ошибка ввода" << endl;
        exit(0);
    }

    // иначе
    else
    {
        int idChoice = stoi(choice);
        array[idChoice]->Get(); // выводим поля
    }
}

// метод установки значения
void Store::Set()
{
    Worker *work = new Worker(); // создаем указатель на объект
    work->Set(); // вызываем метод ввода значеий
    array[countElement++] = work; // вставляем в массив
    this->SortedArray(); // сортируем массив по времени отправления
}

// метод изменения значения
void Store::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    cout << "\nВыберете номер элемента, данные которого хотите изменить: ";
    string choice; // переменная выбора элемента, значения которого мы хотим изменить
    cin >> choice; // ввод

    // обработка исключительной ситуации (проверка на ввод)
    try
    {
        // проверяем нет ли букв
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // если не лежит в диапазоне
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch(const char*mssg) // обработка ошибок
    {
        cout << "Ошибка ввода!" << endl;
        exit(0);
    }

    // вызываем метод изменения знаения
    array[stoi(choice)]->Change();
}

// метод удаления
void Store::Delete()
{
    // очищаем поток ввода
    string buf;
    getline(cin, buf);

    cout << "\nВыберете номер элемента, данные которого хотите удалить: ";
    string choice; // переменная ввода номера элемента
    cin >> choice; // ввод

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch(const char*mssg)
    {
        cout << "Ошибка ввода!" << endl;
        exit(0);
    }

    // удаление значений
    for (int id = stoi(choice); id < countElement - 1; id++) array[id] = array[id+1];
    countElement--;
}
