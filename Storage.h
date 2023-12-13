#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include "Worker.h"

using namespace std;

class Store
{
private:
    Worker **array; // массив для хранения значений
    int countElement; // кол-ва элементов

public:
    Store(); // конструктор по умолчанию
    Store(int size); // конструктор с параметром
    Store(const Store &s); // конструктор копирования
    ~Store(); // деструктор

    void SortedArray(); // сортировка после ввода
    void FindYear(); // поиск по номеру поезда
    void ExtractField(); // извлечь значения объекта
    void GetFiel(); // получить поля
    void Set(); // вставить значение объекта
    void Change(); // изменить значение
    void Delete(); // удалить значние
};

#endif
