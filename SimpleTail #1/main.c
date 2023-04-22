#include <stdio.h>
#include "SimpleTail.h"

int main(int argc, char *argv[]) {
    int n = 0; // Переменная для количества строк
    if (check_arg(argc, argv, &n)) return 1; // Проверка переданных аргументов
    FILE *file = fopen(argv[1], "r"); // Открытие файла
    if (!file) { // Проверка, открылся ли файл
        printf("Error open file %s! Check your filename!", argv[1]);
        return 1;
    }
    print_last_n_string(file, n); // Вывод строк
    fclose(file); // Закрываем файл
    return 0;
}
