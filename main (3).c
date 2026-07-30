#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    if(gcd(a, 26) != 1) {
        printf("Invalid value of a.\n");
        return 0;
    }

    printf("Encrypted Text: ");

    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            printf("%c", ((a * (text[i] - 'A') + b) % 26) + 'A');
        else if(text[i] >= 'a' && text[i] <= 'z')
            printf("%c", ((a * (text[i] - 'a') + b) % 26) + 'a');
        else
            printf("%c", text[i]);
    }

    return 0;
}