#include <stdio.h>
#include <string.h>

int main() {
    char text[100], key[100];
    int i, j = 0;

    printf("Enter Plaintext: ");
    scanf("%s", text);

    printf("Enter Key: ");
    scanf("%s", key);

    int keyLen = strlen(key);

    printf("Encrypted Text: ");

    for(i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if(ch >= 'A' && ch <= 'Z') {
            printf("%c", ((ch - 'A' + key[j % keyLen] - 'A') % 26) + 'A');
            j++;
        }
        else if(ch >= 'a' && ch <= 'z') {
            printf("%c", ((ch - 'a' + key[j % keyLen] - 'a') % 26) + 'a');
            j++;
        }
        else {
            printf("%c", ch);
        }
    }

    return 0;
}