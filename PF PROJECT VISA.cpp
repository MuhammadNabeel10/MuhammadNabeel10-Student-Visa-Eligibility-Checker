#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char *questions[] = {
        "Do you have a university acceptance letter? (yes/no): ",
        "Do you have your IELTS score? (yes/no): ",
        "Do you have proof of funds? (yes/no): ",
        "Do you have a valid passport? (yes/no): ",
        "Do you have the visa application form filled? (yes/no): ",
        "Do you have passport-size photos? (yes/no): ",
        "Do you have your academic transcripts? (yes/no): ",
        "Do you have a medical certificate? (yes/no): ",
        "Do you have a Statement of Purpose (SOP)? (yes/no): "
    };

    char *missingDocs[] = {
        "University acceptance letter",
        "IELTS score",
        "Proof of funds",
        "Passport",
        "Visa application form filled",
        "Passport-size photos",
        "Academic transcripts",
        "Medical certificate",
        "Statement of Purpose (SOP)"
    };

    const int n = sizeof(questions) / sizeof(questions[0]);
    char answer[10];
    char *missingList[9];  // to store pointers to missing document descriptions
    int missingCount = 0;

    printf("Student Visa Document Checklist\n");
    printf("-------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%s", questions[i]);
        scanf("%s", answer);
        toLowerCase(answer);

        if (strcmp(answer, "no") == 0) {
            missingList[missingCount++] = missingDocs[i];
        }
    }

    printf("\n-----------------------------------\n");

    if (missingCount == 0) {
        printf("? All documents are in place. You are ready to apply for your student visa!\n");
    } else {
        printf(" You are missing %d documents:\n", missingCount);
        for (int i = 0; i < missingCount; i++) {
            printf("- %s\n", missingList[i]);
        }
        printf(" Please ensure all documents are available before applying.\n");
    }

    return 0;
}

