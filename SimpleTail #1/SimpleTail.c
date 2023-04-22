#include "SimpleTail.h"

int check_arg(int argc, char **argv, int *n) { // Функция проверки аргументов
    if (argc < 2 || argc > 3) {
        puts("Use ./tail file.txt <num>");
        return 1;
    }
    if (argc == 3)
        for (int i = 0; argv[2][i] != '\0'; i++) { // Обработка числа строк, если преданы
            if (argv[2][i] >= '0' && argv[2][i] <= '9')
                *n = *n * 10 + argv[2][i] - '0';
            else {
                puts("Error! Use uint numbers!\nSet default n = 5");
                *n = 5;
                break;
            }
        }
    else *n = 5;
    return 0;
}

void print_last_n_string(FILE *file, int n) {
    int all_string_num = 1; // Полное количество строк
    char c; // Временная переменная для символа
    while ((c = getc(file)) != EOF) // Считаем количество строк в файле
        if (c == '\n') all_string_num++;
    rewind(file); // Переходим в начало файла
    while ((c = getc(file)) != EOF) {
        if (all_string_num <= n) // Когда дойдём до момента, когда оставшееся количество строк станет равно нашему, начнём их выводить
            putchar(c);
        if (c == '\n') all_string_num--; // Уменьшаем кол-во строк на 1 каждый \n
    }
}