

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Maryam Habibiollahi
//Pointers (part 2)

/*---------------------------------------------------------------------------------*/
                                    /*Functions*/
/*---------------------------------------------------------------------------------*/


struct student_records {
    
    char student_name[30];
    int student_number;
    float course_marks[5];
    struct student_records *next;
};

FILE *fp; // pointer to file where data is saved

struct student_records *root=0; //first unchanging node
struct student_records *s_r; //pointer to new cell
struct student_records *t; //pointer after new cell
struct student_records *v; //pointer before new cell

int c_n, n;
char l[30];

/*****************************************************/

void options()
{
    printf("\n\n ********************* \n\n Please choose one of the following \n\n 1)Introduce new student \n 2)Remove student \n 3)Print student report \n 4)Print report for all students \n 5)Save to file \n 6)Retrieve data from file \n 7)Exit \n\n");
}

/*****************************************************/

void insert()
{
    
    if (root==0) {
        
        root = s_r; //s_r points to a cell after root
        s_r->next = 0;
    }
    
    else
    {
        if (strcmp(s_r->student_name,root->student_name)<0) //for s_r being he first (smallest) cell
        {
            s_r->next=root;
            root=s_r;
        }
        
        else
        {
            t=root->next;
            v=root;
            
            
            while(t!=0 && strcmp(s_r->student_name,t->student_name)>=0)
            {
                v=t;
                t=t->next;
            }
            
            if (strcmp(s_r->student_name,v->student_name)==0)
            {
                printf(" \n");
            }
            
            
            else {
                v->next = s_r; //for s_r somewhere in the middle/ at the end
                s_r->next = t;
            }
        }
    }
}

/*****************************************************/

void main_menu(int i)
{
    
    while (i!=7) {
        printf("\nEnter option (0 to view options)\n");
        scanf("%d",&i);
        
                switch(i) {
                        
                    case 0: //main menu
                        options();
                        
                        break;
                        
                    case 1: //introduce student with marks
                        
                        s_r = (struct student_records*)malloc(sizeof(struct student_records));
                        s_r->next=0;
                        
                        printf("Enter the student's number:");
                        scanf("%d",&s_r->student_number);
                        
                        printf("Enter the student's name:");
                        scanf("%s",s_r->student_name);
                        
                        if (root) {
                            t=root; v=root;
                        
                            while(t!=0 && strcmp(s_r->student_name,t->student_name)>=0) { 
                                v=t;
                                t=t->next;
                            }
                            
                            if (strcmp(s_r->student_name,v->student_name)==0) {
                                printf("This student has already been added\n");
                            }
                            else {
                            printf("\nEnter the five course grades\n");
                            
                            for (c_n=0; c_n<=4; c_n++) {
                                printf("Course %d:",c_n+1);
                                scanf("%f",&s_r->course_marks[c_n]);
                            }
                            }
                        }
                        else {
                            printf("\nEnter the five course grades\n");
                        
                            for (c_n=0; c_n<=4; c_n++) {
                                printf("Course %d:",c_n+1);
                                scanf("%f",&s_r->course_marks[c_n]);
                            }
                        }
                        insert();
        
        
                        break;
                    
                    case 2: //remove student
                        
                        
                        if (root==0) {
                            printf("No students added yet\n");
                        }
                        
                        else {
                            printf("Enter the student name\n");
                            scanf("%s",l);
                            
                            t=root; v=root;
                            
                            while(t!=0 && strcmp(l,t->student_name)>0 ) {
                                v=t;
                                t=t->next;
                            }
                            
                            
                            if(t) {
                                if (strcmp(l,t->student_name)==0)
                                {
                                    if (v==t)  // removing the first node
                                    {
                                        root=t->next;
                                        free(v);
                                        printf("Student %s has been deleted\n",v->student_name);
                                    }
                                    else {
                                        v->next = t->next;
                                        free(t);
                                        printf("Student %s has been deleted\n",t->student_name);
                                    }
                                }
                                
                                else {
                                    printf("No such student has been added to the library\n");
                                }
                            }
                            
                            else {
                                printf("No such student has been added to the library\n");
                            }
                        }
                
                        break;
                        
                        
                    case 3: //print student report
                        
                        if (root==0) {
                            printf("No students added yet\n"); // WORKS :)
                        }
                        
                        else {
                            printf("Enter the student's name\n");
                            scanf("%s",l);
                            
                            t=root; v=root;
                            
                            while (t!=0 && strcmp(l,t->student_name)>0) {
                                
                                v=t;
                                t=t->next;
                            }
                            
                            if (t) {
                                if (strcmp(l,v->student_name)==0)
                                {
                                    
                                    printf("\nStudent %s with SN %d has the following marks: %f, %f, %f, %f, %f\n\n", v->student_name, v->student_number, v->course_marks[0], v->course_marks[1], v->course_marks[2], v->course_marks[3], v->course_marks[4]);
                                }
                                
                                else {
                                    if (strcmp(l,t->student_name)==0) {
                                        printf("\nStudent %s with SN %d has the following marks: %f, %f, %f, %f, %f\n\n", t->student_name, t->student_number, t->course_marks[0], t->course_marks[1], t->course_marks[2], t->course_marks[3], t->course_marks[4]);
                                    }
                                    else {
                                        printf("No such student has been added to the library\n");
                                    }
                                    
                                }
                            }
                            else {
                                printf("No such student has been added to the library\n");
                            }
                        }
        
                        
                        break;
                        
                    case 4: //print report of all students

                        if (root==0) {
                            printf("No students added yet\n"); // EVERYTHING WORKS HERE \(^o^)/
                        }
                        
                        else {
                            printf("\nStudent        Student number              marks\n\n");
                            
                            t=root;
                            
                            while (t!=0) {
                                
                                printf("%s            %d            %f, %f, %f, %f, %f\n",t->student_name, t->student_number, t->course_marks[0], t->course_marks[1], t->course_marks[2], t->course_marks[3], t->course_marks[4]);
                                
                                
                                t = t->next;
                            }
                        }
                        
                        break;
                        
                    case 5: //save to file
                        
                        fp = fopen("Student_Records","w");
                        
                        
                        t=root;
                        
                        if (fp != NULL) {
                            
                            while (t!=0) {
                                
                                fwrite(t, sizeof(struct student_records), 1, fp);
                                
                                t=t->next;
                            }
                            
                            fclose(fp);
                            printf("data has been saved to file\n");
                        }
                        
                        else {
                            printf("ERROR!");
                        }
                        
                        break;
                        
                        
                    case 6: //retrieve data from file
                        
                        fp = fopen("Student_Records","rb");
                        
                        s_r = (struct student_records*)malloc(sizeof(struct student_records));
                        s_r->next=0;
                        
                        if (fp != NULL) {
                            
                            while(fread(s_r, sizeof(struct student_records), 1, fp) ==1)
                            {
                                
                                printf("%s       %d          %f, %f, %f, %f, %f\n",s_r->student_name, s_r->student_number, s_r->course_marks[0], s_r->course_marks[1], s_r->course_marks[2], s_r->course_marks[3], s_r->course_marks[4]);
                                insert();
                                s_r=malloc(sizeof(struct student_records));
                                
                            }
                            fclose(fp);
                        }
                        else {
                            printf("File not found!\n");
                        }
                        
                        break;
                }
    }
}


/*----------------------------------------------------------------------------------*/
                                        /*Main*/
/*----------------------------------------------------------------------------------*/
                        
int main()
{
    
    int a;
    options();
    
    
    //call the menu function
    main_menu(a);
    
}

