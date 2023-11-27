#include <stdio.h>
#include <string.h>

struct Students {
    char name[50];
    int number;
    float score;
};

struct Students listStudents[100];
int quantity = 0;

struct Students inputStudents() {
    struct Students stu;
    printf("\nNhap ten sinh vien: ");
    fflush(stdin);
    gets(stu.name);
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &stu.number);
    printf("Nhap diem sinh vien: ");
    scanf("%f", &stu.score);
    return stu;
}

void displayStudents(struct Students stu) {
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s\n", stu.name);
    printf("Ma so: %d\n", stu.number);
    printf("Diem: %f\n", stu.score);
}

void arrangeName() {
    struct Students temp;
    for (int i = 0; i < quantity - 1; i++) {
        for (int j = i + 1; j < quantity; j++) {
            if (strcmp(listStudents[i].name, listStudents[j].name) > 0) {
                temp = listStudents[i];
                listStudents[i] = listStudents[j];
                listStudents[j] = temp;
            }
        }
    }
}

void arrangeScore() {
    struct Students temp;
    for (int i = 0; i < quantity - 1; i++) {
        for (int j = i + 1; j < quantity; j++) {
            if (listStudents[i].score > listStudents[j].score) {
                temp = listStudents[i];
                listStudents[i] = listStudents[j];
                listStudents[j] = temp;
            }
        }
    }
}

void arrangeNumber() {
    struct Students temp;
    for (int i = 0; i < quantity - 1; i++) {
        for (int j = i + 1; j < quantity; j++) {
            if (listStudents[i].number > listStudents[j].number) {
                temp = listStudents[i];
                listStudents[i] = listStudents[j];
                listStudents[j] = temp;
            }
        }
    }
}

int main() {
    int List;
    do {
        printf("\nChon yeu cau:\n");
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. Hien thi thong tin sinh vien\n");
        printf("3. Sap xep theo ten\n");
        printf("4. Sap xep theo diem\n");
        printf("5. Sap xep theo ma so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &List);

        switch (List) {
            case 1:
                if (quantity < 100) {
                    listStudents[quantity] = inputStudents();
                    quantity++;
                } else {
                    printf("Danh sach sinh vien da day. Khong the them sinh vien moi.\n");
                }
                break;
            case 2:
                printf("\nDanh sach sinh vien:\n");
                for (int i = 0; i < quantity; i++) {
                    displayStudents(listStudents[i]);
                }
                break;
            case 3:
                arrangeName();
                printf("Da sap xep danh sach theo ten.\n");
                break;
            case 4:
                arrangeScore();
                printf("Da sap xep danh sach theo diem.\n");
                break;
            case 5:
                arrangeNumber();
                printf("Da sap xep danh sach theo ma so.\n");
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    } while (List != 0);

    return 0;
}
