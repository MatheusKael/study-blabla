#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    if (argc > 3 || argc == 1)
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
    long header_size = header.subchunk1Size;

    fseek(input_file_pointer, 0, SEEK_END);

    long audio_size = ftell(input_file_pointer);

    fseek(input_file_pointer, header_size, SEEK_SET);

    int num_samples = header.subchunk2Size / (header.bitsPerSample / 8);

    WORD *buffer = (WORD *)malloc(num_samples * sizeof(WORD));

    if (buffer == NULL)
    {
        printf("Error alocating memory to buffer\n");
        return 1;
    }

    fread(buffer, sizeof(WORD), num_samples, input_file_pointer);

    int num_channels = header.numChannels;

    for (int i = 0; i < num_channels; i++)
    {
        for (int j = 0; j < num_samples / num_channels; j++)
        {
            int index1 = i * (num_samples / num_channels) + j;
            int index2 = i * (num_samples / num_channels) + num_samples / num_channels + j- 1;

            WORD tmp = buffer[index1];
            buffer[index1] = buffer[index2];
            buffer[index2] = tmp;
        }
    }

    fwrite(buffer, sizeof(short), num_samples, output_file_pointer);

    fclose(output_file_pointer);
    fclose(input_file_pointer);

    free(buffer);
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

    // BlockAlign  == NumChannels * BitsPerSample/8
    return header.blockAlign;
}