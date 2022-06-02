#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
BYTE buffer[512];
char filename[8];
int i = 0;

int main(int argc, char *argv[])
{
    // check argument amount
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // open file
    FILE *file = fopen(argv[1], "r");
    FILE *img;
    // read bytes
    while (fread(&buffer, 512, sizeof(BYTE), file) == sizeof(BYTE))
    {
        // check for jpg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%.03i.jpg", i);
            // i is 0 by default so this would be the first jpg
            if (i == 0)
            {
                img = fopen(filename, "w");
                fwrite(&buffer, 512, sizeof(BYTE), img);
            }
            else
            {
                fclose(img);
                img = fopen(filename, "w");
                fwrite(&buffer, 512, sizeof(BYTE), img);
            }
            i += 1;
        }
        else if (i > 0)
        {
            fwrite(&buffer, 512, sizeof(BYTE), img);
        }
    }
    fclose(file);
}