/*
Write a program that reads the student information from a tab separated values (tsv) file. The program then creates a text file that records the course grades of the 
students. Each row of the tsv file contains the Last Name, First Name, Midterm1 score, Midterm2 score, and the Final score of a student. A sample of the student 
information is provided in StudentInfo.tsv. Assume the number of students is at least 1 and at most 20.

The program performs the following tasks:

    Read the file name of the tsv file from the user. Assume the file name has a maximum of 25 characters.
    Open the tsv file and read the student information. Assume each last name or first name has a maximum of 25 characters.
    Compute the average exam score of each student.
    Assign a letter grade to each student based on the average exam score in the following scale:
        A: 90 =< x
        B: 80 =< x < 90
        C: 70 =< x < 80
        D: 60 =< x < 70
        F: x < 60
    Compute the average of each exam.
    Output the last names, first names, exam scores, and letter grades of the students into a text file named report.txt. Output one student per row and separate the 
    values with a tab character.
    Output the average of each exam, with two digits after the decimal point, at the end of report.txt. Hint: Use the precision sub-specifier to format the output.

Ex: If the input of the program is:

StudentInfo.tsv

and the contents of StudentInfo.tsv are:

Barrett    Edan    70  45  59
Bradshaw    Reagan  96  97  88
Charlton    Caius   73  94  80
Mayo    Tyrese  88  61  36
Stern    Brenda  90  86  45

the file report.txt should contain:

Barrett    Edan    70  45  59  F
Bradshaw    Reagan  96  97  88  A
Charlton    Caius   73  94  80  B
Mayo    Tyrese  88  61  36  D
Stern    Brenda  90  86  45  C

Averages: midterm1 83.40, midterm2 76.60, final 61.60
*/
#include <stdio.h>

#define MAX_STUDENTS 20
#define MAX_NAME_LENGTH 25
#define MAX_FILENAME_LENGTH 25

// Function to calculate the letter grade based on average score
char calculateGrade(float average) 
{
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

int main() {
    char fileName[MAX_FILENAME_LENGTH];
    char lastName[MAX_NAME_LENGTH], firstName[MAX_NAME_LENGTH];
    int midterm1, midterm2, final;
    int numStudents = 0;
    float totalMidterm1 = 0, totalMidterm2 = 0, totalFinal = 0;

    // Open the file for reading
    printf("Enter the filename: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) 
    {
        printf("Error opening file. Make sure the file exists and is readable.\n");
        return -1;
    }

    // Open the report.txt file for writing
    FILE *reportFile = fopen("report.txt", "w");
    if (reportFile == NULL) 
    {
        printf("Error creating report file.\n");
        return -1;
    }

    // Read and process student information
    fprintf(reportFile, "Last Name\tFirst Name\tMidterm1\tMidterm2\tFinal\tGrade\n");
    while (fscanf(file, "%s %s %d %d %d", lastName, firstName, &midterm1, &midterm2, &final) == 5) 
    {
        // Calculate average
        float average = (midterm1 + midterm2 + final) / 3.0;

        // Update total scores for averages
        totalMidterm1 += midterm1;
        totalMidterm2 += midterm2;
        totalFinal += final;

        // Calculate and print the letter grade to the report file
        char grade = calculateGrade(average);
        fprintf(reportFile, "%s\t%s\t%d\t%d\t%d\t%c\n", lastName, firstName, midterm1, midterm2, final, grade);

        //increase the student count after each calculation
        numStudents++;
    }

    // Calculate and print averages to the report file
    float avgMidterm1 = totalMidterm1 / numStudents;
    float avgMidterm2 = totalMidterm2 / numStudents;
    float avgFinal = totalFinal / numStudents;
    fprintf(reportFile, "\nAverages: midterm1 %.2f, midterm2 %.2f, final %.2f\n", avgMidterm1, avgMidterm2, avgFinal);

    // Close files
    fclose(file);
    fclose(reportFile);

    return 0;
}
