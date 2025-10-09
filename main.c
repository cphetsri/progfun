#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1200
#define MAX_RECORDS 1100

    int decide;
    char buffer[10000];
    char *emp_name;
    char *eqm_name;
    char *brw_date;
    char *rtn_date;
    char emname[1020];
    char emsirname[100];
    char eqmname[50];
    char brwdate[11];
    char rtndate[11];

void waitForEnter(){
    printf("\nPress [ENTER] to return to the main menu......");
    getchar();
    getchar();
}

int decideThing(){

    while (1) {

        printf("===================================================================\n\n");
        printf("Read a Log -- (1)\nBorrow Some Thing -- (2)\nSearch for Borrow Date -- (3)\nUpdate Data -- (4)\nDelete Data -- (5)\nExit the Program -- (0)\n");
        printf("\n===================================================================\n\n");
        printf("What do you want to do [input the number] : ");
        scanf("%d", &decide);

        if (decide == 1){
            printf("\n===================================================================\n\n");
            FILE *brwdata = fopen("borrowdata.csv", "r");
            if (brwdata == NULL) {
                printf("################ Error: could not open csv file ################### \n\n-------- File name doesn't match or That file doesn't exit --------\n\n");
                printf("===================================================================\n");
                waitForEnter();
                continue;
            }

            printf("I was able to open the file\n\n");
            printf("===================================================================\n");

            fgets(buffer, sizeof(buffer), brwdata);
            printf("\n%s\n", buffer);

            while(fgets(buffer, sizeof(buffer), brwdata)) {
                printf("%s", buffer);

            }
            printf("\n");
            fclose(brwdata);
            printf("===================================================================");

            waitForEnter();

            // return 0;

        } else if (decide == 2){
            printf("You selected Borrow Some Thing (2)");
            waitForEnter();
            printf("\n===================================================================\n\n");
            FILE *srchdata;
            srchdata = fopen("borrowdata.csv", "a");
            if (srchdata == NULL) {
                printf("-Error : Cause by worng name of CSV file or Don't have CSV file!!-\n");
                printf("===================================================================\n");
                return 1;
            }

            printf("Enter [Name Sirname] : ");
            scanf("%1019s %99s", emname, emsirname);

            printf("Enter [Equipment] : ");
            scanf("\n%[^\n]", eqmname);

            printf("Enter Borrow Date [YYYY-MM-DD] : ");
            scanf("\n%10s", brwdate);

            printf("Enter Return Date [YYYY-MM-DD] : ");
            scanf("\n%10s", rtndate);

            strcat(emname, " ");
            strcat(emname, emsirname);
            fprintf(srchdata, "\n%s, %s, %s, %s", emname,eqmname,brwdate,rtndate);

            fclose(srchdata);
            printf("===================================================================\n");
            printf("\nAlready added.\n");
            printf("\n===================================================================");
            waitForEnter();
            continue;

        } else if (decide == 3){
            printf("\n===================================================================\n\n");
            FILE *srchdata = fopen("borrowdata.csv", "r");
            if (srchdata == NULL) {
                printf("################ Error: could not open csv file ################### \n\n-------- File name doesn't match or That file doesn't exit --------\n\n");
                printf("===================================================================\n");
                return 1;
            }


            char line[LINE_SIZE];
            char keyword[1200];
            int found = 0;

            printf("Who/What are you looking for? : ");
            scanf("%s", keyword);
            printf("\n===================================================================\n");

            while(fgets(line, sizeof(line), srchdata)) {

                char line_copy[LINE_SIZE];
                strcpy(line_copy, line);

                char *token = strtok(line_copy, ",");
                while (token != NULL) {
                    if (strstr(token, keyword) != NULL) {
                        found = 1;
                        emp_name = strtok(line, ",");
                        printf("Employee Name : %s\n", emp_name);

                        eqm_name = strtok(NULL, ",");
                        printf("Equipment that they borrow : %s\n", eqm_name);

                        brw_date = strtok(NULL, ",");
                        printf("Borrow date : %s\n", brw_date);

                        rtn_date = strtok(NULL, ",");
                        printf("Return date : %s\n", rtn_date);
                    }
                    token = strtok(NULL, ",");
                }

            } if (!found) {
                printf("Not Found anything about '%s', Maybe wrong input.\n", keyword);
            }
            fclose(srchdata);
            waitForEnter();
            continue;

        } else if (decide == 4){
            printf("\n===================================================================\n\n");

            FILE *brwdata = fopen("borrowdata.csv", "r");
            if (brwdata == NULL) {
                printf("################ Error: could not open csv file ###################\n");
                return 1;
            }

            FILE *tempFile = fopen("temp.csv", "w");
            if (tempFile == NULL) {
                fclose(brwdata);
                printf("################ Error: could not create temp file ################\n");
                return 1;
            }

            char keyword[200];
            char line[LINE_SIZE];
            int found = 0;

            printf("Enter employee name you want to edit: ");
            scanf(" %[^\n]", keyword);

            while (fgets(line, sizeof(line), brwdata)) {
                char line_copy[LINE_SIZE];
                strcpy(line_copy, line);

                char *emp = strtok(line_copy, ",");
                if (emp != NULL && strcmp(emp, keyword) == 0) {
                    found = 1;
                    char newEqm[100], newBrw[20], newRtn[20];

                    printf("\n===================================================================\n\n");
                    printf("-------------------Found '%s'-----------------------------\n", keyword);
                    printf("\n===================================================================\n\n");
                    printf("Enter NEW Equipment : ");
                    scanf(" %[^\n]", newEqm);

                    printf("Enter NEW Borrow Date [YYYY-MM-DD] : ");
                    scanf(" %19s", newBrw);

                    printf("Enter NEW Return Date [YYYY-MM-DD] : ");
                    scanf(" %19s", newRtn);

                    fprintf(tempFile, "%s, %s, %s, %s\n", emp, newEqm, newBrw, newRtn);
                } else {
                    fputs(line, tempFile);
                }
            }

            fclose(brwdata);
            fclose(tempFile);

            if (!found) {
                printf("Not found '%s' in database.\n", keyword);
                remove("temp.csv");
            } else {
                remove("borrowdata.csv");
                rename("temp.csv", "borrowdata.csv");
                printf("\n===================================================================\n\n");
                printf("-------------------------Edit complete!!---------------------------\n");
                printf("\n===================================================================\n\n");
            }
            waitForEnter();
            continue;

        } else if (decide == 5){
            printf("\n===================================================================\n\n");

            FILE *brwdata = fopen("borrowdata.csv", "r");
            if (brwdata == NULL) {
                printf("################ Error: could not open csv file ###################\n");
                return 1;
            }

            char lines[MAX_RECORDS][LINE_SIZE];
            int count = 0;

            while (fgets(lines[count], sizeof(lines[count]), brwdata)) {
                lines[count][strcspn(lines[count], "\n")] = 0;
                count++;
            }
            fclose(brwdata);

            if (count <= 1) {
                printf("No data found in file.\n");
                continue;
            }
            
            char target[100];
            printf("Enter equipment name to delete: ");
            getchar();
            fgets(target, sizeof(target), stdin);
            target[strcspn(target, "\n")] = 0;
            target[strcspn(target, "\r")] = 0;
            target[strcspn(target, " ")] = 0;

            int foundIndex[MAX_RECORDS];
            int foundCount = 0;

            printf("\nMatched record for '%s' : \n", target);
            printf("\n");

            char* trim(char *str) {
                while(*str == ' ') str++;

                char *end = str + strlen(str) - 1;
                while(end > str && (*end == ' ' || *end == '\r' || *end == '\n')) {
                    *end = '\0';
                    end--;
                }
                return str;
            }

            for (int i = 1; i < count; i++){
                char temp[LINE_SIZE];
                strcpy(temp, lines[i]);

                char *emp_name = strtok(temp, ",");
                char *eqm_name = strtok(NULL, ",");
                char *brw_date = strtok(NULL, ",");
                char *rtn_date = strtok(NULL, ",");

                emp_name = emp_name ? trim(emp_name) : "";
                eqm_name = eqm_name ? trim(eqm_name) : "";
                brw_date = brw_date ? trim(brw_date) : "";
                rtn_date = rtn_date ? trim(rtn_date) : "";

                if (strcmp(eqm_name, target) == 0) {
                    foundIndex[foundCount++] = i;
                    printf("[%d] %s - %s - %s to %s\n",
                            foundCount, emp_name, eqm_name, brw_date, rtn_date);
                }
            }

            if (foundCount == 0) {
                printf ("No records found for '%s'.\n", target);
                continue;
            }

            int choice;
            printf("\nEnter record number to delete (1 to %d) : ", foundCount);
            scanf("%d", &choice);

            if (choice < 1 || choice > foundCount) {
                printf("Invalid choice.\n");
                return 0;
            }

            int deleteIndex = foundIndex[choice - 1];

            FILE *out = fopen("borrowdata.csv", "w");
            if (!out) {
                printf("Erorr : Cannot write File.\n");
                return 0;

            }

            for (int i = 0; i < count; i++) {
                if (i == deleteIndex) continue;
                fprintf(out, "%s\n", lines[i]);
            }
            fclose(out);

            printf("\nRecord deleted Successfully!\n");
            printf("\n===================================================================");
            waitForEnter();
            continue;

        }else if (decide == 0){
            break;
        
        } else {
            printf("\n################################################################\n");
            printf("\n#----------Error : Cause by insert incorrect NUMBER!!----------#\n");
            printf("\n################################################################\n");
            waitForEnter();

        }
    }
}

int main(){
    decideThing();
    return 0;

}

// บันทึกข้อมูลการยืมอุปกรณ์ในสำนักงาน ลงในไฟล์ csv