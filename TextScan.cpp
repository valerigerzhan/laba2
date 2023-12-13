#include <iostream>
#include <fstream>
#include <string>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // создаем поток ввода
    file.open("Text.txt"); // открытие файла

    if (!file.is_open()) // если файл не открылся
    {
        cout << "Ошибка открытия файла!" << endl;
        exit(0);
    }

    else
    {
        string line; // строка, в которую будут считываться значения из файла

        while (!file.eof()) // пока не конец файла
        {
            string bufLine;
            getline(file, bufLine); // считываем строку
            line += bufLine + '\n';
        }

        string Suggestion; // хранение предложения
        bool FlagFind = false;

        for (int id = 0; id < line.size()+1; id++)
        {
            Suggestion += line[id];
            // если конец предложения
            if (line[id] == '.' || line[id] == '!' || line[id] == '?' || line[id] == '\0')
            {
                // если в предложение нет запятых, выводим
                if (!FlagFind) cout << Suggestion << endl;
                Suggestion.clear();
                FlagFind = false;
            }

            else if (line[id] == ',') FlagFind = true;


        }
    }

    file.close(); // закрываем файл
}
