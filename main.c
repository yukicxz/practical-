#define _CRT_SECURE_NO_WARNINGS
#include "all.h"
void centerprintf(const char* str) { //������� ����������� ������ �������
    int width = 120; //������
    int len = strlen(str); //������
    int startPos = (width - len) / 2; //����������� ������
    for (int i = 0; i < startPos; i++) { //�������� �� ������
        putchar(' ');
    }
    printf("%s", str);
}
int show_menu() { //���������� ����
    setlocale(LC_ALL, "Rus"); // ��������� �������� �����
    char* frm = "%s"; //���������� ������ ��� ������������ �������
    char* text = ("\033[31m""������� �������� ���. �������� �� ������������.\n""\033[m"); //����� ������������ �������
    printf("\n");
    centerprintf("=============================\n");
    centerprintf("        =""\033[91m""     ���������""\033[m"" ����������  =\n");
    centerprintf("=============================\n");
    centerprintf("|                           |\n");
    centerprintf("|       1. ������           |\n");
    centerprintf("|                           |\n");
    centerprintf("         |""\033[91m""       2. ���������        ""\033[m""|\n");
    centerprintf("|                           |\n");
    centerprintf("        |""\033[31m""       3. �����            ""\033[m""|\n");
    centerprintf("|                           |\n");
    centerprintf("=============================\n");


    char choice; //���������� ��� ������
    printf("��� �����: ");
    scanf(" %c", &choice);
    printf("\n");

    switch (choice) { //������������� ��� ������ ������������
    case '1': //���� ������������ ���� 1
        system("cls"); //������� ��������
        func1();
        break;
    case '2': //���� ������������ ���� 2
        system("cls"); //������� ��������
        func2();
        break;
    case '3': //���� ������������ ���� 3
        return 0;
        break;

    default: //���� �� ������ �� ���� �� ������������ ���������
        system("cls"); //������� ��������
        __asm { //������ ������������ �������
            push text //������� � ���� ��������� �� ���������� �����
            push frm //������� � ���� ��������� �� ������
            call printf //����� ������� printf
            add esp, 8 //�������������� �����
        }
        return show_menu(); //������� � ����
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
    char title[] = "  ��������� ����������\n";
    char title2[] = "��������� �������� �.� ���������� �.�. ������ �.�\n";
    char title3[] = "     ������ 22���2 ";
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