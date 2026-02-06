//Name of the project => Text Editor  
//Insertion Deletion Searching wordCount charactercount displaytext undochanges (some bugs)
//fixing issues in undochanges
//createFile and savefile (pending)
//replaceword (pending)
//editfile (pending)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 500

// Linked list node
struct Line {
    char text[LEN];
    struct Line *next;
};

// Globals
struct Line *head = NULL;
struct Line *backup = NULL;
char currentFile[100] = "";

// Function declarations
void createFile();
void openFile();
void displayFile();
void editFile();
void editLine();
void searchWord();
void replaceWord();
void fileStats();
void deleteFile();
void copyFile();
void undoChange();
void saveFile();

// Helper functions
void freeList(struct Line **list);
void backupList();
void restoreBackup();
struct Line* createNode(const char *text);
int countLines();

// ============= Helper Implementations =============

// Create new node
struct Line* createNode(const char *text) {
    struct Line *node = (struct Line*)malloc(sizeof(struct Line));
    strcpy(node->text, text);
    node->next = NULL;
    return node;
}

// Free memory of a list
void freeList(struct Line **list) {
    struct Line *temp;
    while (*list) {
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

// Backup list for undo
void backupList() {
    freeList(&backup);
    struct Line *temp = head, *prev = NULL;
    while (temp) {
        struct Line *newNode = createNode(temp->text);
        if (!backup)
            backup = newNode;
        else
            prev->next = newNode;
        prev = newNode;
        temp = temp->next;
    }
}

// Restore backup list
void restoreBackup() {
    if (!backup) {
        printf(" Nothing to undo.\n");
        return;
    }
    freeList(&head);
    struct Line *temp = backup, *prev = NULL;
    while (temp) {
        struct Line *newNode = createNode(temp->text);
        if (!head)
            head = newNode;
        else
            prev->next = newNode;
        prev = newNode;
        temp = temp->next;
    }
    printf(" Undo successful!\n");
}

// Count lines
int countLines() {
    int count = 0;
    struct Line *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ============= Core Features =============

// Create new file
void createFile() {
    printf("Enter new filename: ");
    scanf("%s", currentFile);
    getchar();

    freeList(&head);
    FILE *fp = fopen(currentFile, "w");
    if (!fp) {
        printf("Error creating file!\n");
        return;
    }
    fclose(fp);

    printf("Enter content (type END to stop):\n");
    while (1) {
        char text[LEN];
        fgets(text, LEN, stdin);
        text[strcspn(text, "\n")] = '\0';
        if (strcmp(text, "END") == 0)
            break;

        struct Line *newNode = createNode(text);
        if (!head)
            head = newNode;
        else {
            struct Line *temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
    saveFile();
    printf(" File '%s' created.\n", currentFile);
}

// Open existing file
void openFile() {
    printf("Enter filename to open: ");
    scanf("%s", currentFile);
    getchar();

    FILE *fp = fopen(currentFile, "r");
    if (!fp) {
        printf(" File not found!\n");
        return;
    }

    freeList(&head);
    char line[LEN];
    while (fgets(line, LEN, fp)) {
        line[strcspn(line, "\n")] = '\0';
        struct Line *newNode = createNode(line);
        if (!head)
            head = newNode;
        else {
            struct Line *temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
    fclose(fp);
    backupList();
    printf(" File '%s' loaded successfully.\n", currentFile);
}

// Display file content
void displayFile() {
    if (!head) {
        printf(" File is empty.\n");
        return;
    }
    int i = 1;
    struct Line *temp = head;
    printf("\n---- %s Content ----\n", currentFile);
    while (temp) {
        printf("%2d | %s\n", i++, temp->text);
        temp = temp->next;
    }
    printf("----------------------\n");
}

// Edit (append) file
void editFile() {
    if (!*currentFile) {
        printf(" No file open.\n");
        return;
    }
    backupList();
    printf("Enter new text (type END to stop):\n");
    while (1) {
        char text[LEN];
        fgets(text, LEN, stdin);
        text[strcspn(text, "\n")] = '\0';
        if (strcmp(text, "END") == 0)
            break;
        struct Line *newNode = createNode(text);
        if (!head)
            head = newNode;
        else {
            struct Line *temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
    saveFile();
    printf(" File updated.\n");
}

// Edit specific line
void editLine() {
    if (!head) {
        printf(" File empty.\n");
        return;
    }

    int lineNo;
    printf("Enter line number to edit: ");
    scanf("%d", &lineNo);
    getchar();

    struct Line *temp = head;
    int i = 1;
    while (temp && i < lineNo) {
        temp = temp->next;
        i++;
    }
    if (!temp) {
        printf(" Invalid line number.\n");
        return;
    }

    backupList();
    printf("Current line: %s\nEnter new text: ", temp->text);
    fgets(temp->text, LEN, stdin);
    temp->text[strcspn(temp->text, "\n")] = '\0';

    saveFile();
    printf(" Line %d updated.\n", lineNo);
}

// Search word
void searchWord() {
    if (!head) {
        printf(" File is empty.\n");
        return;
    }

    char word[50];
    printf("Enter word to search: ");
    scanf("%s", word);

    struct Line *temp = head;
    int lineNo = 1, found = 0;
    while (temp) {
        if (strstr(temp->text, word)) {
            printf("Found '%s' in line %d: %s\n", word, lineNo, temp->text);
            found = 1;
        }
        temp = temp->next;
        lineNo++;
    }

    if (!found)
        printf("'%s' not found.\n", word);
}

// Replace word
void replaceWord() {
    if (!head) {
        printf(" File is empty.\n");
        return;
    }

    char oldW[50], newW[50];
    printf("Enter word to replace: ");
    scanf("%s", oldW);
    printf("Enter new word: ");
    scanf("%s", newW);
    getchar();

    backupList();
    struct Line *temp = head;
    int count = 0;
    while (temp) {
        char *pos;
        while ((pos = strstr(temp->text, oldW))) {
            char buffer[LEN];
            *pos = '\0';
            sprintf(buffer, "%s%s%s", temp->text, newW, pos + strlen(oldW));
            strcpy(temp->text, buffer);
            count++;
        }
        temp = temp->next;
    }

    saveFile();
    printf(" %d replacements done.\n", count);
}

// File statistics
void fileStats() {
    int lines = 0, words = 0, chars = 0;
    struct Line *temp = head;
    while (temp) {
        lines++;
        chars += strlen(temp->text);
        char copy[LEN];
        strcpy(copy, temp->text);
        char *token = strtok(copy, " ");
        while (token) {
            words++;
            token = strtok(NULL, " ");
        }
        temp = temp->next;
    }

    printf(" Lines: %d |  Words: %d |  Characters: %d\n", lines, words, chars);
}

// Copy file
void copyFile() {
    char newFile[100];
    printf("Enter destination filename: ");
    scanf("%s", newFile);
    getchar();

    FILE *fp = fopen(newFile, "w");
    if (!fp) {
        printf(" Cannot create destination file.\n");
        return;
    }
    struct Line *temp = head;
    while (temp) {
        fprintf(fp, "%s\n", temp->text);
        temp = temp->next;
    }
    fclose(fp);
    printf(" File copied to '%s'.\n", newFile);
}

// Delete file
void deleteFile() {
    char filename[100];
    printf("Enter filename to delete: ");
    scanf("%s", filename);
    if (remove(filename) == 0)
        printf("🗑️ File '%s' deleted.\n", filename);
    else
        printf(" Unable to delete file.\n");
}

// Save file
void saveFile() {
    if (!*currentFile) return;
    FILE *fp = fopen(currentFile, "w");
    if (!fp) return;
    struct Line *temp = head;
    while (temp) {
        fprintf(fp, "%s\n", temp->text);
        temp = temp->next;
    }
    fclose(fp);
}

// Undo change
void undoChange() {
    restoreBackup();
    saveFile();
}

// ============= Main Function =============
int main() {
    int choice;
    while (1) {
        printf("\n======= LINKED LIST CODE EDITOR =======\n");
        printf("1. Create New File\n");
        printf("2. Open File\n");
        printf("3. Edit (Append)\n");
        printf("4. Edit Specific Line\n");
        printf("5. Search Word\n");
        printf("6. Replace Word\n");
        printf("7. File Statistics\n");
        printf("8. Copy File\n");
        printf("9. Delete File\n");
        printf("10. Undo Last Change\n");
        printf("11. Display File\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: createFile(); break;
            case 2: openFile(); break;
            case 3: editFile(); break;
            case 4: editLine(); break;
            case 5: searchWord(); break;
            case 6: replaceWord(); break;
            case 7: fileStats(); break;
            case 8: copyFile(); break;
            case 9: deleteFile(); break;
            case 10: undoChange(); break;
            case 11: displayFile(); break;
            case 12: printf(" Exiting editor...\n"); exit(0);
            default: printf(" Invalid choice!\n");
        }
    }
    return 0;
}
