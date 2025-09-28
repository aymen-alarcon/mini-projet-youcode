#ifndef STUDENT_H
#define STUDENT_H

struct student {
    int id;
    char firstname[10];
    char lastname[10];
    float grade[4];
    float average;
};

extern struct student class[30];
extern int studentCount;

void ajouterEtudiant();
void afficherEtudiants();
void deleteStudent();
void deleteAllStudents();
void updateStudent();

#endif
