#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct_student_record.h"
#include "func_student_record.h"
 

int main()
{
    struct student y;
    int choice = 0;

    printf("Menu:\n");
    printf("1: Display Student Information\n");
    printf("2: Add New Student\n");
    printf("3: Update Student Information\n");

    printf("Enter OPtion: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            display_student_info(&y);
            break;

        case 2:
            add_student_info (&y);
            break;

        case 3:
            update_record (&y);
            break;

        Default:
            printf("Invalid selection\n");
            break;
    }
    
    return 0;
}