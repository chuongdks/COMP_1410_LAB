#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 44
#define MAX_RATING_LENGTH 5
#define MAX_SHOWTIMES_LENGTH 100

#define MAX_ITEMS 20

int main() {
    char fileName[25];
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) 
    {
        printf("Could not open file %s\n", fileName);
        return -1;
    }

    char str[100];
    char time[MAX_ITEMS][MAX_SHOWTIMES_LENGTH];
    char title[MAX_ITEMS][MAX_TITLE_LENGTH];
    char rating[MAX_ITEMS][MAX_RATING_LENGTH];

    char test[MAX_ITEMS][MAX_TITLE_LENGTH];

    // read file line by line
    int count = 0;
    while (fgets(str, sizeof(str), file) != NULL && count < MAX_ITEMS) 
    {
        // remove trailing newline from str
        int length = strlen(str);
        if (str[length-1] == '\n') 
        {
            str[length-1] = '\0';
        }

        // extract fields from str separated by tabs
        char *token = strtok(str, ",");
        strcpy(time[count], token);

        token = strtok(NULL, ",");
        strncpy(title[count], token, 44);
        title[count][strlen(title[count]) - 1] = '\0'; 

        token = strtok(NULL, ",");
        strcpy(rating[count], token);
        rating[count][strlen(rating[count]) - 1] = '\0'; 

        //printf("%s | %5s | %s\n", title[count], rating[count], time[count]);

        //increase item count when move to next line
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%-44s | %5s | %s\n", title[i], rating[i], time[i]);
    } 

    fclose(file);

    return 0;
}