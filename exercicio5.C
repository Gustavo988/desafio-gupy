#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;
    int i, j;

    printf("Informe uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    i = 0;
    j = strlen(str) - 1;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("String invertida: %s\n", str);

    return 0;
}
