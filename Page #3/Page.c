#include "Page.h"

int compare_string(const char *s1, const char *s2) { // Функция сравнения строк
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; ++i) {
        if (s1[i] != s2[i]) return 1;
        if (s1[i] == '\0' && s2[i] != '\0') return 1;
        if (s2[i] == '\0' && s1[i] != '\0') return 1;
    }
    return 0;
}

int check_arg(int argc, char **argv, int *p, int *n) { // Функция проверки аргументов
    if (argc != 6) {
        puts("Use ./page file.txt -p <num_str> -n <len>");
        return 1;
    }
    if (!compare_string(argv[2], "-p"))
        for (int i = 0; argv[3][i] != '\0'; i++) { // Обработка числа строк
            if (argv[3][i] >= '0' && argv[3][i] <= '9')
                *p = *p * 10 + argv[3][i] - '0';
            else {
                puts("Error! Use uint numbers!\nSet default p = 2");
                *p = 2;
                break;
            }
        }
    else {
        puts("Use ./page file.txt -p <num_str> -n <len>");
        return 1;
    }
    if (!compare_string(argv[4], "-n"))
        for (int i = 0; argv[5][i] != '\0'; i++) { // Обработка длинны
            if (argv[5][i] >= '0' && argv[5][i] <= '9')
                *n = *n * 10 + argv[5][i] - '0';
            else {
                puts("Error! Use uint numbers!\nSet default n = 5");
                *n = 5;
                break;
            }
        }
    else {
        puts("Use ./page file.txt -p <num_str> -n <len>");
        return 1;
    }
    return 0;
}

void print_pages(FILE *file, int p, int n) {
    char c; // Временная переменная символа
    int page = 0, line = 0, sym = 0; // Страница, строка, символ
    while ((c = getc(file)) != EOF) { // Посимвольно читаем файл до конца
        new_cycle: // Метка на начало цикла
        if (line < p) { // Проверяем, что кол-во строк меньше введённого пользователем
            if (sym < n && c != '\n') { // Проверяем, что кол-во символов меньше введённого пользователем и не конец слова
                if (sym == 0) printf("%d: ", line + 1); // Если новая строка, то выведем её номер
                putchar(c); // Выводим символ
                sym++; // Увеличиваем кол-во выведенных символов на 1
            } else { // Если конец лимита символов или конец слова
                putchar('\n'); // Переводим каретку
                sym = 0; // Обнуляем кол-во символов
                line++; // Увеличиваем кол-вл строк на 1
                if (c != '\n') { // Если это не enter, то обработаем символ ещё раз
                    goto new_cycle;
                }
            }
        } else {
            printf("- Page %d -\n", ++page); // Выведем номер страницы
            line = 0; // Обнуляем кол-во строк
            sym = 0; // Обнуляем кол-во символов
            goto new_cycle; // Обработаем символ ещё раз
        }
    }
}