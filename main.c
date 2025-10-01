#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1200

int main(){

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


    printf("===================================================================\n\n");
    printf("Read a Log -- (1)\nBorrow Some Thing -- (2)\nSearch for Borrow Date -- (3)\nEdit Data -- (4)\n");
    printf("\n===================================================================\n\n");
    printf("What do you want to do [input the number] : ");
    scanf("%d", &decide);
    // printf("%d\n", decide);

    if (decide == 1){
        printf("\n===================================================================\n\n");
        FILE *brwdata = fopen("borrowdata.csv", "r");
        if (brwdata == NULL) {
            printf("################ Error: could not open csv file ################### \n\n-------- File name doesn't match or That file doesn't exit --------\n\n");
            printf("===================================================================\n");
            exit(-1);
        }

        printf("I was able to open the file\n\n");
        printf("===================================================================\n");

        fgets(buffer, sizeof(buffer), brwdata);
        printf("\n%s\n", buffer);

        while(fgets(buffer, sizeof(buffer), brwdata)) {
            printf("%s", buffer);

            // emp_name = strtok(buffer, ",");
            // printf("Employee Name : %s\n", emp_name);

            // eqm_name = strtok(NULL, ",");
            // printf("Equipment that they need : %s\n", eqm_name);

            // brw_date = strtok(NULL, ",");
            // printf("Borrow date : %s\n", brw_date);

            // rtn_date = strtok(NULL, ",");
            // printf("Return date : %s\n", rtn_date);
        }
        printf("\n");

        fclose(brwdata);



    } else if (decide == 2){
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
        scanf("\n%49s", eqmname);

        printf("Enter Borrow Date [YYYY-MM-DD] : ");
        scanf("\n%10s", brwdate);

        printf("Enter Return Date [YYYY-MM-DD] : ");
        scanf("\n%10s", rtndate);

        strcat(emname, " ");
        strcat(emname, emsirname);
        fprintf(srchdata, "\n%s, %s, %s, %s", emname,eqmname,brwdate,rtndate);

        fclose(srchdata);
        printf("\nAlready added.\n");
        return 0;



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

        while(fgets(line, sizeof(line), srchdata)) {
            
            char line_copy[LINE_SIZE];
            strcpy(line_copy, line);

            char *token = strtok(line_copy, ",");
            while (token != NULL) {
                if (strstr(token, keyword) != NULL) {
                    // printf("Found '%s' in data base ---> %s\n", keyword, line);
                    found = 1;
                    emp_name = strtok(line, ",");
                    printf("Employee Name : %s\n", emp_name);

                    eqm_name = strtok(NULL, ",");
                    printf("Equipment that they borrow : %s\n", eqm_name);

                    brw_date = strtok(NULL, ",");
                    printf("Borrow date : %s\n", brw_date);

                    rtn_date = strtok(NULL, ",");
                    printf("Return date : %s\n", rtn_date);
                    // break;
                }
                token = strtok(NULL, ",");
            }

        } if (!found) {
            printf("Not Found anything about '%s', Maybe wrong input.\n", keyword);
        }
        fclose(srchdata);
        return 0;



    } else if (decide == 4){
        printf("\n===================================================================\n\n");
        FILE *srchdata = fopen("borrowdata.csv", "r");
        if (srchdata == NULL) {
            perror("-Error : Cause by worng name of CSV file or Don't have CSV file!!-\n");
            printf("===================================================================\n");
            return 1;
        }

        FILE *tempFile = fopen("borrowdata.csv", "w");
        if (tempFile == NULL) {
            fclose(srchdata);
        }

        char line[LINE_SIZE];

        while (fgets(line, sizeof(line), fp)) {

        }





    } else {
        printf("\n################################################################\n");
        printf("\n#----------Error : Cause by insert incorrect NUMBER!!----------#\n");
        printf("\n################################################################\n");

    }

}

// บันทึกข้อมูลการยืมอุปกรณ์ในสำนักงาน ลงในไฟล์ csv