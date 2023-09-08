#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
size_t row_size = 100;

char* getch(char* text, size_t i, size_t j) {
    return text + row_size * i + j;
}

char* getstr(char* text, size_t i) {
    return text + row_size * i;
}

void setch(char* text, size_t i, size_t j, char change) {
    *(text + row_size * i + j) = change;
}

void setstr(char* text, size_t i, const char* change) {
    strcpy(text, change);
}

char* ReadFile(const char* name) {
    char* text = (char*)calloc(10000, sizeof(char));
    char* change_ptr = text;
    FILE* f = NULL;

    fopen_s(&f, name, "r");

    size_t i = 0;
    char symbol = fgetc(f);
    while (symbol != EOF) {
        if (symbol == '\n') {
            symbol = fgetc(f);
            i++;
            *change_ptr = '\0';
            change_ptr = text + i * row_size;
            continue;
        }
        *change_ptr = symbol;
        change_ptr++;
        symbol = fgetc(f);
    }
    //printf("%s", text);
    
    *change_ptr = '\0';
    return text;
}
int main()
{
    char str[10][100] = {};
    const char* name = "text.txt";
 
    char* txt = ReadFile(name);
    printf("%s", getstr(txt, 2));
}