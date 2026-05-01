#include <stdio.h>
#include <string.h>
#define MAX 10
struct employee {
    int id;
    char name[20];
};     
struct employee emp[MAX];
int hashTable[MAX];
/* Hash function */
int hash(int key) {
    return key % MAX;
}
/* Insert using Linear Probing */
void insert(int key) {
    int index = hash(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % MAX;   // linear probing
    }
    hashTable[index] = key;
    printf("Enter emp id: ");
    scanf("%d", &emp[index].id);
    printf("Enter emp name: ");
    scanf("%s", emp[index].name);
}
/* Display function */
void display() {
    int ch;
    printf("\n1.Display All\n2.Filtered Display");
    printf("\nEnter choice: ");
    scanf("%d", &ch);
    printf("\nHTKey\tEmpID\tEmpName\n");
    for (int i = 0; i < MAX; i++) {
        if (ch == 1) {
            printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
        } else {
            if (hashTable[i] != -1) {
                printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
            }
        }
    }
}
int main() {
    int key, ans = 1;
    for (int i = 0; i < MAX; i++) {
        hashTable[i] = -1;
        emp[i].id = 0;
        strcpy(emp[i].name, "");
    }
    printf("Collision handling by linear probing\n");
    while (ans) {
        printf("\nEnter the data: ");
        scanf("%d", &key);

        insert(key);

        printf("Do you wish to continue? (1/0): ");
        scanf("%d", &ans);
    }
    display();
    return 0;
}