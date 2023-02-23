#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);
int read_wav_header(FILE* file);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if(argc > 3) {
        printf("Usage: reverse <input_file> <output_file>\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input_file = fopen(argv[1], "r");

    if(input_file == NULL) {
        printf("could not open the file\n");
    }


    // Read header
    // TODO #3


    // Use check_format to ensure WAV format
    // TODO #4

    // Open output file for writing
    // TODO #5

    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int read_wav_header(FILE* file) {
    WAVHEADER header;

    fread(&header.chunkID, sizeof(BYTE),  )

}
int check_format(WAVHEADER header)
{
    // TODO #4
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}