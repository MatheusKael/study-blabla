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
    int header_size = sizeof(WAVHEADER);

    fread(&header, header_size, 1, input_file_pointer);
    check_format(header);

    if (fwrite(&header, header_size, 1, output_file_pointer) != 1)
    {
        printf("Error writing header to output file\n");
        return 1;
    }

    int block_size = get_block_size(header);
    int bytes_per_sample = (header.bitsPerSample / 8);
    long audio_size = header.subchunk2Size / bytes_per_sample;

    fseek(input_file_pointer, header_size, SEEK_SET);

    int num_samples = audio_size / header.numChannels;

    short *buffer = malloc(audio_size * sizeof(short));

    if (buffer == NULL)
    {
        printf("Error alocating memory to buffer\n");
        return 1;
    }

    fread(buffer, bytes_per_sample, audio_size, input_file_pointer);
    for (int i = 0; i < num_samples / 2; i++)
    {
        for (int j = 0; j < header.numChannels; j++)
        {
            short tmp = buffer[i * header.numChannels + j];
            buffer[i * header.numChannels + j] = buffer[(num_samples - i - 1) * header.numChannels + j];
            buffer[(num_samples - i - 1) * header.numChannels + j] = tmp;
        }
    }

    fwrite(buffer, bytes_per_sample, audio_size, output_file_pointer);

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