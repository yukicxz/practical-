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
    show_menu();
    return 0;
}