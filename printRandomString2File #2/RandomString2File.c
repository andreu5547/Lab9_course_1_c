#include "RandomString2File.h"

void printRandomString2File(FILE *file_1, FILE *file_2) {
    char c_1 = '0', c_2 = '0'; // Переменные для хранения символов каждого из файлов
    while (c_1 != EOF || c_2 != EOF) { // Проверяем, что хотя бы один из файлов не кончился
        if (c_1 != EOF) { // Проверяем что первый не кончился
            // Выводим строку
            while ((c_1 = getc(file_1)) != '\n' && c_1 != EOF) putchar(c_1);
            putchar('\n');
        }
        if (c_2 != EOF) { // Проверяем что второй не кончился
            // Выводим строку
            while ((c_2 = getc(file_2)) != '\n' && c_2 != EOF) putchar(c_2);
            putchar('\n');
        }
    }
}