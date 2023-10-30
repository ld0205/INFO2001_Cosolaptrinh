#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
		int year;

    printf("Nhap nam: ");
    scanf("%d", &year);

    if (year <= 0) {
        printf("INVALID\n");
    } else if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
	return 0;
}
