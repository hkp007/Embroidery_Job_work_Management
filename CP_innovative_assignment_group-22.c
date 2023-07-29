#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

void work_detail();
void insert_record_work();
void display_record_work();
void search_record_work();
void del_record_work();
void update_record_work();
void sort_record_work();

struct work_detail
{
    int work_chalan_no;
    char work_design_no[10];
    char work_party_name[40];
    int work_pcs;
    int work_rate;
    int work_amount;
    int d,m,y;
    int work_inward_chalan_no;
};

struct work_detail s;

void inward_details();
void insert_record_inward();
void display_record_inward();
void search_record_inward();
void del_record_inward();
void update_record_inward();
void sort_record_inward();

struct inward
{
    char in_date[10];
    int inwars_chalan_no;
    char in_design_no[10];
    char in_party_name[40];
    int in_pcs;
    int in_rate;
};

struct inward a;

void Purch_details();
void insert_record_Purch();
void display_record_Purch();
void search_record_Purch();
void del_record_Purch();
void update_record_Purch();
void sort_record_Purch();

struct Purch
{
    char Purch_date[10];
    int Purch_chalan_no;
    char Purch_Supplier_name[10];
    int Box_no;
    int Purch_pcs;
    int Purch_rate;
};

struct Purch c;

int main()
{
    system("clear");
    int a=0;
    while (a!=4)
    {
        printf("\n");
        printf("-------------------------------------------------\n");
        printf("    Embroidery Job Work Management Programme\n");
        printf("-------------------------------------------------\n");
        printf("\n");
        printf("1. Inward Detail.\n");
        printf("2. Work Detail.\n");
        printf("3. Purchase Detail.\n");
        printf("4. Exit the programme.\n");
        printf("\n");
        printf("◊  Enter the number which functionality you want to use : ");
        scanf("%d",&a);
        printf("\n");
        switch (a)
        {
        case 1:
            inward_details();
            system("clear");
            break;
    
        case 2:
            work_detail();
            system("clear");
            break;

        case 3:
            Purch_details();
            system("clear");
            break;
    
        case 4:
            exit(1);
            break;
    
        default:
            printf("Select valid number.\n");
            break;
    }
    printf("\n");
    } 
    return 0;
}

