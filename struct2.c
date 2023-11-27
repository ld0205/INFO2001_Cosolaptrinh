#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50


struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    float score;
};


void sortStudentsByName(struct Student students[], int numStudents) {
    int i, j;
    struct Student temp;

    for (i = 0; i < numStudents - 1; i++) {
        for (j = i + 1; j < numStudents; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}


void sortStudentsByScore(struct Student students[], int numStudents) {
    int i, j;
    struct Student temp;

    for (i = 0; i < numStudents - 1; i++) {
        for (j = i + 1; j < numStudents; j++) {
            if (students[i].score > students[j].score) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}


int searchStudentByName(struct Student students[], int numStudents, char searchName[]) {
    int i;

    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            return i; 
        }
    }

    return -1; 
}


int searchStudentByID(struct Student students[], int numStudents, int searchID) {
    int i;

    for (i = 0; i < numStudents; i++) {
        if (students[i].id == searchID) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents, i;
    
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &numStudents);

    
    for (i = 0; i < numStudents; i++) {
        printf("Nhap thong tin cho sinh vien %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Ten: ");
        scanf("%s", students[i].name);
        printf("Ðiem so: ");
        scanf("%f", &students[i].score);
    }

    
    sortStudentsByName(students, numStudents);
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    for (i = 0; i < numStudents; i++) {
        printf("ID: %d, Ten: %s, Ðiem so: %.2f\n", students[i].id, students[i].name, students[i].score);
    }

    
    char searchName[MAX_NAME_LENGTH];
    printf("\nNhap ten sinh vien can tim: ");
    scanf("%s", searchName);
    int foundIndex = searchStudentByName(students, numStudents, searchName);
    if (foundIndex != -1) {
        printf("Sinh vien có ten %s duoc tim thay tai vi tri %d.\n", searchName, foundIndex + 1);
    } else {
        printf("Khong tim thay sinh vien co ten %s.\n", searchName);
    }

    
    int searchID;
    printf("\nNhap ID sinh vien can tim: ");
    scanf("%d", &searchID);
    foundIndex = searchStudentByID(students, numStudents, searchID);
    if (foundIndex != -1) {
        printf("Sinh vien có ID %d duoc tim thay tai vi tri %d.\n", searchID, foundIndex + 1);
    } else {
        printf("Không tim thay sinh vien co ID %d.\n", searchID);
    }
       return 0;
   }
