#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int decide;
    char buffer[10000];
    char *emp_name;
    char *eqm_name;
    char *brw_date;
    char *rtn_date;
    char emname[1020];
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
        // printf("\nThe first line is :\n%s\n", buffer);

        while(fgets(buffer, sizeof(buffer), brwdata)) {
            // printf("The rest of the line is :\n%s\n", buffer);

            emp_name = strtok(buffer, ",");
            printf("Employee Name : %s\n", emp_name);

            eqm_name = strtok(NULL, ",");
            printf("Equipment that they need : %s\n", eqm_name);

            brw_date = strtok(NULL, ",");
            printf("Borrow date : %s\n", brw_date);

            rtn_date = strtok(NULL, ",");
            printf("Return date : %s\n", rtn_date);
        }

        fclose(brwdata);

    } else if (decide == 2){
        printf("\n===================================================================\n\n");
        FILE *fop;
        fop = fopen("borrowdata.csv", "a");
        if (fop == NULL) {
            printf("-Error : Cause by worng name of CSV file or Don't have CSV file!!-\n");
            printf("===================================================================\n");
            return 1;
        }

        printf("Enter [Name Sirname] : ");
        scanf("%1019s", emname);

        printf("Enter [Equipment]" : );
        scanf("%49s", eqmname);

        printf("Enter Borrow Date [YYYY-MM-DD] : ");
        scanf("%10s", brwdate);

        printf("Enter Return Date [YYYY-MM-DD] : ");
        scanf("%10s", rtndate);


        fprintf(fop, "%s,%s,%s,%s", emname,eqmname,brwdata,rtndate);

        fclose(fop);
        printf("\nAlready added.\n");
        return 0;

    } else {
        printf("\n################################################################\n");
        printf("\n#----------Error : Cause by insert incorrect NUMBER!!----------#\n");
        printf("\n################################################################\n");

    }

    







    

}

// บันทึกข้อมูลการยืมอุปกรณ์ในสำนักงาน ลงในไฟล์ csv