/*
Given a text file containing the availability of food items, write a program that reads the information from the text file and outputs the available food items. 
The program first reads the name of the text file from the user. The program then reads the text file, stores the information into the four string arrays predefined in the
program, and outputs the available food items in the following format: name (category) -- description

Assume the text file contains the category, name, description, and availability of at least one food item, separated by a tab character ('\t').

Hints: Use the fgets() function to read each line of the input text file. When extracting texts between the tab characters, copy the texts character-by-character until 
a tab character is reached. A string always ends with a null character ('\0').

Ex: If the input of the program is:

food.txt

and the contents of food.txt are:

Sandwiches    Ham sandwich    Classic ham sandwich    Available
Sandwiches    Chicken salad sandwich  Chicken salad sandwich  Not available
Sandwiches    Cheeseburger    Classic cheeseburger    Not available
Salads    Caesar salad    Chunks of romaine heart lettuce dressed with lemon juice    Available
Salads    Asian salad Mixed greens with ginger dressing, sprinkled with sesame    Not available
Beverages    Water   16oz bottled water  Available
Beverages    Coca-Cola   16oz Coca-Cola  Not available
Mexican food    Chicken tacos   Grilled chicken breast in freshly made tortillas    Not available
Mexican food    Beef tacos  Ground beef in freshly made tortillas   Available
Vegetarian    Avocado sandwich    Sliced avocado with fruity spread   Not available

the output of the program is:

Ham sandwich (Sandwiches) -- Classic ham sandwich
Caesar salad (Salads) -- Chunks of romaine heart lettuce dressed with lemon juice
Water (Beverages) -- 16oz bottled water
Beef tacos (Mexican food) -- Ground beef in freshly made tortillas
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_LENGTH 100

int main() {
    char category[MAX_ITEMS][MAX_LENGTH];
    char name[MAX_ITEMS][MAX_LENGTH];
    char description[MAX_ITEMS][MAX_LENGTH];
    char availability[MAX_ITEMS][MAX_LENGTH];

    char filename[MAX_LENGTH];
    char str[1000]; // maximum string length
    
    // get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);
    
    // open file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return -1;
    }
    
    // read file line by line
    int count = 0;
    while (fgets(str, sizeof(str), file) != NULL && count < MAX_ITEMS) 
    {
        // extract fields from str separated by tabs
        char *token = strtok(str, "\t");
        strcpy(category[count], token);
        token = strtok(NULL, "\t");
        strcpy(name[count], token);
        token = strtok(NULL, "\t");
        strcpy(description[count], token);
        token = strtok(NULL, "\t");
        strcpy(availability[count], token);
        
        // remove trailing newline from description, 
        /*dont need this part to work
        int len = strlen(description[count]);
        if (description[count][len-1] == '\n') 
        {
            description[count][len-1] = '\0';
        }
        */

        // print available items
        printf("Available food items:\n");
        if (strcmp(availability[count], "Available\n") == 0) 
        {
            printf("%s (%s) -- %s\n", name[count], category[count], description[count]);
        }
        
        //increase item count when move to next line
        count++;
    }
    
    // close file
    fclose(file);
    
    return 0;
}