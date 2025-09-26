#include <stdio.h>

struct student{
    int id;
    char firstname[10];
    char lastname[10];
    float grade[4];
    float average;
};

int main(){
    struct student class[30];
    int choice;
    int size = sizeof(class) / sizeof(class[0]);
    int search;
    int studentCount = 0; 
    float class_average = 0;
    float sum = 0;

    do{
        debut:
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
                for (int i = 0; i < size; i++)
                {
                        printf("Enter student's ID: ");
                        scanf("%d", &class[studentCount].id);
                        printf("Enter first name: ");
                        scanf("%s", class[studentCount].firstname);
                        printf("Enter last name: ");
                        scanf("%s", class[studentCount].lastname);
                        studentCount++;
                        goto debut;
                }
            break;
            case 2 :  
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
                        printf("Enter grade %d: ", g + 1);
                        scanf("%f", &class[index].grade[g]);
                        sum = sum + class[index].grade[g];
                    }
                    class[index].average = sum / 4;
                    printf("%.2f\n", class[index].average);
                }
                goto debut;
                break;
                case 3 :
                for (int i = 0; i < studentCount; i++) {
                    printf("ID: %d | first name: %s | last name:  %s | ", class[i].id, class[i].firstname, class[i].lastname);
                    for (int g = 0; g < 4; g++) {
                        printf("[%.2f] ", class[i].grade[g]);
                        sum = sum + class[index].grade[g];
                    }                    
                    
                    class[index].average = sum / 4;
                    printf("%.2f\n", class[index].average);
                    printf("\n");
                }   
                goto debut;
                break;
            case 4 :
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
                        for (int g = 0; g < 4; g++) {
                            printf("note %d : %.2f\n", g + 1, class[ind].grade[g]);
                        }
                        printf("%.2f\n", class[ind].average);
                    }
                    goto debut;
                break;
                case 5:
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
                
                    goto debut;
                break;
        }
    }while (choice != 0);
}