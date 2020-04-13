#include <stdio.h>
#include <stdlib.h>
//eliminate magic numbers
#define JAR 512

//making a struct
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: name of the infile\n");
        return 1;
    }

    // open input file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    BYTE storage[JAR];
    int count = 0;

    char jpeg_name[64];
    FILE *img;


    while (fread(storage, sizeof(storage), 1, file) == 1)
    {
        if (storage[0] == 0xff &&
            storage[1] == 0xd8 &&
            storage[2] == 0xff &&
            (storage[3] & 0xf0) == 0xe0)
        {
            if (count > 0)
            {
                fclose(img);
                sprintf(jpeg_name, "%03d.jpg", count);
                count += 1;
                img = fopen(jpeg_name, "w");
                fwrite(storage, sizeof(storage), 1, img);
            }
            if (count == 0)
            {
                sprintf(jpeg_name, "%03d.jpg", count);
                count += 1;
                img = fopen(jpeg_name, "w");
                fwrite(storage, sizeof(storage), 1, img);
            }

        }
        else if (count > 0)
        {

            fwrite(storage, sizeof(storage), 1, img);
        }
    }

    fclose(img);
    fclose(file);

    return 0;
}
