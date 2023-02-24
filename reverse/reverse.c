#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    if (argc > 3)
    {
        printf("Usage: reverse <input_file> <output_file>\n");
        return 1;
    }

    FILE *input_file_pointer = fopen(argv[1], "rb");
    FILE *output_file_pointer = fopen(argv[2], "wb");

    if (input_file_pointer == NULL && output_file_pointer == NULL)
    {
        printf("could not open the file\n");
        return 1;
    }

    WAVHEADER header;

    fread(&header, sizeof(WAVHEADER), 1, input_file_pointer);
    check_format(header);

    if (fwrite(&header, sizeof(WAVHEADER), 1, output_file_pointer) != 1)
    {
        printf("Error writing header to output file\n");
        return 1;
    }


    int block_size = get_block_size(header);

    fseek(input_file_pointer, 0, SEEK_END);

    long input_file_size = ftell(input_file_pointer);
    


    fclose(output_file_pointer);
    fclose(input_file_pointer);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    char format[5];

    strncpy(format, (const char *)header.format, 4);

    format[4] = '\0';

    if (strcmp(format, "WAVE") != 0)
    {
        printf("wrong format.\n");
        return 1;
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7

    return header.blockAlign;
}