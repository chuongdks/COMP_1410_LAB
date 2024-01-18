#include <stdio.h>
#include <string.h>

//#include "Student.h"

typedef struct Student_struct {
    char *studentName;
    double studentGPA;
} Student;

Student InitStudent(); // - initializes name to "Louie" and gpa to 1.0
Student SetName(char *name, Student s); //- sets the student's name
Student SetGPA(double gpa, Student s); //- sets the student's GPA
void GetName(char* studentName, Student s); //- return the student's name in studentName
double GetGPA(Student s); //- returns the students GPA

int main() {
    Student student = InitStudent();
    char name[20];
    
    GetName(name, student);
    printf("%s/%.1lf\n", name, GetGPA(student));

    student = SetName("Felix", student);
    student = SetGPA(3.7, student);
    GetName(name, student);
    printf("%s/%.1lf\n", name, GetGPA(student));

	return 0;
}

Student InitStudent(){
    Student newStudent;
    newStudent.studentName = "Louie";
    newStudent.studentGPA = 1.0;
    return newStudent;
}

Student SetName(char *name, Student s){
    s.studentName = name;
    return s;
}

void GetName(char* studentName, Student s){
    strcpy(studentName, s.studentName);
}

Student SetGPA(double gpa, Student s){
    s.studentGPA = gpa;
    return s;
}

double GetGPA(Student s){
    return s.studentGPA;
}

