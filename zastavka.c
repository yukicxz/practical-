#define _CRT_SECURE_NO_WARNINGS
#include "all.h"
int zastavka()
{
    system("cls"); //очистка консоли
    setlocale(LC_ALL, "Rus"); //установка русского языка
    char title[] = "  Сортировка слиянием\n"; //
    char title2[] = "Выполнили Корнилов В.М Самофалова А.В. Перкин П.О\n"; //объявление текстовых массивов
    char title3[] = "     Группа 22ВВП2 "; //
    int length = strlen(title); //
    int length2 = strlen(title2); //Определение длинны массивов
    int length3 = strlen(title3); //
    int x, y;

    CONSOLE_SCREEN_BUFFER_INFO csbi; //
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); //
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1; // Установка размеров консоли
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; //

    x = (console_width - length) / 2; // Определение центра консоли
    y = console_height / 2; //


    for (int i = 0; i < y; i++) //добавление отступов до центра по y
        printf("\n"); //
    for (int i = 0; i < x; i++) //добавление отступов до центра по x
        printf(" "); //
    for (int j = 0; j < length; j++) 
    {
        printf("\033[91m""%c""\033[m", title[j]); //посимвольный вывод 1 массива
        Sleep(60); //промежуток вывода каждого символа
    }
    Sleep(500);

    for (int i = 0; i < 35; i++) //добавление отступов по x
        printf(" ");
    for (int m = 0; m < length2; m++) 
    {
        printf("%c", title2[m]);//посимвольный вывод 2 массива
        Sleep(60); //промежуток вывода каждого символа
    }
    Sleep(500);
    for (int l = 0; l < y; l++) //добавление отступов по y
        printf("\n");
    for (int l = 0; l < x; l++) //добавление отступов по x
        printf(" ");
    for (int n = 0; n < length3; n++)
    {
        printf("%c", title3[n]); //посимвольный вывод 3 массива
        Sleep(60); //промежуток вывода каждого символа
    }
    Sleep(2000);
    system("cls"); //очистка консоли
    return 0;
}