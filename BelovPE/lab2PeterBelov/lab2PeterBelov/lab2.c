#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ����� 1: ������������ ��������� �����
void user_guesses() {
    srand(time(NULL));
    int secret_number = rand() % 1000 + 1;
    int attempts = 0;
    int guess;

    printf("� ������� ����� �� 1 �� 1000. ���������� �������!\n");

    do {
        printf("������� ���� �������: ");
        if (scanf("%d", &guess) != 1) {
            printf("������ �����! ������� ����� �����.\n");
            // ������� ����� �����
            while (getchar() != '\n');
            continue;
        }
        attempts++;

        if (guess < secret_number) {
            printf("���������� ����� ������\n");
        }
        else if (guess > secret_number) {
            printf("���������� ����� ������\n");
        }
        else {
            printf("�������! ����������!\n");
        }
    } while (guess != secret_number);

    printf("����� �������: %d\n", attempts);
}

// ����� 2: ��������� ��������� ����� (�������� �����)
void computer_guesses() {
    int low = 1;
    int high = 1000;
    int attempts = 0;
    char response;
    int guess;

    printf("��������� ����� �� 1 �� 1000. � �������� �������!\n");
    printf("�������:\n'>' - ���� ���� ����� ������\n'<' - ���� ���� ����� ������\n'=' - ���� � ������\n");

    do {
        guess = (low + high) / 2;
        attempts++;

        printf("��� �������: %d\n", guess);
        printf("��� �����: ");

        if (scanf(" %c", &response) != 1) {
            printf("������ �����!\n");
            while (getchar() != '\n');
            attempts--;
            continue;
        }

        if (response == '>') {
            low = guess + 1;
        }
        else if (response == '<') {
            high = guess - 1;
        }
        else if (response == '=') {
            printf("���! � ������ �� %d �������!\n", attempts);
        }
        else {
            printf("�������� ����! ����������� ������ '>', '<' ��� '='\n");
            attempts--; // �� ������� ��� �������
        }

        // �������� �� ������ ��������� ����
        if (low > high) {
            printf("�� ���-�� �������� � ��������! �������� ������.\n");
            low = 1;
            high = 1000;
            attempts = 0;
        }
    } while (response != '=');
}

int main() {
    int choice;

    printf("=== ���� '������ �����' ===\n");

    do {
        printf("\n�������� �����:\n");
        printf("1 - � �������� �����\n");
        printf("2 - ��������� ��������� �����\n");
        printf("0 - �����\n");
        printf("��� �����: ");

        if (scanf("%d", &choice) != 1) {
            printf("������ �����! ������� �����.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            user_guesses();
            break;
        case 2:
            computer_guesses();
            break;
        case 0:
            printf("�� ��������!\n");
            break;
        default:
            printf("�������� �����! ���������� �����.\n");
        }
    } while (choice != 0);

    return 0;
}