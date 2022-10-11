#include<stdio.h>
#include<stdlib.h>        //ʹ��malloc�����Լ�exit����
#include<string.h>

typedef struct COURSE     //��¼���γ����Ƽ���ƽ���ֵĽṹ��
{
    char course_name[50];    //course_name����ÿγ�����
    double course_ave;        //course_ave����ÿγ̵�ƽ����
    char max_name[20];        //max_name����ÿγ���߷ֵ�������
    double course_max;        //course_max�ÿγ���߷�
    int rank[5];            //ѧ����,��,��,����,�����������
} CLASS;
typedef struct course     //��¼ѧ���Ŀγ����ƺ͸ÿγ̷����Ľṹ��
{
    char course_name[50];
    double course_score;
} COU;
typedef struct student     //��¼ѧ����Ϣ�Ľṹ��
{
    int ID;                    //ѧ��ѧ��
    char name[20];                //ѧ������
    double ave;                    //ѧ��ƽ����
    double sum;                    //ѧ���ܷ�
    COU course[20];                //ѧ�����Ը��ſγ����
    struct student *next;        //nextָ��ָ����һ�����
} STU;

int menu();     //�˵�����
STU *Creat_sutdent1(STU *head);      //�Ӽ���������ѧ����Ϣ�ĺ���
STU *Creat_sutdent2(STU *head);     //���ļ������ѧ����Ϣ�ĺ���
STU *Del_student1(STU *head);      //��ѧ��ɾ��ѧ����Ϣ�ĺ���
STU *Del_student2(STU *head);      //������ɾ��ѧ����Ϣ�ĺ���
STU *Insert_student1(STU *head);     //��ѧ�Ų���ѧ����Ϣ�ĺ���
STU *Insert_student2(STU *head);     //����������ѧ����Ϣ�ĺ���
STU *Search_student1(STU *head);     //��ѧ�Ų���ѧ����Ϣ�ĺ���
STU *Search_student2(STU *head);     //����������ѧ����Ϣ�ĺ���
void *Rank_student(STU *head);       //�ɼ�������
void BubbleSort1(STU *head, int score_num);      //��ĳ�ųɼ�ð��������
void BubbleSort2(STU *head);     //���ܳɼ�ð��������
void print1(STU *head);     //��ʾѧ����Ϣ����Ļ�ĺ���
void print2(STU *head);        //��ʾѧ����Ϣ���ļ��ĺ���
CLASS class_num[20];
int course_num;     //�γ�����
int stu_num;     //ѧ������

int main() {
    int select, op;     //select����˵���ѡ�op�������ڲ���ĳЩѡ��
    STU *head;        //headͷ���
    STU *p;            //�����е���ʱ���
    head = NULL;        //head��㸳��ֵ
    while (true) {
        system("CLS");    //��������
        select = menu();        //���ò˵�����
        if (select == 0) break;
        switch (select) {
            case 1:
                system("CLS");    //��������
                head = Creat_sutdent1(head);    //����ѧ���ɼ�ϵͳ
                break;
            case 2:
                system("CLS");    //��������
                head = Creat_sutdent2(head);    //����ѧ���ɼ�ϵͳ
                break;
            case 3:
                system("CLS");    //��������
                if (head == NULL) {  //����ɼ�ϵͳ��û��ѧ����Ϣ,����ʾ�û�������ѧ����Ϣ
                    printf("��������ѧ����Ϣ!\n");
                }
                else {
                    system("CLS");     //��������
                    p = head->next;
                    print1(head);        //��ʾѧ����Ϣ����Ļ
                }
                break;
            case 4:
                system("CLS");    //��������
                if (head == NULL) {      //����ɼ�ϵͳ��û��ѧ����Ϣ,����ʾ�û�������ѧ����Ϣ
                    printf("��������ѧ����Ϣ!\n");
                }
                else {
                    system("CLS");     //��������
                    p = head->next;
                    print2(head);        //��ʾѧ����Ϣ���ļ�
                }
                break;
            case 5:
                system("CLS");    //��������
                printf("������ɾ����ʽ:\n");
                printf("1.��ѧ��ɾ��\n");
                printf("2.������ɾ��\n");
                scanf("%d", &op);
                if (op == 1){
                    head = Del_student1(head);     //��ѧ��ɾ��ѧ����Ϣ
                }
                else{
                    head = Del_student2(head);     //������ɾ��ѧ����Ϣ
                }
                break;
            case 6:
                system("CLS");    //��������
                printf("��ѡ�����ķ�ʽ:\n");
                printf("1.��ѧ�Ų���\n");
                printf("2.����������\n");
                scanf("%d", &op);
                if (op == 1){
                    head = Insert_student1(head);     //��ѧ�Ų���ѧ����Ϣ
                }
                else{
                    head = Insert_student2(head);     //����������ѧ����Ϣ
                }
                break;
            case 7:
                system("CLS");    //��������
                printf("��ѡ����ҵķ�ʽ:\n");
                printf("1.��ѧ�Ų���\n");
                printf("2.����������\n");
                scanf("%d", &op);
                if (op == 1){
                    head = Search_student1(head);     //��ѧ�Ų���ѧ����Ϣ
                }
                else{
                    head = Search_student2(head);     //����������ѧ����Ϣ
                }
                break;
            case 8:
                system("CLS");    //��������
                Rank_student(head);     //�ɼ�������
                break;
        }
        printf("�밴Enter������\n");
        getchar();
    }
    return 0;
}

