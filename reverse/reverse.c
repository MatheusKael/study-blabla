#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc > 3)
    {
        printf("Usage: reverse <input_file> <output_file>\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input_file_pointer = fopen(argv[1], "r");

    if (input_file_pointer == NULL)
    {
        printf("could not open the file\n");
        return 1;
    }

    FILE *output_file_pointer = fopen(argv[2], "w");

    if (output_file_pointer == NULL)
    {
        printf("could not open the file\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;

    fread(&header, sizeof(WAVHEADER), 1, input_file_pointer);

    // Use check_format to ensure WAV format
    // TODO #4

    check_format(header);

    // Open output file for writing
    // TODO #5
    int output_file_size = header.subchunk1Size;

    // Write header to file
    // TODO #6
    if (fwrite(&header, sizeof(WAVHEADER), 1, output_file_pointer) != 1)
    {
        printf("Error writing header to output file\n");
        return 1;
    }

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);


    fseek(input_file_pointer, 0, SEEK_END);
    long input_file_size = ftell(input_file_pointer);
    fseek(input_file_pointer, 0, SEEK_END);

    int num_blocks = input_file_size / block_size;
    printf("%i, %i\n", block_size, num_blocks);

    // Write reversed audio to file
    // TODO #8
    char *buffer = malloc(block_size);

    for (int i = 0; i < num_blocks; i++)
    {
        fread(buffer, block_size, 1, input_file_pointer);

        for (int j = 0; j < block_size / 2; j++)
        {
            char tmp = buffer[j];
            // buffer[j] = buffer[block_size - j - 2];
            // buffer[block_size - j - 2] = tmp;
            // tmp = buffer[j + 1];
            buffer[j] = buffer[block_size - j - 1];
            buffer[block_size - j - 1] = tmp;
        }
        fwrite(buffer, block_size, 1, output_file_pointer);
    }

    free(buffer);
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

    return header.numChannels * (header.bitsPerSample / 8) * header.sampleRate;
}