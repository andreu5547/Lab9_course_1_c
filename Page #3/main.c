#include <stdio.h>
#include "Page.h"

int main(int argc, char *argv[]) {
    int p = 0, n = 0; // Переменная ограничения строк и символов на странице
    if (check_arg(argc, argv, &p, &n)) return 1; // Проверка переданных аргументов
    FILE *file = fopen(argv[1], "r"); // Открытие файла
    if (!file) { // Проверка, открылся ли файл
        printf("Error open file %s! Check your filename!", argv[1]);
        return 1;
    }
    print_pages(file, p, n);
    fclose(file); // Закрываем файл
    return 0;
}
