#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);
WAVHEADER read_wav_header(FILE *file);

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
    WAVHEADER header = read_wav_header(input_file_pointer);

    fclose(input_file_pointer);

    // Use check_format to ensure WAV format
    // TODO #4

    check_format(header);

    // Open output file for writing
    // TODO #5
    DWORD output_file_size = header.subchunk2Size;
    BYTE *data_buffer = malloc(output_file_size);

    // Write header to file
    // TODO #6
    if (fwrite(&header, sizeof(header), 1, output_file_pointer) != 1)
    {
        printf("Error writing header to output file\n");
        return 1;
    }

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

WAVHEADER read_wav_header(FILE *file)
{
    WAVHEADER header;

    fread(&header.chunkID, sizeof(BYTE), 4, file);
    fread(&header.chunkSize, sizeof(DWORD), 1, file);
    fread(&header.format, sizeof(BYTE), 4, file);
    fread(&header.subchunk1ID, sizeof(BYTE), 4, file);
    fread(&header.subchunk1Size, sizeof(DWORD), 1, file);
    fread(&header.audioFormat, sizeof(WORD), 1, file);
    fread(&header.numChannels, sizeof(WORD), 1, file);
    fread(&header.sampleRate, sizeof(DWORD), 1, file);
    fread(&header.byteRate, sizeof(DWORD), 1, file);
    fread(&header.bitsPerSample, sizeof(WORD), 1, file);
    fread(&header.subchunk2ID, sizeof(BYTE), 4, file);
    fread(&header.subchunk2Size, sizeof(DWORD), 1, file);

    return header;
}
int check_format(WAVHEADER header)
{
    // TODO #4
    // printf("%s", header.format);
    if (strcmp((const char*)header.format, "WAVE") != 0)
    {
        printf("%s\n", header.format);
        printf("wrong file format\n");
        return 1;
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}