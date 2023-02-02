// Switch Shaver C | Greyson Rowland (2023)

#define _LARGEFILE64_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    FILE *fptr;
    char choice[4096];
    char file[500];

    if (argv[1] == NULL) {
        printf("Please enter the name of the file: ");
        scanf("%s", file);
        fptr = fopen64(file, "rb+");
    } else {
        strcpy(file, argv[1]);
        fptr = fopen64(file, "rb+");
    }

    fseeko64(fptr, -0ULL, SEEK_END);   
    while ((unsigned char)fgetc(fptr) == 255) {
        fseeko64(fptr, -10000ULL, SEEK_CUR); 
    }
    while ((unsigned char)fgetc(fptr) != 255 || (unsigned char)fgetc(fptr) != 255 || (unsigned char)fgetc(fptr) != 255 || (unsigned char)fgetc(fptr) != 255) {
        fseeko64(fptr, 1ULL, SEEK_CUR);
    }
    _chsize_s(_fileno(fptr), ftello64(fptr) + 100);
    return 0;
}
