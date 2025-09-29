#include "student.h"
#include "menu.h"
#include <stdio.h>
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"

int searchStudents();

int searchStudents(){
    if (studentCount == 0) {
        printf("No students available.\n");
    }

    int search;
    printf("can you please enter the user's ID: ");
    scanf("%d", &search);
    int index = -1;

    for (int i = 0; i < studentCount; i++)
    {
        if (class[i].id == search)
        {
            index = i;
        }

    }
    if (index == -1)
    {
        printf("Sorry there is no student with that id");
    }
    
    return index;
}
int main() {
    showMenu();

    MYSQL *conn; 
    MYSQL_RES *res; 
    MYSQL_ROW row; 
 
    char *server = "localhost"; 
    char *user = "root"; 
    char *password = "aymen";
    char *database = "mini_project"; 
 
    conn = mysql_init(NULL); 
 
    if (!mysql_real_connect(conn, server, 
        user, password, database, 3306, NULL, 0)) { 
        fprintf(stderr, "%s\n", mysql_error(conn)); 
        exit(1); 
    } 

    return 0;
}