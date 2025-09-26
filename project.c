#include <stdio.h>

int calculerMoyenneGenerale();
int afficherBulletin();
int afficherEtudiants();
int calculerMoyenneEtudiant();
int saisirNotes();
int ajouterEtudiant();
// files(prototypes, service menu) ; optimization; mysql delete and update
struct student{
    int id;
    char firstname[10];
    char lastname[10];
    float grade[4];
    float average;
};
    int studentCount = 0; 
    float class_average = 0;
    struct student class[30];
    int size = sizeof(class) / sizeof(class[0]);

int main(){
    int choice;

    do{
        printf("\nHello! What would you like to do today?\n");
        printf("Press 1 to Add a student\n");
        printf("Press 2 to add students grades\n");
        printf("Press 3 to display all students\n");
        printf("Press 4 to display a students paper sheet\n");
        printf("Press 5 to calculate the grade average for the whole class\n");
        printf("Press 0 to Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1 :
                ajouterEtudiant();
            break;
            case 2 : 
                 saisirNotes();
                break;
            case 3 :
                afficherEtudiants();
            break;
            case 4 :
                afficherBulletin();
            break;
            case 5:
                calculerMoyenneGenerale();
            break;
            case 0: 
            return 0;
        }
    }while (choice != 0);
}

int ajouterEtudiant(){
    for (int i = 0; i < size; i++)
    {
        printf("Enter student's ID: ");
        scanf("%d", &class[studentCount].id);
        printf("Enter first name: ");
        scanf("%s", class[studentCount].firstname);
        printf("Enter last name: ");
        scanf("%s", class[studentCount].lastname);
        studentCount++;
        main();
    }
}

int saisirNotes(){
        float sum = 0;

        int search;
            printf("could you please specify which students grade(by entering his ID)");
                scanf("%d", &search);
                
                int index = -1;
                for (int i = 0; i < studentCount; i++) {
                    if (class[i].id == search) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Student not found!\n");
                } else {
                    for (int g = 0; g < 4; g++) {
                        do
                        {
                            printf("Enter grade %d: ", g + 1);
                            scanf("%f", &class[index].grade[g]);
                            if (class[index].grade[g] < 1 || class[index].grade[g] > 20)
                            {
                                printf("could you please enter a valid number");
                            }
                            
                        } while (class[index].grade[g] < 1 || class[index].grade[g] > 20);
                        
                        sum = sum + class[index].grade[g];
                    }
                    class[index].average = sum / 4;
                    printf("%.2f\n", class[index].average);
                }
                    for (int i = 0; i < 4; i++)
    {
        class[index].average = sum / 4;
    }
    printf("%.2f\n", class[index].average);
    printf("\n");
}

int afficherBulletin(){
    int search;
    printf("could you please specify which students grade(by entering his ID)");
    scanf("%d", &search);       
    int ind = -1;
    for (int i = 0; i < studentCount; i++) {
        if (class[i].id == search) {
            ind = i;
            break;
            }
        }
        if (ind == -1) {
            printf("Student not found!\n");
        } else {
            for (int i = 0; i < studentCount; i++)
            {
                for (int g = 0; g < 4; g++) {
                    printf("note %d : %.2f\n", g + 1, class[ind].grade[g]);
                }
                printf("%.2f\n", class[ind].average);
            }
        }
}

int calculerMoyenneGenerale(){
    if (studentCount == 0) {
        printf("No students to calculate average.\n");
    } else {
        float total = 0;
        for (int i = 0; i < studentCount; i++) {
            total += class[i].average;
        }
        float class_average = total / studentCount;
        printf("Class average: %.2f\n", class_average);
    }
}

int afficherEtudiants(){
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | first name: %s | last name:  %s | [", class[i].id, class[i].firstname, class[i].lastname);
        for (int g = 0; g < 3; g++) {
            printf("%.2f, ", class[i].grade[g]);
        }           
        printf("%.2f] |", class[i].grade[3]);
        printf("\t%.2f\n", class[i].average);
    } 
}