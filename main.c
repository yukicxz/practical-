#define _CRT_SECURE_NO_WARNINGS
#include "all.h"
void mergeSort(int* a, int l, int r) {
    setlocale(LC_ALL, "Russian");
    if (l == r)//проверяем условие равенства левой и правой границы последовательности
        return;//управление возвращается вызывающей функции
    int mid = (l + r) / 2; // определяем середину массива
    //рекурсивно вызываем функцию сортировки для каждой половины
    mergeSort(a, l, mid);//вызов функции сортировки для первой половины последовательности
    mergeSort(a, mid + 1, r);//вызов функции сортировки для левой половины последовательности
    int i = l;  // начало первой половины
    int j = mid + 1; // начало второй половины
    int* tmp = (int*)malloc(r * sizeof(int)); // выделение памяти под дополнительный массив, в котором формируется
    //отсортированная последовательность
    if (tmp == NULL) {//вывод ошибки в случае, если память не была выделена
        printf("Ошибка выделения памяти");
        return;
    }
    for (int s = 0; s < r - l + 1; s++) //сортировка последоваельности
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        if ((j > r) || ((i <= mid) && (a[i] < a[j])))//проверка условия выхода за правую границу второй последовательности
            //или являеся ли элемент первой половины последовательности меньшим
        {
            tmp[s] = a[i];//записываем в дополнительный массив элемент первой половины последовательности
            i++;//инкрементируем i и продвигаемся по первой половине последовательности
        }
        else//если условие не выполняется
        {
            tmp[s] = a[j];//записываем в формируемую последовательность элемент второй половины последовательности
            j++;// инкрементируем j и продвигаемся по второй половине последовательности
        }
    }
    // переписываем сформированную последовательность в исходный массив
    for (int s = 0; s < r - l + 1; s++)
        a[l + s] = tmp[s];
}
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
        return show_menu();
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
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int size;//размер массива
    printf("Введите размер массива больше одного: ");
    scanf("%d", &size);//считывание размера массива
    int* a = (int*)malloc(size * sizeof(int));//выделенеие памяти под динамический массив
    if (a == NULL) {//вывод ошибки в случае, если память не была выделена
        printf("Ошибка выделения памяти");
        return;
    }
    // Заполняем элементы массива случайными числами
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
        printf(" %d ", a[i]);
    }
    mergeSort(a, 0, size - 1); // вызываем функцию сортировки
    printf("\n");
    // Выводим отсортированный массив
    for (int i = 0; i < size; i++)
        printf(" %d ", a[i]);
    free(a);//освобождаем выделенную память
}
void func2() {

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