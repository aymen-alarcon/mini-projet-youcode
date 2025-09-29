#include "student.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

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
    
    sqlite3 *db;
    char *err_msg = 0;

    // Open or create a database file
    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a table
    const char *sql_create =
        "CREATE TABLE IF NOT EXISTS Students("
        "ID INTEGER PRIMARY KEY, "
        "Name TEXT, "
        "Grade REAL);";

    rc = sqlite3_exec(db, sql_create, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
/*
    // Insert data
    const char *sql_insert =
        "INSERT INTO Students (Name, Grade) VALUES ('Alice', 17.5);";

    rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Read data
    const char *sql_select = "SELECT * FROM Students;";
*/
    // Callback to print rows
    int callback(void *NotUsed, int argc, char **argv, char **azColName) {
        for (int i = 0; i < argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }

    rc = sqlite3_exec(db, sql_select, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
    return 0;
}
