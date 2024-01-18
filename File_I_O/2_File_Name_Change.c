/*
A photographer is organizing a photo collection about the national parks in the US and would like to annotate the information about each of the photos into a separate 
set of files. Write a program that reads the name of a text file containing a list of photo file names. The program then reads the photo file names from the text file, 
replaces the "_photo.jpg" portion of the file names with "_info.txt", and outputs the modified file names.

Assume the unchanged portion of the photo file names contains only letters and numbers, and the text file stores one photo file name per line. If the text file is empty, 
the program produces no output. Assume also the maximum number of characters of all file names is 100.

Ex: If the input of the program is:

ParkPhotos.txt

and the contents of ParkPhotos.txt are:

Acadia2003_photo.jpg
AmericanSamoa1989_photo.jpg
BlackCanyonoftheGunnison1983_photo.jpg
CarlsbadCaverns2010_photo.jpg
CraterLake1996_photo.jpg
GrandCanyon1996_photo.jpg
IndianaDunes1987_photo.jpg
LakeClark2009_photo.jpg
Redwood1980_photo.jpg
VirginIslands2007_photo.jpg
Voyageurs2006_photo.jpg
WrangellStElias1987_photo.jpg

the output of the program is:

Acadia2003_info.txt
AmericanSamoa1989_info.txt
BlackCanyonoftheGunnison1983_info.txt
CarlsbadCaverns2010_info.txt
CraterLake1996_info.txt
GrandCanyon1996_info.txt
IndianaDunes1987_info.txt
LakeClark2009_info.txt
Redwood1980_info.txt
VirginIslands2007_info.txt
Voyageurs2006_info.txt
WrangellStElias1987_info.txt

*/

#include <stdio.h>
#include <string.h>

//Correct Version
int main(void) {
    FILE* inFile = NULL; // File pointer
    char fileName[50];
    
    char *underscorePos;
    char str[100];


    // Try to open the file
    scanf("%s", fileName);
    inFile = fopen(fileName, "r");

    if (inFile == NULL) 
    {
        //printf("Error opening file. Make sure the file exists and is readable.\n");
        return -1; // -1 indicates an error
    }

    // Read and process each line from the file
    while (fscanf(inFile, "%s", str) == 1) 
    {
        // Replace the extension in the filename
        underscorePos = strrchr(str, '_'); // Find the position of the last underscore

        // If an underscore is found, replace "_photo.jpg" with "_info.txt"
        if (underscorePos != NULL) 
        {
            strcpy(underscorePos, "_info.txt");
        }

        // Output the modified filename
        printf("%s\n", str);
    }

    // Close the file
    fclose(inFile);
    return 0;
}


//OR

/*
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

void replaceExtension(char *str) {
    // Find the position of the last underscore
    char *underscorePos = strrchr(str, '_');

    // If an underscore is found, replace "_photo.jpg" with "_info.txt"
    if (underscorePos != NULL) {
        strncpy(underscorePos, "_info.txt", 10);
    }
}

int main() {
    FILE *inputFile;
    char str[MAX_FILENAME_LENGTH];

    // Open the input file
    inputFile = fopen("ParkPhotos.txt", "r");

    // Check if the file was successfully opened
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read and process each line from the file
    while (fgets(str, sizeof(str), inputFile) != NULL) {
        // Remove newline character from the end of the str
        str[strcspn(str, "\n")] = '\0';

        // Replace the extension in the str
        replaceExtension(str);

        // Output the modified str
        printf("%s\n", str);
    }

    // Close the file
    fclose(inputFile);

    return 0;
}
*/

