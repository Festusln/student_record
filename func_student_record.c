#include<stdio.h>
#include "func_student_record.h"

//function to add new student
 void add_student_info (struct student *x)  
 {
     FILE *fp = NULL;
     fp = fopen("file.txt", "a+");
     x = (struct student *)malloc(sizeof(struct student));
     if (fp == NULL)
     {
         perror("Error in opening file\n");
     }
    else
    {
     printf("Enter matric no: ");
     scanf("%d", &x->matric);

     printf("Enter first name: ");
     scanf("%s", x->fname);
   
     printf("Enter last name: ");
     scanf("%s", x->lname);
   
     fprintf(fp, "%d %s %s\n", x->matric, x->fname, x->lname); //printing student info to file

     if (fprintf<0)                                         //Condition to check status of saving student info
     printf("Error in saving the student information\n");
     else
     printf("Student information saved successfully\n");

    }

    fclose(fp);
    free(x);
 }

//function to display all students' information
 void display_student_info(struct student *x)   
 {
    FILE *fp = fopen("file.txt", "r");
    x = (struct student *)malloc(sizeof(struct student));

    while ((fscanf(fp, "%d %s %s", &x->matric, x->fname, x->lname))!=EOF)
    {
        printf("%d %s %s\n", x->matric, x->lname, x->fname);
    }
    free(x);
    fclose(fp);
 }


//function to update students' first and last name
 void update_record (struct student *x)     
  {
    FILE *fp = fopen("file.txt", "r");
    FILE *fp1 = fopen("temp.txt", "a");     //temporary file where data are copied
    x = (struct student *)malloc(sizeof(struct student));
    
    int id = 0;
    printf("Enter matric number whose name is to be updated: ");
    scanf("%d", &id);
    int f =0;        //conditio to check if-else for the entered matric number
    
    while ((fscanf(fp, "%d %s %s", &x->matric, x->fname, x->lname))!=EOF)
    {
        if (x->matric == id)
        {
            f =1;
            char new_fname[10];
            char new_lname[10];
            printf("Enter the new first name: ");
            scanf("%s", new_fname);

            printf("Enter the new last name: ");
            scanf("%s", new_lname);
            
            fprintf(fp1, "%d %s %s\n", x->matric, new_fname, new_lname);
        }
        else
        {
            fprintf(fp1, "%d %s %s\n", x->matric, x->fname, x->lname);
        }
        
    }
        if (f == 0)
        {
            printf("Matric number do not match any existing matric number\n");
        }    

    free(x);
    fclose(fp);
    fclose(fp1);

    fp = fopen("file.txt", "w"); //Opening file.txt in write mode, automatically deleting its current contents
    fp1 = fopen("temp.txt", "r"); //opening temp.txt to read its contents
    
    while (fscanf(fp1, "%d %s %s", &x->matric, x->fname, x->lname)!=EOF)
    {
        fprintf(fp, "%d %s %s\n", x->matric, x->fname, x->lname);       //copying updated data in temp.txt into file.txt
   
    }


    fclose(fp);
    fclose(fp1);
    remove("temp.txt");     //deleting the temporary file (temp.txt).

 }