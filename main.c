#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char buffer[10000];
    char *emp_name;
    char *eqm_name;
    char *brw_date;
    char *rtn_date;

    printf("===================================================================\n\n");
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

    



    // FILE *fop;
    // fop = fopen("borrowdata.csv", "a");
    // if (fop == NULL) {
    //     printf("Error when opening the file!\n");
    //     return 1;
    // }

    // fprintf(fop, "\"Johnny Depp\", \"projecttor\", \"2025-08-01\", \"2025-08-29\"");

    // fclose(fop);
    // printf("\nAlready added.\n");
    // return 0;



    

}

// บันทึกข้อมูลการยืมอุปกรณ์ในสำนักงาน ลงในไฟล์ csv