int menu()        //�˵�����
{
    int choice;
    printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
    printf("~*--------С�ͽ������ϵͳ---------*~\n");
    printf("~*       1.�Ӽ������ѧ����Ϣ      *~\n");
    printf("~*       2.���ļ����ѧ����Ϣ      *~\n");
    printf("~*       3.��ʾѧ����Ϣ����Ļ      *~\n");
    printf("~*       4.��ʾѧ����Ϣ���ļ�      *~\n");
    printf("~*       5.ɾ��ѧ����Ϣ            *~\n");
    printf("~*       6.����ѧ����Ϣ            *~\n");
    printf("~*       7.����ѧ����Ϣ            *~\n");
    printf("~*       8.�ɼ�����                *~\n");
    printf("~*       0.�˳�                    *~\n");
    printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
    printf("������ѡ��:");
    scanf("%d", &choice);
    getchar();
    return choice;
}

STU *Creat_sutdent1(STU *head)    //���ѧ����Ϣ�ĺ���
{
    STU *p1 = NULL;
    STU *p2 = NULL;
    int i, j, k;
    head = (STU *) malloc(sizeof(STU));
    p2 = head;
    printf("��������ѧ������:");        //���뱾�ο���ѧ��������
    scanf("%d", &stu_num);
    printf("�����뱾��ѧ���μӿγ̿��Ե���Ŀ:");    //���뱾�ο��Կγ�����
    scanf("%d", &course_num);
    getchar();
    printf("�����뱾�θ��ſγ̿��Ե�����:\n");        //���뱾�ο��Ը��γ�����
    for (i = 0; i < course_num; i++) {
        printf("��%d�ſγ�:", i + 1);
        gets(class_num[i].course_name);
        class_num[i].course_ave = 0;        //��ʼ���ÿγ̵�ƽ����
        class_num[i].course_max = 0;        //��ʼ���ÿγ̵���߷�
        for (k = 0; k < 5; k++){
            class_num[i].rank[k] = 0;            //��ʼ���ÿγ̵ĸ��ȼ�����
        }
    }
    for (i = 0; i < stu_num; i++) {
        system("CLS");            //��������
        p1 = (STU *) malloc(sizeof(STU));
        p2->next = p1;
        printf("�������%d��ѧ������Ϣ:\n", i + 1);
        printf("ѧ��:");
        scanf("%d", &p1->ID);
        printf("����:");
        getchar();
        gets(p1->name);
        p1->sum = 0;
        for (j = 0; j < course_num; j++) {
            printf("������%s�ɼ�:", class_num[j].course_name);
            scanf("%lf", &p1->course[j].course_score);
            if (p1->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
                class_num[j].rank[0]++;
            else if (p1->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
                class_num[j].rank[1]++;
            else if (p1->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
                class_num[j].rank[2]++;
            else if (p1->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
                class_num[j].rank[3]++;
            else
                class_num[j].rank[4]++;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
            if (p1->course[j].course_score > class_num[j].course_max) {
                class_num[j].course_max = p1->course[j].course_score;
                strcpy(class_num[j].max_name, p1->name);
            }
            strcpy(p1->course[j].course_name, class_num[j].course_name);
            p1->sum += p1->course[j].course_score;
            class_num[j].course_ave += p1->course[j].course_score;

        }
        p1->ave = p1->sum / course_num;
        p2 = p1;
    }
    for (j = 0; j < course_num; j++) {
        class_num[j].course_ave /= stu_num;
    }
    p1->next = NULL;
    return head;
}

STU *Creat_sutdent2(STU *head)    //���ѧ����Ϣ�ĺ���
{
    FILE *fp;            //�ļ�ָ��fp
    char file_name[100] = "\0";
    printf("�������ļ�����λ�ü�����\n");
    printf("(just like D:\\\\file.txt)\n");
    gets(file_name);    //��ȡһ��ָ�����ı��ļ�
    //����ļ��޷������򿪣���fopen()��������NULLָ��
    if ((fp = fopen(file_name, "r+")) == NULL) {
        printf("���ļ�:%s ʧ��!!!\n", file_name);
        exit(0);        //exit(0)��ʾ�������г����˳�����
    }
    STU *p1 = NULL;
    STU *p2 = NULL;
    int i, j, k;
    head = (STU *) malloc(sizeof(STU));
    p2 = head;
    printf("��������ѧ������:");        //���뱾�ο���ѧ��������
    scanf("%d", &stu_num);
    printf("�����뱾��ѧ���μӿγ̿��Ե���Ŀ:");    //���뱾�ο��Կγ�����
    scanf("%d", &course_num);
    getchar();
    printf("�����뱾�θ��ſγ̿��Ե�����:\n");        //���뱾�ο��Ը��γ�����
    for (i = 0; i < course_num; i++) {
        printf("��%d�ſγ�:", i + 1);
        gets(class_num[i].course_name);
        class_num[i].course_ave = 0;        //��ʼ���ÿγ̵�ƽ����
        class_num[i].course_max = 0;        //��ʼ���ÿγ̵���߷�
        for (k = 0; k < 5; k++) {
            class_num[i].rank[k] = 0;            //��ʼ���ÿγ̵ĸ��ȼ�����
        }
    }
    for (i = 0; i < stu_num; i++) {
        system("CLS");            //��������
        p1 = (STU *) malloc(sizeof(STU));
        p2->next = p1;
        fscanf(fp, "%d", &p1->ID);
        fscanf(fp, "%s", p1->name);
        p1->sum = 0;
        for (j = 0; j < course_num; j++) {
            fscanf(fp, "%lf", &p1->course[j].course_score);
            if (p1->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
                class_num[j].rank[0]++;
            else if (p1->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
                class_num[j].rank[1]++;
            else if (p1->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
                class_num[j].rank[2]++;
            else if (p1->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
                class_num[j].rank[3]++;
            else
                class_num[j].rank[4]++;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
            //�����ѧ�����ųɼ�����߷�Ҫ�ߣ�����߷�Ϊ��ѧ��
            if (p1->course[j].course_score > class_num[j].course_max) {
                class_num[j].course_max = p1->course[j].course_score;
                strcpy(class_num[j].max_name, p1->name);
            }
            strcpy(p1->course[j].course_name, class_num[j].course_name);
            p1->sum += p1->course[j].course_score;        //��ѧ����ǰ�ּܷ��ϴ��ſγ̷���
            class_num[j].course_ave += p1->course[j].course_score;    //���ſγ�ƽ���ּ��ϴ�ѧ�����ųɼ�
        }
        p1->ave = p1->sum / course_num;        //�����ѧ��ƽ����
        p2 = p1;
    }
    for (j = 0; j < course_num; j++) {
        class_num[j].course_ave /= stu_num;        //�������пγ̵�ƽ����
    }
    p1->next = NULL;
    fclose(fp);
    return head;
}

void print1(STU *head)            //��ʾѧ����Ϣ����Ļ�ĺ���
{
    STU *p;
    int j;
    int n = 9, i;
    p = head->next;
    printf("ȫ��ѧ����Ϣ:\n");
    printf("---ѧ��---------����-");
    for (j = 0; j < course_num; j++) {
        for (i = 0; i < n; i++)     //���Ƹ�ʽ
            printf("-");
        printf("%s", class_num[j].course_name);
    }
    printf("---------�ܷ�--------ƽ����----");
    printf("\n");
    while (p != NULL)            //���ѧ����Ϣ
    {
        printf("%11d", p->ID);
        printf("%10s", p->name);
        for (j = 0; j < course_num; j++){
            printf("%12.2lf", p->course[j].course_score);
        }
        printf("%13.2lf", p->sum);
        printf("%12.2lf", p->ave);
        p = p->next;
        printf("\n");
    }
    printf(" ����ƽ����");            //�������ƽ����
    n = 17;     //���Ƹ�ʽ
    for (j = 0; j < course_num; j++) {
        if (j > 0)     //���Ƹ�ʽ
            n = 7;
        for (i = 0; i < n; i++)     //���Ƹ�ʽ
            printf(" ");
        printf("%.2lf", class_num[j].course_ave);
    }
    printf("\n");
    printf("������߷�:  ");
    for (j = 0; j < course_num; j++)        //���������߷�
    {
        printf("%s:%s(%.2lf)   ", class_num[j].course_name, class_num[j].max_name, class_num[j].course_max);
    }
    printf("\n");
    printf("���Ƹ��������������:  \n");    //������Ƹ��������������

    for (j = 0; j < course_num; j++) {
        int stu_pass = 0;
        for (int l = 0; l < 4; l++){
            stu_pass += class_num[j].rank[l];
        }
        printf("%s:     ", class_num[j].course_name);
        printf("��(%2d��)     ��(%2d��)     ", class_num[j].rank[0], class_num[j].rank[1]);
        printf("��(%2d��)     ����(%2d��)     ������(%2d��)     ", class_num[j].rank[2], class_num[j].rank[3],
               class_num[j].rank[4]);
        printf("�ܼ���(%2d��)     ������(%4.2lf%%)\n", stu_pass, stu_pass * 1.0 / stu_num * 100);
    }
}

void print2(STU *head)            //��ʾѧ����Ϣ���ļ��ĺ���
{
    STU *p;
    FILE *fb;
    if ((fb = fopen("D:\\��Ϣ.txt", "w")) == NULL) {
        printf("���ļ�: ��Ϣ.txt ʧ��!!!\n");
        exit(0);        //exit(0)��ʾ�������г����˳�����
    }
    int j;
    int n = 9, i;
    p = head->next;
    fprintf(fb, "ȫ��ѧ����Ϣ:\n");
    fprintf(fb, "---ѧ��---------����-");
    for (j = 0; j < course_num; j++) {
        for (i = 0; i < n; i++)     //���Ƹ�ʽ
            fprintf(fb, "-");
        if (n < 9)     //���Ƹ�ʽ
            n++;
        fprintf(fb, "%s", class_num[j].course_name);
    }
    fprintf(fb, "---------�ܷ�--------ƽ����----");
    fprintf(fb, "\n");
    while (p != NULL)                //���ѧ����Ϣ
    {
        fprintf(fb, "%8d", p->ID);
        fprintf(fb, "%12s", p->name);
        for (j = 0; j < course_num; j++)
            fprintf(fb, "%13.2lf", p->course[j].course_score);
        fprintf(fb, "%13.2lf", p->sum);
        fprintf(fb, "%12.2lf", p->ave);
        p = p->next;
        fprintf(fb, "\n");
    }
    fprintf(fb, "����ƽ����:  ");                //�������ƽ����
    for (j = 0; j < course_num; j++) {
        fprintf(fb, "%s(%.2lf)   ", class_num[j].course_name, class_num[j].course_ave);
    }
    fprintf(fb, "\n");
    fprintf(fb, "������߷�:  ");                //���������߷�
    for (j = 0; j < course_num; j++) {
        fprintf(fb, "%s:%s(%.2lf)   ", class_num[j].course_name, class_num[j].max_name, class_num[j].course_max);
    }
    fprintf(fb, "\n");
    fprintf(fb, "���Ƹ��������������:  \n");            //������Ƹ��������������

    for (j = 0; j < course_num; j++) {
        int stu_pass = 0;
        for (int l = 0; l < 4; l++)
            stu_pass += class_num[j].rank[l];
        fprintf(fb, "%s:     ", class_num[j].course_name);
        fprintf(fb, "��(%2d��)     ��(%2d��)     ", class_num[j].rank[0], class_num[j].rank[1]);
        fprintf(fb, "��(%2d��)     ����(%2d��)     ������(%2d��)     ", class_num[j].rank[2], class_num[j].rank[3],
                class_num[j].rank[4]);
        fprintf(fb, "�ܼ���(%2d��)     ������(%4.2lf%%)\n", stu_pass, stu_pass * 1.0 / stu_num * 100);
    }
    fclose(fb);
}

STU *Del_student1(STU *head)     //��ѧ��ɾ��ѧ����Ϣ�ĺ���
{
    struct student *p1;     //p1���浱ǰ��Ҫ���Ľڵ�ĵ�ַ
    struct student *p2;     //p2���浱ǰ�����Ľڵ�ĵ�ַ
    int ID;
    int j, op1 = 1;
    if (head == NULL)     //�ǿ�����
    {
        printf("ѧ����Ϣ������!\n");
        return head;
    }
    while (op1) {
        printf("������Ҫɾ��ѧ����ѧ��:");
        scanf("%d", &ID);     //����Ҫɾ��ѧ����ѧ��
        p1 = head;
        while (p1->ID != ID && p1->next != NULL)     //p1ָ��Ľڵ㲻����Ҫ���ҵģ��������������һ���ڵ㣬�ͼ���������
        {
            p2 = p1;     //���浱ǰ�ڵ�ĵ�ַ
            p1 = p1->next;     //����һ���ڵ�
        }
        if (p1->ID == ID)     //�ҵ���
        {
            if (p1 == head)      //���Ҫɾ���Ľڵ��ǵ�һ���ڵ�
            {
                head = p1->next;     //ͷָ��ָ���һ���ڵ�ĺ�һ���ڵ㣬Ҳ���ǵڶ����ڵ㡣������һ���ڵ�Ͳ��������У���ɾ��
            } else     //����������ڵ㣬����ԭ��ָ��ǰ�ڵ��ָ�룬ָ��������һ���ڵ㣬���ɾ��
            {
                p2->next = p1->next;
            }
            stu_num--;     //ѧ��������֮��һ
            for (j = 0; j < course_num; j++)     //���¼�����ſγ̵�ƽ����,��߷�,���ȼ�����
            {
                if (strcmp(p1->name, class_num[j].max_name) == 0)        //���ɾ����ѧ��Ϊĳ�ſγ̵���߷�
                {
                    class_num[j].course_max = 0;
                    STU *p2 = head;
                    while (p2->next != NULL)                        //����Ѱ����߷ֵ�ѧ��
                    {
                        if (p2->course[j].course_score > class_num[j].course_max) {
                            class_num[j].course_max = p2->course[j].course_score;
                            strcpy(class_num[j].max_name, p2->name);
                        }
                        p2 = p2->next;
                    }

                }
                if (p1->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
                    class_num[j].rank[0]--;
                else if (p1->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
                    class_num[j].rank[1]--;
                else if (p1->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
                    class_num[j].rank[2]--;
                else if (p1->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
                    class_num[j].rank[3]--;
                else
                    class_num[j].rank[4]--;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
                class_num[j].course_ave = class_num[j].course_ave * (stu_num + 1) - p1->course[j].course_score;
                class_num[j].course_ave = class_num[j].course_ave / stu_num;
            }
            printf("ѧ��:%s(ѧ��Ϊ%d)�Ѿ��Ӹóɼ�����ϵͳ��ɾ��\n", p1->name, p1->ID);
            free(p1);     //�ͷŵ�ǰ�ڵ�
            p1 = NULL;
        } else     //û���ҵ��������ѧ�Ų�����
        {
            printf("ѧ��%d������", ID);
        }
        printf("�Ƿ������ɾ��?(�������ɾ��������1,��������0)");
        scanf("%d", &op1);
        system("CLS");    //��������
    }
    return head;
}

STU *Del_student2(STU *head)     //������ɾ��ѧ����Ϣ�ĺ���
{
    struct student *p1;     //p1���浱ǰ��Ҫ���Ľڵ�ĵ�ַ
    struct student *p2;     //p2���浱ǰ�����Ľڵ�ĵ�ַ
    char name[20];
    int j, op1 = 1;
    if (head == NULL)     //�ǿ�����
    {
        printf("������ʧ��!\n");
        return head;
    }
    while (op1) {
        printf("������Ҫɾ��ѧ��������:");
        getchar();
        gets(name);     //����Ҫɾ��ѧ��������
        p1 = head;
        while (strcmp(p1->name, name) != 0 && p1->next != NULL)     //p1ָ��Ľڵ㲻����Ҫ���ҵģ��������������һ���ڵ㣬�ͼ���������
        {
            p2 = p1;     //���浱ǰ�ڵ�ĵ�ַ
            p1 = p1->next;     //����һ���ڵ�
        }
        if (strcmp(p1->name, name) == 0)     //�ҵ���
        {
            if (p1 == head)     //���Ҫɾ���Ľڵ��ǵ�һ���ڵ�
            {
                head = p1->next;     //ͷָ��ָ���һ���ڵ�ĺ�һ���ڵ㣬Ҳ���ǵڶ����ڵ㡣������һ���ڵ�Ͳ��������У���ɾ��
            } else     //����������ڵ㣬����ԭ��ָ��ǰ�ڵ��ָ�룬ָ��������һ���ڵ㣬���ɾ��
            {
                p2->next = p1->next;
            }
            stu_num--;     //ѧ��������֮��һ
            for (j = 0; j < course_num; j++)     //���¼�����ſγ̵�ƽ����,��߷�,���ȼ�����
            {
                if (strcmp(p1->name, class_num[j].max_name) == 0)        //���ɾ����ѧ��Ϊĳ�ſγ̵���߷�
                {
                    class_num[j].course_max = 0;
                    STU *p2 = head;
                    while (p2->next != NULL)                        //����Ѱ����߷ֵ�ѧ��
                    {
                        if (p2->course[j].course_score > class_num[j].course_max) {
                            class_num[j].course_max = p2->course[j].course_score;
                            strcpy(class_num[j].max_name, p2->name);
                        }
                        p2 = p2->next;
                    }

                }
                if (p1->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
                    class_num[j].rank[0]--;
                else if (p1->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
                    class_num[j].rank[1]--;
                else if (p1->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
                    class_num[j].rank[2]--;
                else if (p1->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
                    class_num[j].rank[3]--;
                else
                    class_num[j].rank[4]--;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
                class_num[j].course_ave = class_num[j].course_ave * (stu_num + 1) - p1->course[j].course_score;
                class_num[j].course_ave = class_num[j].course_ave / stu_num;
            }
            printf("ѧ��:%s(ѧ��Ϊ%d)�Ѿ��Ӹóɼ�����ϵͳ��ɾ��\n", p1->name, p1->ID);
            free(p1);     //�ͷŵ�ǰ�ڵ�
            p1 = NULL;

        } else     //û���ҵ��������ѧ�Ų�����
        {
            printf("����%s������", name);
        }
        printf("�Ƿ������ɾ��?(�������ɾ��������1,��������0)");
        scanf("%d", &op1);
        system("CLS");    //��������
    }
    return head;
}

STU *Insert_student1(STU *head)     //��ѧ�Ų���ѧ����Ϣ�ĺ���
{
    int ID, op, j, op1 = 1;
    while (op1) {
        STU *p1 = NULL, *p2 = NULL;     //p1���浱ǰ��Ҫ���Ľڵ�ĵ�ַ
        STU *stu;
        stu = (STU *) malloc(sizeof(STU));
        printf("������Ҫ����λ�õ�ѧ��:");
        scanf("%d", &ID);             //���������λ�õ�ѧ��
        printf("������ڸ�ѧ��ǰ�滹�Ǻ���:");
        printf("1.ǰ��:");
        printf("2.����:");
        scanf("%d", &op);
        printf("��������������ѧ������Ϣ:\n");
        printf("ѧ��:");
        scanf("%d", &stu->ID);
        getchar();
        printf("����:");
        gets(stu->name);
        stu->sum = 0;
        for (j = 0; j < course_num; j++)      //���¼�����ſγ̵�ƽ����,��߷�,���ȼ�����
        {
            printf("������%s����:", class_num[j].course_name);
            scanf("%lf", &stu->course[j].course_score);
            strcpy(stu->course[j].course_name, class_num[j].course_name);
            stu->sum += stu->course[j].course_score;
            class_num[j].course_ave = class_num[j].course_ave * stu_num + stu->course[j].course_score;
            if (stu->course[j].course_score > class_num[j].course_max)        //����¼����ѧ�����ųɼ���֮ǰ��߳ɼ�Ҫ��,���ѧ��Ϊ���ſγ���߷�
            {
                class_num[j].course_max = stu->course[j].course_score;
                strcpy(class_num[j].max_name, stu->name);
            }
            if (stu->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
                class_num[j].rank[0]++;
            else if (stu->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
                class_num[j].rank[1]++;
            else if (stu->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
                class_num[j].rank[2]++;
            else if (stu->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
                class_num[j].rank[3]++;
            else
                class_num[j].rank[4]++;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
        }
        stu->ave = stu->sum / course_num;
        stu_num++;     //ѧ��������֮��һ
        for (j = 0; j < course_num; j++)
            class_num[j].course_ave /= stu_num;
        if (head == NULL)      //��������ǿձ���ֱ�Ӳ���
        {
            head = stu;
            stu->next = NULL;
        } else {
            p1 = head;
            while (p1->ID != ID && p1->next != NULL)     //p1ָ��Ľڵ㲻����Ҫ���ҵģ��������������һ���ڵ㣬����������
            {
                p2 = p1;
                p1 = p1->next;     //����һ���ڵ�
            }
            if (p1->ID == ID)      //�ҵ���
            {
                if (op == 2)      //�����ں���
                {
                    stu->next = p1->next;      //��Ȼstu����һ�ڵ���ԭp1��next
                    p1->next = stu;      //�����ԭp1����һ�ڵ����Ҫ����Ľ��λ��
                } else     //������ǰ��
                {
                    stu->next = p1;
                    p2->next = stu;

                }

            } else                    //���û�ҵ���λ�õ�ѧ��,��ѯ���Ƿ�������һ��
            {
                printf("û�ҵ���λ�õ�ѧ��\n");
                printf("�Ƿ���Ҫ����ѧ�����뵽���һ����(��������1����������0)\n");
                int op1;
                scanf("%d", &op1);
                if (op1) {
                    p1->next = stu;
                    stu->next = NULL;
                }

            }

        }
        printf("�Ƿ����������?(�����������������1,��������0)");
        scanf("%d", &op1);
        system("CLS");    //��������
    }

    return head;
}

STU *Insert_student2(STU *head)     //����������ѧ����Ϣ�ĺ���
{
    int op, j, op1 = 1;
    while (op1) {
        STU *p1 = NULL, *p2 = NULL;     //p1���浱ǰ��Ҫ���Ľڵ�ĵ�ַ
        STU *stu;
        stu = (STU *) malloc(sizeof(STU));
        printf("������Ҫ����λ�õ�����:");
        char name[20];
        getchar();
        gets(name);     //���������λ�õ�����
        printf("������ڸ�����ǰ�滹�Ǻ���:");
        printf("1.ǰ��:");
        printf("2.����:");
        scanf("%d", &op);
        printf("��������������ѧ������Ϣ:\n");
        printf("ѧ��:");
        scanf("%d", &stu->ID);
        getchar();
        printf("����:");
        gets(stu->name);
        stu->sum = 0;
        for (j = 0; j < course_num; j++)      //���¼�����ſγ̵�ƽ����,��߷�,���ȼ�����
        {
            printf("������%s����:", class_num[j].course_name);
            scanf("%lf", &stu->course[j].course_score);
            strcpy(stu->course[j].course_name, class_num[j].course_name);
            stu->sum += stu->course[j].course_score;
            class_num[j].course_ave = class_num[j].course_ave * stu_num + stu->course[j].course_score;
            if (stu->course[j].course_score > class_num[j].course_max)        //����¼����ѧ�����ųɼ���֮ǰ��߳ɼ�Ҫ��,���ѧ��Ϊ���ſγ���߷�
            {
                class_num[j].course_max = stu->course[j].course_score;
                strcpy(class_num[j].max_name, stu->name);
            }
            if (stu->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
                class_num[j].rank[0]++;
            else if (stu->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
                class_num[j].rank[1]++;
            else if (stu->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
                class_num[j].rank[2]++;
            else if (stu->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
                class_num[j].rank[3]++;
            else
                class_num[j].rank[4]++;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
        }
        stu->ave = stu->sum / course_num;
        stu_num++;     //ѧ��������֮��һ
        for (j = 0; j < course_num; j++)
            class_num[j].course_ave /= stu_num;
        if (head == NULL)                  //��������ǿձ���ֱ�Ӳ���
        {
            head = stu;
            stu->next = NULL;
        } else {
            p1 = head;
            while (strcmp(p1->name, name) != 0 && p1->next != NULL)      //p1ָ��Ľڵ㲻����Ҫ���ҵģ��������������һ���ڵ㣬����������
            {
                p2 = p1;
                p1 = p1->next;                //����һ���ڵ�
            }
            if (strcmp(p1->name, name) == 0)      //�ҵ���
            {
                if (op == 2) {
                    stu->next = p1->next;     //��Ȼstu����һ�ڵ���ԭp1��next
                    p1->next = stu;            //�����ԭp1����һ�ڵ����Ҫ����Ľ��λ��
                } else {
                    stu->next = p1;
                    p2->next = stu;

                }

            } else {

                printf("û�ҵ���λ�õ�����\n");                    //��û�ҵ�,��ѯ���Ƿ���뵽�����
                printf("�Ƿ���Ҫ����ѧ�����뵽���һ��?(��������1����������0)\n");
                int op1;
                scanf("%d", &op1);
                if (op1) {
                    p1->next = stu;
                    stu->next = NULL;
                }

            }
        }
        printf("�Ƿ����������?(�����������������1,��������0)");
        scanf("%d", &op1);
        system("CLS");    //��������
    }

    return head;
}

STU *Search_student1(STU *head)     //��ѧ�Ų���ѧ����Ϣ�ĺ���
{
    int ID, j = 0, op1 = 1;
    while (op1) {
        STU *p;
        p = head;
        printf("������Ҫ���ҵ�ѧ��:");
        scanf("%d", &ID);      //����Ҫ���ҵ�ѧ��
        while (p->ID != ID && p->next != NULL)     //pָ��Ľڵ㲻����Ҫ���ҵģ��������������һ���ڵ㣬�ͼ���������
        {
            p = p->next;     //����һ���ڵ�
        }
        if (p->ID == ID)     //�ҵ��˲���ʾ��ѧ���Ļ�����Ϣ
        {
            printf("�����Ǹ�ѧ���Ļ�����Ϣ:\n");
            printf("ѧ��:%d\n", p->ID);
            printf("����:%s\n", p->name);
            printf("�����Ǳ��ο������:\n");
            for (j = 0; j < course_num; j++)
                printf("%s�ɼ�:%.2lf\n", class_num[j].course_name, p->course[j].course_score);
            printf("ƽ����:%.2lf\n", p->ave);
            printf("�ܷ�:%.2lf\n", p->sum);
            printf("�Ƿ�Ҫ�޸ĸÿ����ĳɼ�(�����޸�������1,��������0)");
            int op1;
            scanf("%d", &op1);
            while (op1)     //ʵ��ѧ����Ϣ�޸ĵĹ���
            {
                getchar();
                char cou_name[50];
                double score;
                printf("������Ҫ�޸ĵĿγ�����:\n");
                gets(cou_name);
                printf("�޸ĵķ���:\n");
                scanf("%lf", &score);
                for (j = 0; j < course_num; j++)     //���¼�����ſγ̵�ƽ����,��߷�,���ȼ�����
                {
                    if (strcmp(class_num[j].course_name, cou_name) == 0) {
                        class_num[j].course_ave = class_num[j].course_ave * stu_num - p->course[j].course_score + score;
                        class_num[j].course_ave = class_num[j].course_ave / stu_num;
                        break;
                    }
                }
                if (p->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
                    class_num[j].rank[0]--;
                else if (p->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
                    class_num[j].rank[1]--;
                else if (p->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
                    class_num[j].rank[2]--;
                else if (p->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
                    class_num[j].rank[3]--;
                else
                    class_num[j].rank[4]--;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
                if (score >= 90)                                //������ųɼ��޸ĺ���ڵ���90��,���ŵ�������1
                    class_num[j].rank[0]++;
                else if (score >= 80)                            //������ųɼ��޸ĺ���ڵ���80��,������������1
                    class_num[j].rank[1]++;
                else if (score >= 70)                            //������ųɼ��޸ĺ���ڵ���70��,���е�������1
                    class_num[j].rank[2]++;
                else if (score >= 60)                            //������ųɼ��޸ĺ���ڵ���60��,�򼰸��������1
                    class_num[j].rank[3]++;
                else
                    class_num[j].rank[4]++;                    //������ųɼ��޸ĺ�С��60��,�򲻼����������1
                if (score > class_num[j].course_max)        //������ųɼ��޸ĺ��֮ǰ��߳ɼ�Ҫ��,���ѧ��Ϊ���ſγ���߷�
                {
                    class_num[j].course_max = p->course[j].course_score;
                    strcpy(class_num[j].max_name, p->name);

                }
                p->course[j].course_score = score;
                printf("�Ƿ�Ҫ�����޸ĸÿ����������ɼ�(�����޸�������1,��������0)");
                scanf("%d", &op1);
            }
        } else
            printf("��ѧ�����ڳɼ�����ϵͳ��\n");    //û�ҵ�

        printf("�Ƿ����������?(�����������������1,��������0)");
        scanf("%d", &op1);
        system("CLS");    //��������
    }

    return head;
}

STU *Search_student2(STU *head)     //����������ѧ����Ϣ�ĺ���
{
    int j = 0, op1 = 1;
    char name[20];
    while (op1) {
        STU *p;
        p = head;
        printf("������Ҫ���ҵ�����:");
        getchar();
        gets(name);     //����Ҫ���ҵ�����
        while (strcmp(p->name, name) != 0 && p->next != NULL)     //pָ��Ľڵ㲻����Ҫ���ҵģ��������������һ���ڵ㣬�ͼ���������
        {
            p = p->next;     //����һ���ڵ�
        }
        if (strcmp(p->name, name) == 0)     //�ҵ��˲���ʾ��ѧ���Ļ�����Ϣ
        {
            printf("�����Ǹ�ѧ���Ļ�����Ϣ:\n");
            printf("ѧ��:%d\n", p->ID);
            printf("����:%s\n", p->name);
            printf("�����Ǳ��ο������:\n");
            for (j = 0; j < course_num; j++)
                printf("%s�ɼ�:%.2lf\n", class_num[j].course_name, p->course[j].course_score);
            printf("ƽ����:%.2lf\n", p->ave);
            printf("�ܷ�:%.2lf\n", p->sum);
            printf("�Ƿ�Ҫ�޸ĸÿ����ĳɼ�(�����޸�������1,��������0)");
            int op1;
            scanf("%d", &op1);
            while (op1)     //ʵ��ѧ����Ϣ�޸ĵĹ���
            {
                getchar();
                char cou_name[50];
                double score;
                printf("������Ҫ�޸ĵĿγ�����:\n");
                gets(cou_name);
                printf("�޸ĵķ���:\n");
                scanf("%lf", &score);
                for (j = 0; j < course_num; j++)     //���¼�����ſγ̵�ƽ����
                {
                    if (strcmp(class_num[j].course_name, cou_name) == 0) {
                        class_num[j].course_ave = class_num[j].course_ave * stu_num - p->course[j].course_score + score;
                        class_num[j].course_ave = class_num[j].course_ave / stu_num;
                        break;
                    }
                }
                if (p->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
                    class_num[j].rank[0]--;
                else if (p->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
                    class_num[j].rank[1]--;
                else if (p->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
                    class_num[j].rank[2]--;
                else if (p->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
                    class_num[j].rank[3]--;
                else
                    class_num[j].rank[4]--;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
                if (score >= 90)                                //������ųɼ��޸ĺ���ڵ���90��,���ŵ�������1
                    class_num[j].rank[0]++;
                else if (score >= 80)                            //������ųɼ��޸ĺ���ڵ���80��,������������1
                    class_num[j].rank[1]++;
                else if (score >= 70)                            //������ųɼ��޸ĺ���ڵ���70��,���е�������1
                    class_num[j].rank[2]++;
                else if (score >= 60)                            //������ųɼ��޸ĺ���ڵ���60��,�򼰸��������1
                    class_num[j].rank[3]++;
                else
                    class_num[j].rank[4]++;                    //������ųɼ��޸ĺ�С��60��,�򲻼����������1
                if (score > class_num[j].course_max)        //������ųɼ��޸ĺ��֮ǰ��߳ɼ�Ҫ��,���ѧ��Ϊ���ſγ���߷�
                {
                    class_num[j].course_max = p->course[j].course_score;
                    strcpy(class_num[j].max_name, p->name);
                }
                p->course[j].course_score = score;
                printf("�Ƿ�Ҫ�����޸ĸÿ����������ɼ�(�����޸�������1,��������0)");
                scanf("%d", &op1);
            }
        } else
            printf("��ѧ�����ڳɼ�����ϵͳ��\n");    //û�ҵ�
        printf("�Ƿ����������?(�����������������1,��������0)");
        scanf("%d", &op1);
        system("CLS");    //��������
    }

    return head;
}

void *Rank_student(STU *head)     //�ɼ�������
{
    char cou_name[50];
    int j, op1;
    printf("��������Ҫ��������ʽ\n");     //ѡ��������ʽ
    printf("1.���Ƴɼ�����\n");
    printf("2.�ܳɼ�����\n");
    scanf("%d", &op1);
    getchar();
    if (op1 == 1) {
        printf("������Ҫ�����Ŀγ�����:");
        gets(cou_name);
        for (j = 0; j < course_num; j++)      //Ѱ�ҿγ��������ڵ��±�
            if (strcmp(cou_name, class_num[j].course_name) == 0)
                break;
        BubbleSort1(head, j);
    } else
        BubbleSort2(head);
    return head;
}

void BubbleSort1(STU *head, int score_num)     //��ĳ�ųɼ�����ĺ���
{
    STU *p, *prep, *temp, *tail;
    tail = NULL;
    while (head->next != tail) {
        prep = head;
        p = head->next;
        while (p->next != tail) {
            if (p->course[score_num].course_score < p->next->course[score_num].course_score) {
                temp = p->next;
                prep->next = p->next;
                p->next = p->next->next;
                prep->next->next = p;
                p = temp;
            }
            p = p->next;
            prep = prep->next;
        }
        tail = p;
    }
}

void BubbleSort2(STU *head)     //���ܳɼ�����ĺ���
{
    STU *p, *prep, *temp, *tail;
    tail = NULL;
    while (head->next != tail) {
        prep = head;
        p = head->next;
        while (p->next != tail) {
            if (p->sum < p->next->sum) {
                temp = p->next;
                prep->next = p->next;
                p->next = p->next->next;
                prep->next->next = p;
                p = temp;
            }
            p = p->next;
            prep = prep->next;
        }
        tail = p;
    }
}
