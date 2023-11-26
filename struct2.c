#include <stdio.h>
#define MAX_EMPLOYEES 100

struct Employee {
    int employeeID;
    char name[50];
    char position[50];
    int salary;
};

struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

void addEmployee() {
    if (numEmployees == MAX_EMPLOYEES) {
        printf("Khong the them nhan vien. Da dat gioi han.\n");
        return;
    }
    
    struct Employee newEmployee;
    
    printf("Nhap ma nhan vien: ");
    scanf("%d", &newEmployee.employeeID);
    printf("Nhap ten nhan vien: ");
    scanf("%s", newEmployee.name);
    printf("Nhap chuc vu: ");
    scanf("%s", newEmployee.position);
    printf("Nhap luong: ");
    scanf("%d", &newEmployee.salary);
    
    employees[numEmployees++] = newEmployee;
    
    printf("Da them nhan vien thanh cong.\n");
}

void removeEmployee() {
    int employeeID;
    int employeeIndex = -1;
    
    printf("Nhap ma nhan vien can xoa: ");
    scanf("%d", &employeeID);
    
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == employeeID) {
            employeeIndex = i;
            break;
        }
    }
    
    if (employeeIndex == -1) {
        printf("Khong tim thay nhan vien co ma %d.\n", employeeID);
    } else {
        for (int i = employeeIndex; i < numEmployees - 1; i++) {
            employees[i] = employees[i+1];
        }
        numEmployees--;
        printf("Da xoa nhan vien co ma %d.\n", employeeID);
    }
}

void displayEmployees() {
    if (numEmployees == 0) {
        printf("Khong co nhan vien de hien thi.\n");
        return;
    }
    
    printf("|%-10s|%-20s|%-20s|%-10s|\n", "Ma NV", "Ten", "Chuc vu", "Luong");
    for (int i = 0; i < numEmployees; i++) {
        printf("|%-10d|%-20s|%-20s|%-10d|\n", employees[i].employeeID, employees[i].name, employees[i].position, employees[i].salary);
    }
}

void sortEmployees() {
    struct Employee temp;
    
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = i + 1; j < numEmployees; j++) {
            if (employees[i].employeeID > employees[j].employeeID) {
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
    
    printf("Da sap xep nhan vien theo ma nhan vien.\n");
}

int main() {
    int choice;
    
    do {
        printf("\nCac chuc nang:\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi nhan vien\n");
        printf("4. Sap xep nhan vien\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                removeEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                sortEmployees();
                break;
            case 5:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 5);
    
    return 0;
}
