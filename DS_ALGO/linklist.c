#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
    int rollno;
    char name[30];
    double marks;
    struct student *next;
};

int main()
{
     struct student *p;
     p=(struct student*)malloc(sizeof(struct student));
     p->rollno=101;
     strcpy(p->name,"gondya prashantta khandekar");
     p->marks=90;
     
     p->next=(struct student*)malloc(sizeof(struct student));
     p->next->rollno=105;
     strcpy(p->next->name,"ketan kishor more");
     p->next->marks=79;
     p->next->next=NULL;
     
     printf("%d\t%s\t%lf\t\n",p->rollno,p->name,p->marks);
     printf("%d\t%s\t%lf\t\n",p->next->rollno,p->next->name,p->next->marks);
     
     return 0;
}

