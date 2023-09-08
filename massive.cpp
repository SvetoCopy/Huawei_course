#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char** ReadFile(const char* name) {
    char* buff = (char*)calloc(200, sizeof(char));
    size_t nLines = 10;
    FILE* f = NULL;
    char** data = (char**)calloc(nLines, sizeof(char*));

    fopen_s(&f, name, "r");
    assert(f != NULL);

    size_t i = 0;
    while (fgets(buff, 100, f) != NULL) {
        
        data[i] = _strdup(buff);
        i++;
    }
    delete buff;
    return data;  
}

int main()
{
    const char* name = "text.txt";
 
    char** txt = ReadFile(name);
    for (int i = 0; i < 4; ++i) {
        printf("%s", txt[i]);
    }
}