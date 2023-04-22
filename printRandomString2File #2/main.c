#include <stdio.h>
#include "RandomString2File.h"

int main(int argc, char *argv[]) {
    // Открываем 2 файла и проверяем корректность открытия
    FILE *file_1 = fopen(argv[1], "r"); // Открытие файла
    if (!file_1) { // Проверка, открылся ли файл
        printf("Error open file_1 %s! Check your filename!", argv[1]);
        return 1;
    }
    FILE *file_2 = fopen(argv[2], "r"); // Открытие файла
    if (!file_2) { // Проверка, открылся ли файл
        printf("Error open file_2 %s! Check your filename!", argv[2]);
        return 1;
    }

    printRandomString2File(file_1, file_2);

    // Закрываем оба файла
    fclose(file_1);
    fclose(file_2);

    return 0;
}