void inward_details()
{
    int ch;
    while (ch != 7)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("\tWelcome to programme\n");
        printf("------------------------------------\n\n\n");
        printf("-----  Aviable Functionalities -----\n\n");
        printf("\t1: Insert record\n");
        printf("\t2: Display record\n");
        printf("\t3: Search record\n");
        printf("\t4: Delete record\n");
        printf("\t5: Update record\n");
        printf("\t6: Sort record\n");
        printf("\t7: Exit\n\n");
        printf("\tEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("clear");
            insert_record_inward();
            break;

        case 2:
            system("clear");
            display_record_inward();
            break;

        case 3:
            system("clear");
            search_record_inward();
            break;

        case 4:
            system("clear");
            del_record_inward();
            break;

        case 5:
            system("clear");
            update_record_inward();
            break;

        case 6:
            system("clear");
            sort_record_inward();
            break;

        case 7:
            system("clear");
            break;

        default:
            printf("\n\t\tWrong choice entered.");
            break;
        }
        printf("\n");
    }
}
void insert_record_inward()
{
    FILE *fp;

    fp = fopen("inward.txt", "ab+");

    if (fp == NULL)
    {
        printf("\n---- Error: Cannot Open The File!!!");
        return;
    }
    printf("\n\n---- Previous Stored data ----");
    display_record_inward();

    printf("\n\n---- Enter New Inward Data ----\n\n");
    fflush(stdin);
    printf("\nEnter Date : ");
    gets(a.in_date);
    fflush(stdin);
    printf("\nEnter Inward Chalan No : ");
    scanf("%d", &a.inwars_chalan_no);
    fflush(stdin);
    printf("\nEnter Party's Name : ");
    gets(a.in_party_name);
    fflush(stdin);
    printf("\nEnter Design No : ");
    gets(a.in_design_no);
    printf("\nEnter Number Of Pcs : ");
    scanf("%d", &a.in_pcs);
    printf("\nEnter Rate : ");
    scanf("%d", &a.in_rate);
    fwrite(&a, sizeof(a), 1, fp);
    {
        printf("\n\n!!! Inward Record Inserted Sucessfully\n");
    }
    fclose(fp);
    printf("\n\tUpdated Record !!");
    display_record_inward();
}
void display_record_inward()
{
    FILE *fp;
    fp = fopen("inward.txt", "rb");

    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;
    }

    printf("\n\n---- Inward Details Are As Follows ----\n");
    printf("\n Date        Inward Chalan No    Party's Name       Design No       Pcs       Rate\n\n");
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        printf("%12s%15d%15s%15s%12d%12d\n", a.in_date, a.inwars_chalan_no, a.in_party_name, a.in_design_no, a.in_pcs, a.in_rate);
    }
    fclose(fp);
}
void search_record_inward()
{
    int ch_no, flag = 0;
    FILE *fp;
    fp = fopen("inward.txt", "rb");
    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;
    }
    printf("\n\nEnter Inward Chalan Number Which You Want to Search : ");
    scanf("%d", &ch_no);
    while (fread(&a, sizeof(a), 1, fp) > 0 && flag == 0)
    {
        if (a.inwars_chalan_no == ch_no)
        {
            flag = 1;
            printf("\n\nSearch Sucessfull And Record is as follow : \n");
            printf("\n Date        Inward Chalan No    Party's Name       Design No       Pcs       Rate\n\n");
            printf("%12s%15d%15s%15s%12d%12d\n", a.in_date, a.inwars_chalan_no, a.in_party_name, a.in_design_no, a.in_pcs, a.in_rate);
        }
    }
    if (flag == 0)
    {
        printf("\n\n\tNo Such Record Found !!!\n");
    }
    fclose(fp);
}
void del_record_inward()
{
    int chalan_no;
    unsigned flag = 0;
    FILE *fp, *ft;
    fp = fopen("inward.txt", "rb");
    ft = fopen("inward1.txt", "ab+");
    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;
    }
    printf("\n---- Previous Store data ----");
    display_record_inward();
    printf("\n\nEnter Inward Chalan Number Which You Want to Delete : ");
    scanf("%d", &chalan_no);
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        if (a.inwars_chalan_no != chalan_no)
        {
            fwrite(&a, sizeof(a), 1, ft);
        }
        else
        {
            flag = 1;
        }
    }
    printf("\nRecord Deleted Sucessfully \n");
    if (flag == 0)
    {
        printf("\n\n\t\tNo such Record Found !!!");
    }
    fclose(fp);
    fclose(ft);
    remove("inward.txt");
    rename("inward1.txt", "inward.txt");
    printf("\n\t Update Record !!\n");
    display_record_inward();
}
void update_record_inward()
{
    int ch_no, flag = 0;
    FILE *fp;
    fp = fopen("inward.txt", "rb+");
    fp = fopen("inward.txt", "rb+");
    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;
    }
    printf("\n\nEnter Inward Chalan Number whose record you want to update : ");
    scanf("%d", &ch_no);
    printf("\n--- Previously stored record of given chalan number number ---");
    while (fread(&a, sizeof(a), 1, fp) > 0 && flag == 0)
    {
        if (a.inwars_chalan_no == ch_no)
        {
            flag = 1;
            printf("\n Date        Inward Chalan No    Party's Name       Design No       Pcs       Rate\n\n");
            printf("%12s%15d%15s%15s%12d%12d\n", a.in_date, a.inwars_chalan_no, a.in_party_name, a.in_design_no, a.in_pcs, a.in_rate);
            printf("\n---- Now Enter The New Record ----\n\n");

            fflush(stdin);
            printf("\nEnter New Date : ");
            gets(a.in_date);
            fflush(stdin);
            printf("\nEnter New Inward Chalan No : ");
            scanf("%d", &a.inwars_chalan_no);
            fflush(stdin);
            printf("\nEnter New Party's Name : ");
            gets(a.in_party_name);
            fflush(stdin);
            printf("\nEnter New Design No : ");
            gets(a.in_design_no);
            printf("\nEnter New Number Of Pcs : ");
            scanf("%d", &a.in_pcs);
            printf("\nEnter New Rate : ");
            scanf("%d", &a.in_rate);
            fseek(fp, -(long)sizeof(a), 1);
            fwrite(&a, sizeof(a), 1, fp);
            printf("\n\nRecord Updated Successfully Check The Display.\n");
        }
    }
    if (flag == 0)
    {
        printf("\n\t\tError : Something went wrong !!!");
    }
    fclose(fp);
}
void sort_record_inward()
{
    struct inward temp;
    struct inward arr[50];

    int i, j, size = 0;
    FILE *fp;
    fp = fopen("inward.txt", "rb");
    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot open file !!!\n");
    }
    i = 0;
    while (fread(&arr[i], sizeof(arr[i]), 1, fp) == 1)
    {
        i++;
        size++;
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size-i-1 ; j++)
        {
            if (arr[j].inwars_chalan_no > arr[j + 1].inwars_chalan_no)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nAfter Sorting Inward Detail !!\n\n");
    printf("\n Date        Inward Chalan No    Party's Name       Design No       Pcs       Rate\n\n");
    for (i = 0; i < size; i++)
    {
        printf("%12s%15d%15s%15s%12d%12d\n", arr[i].in_date, arr[i].inwars_chalan_no, arr[i].in_party_name, arr[i].in_design_no, arr[i].in_pcs, arr[i].in_rate);
    }
    fclose(fp);
}

