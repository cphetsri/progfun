#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("===================================================================\n\n");

    FILE *brwdata = fopen("borrowdfsdata.csv", "r");
    if (brwdata == NULL) {
        printf("################ Error: could not open csv file ################### \n\n-------- File name doesn't match or That file doesn't exit --------\n\n");
        printf("===================================================================\n");
        exit(-1);
    }

    printf("I was able to open the file\n");
    printf("===================================================================\n");
}

// บันทึกข้อมูลการยืมอุปกรณ์ในสำนักงาน ลงในไฟล์ csv