#define _CRT_SECURE_NO_WARNINGS
#include "all.h"
int zastavka()
{
    system("cls"); //������� �������
    setlocale(LC_ALL, "Rus"); //��������� �������� �����
    char title[] = "  ���������� ��������\n"; //
    char title2[] = "��������� �������� �.� ���������� �.�. ������ �.�\n"; //���������� ��������� ��������
    char title3[] = "     ������ 22���2 "; //
    int length = strlen(title); //
    int length2 = strlen(title2); //����������� ������ ��������
    int length3 = strlen(title3); //
    int x, y;

    CONSOLE_SCREEN_BUFFER_INFO csbi; //
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); //
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1; // ��������� �������� �������
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; //

    x = (console_width - length) / 2; // ����������� ������ �������
    y = console_height / 2; //


    for (int i = 0; i < y; i++) //���������� �������� �� ������ �� y
        printf("\n"); //
    for (int i = 0; i < x; i++) //���������� �������� �� ������ �� x
        printf(" "); //
    for (int j = 0; j < length; j++) 
    {
        printf("\033[91m""%c""\033[m", title[j]); //������������ ����� 1 �������
        Sleep(60); //���������� ������ ������� �������
    }
    Sleep(500);

    for (int i = 0; i < 35; i++) //���������� �������� �� x
        printf(" ");
    for (int m = 0; m < length2; m++) 
    {
        printf("%c", title2[m]);//������������ ����� 2 �������
        Sleep(60); //���������� ������ ������� �������
    }
    Sleep(500);
    for (int l = 0; l < y; l++) //���������� �������� �� y
        printf("\n");
    for (int l = 0; l < x; l++) //���������� �������� �� x
        printf(" ");
    for (int n = 0; n < length3; n++)
    {
        printf("%c", title3[n]); //������������ ����� 3 �������
        Sleep(60); //���������� ������ ������� �������
    }
    Sleep(2000);
    system("cls"); //������� �������
    return 0;
}