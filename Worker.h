#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string.h>
using namespace std;

class Worker
{
private:
    string name; // ФИО
    string post; // должность
    string year; // год поступления на работу

public:
    Worker(); // конструктор по умолчанию
    Worker(string name, string post, string year); // конструктор с параметром
    Worker(const Worker &w); // конструктор копирования
    ~Worker(); // деструктор

    void Extract(); // метод извлечения значения
    void Get(); // метод получения полей
    void GetInformatio(); // метод получения информации о конкретном человеке
    string GetName(); // метод получения поля имени для упорядочивания
    string GetPost(); // метод получения должности
    string GetYear(); // метод получения года поступления на работу
    void Set(); // метод установки значения
    void Change(); // метод редактирования значений

    friend ostream &operator<< (ostream &stream, Worker &w); // перегрузка оператора извлеченния
    friend istream &operator>> (istream &stream, Worker &w); // перегрузка оператора вставки
};

#endif