void work_detail()
{
    int ch;
    while (ch!=7)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("\tWelcome to programme\n");
        printf("------------------------------------\n\n\n");
        printf("-----  Aviable Functionalities -----\n\n");
        printf("\t1: Insert record\n");
        printf("\t2: Display record\n");
        printf("\t3: Search record\n");
        printf("\t4: Delete record\n");
        printf("\t5: Update record\n");
        printf("\t6: Sort record\n");
        printf("\t7: Back\n\n");
        printf("\tEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            system("clear");
            insert_record_work();
            break;
        
        case 2:
            system("clear");
            display_record_work();
            break;
        
        case 3:
            system("clear");
            search_record_work();
            break;
        
        case 4:
            system("clear");
            del_record_work();
            break;
        
        case 5:
            system("clear");
            update_record_work();
            break;
        
        case 6:
            system("clear");
            sort_record_work();
            break;
        
        case 7:
            system("clear");
            break;
        
        default:
            printf("\n\t\tWrong choice entered.");
            break;
        }
        printf("\n");   
    }
}
void insert_record_work() 
{
    FILE *fp;

    fp=fopen("work.txt","ab+");

    if (fp==NULL)
    {
        printf("\n---- Error: Cannot Open The File!!!");
        return;
    }
    printf("\n\n---- Previous Stored data ----");
    display_record_work();

    printf("\n\n------- Enter New Data -------\n\n");
    printf("\nEnter date : ");
    scanf("%d/%d/%d",&s.d,&s.m,&s.y);
    printf("\nEnter chalan number : ");
    scanf("%d",&s.work_chalan_no);
    fflush(stdin);
    printf("\nEnter party Name : ");
    gets(s.work_party_name);
    printf("\nEnter design no. : ");
    gets(s.work_design_no);
    printf("\nEnter inward_chalan_no : ");
    scanf("%d",&s.work_inward_chalan_no);
    printf("\nEnter pcs : ");
    scanf("%d",&s.work_pcs);
    printf("\nEnter rate : ");
    scanf("%d",&s.work_rate);
    s.work_amount=s.work_pcs*s.work_rate;
    fwrite(&s,sizeof(s),1,fp);
    {
        printf("\n\n!!! Record Inserted Sucessfully\n");
    }
    fclose(fp);
    printf("\n\tUpdated Record !!");
    display_record_work();
}
void display_record_work()
{
    FILE *fp;
    fp=fopen("work.txt","rb");

    if (fp==NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;         
    }
    
    printf("\n\n-------- Details Are As Follows --------\n");
    printf("\nDate\t\tChalan_no\tParty \t\tDesign\tInward\tPcs\tRate\tAmount\n\n");
    while (fread(&s,sizeof(s),1,fp)==1)
    {
        printf("%d/%d/%d\t%d\t\t%-12s\t%-8s%d\t%-8d%-8d%d\n",s.d,s.m,s.y,s.work_chalan_no,s.work_party_name,s.work_design_no,s.work_inward_chalan_no,s.work_pcs,s.work_rate,s.work_amount);
    }
    fclose(fp);
}
void search_record_work()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("work.txt","rb");
    if (fp==NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;         
    }
    printf("\n\nEnter Chalan Number Which You Want to Search : ");
    scanf("%d",&ro);
    while (fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.work_chalan_no==ro)
        {
            flag=1;
            printf("\n\nSearch Sucessfull And Record is as follow : \n");
            printf("\nDate\t\tChalan_no\tParty \t\tDesign\tInward\tPcs\tRate\tAmount\n\n");
            printf("%d/%d/%d\t%d\t\t%-12s\t%-8s%d\t%-8d%-8d%d\n",s.d,s.m,s.y,s.work_chalan_no,s.work_party_name,s.work_design_no,s.work_inward_chalan_no,s.work_pcs,s.work_rate,s.work_amount);
        }
    }
    if (flag==0)
    {
        printf("\n\n\tNo Such Record Found !!!\n");
    }  
    fclose(fp);    
}
void del_record_work()
{
    int cache;
    unsigned flag=0;
    FILE *fp,*ft;
    fp=fopen("work.txt","rb");
    ft=fopen("work1.txt","ab+");
    if (fp==NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;         
    }
    printf("\n---- Previous Store data ----");
    display_record_work();
    printf("\n\nEnter Chalan Number Which You Want to Delete : ");
    scanf("%d",&cache);
    while (fread(&s,sizeof(s),1,fp)==1)
    {
        if (s.work_chalan_no!=cache)
        {
            fwrite(&s,sizeof(s),1,ft);
        }
        else
        {
            flag=1;
            printf("\nRecord Deleted Sucessfully \n");
        }    
    }
    if (flag==0)
    {
        printf("\n\n\t\tNo such Record Found !!!");
    }
    fclose(fp);
    fclose(ft);
    remove("work.txt");
    rename("work1.txt","work.txt");
    printf("\n\t Update Record !!\n");
    display_record_work();  
}
void update_record_work()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("work.txt","rb+");
    if (fp==NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;         
    }
    printf("\n\nEnter Chalan Number whose record you want to update : ");
    scanf("%d",&ro);
    printf("\n--- Previously stored record of given chalan number ---");
    while (fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if (s.work_chalan_no==ro)
        {
            flag=1;
            printf("\nDate\t\tChalan_no\tParty \t\tDesign\tInward\tPcs\tRate\tAmount\n\n");
            printf("%d/%d/%d\t%d\t\t%-12s\t%-8s%d\t%-8d%-8d%d\n",s.d,s.m,s.y,s.work_chalan_no,s.work_party_name,s.work_design_no,s.work_inward_chalan_no,s.work_pcs,s.work_rate,s.work_amount);
            printf("\n---- Now Enter The New Record ----\n\n");
            printf("\nEnter date : ");
            scanf("%d/%d/%d",&s.d,&s.m,&s.y);
            printf("\nUpdate Chalan Number : ");
            scanf("%d",&s.work_chalan_no);
            fflush(stdin);
            printf("\nEnter party name : ");
            gets(s.work_party_name);
            printf("\nEnter design no. : ");
            gets(s.work_design_no);
            printf("\nEnter inward_chalan_no : ");
            scanf("%d",&s.work_inward_chalan_no);
            printf("\nEnter pcs : ");
            scanf("%d",&s.work_pcs);
            printf("\nEnter rate : ");
            scanf("%d",&s.work_rate);
            s.work_amount=s.work_pcs*s.work_rate;
            fseek(fp,-(long)sizeof(s),1);
            fwrite(&s,sizeof(s),1,fp);
            printf("\n\nRecord Updated Successfully Check The Display.\n");
        }
        
    }
    if (flag==0)
    {
        printf("\n\t\tError : Something went wrong !!!");
    }
    fclose(fp); 
}
void sort_record_work()
{
    struct work_detail temp;
    struct work_detail arr[50];

    int i,j,k=0;
    FILE *fp;
    fp=fopen("work.txt","rb");
    if (fp==NULL)
    {
        printf("\n\t\tError : Cannot open file !!!\n");
    }
    i=0;
    while (fread(&arr[i],sizeof(arr[i]),1,fp)==1)
    {
        i++;
        k++;
    }
    for ( i = 0; i < k; i++)
    {
        for ( j = 0; j < k-i-1; j++)
        {
            if (arr[j].work_chalan_no>arr[j+1].work_chalan_no)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\nAfter Sorting Work Details !!\n\n");
    printf("\nDate\t\tChalan_no\tParty \t\tDesign\tInward\tPcs\tRate\tAmount\n\n");
    for ( i = 0; i < k; i++)
    {
        printf("%d/%d/%d\t%d\t\t%-12s\t%-8s%d\t%-8d%-8d%d\n",arr[i].d,arr[i].m,arr[i].y,arr[i].work_chalan_no,arr[i].work_party_name,arr[i].work_design_no,arr[i].work_inward_chalan_no,arr[i].work_pcs,arr[i].work_rate,arr[i].work_amount);
    }
    fclose(fp);
}

void Purch_details()
{
    int ch;
    while (ch != 7)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("\tWelcome to programme\n");
        printf("------------------------------------\n\n\n");
        printf("-----  Aviable Functionalities -----\n\n");
        printf("\t1: Insert record\n");
        printf("\t2: Display record\n");
        printf("\t3: Search record\n");
        printf("\t4: Delete record\n");
        printf("\t5: Update record\n");
        printf("\t6: Sort record\n");
        printf("\t7: Exit\n\n");
        printf("\tEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("clear");
            insert_record_Purch();
            break;

        case 2:
            system("clear");
            display_record_Purch();
            break;

        case 3:
            system("clear");
            search_record_Purch();
            break;

        case 4:
            system("clear");
            del_record_Purch();
            break;

        case 5:
            system("clear");
            update_record_Purch();
            break;

        case 6:
            system("clear");
            sort_record_Purch();
            break;

        case 7:
            system("clear");
            break;

        default:
            printf("\n\t\tWrong choice entered.");
            break;
        }
        printf("\n");
    }
}
void insert_record_Purch()
{
    FILE *fp;

    fp = fopen("Purch.txt", "ab+");

    if (fp == NULL)
    {
        printf("\n---- Error: Cannot Open The File!!!");
        return;
    }
    printf("\n\n---- Previous Stored data ----");
    display_record_Purch();

    printf("\n\n---- Enter New Purchase Data ----\n\n");
    printf("\nEnter Date : ");
    fflush(stdin);
    gets(c.Purch_date);
    printf("\nEnter Purchase Chalan No : ");
    scanf("%d", &c.Purch_chalan_no);
    fflush(stdin);
    printf("\nEnter Suppier's Name : ");
    gets(c.Purch_Supplier_name);
    printf("\nEnter Box No : ");
    scanf("%d",&c.Box_no);
    printf("\nEnter Number Of Pcs : ");
    scanf("%d", &c.Purch_pcs);
    printf("Enter Rate : ");
    scanf("%d", &c.Purch_rate);
    fwrite(&c, sizeof(c), 1, fp);
    {
        printf("\n\n!!! Purchase Record Inserted Sucessfully\n");
    }
    fclose(fp);
    printf("\n\tUpdated Record !!");
    display_record_Purch();
}
void display_record_Purch()
{
    FILE *fp;
    fp = fopen("Purch.txt", "rb");

    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;
    }

    printf("\n\n---- Purchase Details Are As Follows ----\n");
    printf("\n\tDate\tChalan No    Supplier     Box No    \tPcs        Rate     Amt\n\n");
    while (fread(&c, sizeof(c), 1, fp) == 1)
    {
    printf("%12s%12d%12s%12d%11d%12d%8d\n", c.Purch_date, c.Purch_chalan_no, c.Purch_Supplier_name, c.Box_no, c.Purch_pcs, c.Purch_rate,c.Purch_pcs*c.Purch_rate);

    }

    fclose(fp);
}
void search_record_Purch()
{
    int ch_no, flag = 0;
    FILE *fp;
    fp = fopen("Purch.txt", "rb");
    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;
    }
    printf("\n\nEnter Purchase Chalan Number Which You Want to Search : ");
    scanf("%d", &ch_no);
    while (fread(&c, sizeof(c), 1, fp) > 0 && flag == 0)
    {
        if (c.Purch_chalan_no == ch_no)
        {
            flag = 1;
            printf("\n\nSearch Sucessful And Record is as follow : \n");
           printf("\n\tDate\tChalan No    Supplier     Box No    \tPcs        Rate     Amt\n\n");
           printf("%12s%12d%12s%12d%11d%12d%8d\n", c.Purch_date, c.Purch_chalan_no, c.Purch_Supplier_name, c.Box_no, c.Purch_pcs, c.Purch_rate,c.Purch_pcs*c.Purch_rate);

        }
    }
    if (flag == 0)
    {
        printf("\n\n\tNo Such Record Found !!!\n");
    }
    fclose(fp);
}
void del_record_Purch()
{
    int chalan_no;
    unsigned flag = 0;
    FILE *fp, *ft;
    fp = fopen("Purch.txt", "rb");
    ft = fopen("Purch1.txt", "ab+");
    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;
    }
    printf("\n---- Previous Store data ----");
    display_record_Purch();
    printf("\n\nEnter Purchase Chalan Number Which You Want to Delete : ");
    scanf("%d", &chalan_no);
    while (fread(&c,sizeof(c), 1, fp) == 1)
    {
        if (c.Purch_chalan_no != chalan_no)
        {
            fwrite(&c,sizeof(c), 1, ft);
        }
        else
        {
            flag = 1;
            printf("\nRecord Deleted Sucessfully \n");
        }
    }
    if (flag == 0)
    {
        printf("\n\n\t\tNo such Record Found !!!");
    }
    fclose(fp);
    fclose(ft);
    remove("Purch.txt");
    rename("Purch1.txt", "Purch.txt");
    printf("\n\t Record is updated!!\n");
    display_record_Purch();
}
void update_record_Purch()
{
    int ch_no, flag = 0;
    FILE *fp;
    fp = fopen("Purch.txt", "rb+");
    fp = fopen("Purch.txt", "rb+");
    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot Open The File !!!");
        return;
    }
    printf("\n\nEnter Purchase Chalan Number whose entries you want to update : ");
    scanf("%d", &ch_no);
    printf("\n---- Previously stored record of given Purchase chalan number ----");
    while (fread(&c, sizeof(c), 1, fp) > 0 && flag == 0)
    {
        if (c.Purch_chalan_no == ch_no)
        {
            flag = 1;
           printf("\n\tDate\tChalan No    Supplier     Box No    \tPcs        Rate     Amt\n\n");
            printf("%12s%12d%12s%12d%11d%12d%8d\n", c.Purch_date, c.Purch_chalan_no, c.Purch_Supplier_name, c.Box_no, c.Purch_pcs, c.Purch_rate,c.Purch_pcs*c.Purch_rate);
            printf("\n**** Now Enter The New Entries ****\n\n");

            fflush(stdin);
            printf("\nEnter New Date : ");
            gets(c.Purch_date);
            printf("\nEnter New Purchase Chalan No : ");
            scanf("%d", &c.Purch_chalan_no);
            fflush(stdin);
            printf("\nEnter New Party's Name : ");
            gets(c.Purch_Supplier_name);
            printf("\nEnter New Box No : ");
            scanf("%d",&c.Box_no);
            printf("\nEnter New Number Of Pcs : ");
            scanf("%d", &c.Purch_pcs);
            printf("\nEnter New Rate : ");
            scanf("%d", &c.Purch_rate);
            fseek(fp, -(long)sizeof(c), 1);
            fwrite(&c, sizeof(c), 1, fp);
            printf("\n\nRecord Updated Successfully Check The Display.\n");
        }
    }
    if (flag == 0)
    {
        printf("\n\t\tError : Something went wrong !!!");
    }
    fclose(fp);
}
void sort_record_Purch()
{
    struct Purch temp;
    struct Purch arr[50];

    int i, j, k = 0;
    FILE *fp;
    fp = fopen("Purch.txt", "rb");
    if (fp == NULL)
    {
        printf("\n\t\tError : Cannot open file !!!\n");
    }
    i = 0;
    while (fread(&arr[i], sizeof(arr[i]), 1, fp) == 1)
    {
        i++;
        k++;
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k - i - 1; j++)
        {
            if (arr[j].Purch_chalan_no > arr[j + 1].Purch_chalan_no)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nAfter Sorting Purchase Details !!\n\n");
    for (i = 0; i < k; i++)
    {
        printf("%12s%12d%12s%12d%11d%12d%8d\n", arr[i].Purch_date, arr[i].Purch_chalan_no, arr[i].Purch_Supplier_name, arr[i].Box_no, arr[i].Purch_pcs, arr[i].Purch_rate,arr[i].Purch_pcs*arr[i].Purch_rate);
    }
    fclose(fp);
}