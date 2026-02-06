#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define LEN 500

// Function declarations
void createFile();
void openFile();
void editFile();
void searchWord();
void replaceWord();
void fileStats();
void deleteFile();
void copyFile();
void editLine();
void undoChange();

// backup file name (used for undo)
char backupFile[] = "backup_temp.txt";

int main() {
    int choice;

    while (1) {
        printf("\n====== UPPER-INTERMEDIATE CODE EDITOR ======\n");
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
        printf("11. Exit\n");
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
            case 11: printf("Exiting editor...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// ======================= BASIC FEATURES =======================

void backup(char *filename) {
    FILE *src = fopen(filename, "r");
    FILE *dest = fopen(backupFile, "w");
    if (!src || !dest) return;

    char ch;
    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    fclose(src);
    fclose(dest);
}

void createFile() {
    char filename[100], data[LEN];
    printf("Enter new filename: ");
    gets(filename);

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error creating file!\n");
        return;
    }

    printf("Enter text (type END to finish):\n");
    while (1) {
        gets(data);
        if (strcmp(data, "END") == 0) break;
        fputs(data, fp);
        fputc('\n', fp);
    }

    fclose(fp);
    printf("File '%s' created successfully!\n", filename);
}

void openFile() {
    char filename[100], ch;
    printf("Enter filename to open: ");
    gets(filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found!\n");
        return;
    }

    printf("\n--- Content of %s ---\n", filename);
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    printf("\n----------------------\n");
    fclose(fp);
}

void editFile() {
    char filename[100], data[LEN];
    printf("Enter filename to edit: ");
    gets(filename);

    backup(filename); // backup before edit

    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("File not found!\n");
        return;
    }

    printf("Enter new text (type END to finish):\n");
    while (1) {
        gets(data);
        if (strcmp(data, "END") == 0) break;
        fputs(data, fp);
        fputc('\n', fp);
    }

    fclose(fp);
    printf("File updated successfully!\n");
}

// ======================= NEW FEATURES =======================

void editLine() {
    char filename[100], buffer[MAX][LEN];
    int lineCount = 0, target;
    printf("Enter filename to edit a line: ");
    gets(filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found!\n");
        return;
    }

    backup(filename); // backup before change

    while (fgets(buffer[lineCount], LEN, fp)) lineCount++;
    fclose(fp);

    printf("Total lines: %d\n", lineCount);
    printf("Enter line number to modify or delete (0 to cancel): ");
    scanf("%d", &target);
    getchar();

    if (target <= 0 || target > lineCount) {
        printf("Invalid line number.\n");
        return;
    }

    printf("Current line: %s", buffer[target - 1]);
    printf("\nChoose:\n1. Modify line\n2. Delete line\nEnter choice: ");
    int option;
    scanf("%d", &option);
    getchar();

    if (option == 1) {
        printf("Enter new text: ");
        gets(buffer[target - 1]);
        strcat(buffer[target - 1], "\n");
    } else if (option == 2) {
        for (int i = target - 1; i < lineCount - 1; i++)
            strcpy(buffer[i], buffer[i + 1]);
        lineCount--;
    } else {
        printf("Invalid option.\n");
        return;
    }

    fp = fopen(filename, "w");
    for (int i = 0; i < lineCount; i++)
        fputs(buffer[i], fp);
    fclose(fp);

    printf("Changes saved successfully!\n");
}

void undoChange() {
    char filename[100];
    printf("Enter filename to undo last change: ");
    gets(filename);

    FILE *backupFp = fopen(backupFile, "r");
    if (!backupFp) {
        printf("No backup found for undo.\n");
        return;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error restoring file.\n");
        fclose(backupFp);
        return;
    }

    char ch;
    while ((ch = fgetc(backupFp)) != EOF)
        fputc(ch, fp);

    fclose(backupFp);
    fclose(fp);

    printf("Undo successful! File restored to previous version.\n");
}

// ======================= OTHER FEATURES =======================

void searchWord() {
    char filename[100], word[50], line[LEN];
    int line_no = 0, found = 0;

    printf("Enter filename: ");
    gets(filename);
    printf("Enter word to search: ");
    gets(word);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found!\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        line_no++;
        if (strstr(line, word)) {
            printf("Found '%s' in line %d: %s", word, line_no, line);
            found = 1;
        }
    }

    if (!found) printf("'%s' not found.\n", word);
    fclose(fp);
}

void replaceWord() {
    char filename[100], oldWord[50], newWord[50];
    char tempFile[] = "temp.txt";
    char buffer[LEN];
    int replaced = 0;

    printf("Enter filename: ");
    gets(filename);
    printf("Enter word to replace: ");
    gets(oldWord);
    printf("Enter new word: ");
    gets(newWord);

    backup(filename); // backup before replace

    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen(tempFile, "w");
    if (!fp || !temp) {
        printf("Error opening file!\n");
        return;
    }

    while ((fgets(buffer, LEN, fp)) != NULL) {
        char *pos, tempBuffer[LEN];
        int index = 0;
        strcpy(tempBuffer, buffer);

        while ((pos = strstr(tempBuffer, oldWord)) != NULL) {
            replaced++;
            int len = pos - tempBuffer;
            tempBuffer[len] = '\0';
            fprintf(temp, "%s%s", tempBuffer, newWord);
            strcpy(tempBuffer, pos + strlen(oldWord));
        }
        fprintf(temp, "%s", tempBuffer);
    }

    fclose(fp);
    fclose(temp);
    remove(filename);
    rename(tempFile, filename);

    if (replaced)
        printf("All occurrences of '%s' replaced with '%s'.\n", oldWord, newWord);
    else
        printf("No occurrences found.\n");
}

void fileStats() {
    char filename[100];
    printf("Enter filename: ");
    gets(filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found!\n");
        return;
    }

    int chars = 0, words = 0, lines = 0;
    char ch, prev = ' ';
    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if ((ch == ' ' || ch == '\n' || ch == '\t') &&
            !(prev == ' ' || prev == '\n' || prev == '\t'))
            words++;
        prev = ch;
    }

    fclose(fp);
    printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);
}

void deleteFile() {
    char filename[100];
    printf("Enter filename to delete: ");
    gets(filename);

    if (remove(filename) == 0)
        printf("File '%s' deleted successfully.\n", filename);
    else
        printf("Error deleting file.\n");
}

void copyFile() {
    char src[100], dest[100];
    printf("Enter source filename: ");
    gets(src);
    printf("Enter destination filename: ");
    gets(dest);

    FILE *fsrc = fopen(src, "r");
    FILE *fdest = fopen(dest, "w");
    if (!fsrc || !fdest) {
        printf("Error opening files!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(fsrc)) != EOF)
        fputc(ch, fdest);

    fclose(fsrc);
    fclose(fdest);
    printf("File copied successfully!\n");
}
