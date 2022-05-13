#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#define BLOCKS 512
typedef char *string;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
//Checks if user input is Valid or not
    if (argc != 2)
    {
        printf("Usuage ./recover <raw_file_name>\n");
        return 1;
    }

    string file_name = argv[1];
//Make a file pointer which can use to read the contains of the file
    FILE *readFilePtr = fopen(file_name, "r");

    if (readFilePtr == NULL)
    {
        return 2;
    }
//Creates an array of number 512 of Bytes each byte is 8 bits so we have 4,096 bits wow that's alot
    BYTE BYTES[BLOCKS];

    int images_number = 0;
//init process
    FILE *output_file = NULL;
//If i created this char in stack it will give segment fault error
    char *fileName = malloc(8 * sizeof(char));

    while (fread(BYTES, sizeof(BYTE), BLOCKS, readFilePtr))
    {
        if (BYTES[0] == 0xff && BYTES[1] == 0xd8 && BYTES[2] == 0xff && (BYTES[3] & 0xf0) == 0xe0)
        {
//It will start creating JPEG files starting from 1.jpg to 50.jpg
            sprintf(fileName, "%03i.jpg", images_number);
            output_file = fopen(fileName, "w");
            images_number++;
        }
        if (output_file != NULL)
        {
            fwrite(BYTES, sizeof(BYTE), BLOCKS, output_file);
        }
    }
//Close all the opened resources to be able to free memory space and avoid any memory leaks
    free(fileName);
    fclose(readFilePtr);
    fclose(output_file);
    return 0;
}