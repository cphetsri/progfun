#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("===================================================================\n\n");

    FILE *brwdata = fopen("borrowdata.csv", "r");
    if (brwdata == NULL) {
        printf("################ Error: could not open csv file ################### \n\n-------- File name doesn't match or That file doesn't exit --------\n\n");
        printf("===================================================================\n");
        exit(-1);
    }

    printf("I was able to open the file\n\n");
    printf("===================================================================\n");




    // FILE *fop;
    // fop = fopen("borrowdata.csv", "a");
    // if (fop == NULL) {
    //     printf("Error when opening the file!\n");
    //     return 1;
    // }

    // fprintf(fop, "Johnny Depp, projecttor, 2025-08-01, 2025-08-29");

    // fclose(fop);
    // printf("\nAlready added.");
    // return 0;



    

}

// บันทึกข้อมูลการยืมอุปกรณ์ในสำนักงาน ลงในไฟล์ csv