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
    DWORD output_file_size = header.subchunk2Size;

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

    printf("%i\n", block_size);

    int num_blocks = output_file_size / block_size;

    // Write reversed audio to file
    // TODO #8
    char *buffer = malloc(block_size* sizeof(char));

    for (int i = 0; i < num_blocks; i++)
    {
        fread(buffer, sizeof(char), block_size, input_file_pointer);

        for (int j = 0; j < block_size / 2; j++)
        {
            char tmp = buffer[j];
            buffer[j] = buffer[block_size - j - 1];
            buffer[block_size - j - 1] = tmp;
        }

        fwrite(buffer, sizeof(char), block_size, output_file_pointer);
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

    printf("%i %i\n", header.numChannels, header.bitsPerSample);
    return header.numChannels * (header.bitsPerSample / 8) * header.sampleRate;
}