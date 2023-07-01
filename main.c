#define _CRT_SECURE_NO_WARNINGS
#include "all.h"
void centerprintf(const char* str) { //функция определения центра консоли
    int width = 120; //высота
    int len = strlen(str); //длинна
    int startPos = (width - len) / 2; //определение центра
    for (int i = 0; i < startPos; i++) { //смещение до центра
        putchar(' ');
    }
    printf("%s", str);
}
int show_menu() { //объявление меню
    setlocale(LC_ALL, "Rus"); // установка русского языка
    char* frm = "%s"; //символьный формат для ассемблерной вставки
    char* text = ("\033[31m""Данного варианта нет. Выберите из предложенных.\n""\033[m"); //текст ассемблерной вставки
    printf("\n");
    centerprintf("=============================\n");
    centerprintf("        =""\033[91m""     Шейкерная""\033[m"" Сортировка  =\n");
    centerprintf("=============================\n");
    centerprintf("|                           |\n");
    centerprintf("|       1. Начать           |\n");
    centerprintf("|                           |\n");
    centerprintf("         |""\033[91m""       2. Настройки        ""\033[m""|\n");
    centerprintf("|                           |\n");
    centerprintf("        |""\033[31m""       3. Выход            ""\033[m""|\n");
    centerprintf("|                           |\n");
    centerprintf("=============================\n");


    char choice; //переменная для выбора
    printf("Ваш выбор: ");
    scanf(" %c", &choice);
    printf("\n");

    switch (choice) { //переключатель для выбора пользователя
    case '1': //если пользователь ввел 1
        system("cls"); //очистка конслоли
        func1();
        break;
    case '2': //если пользователь ввел 2
        system("cls"); //очистка конслоли
        func2();
        break;
    case '3': //если пользователь ввел 3
        return 0;
        break;

    default: //если не выбран ни один из предложенных вариантов
        system("cls"); //очистка конслоли
        __asm { //начало ассемблерной вставки
            push text //заносим в стек указатель на переменную текст
            push frm //заносим в стек указатель на формат
            call printf //вызов функции printf
            add esp, 8 //восстановление стека
        }
        return show_menu(); //возврат в меню
    }
}
void func1() {
    return 0;
}
void func2() {
    return 0;
}
int main()
{
    zastavka();
    show_menu();
    return 0;
}
int zastavka()
{
    system("cls");
    setlocale(LC_ALL, "Rus");
    char title[] = "  Шейкерная Сортировка\n";
    char title2[] = "Выполнили Корнилов В.М Самофалова А.В. Перкин П.О\n";
    char title3[] = "     Группа 22ВВП2 ";
    int length = strlen(title);
    int length2 = strlen(title2);
    int length3 = strlen(title3);
    int x, y;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    x = (console_width - length) / 2;
    y = console_height / 2;


    for (int i = 0; i < y; i++)
        printf("\n");
    for (int i = 0; i < x; i++)
        printf(" ");
    for (int j = 0; j < length; j++)
    {
        printf("\033[91m""%c""\033[m", title[j]);
        Sleep(100);
    }
    Sleep(1000);

    for (int i = 0; i < 35; i++)
        printf(" ");
    for (int m = 0; m < length2; m++)
    {
        printf("%c", title2[m]);
        Sleep(100);
    }
    Sleep(1000);
    for (int l = 0; l < y; l++)
        printf("\n");
    for (int l = 0; l < x; l++)
        printf(" ");
    for (int n = 0; n < length3; n++)
    {
        printf("%c", title3[n]);
        Sleep(100);
    }
    Sleep(2000);
    system("cls");
    return 0;
}