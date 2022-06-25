#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    system("chcp 1251");
    system("cls");
    FILE* file = NULL, * temp_file = NULL;
    char filename[] = "file.txt"; //название файла
    size_t length;
    file = fopen(filename, "rb");

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    printf("Размер файла: %d\n", length);
    fclose(file);

    int part_count = 5; // кол-во частей деления файла
    size_t part_size;
    part_size = length / part_count;
    printf("Размер части файла: %d\n", part_size);

    char * part_file = NULL;
    char* pool;
    size_t bytes;

    part_file = (char*)calloc(part_size, sizeof(char));
    file = fopen(filename, "rb");
    size_t ctr = 0;

    pool = calloc(part_size, sizeof(char));


    while (!feof(file))
    {
        char part[15];
        sprintf(part, ".part%d", ctr+1);

        strcpy(part_file, filename);
        strcat(part_file, part);
        ctr++;

        bytes = fread(pool, sizeof(char), part_size, file);


        temp_file = fopen(part_file, "wb");

       
        fwrite(pool, sizeof(char), bytes, temp_file);
    }
    free(pool);
    free(part_file);
    printf("Размер файла: %d\n", ctr);

    fclose(file);
    return 0;
}
