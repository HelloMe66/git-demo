#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 30
typedef struct student{
    int id;
    int score;
    char name[INITSIZE];
    struct student *next;
}student;
void Initlink(student *s,int n)
{
    int i=0;
    student *p,*q;
    q=s;
    printf("请输入%d个学生的信息: 形式为： 学号 姓名(拼音) 分数 \n",n);
    for (i = 0; i < n; ++i) {
        p=(student*) malloc(sizeof(student));
        scanf("%d%s%d",&p->id,p->name,&p->score);
        p->next=q->next;
        q->next=p;
        q=p;
    }
}
void printNews(student *s)
{
    student *p;
    p=s->next;
    while (p!=NULL)
    {
        printf("%d\t%s\t%d\t\n",p->id,p->name,p->score);
        p=p->next;
    }

}
int searchNew(student *s,student s1)
{
    int count=1;
    student *p=s->next;
    while (p!=NULL)
    {
        if(p->id==s1.id)
        {
            return count;
        }else{
            count++;
            p=p->next;
        }
    }
    return 0;
}
int insertS(student *s,student s1)
{
    student *p,*q;
    q=s;
    p=s->next;
    while(p!=NULL)
    {
        if(p->score<s1.score)//小于s1成绩
        {
            q->next=&s1;
            s1.next=p;
            return 1;
        }else{
            q=p;
            p=p->next;
        }
    }
    q->next=&s1;
    s1.next=p;
    return 1;

}
int deletelink(student *s,int n)
{
    int i=0;
    student *p,*q;
    q=s;
    p=s->next;
    for (i = 1; i < n; ++i) {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    free(p);

}
int orderlink(student *s,int n)
{
    student *p,*q,*minp,*minq,*root;
    minq=minp=root=q=s->next;
    p=q->next;
    s->next=NULL;
    while(root!=NULL)
    {
        while(p!=NULL){
            if(minp->score>p->score){
                minp=p;
                minq=q;
            }
            q=p;
            p=p->next;
        }
        if(minp==root){
            root=root->next;
        }
        if(minp!=minq){
            minq->next=minp->next;
            minp->next=s->next;
            s->next=minp;
        }else{
            minp->next=s->next;
            s->next=minp;
        }
        minp=minq=q=root;
        if(root!=NULL){
            p=q->next;
        }
    }
    return 1;
}
int main()
{
    int n,i=0,option=0;
    student s1;
    student *s;
    s=(student*) malloc(sizeof (student));
    s->next=NULL;
    printf("请输入n:");
    scanf("%d",&n);
    Initlink(s,n);
    printf("请输入功能编号，执行下方功能:\n"
           "1、从链表头开始，遍历输出学生信息\n"
           "2、输入一个学生信息，按学号查找，给出查找结果,如果找到，删除该学生信息；然后遍历输出学生信息\n"
           "3、输入一个学生信息，按成绩插在第一个小于他的成绩前面；然后遍历输出学生信息\n"
           "4、把学生按成绩由高到低排序，输出排序结果\n"
           "5、销毁链表\n");
    printf("请输入：");
    scanf("%d",&option);
    switch (option) {
        case 1:
            printf("功能1：从链表头开始，遍历输出学生信息\n");
            printNews(s);
            break;
        case 2:
            printf("功能2：输入一个学生信息，按学号查找，给出查找结果\n");
            printf("请输入学生信息：形式为： 学号 姓名(拼音) 分数\n");
            scanf("%d%s%d", &s1.id, s1.name, &s1.score);
            i = searchNew(s, s1);
            if (!i) {
                printf("没找到!");
            } else {
                printf("找到啦!\n");
                printf("如果找到，删除该学生信息；然后遍历输出学生信息；\n");
                deletelink(s, i);
                printNews(s);
            }
            break;
        case 3:
            printf("功能3：输入一个学生信息，按成绩插在第一个小于他的成绩前面；然后遍历输出学生信息；\n");
            printf("请输入学生信息：形式为： 学号 姓名(拼音) 分数\n");
            scanf("%d%s%d", &s1.id, s1.name, &s1.score);
            insertS(s, s1);
            printNews(s);
            break;
        case 4:
            printf("功能4：把学生按成绩由高到低排序，输出排序结果\n");
            orderlink(s, n);
            printNews(s);
            break;
        case 5:
            free(s);//销毁
            break;
    }
}
