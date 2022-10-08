#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

const int JPEG_CHUNK = 512;

int main(int argc, char *argv[])
{
    //Ensure program accepts only 1 command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGEFILE");
        return 1;
    }

    //Open file containing images to READ
    //If file is empty, return error
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("Could not open IMAGEFILE");
        return 1;
    }

    //INITIALIZE VARIABLES
    //Buffer to hold 512bytes
    uint8_t buffer[JPEG_CHUNK];

    //Counter keeping track of #jpegs found
    int counter = 0;

    //Initialize output file
    FILE *outputFile = NULL;

    //Allocate space in memory for output filenames
    char *fileName = malloc(8);

    //Loop through input file
    while (fread(buffer, sizeof(uint8_t), JPEG_CHUNK, inputFile) == JPEG_CHUNK)
    {
        //Check if first 4 bytes in buffer have JPEG signatures
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            //Print filename to this allocated memory space
            //outputFile will now be equal to new filename
            sprintf(fileName, "%03i.jpg", counter);
            outputFile = fopen(fileName, "w");

            counter += 1;

        }
        if (outputFile != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), JPEG_CHUNK, outputFile);
        }
    }
    //Close jpegs and imageFile
    free(fileName);
    fclose(outputFile);
    fclose(inputFile);

    return 0;
}