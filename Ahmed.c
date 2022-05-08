#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ahmed.h"
int students=0;
int i=0,j;
notebook b;
void Load(notebook c1[])
{
    FILE*f1;
    f1= fopen("C:\\Term 3\\programming 1\\Ahmed\\PhoneBook.txt","r");
    char c;
    printf("\t\t\t\t\t WELCOME TO PHONE NOTEBOOK\n\n");
    int i,j;
    while(!feof(f1))
    {
        for (c = getc(f1); c != EOF; c = getc(f1))
            if (c == '\n')
                students = students + 1;
        students++;
    }
    fclose(f1);
    f1=fopen("C:\\Term 3\\programming 1\\Ahmed\\PhoneBook.txt","r");
    while (i<=students)
    {
        fscanf(f1,"%[^,],%[^,],%d-%d-%d,%[^,],%[^,],%s",&c1[i].FirstName,&c1[i].LastName,&c1[i].DOB.day,&c1[i].DOB.month,&c1[i].DOB.year,&c1[i].address,&c1[i].email,&c1[i].phone);
        if(i<students)
        {
            fscanf(f1,"\n");
        }
        i++;
    }
    fclose(f1);
}

void Add(notebook c1[])
{
    int i;
    students++;
    printf("Please enter first name     :   ");
    scanf("%s",&c1[students-1].FirstName);
    printf("Please enter last name      :   ");
    scanf("%s",&c1[students-1].LastName);
    printf("Please enter day of birth   :   ");
    scanf("%d",&c1[students-1].DOB.day);
    printf("Please enter month of birth :   ");
    scanf("%d",&c1[students-1].DOB.month);
    printf("Please enter year of birth  :   ");
    scanf("%d",&c1[students-1].DOB.year);
    printf("Please enter address        :   ");
    fflush(stdin);
    fgets(c1[students-1].address,100,stdin);
    c1[students-1].address[strcspn(c1[students-1].address,"\n")]='\0';
    fflush(stdin);
    printf("Please enter email          :   ");
    scanf("%s",&c1[students-1].email);
    printf("Please enter phone number   :   ");
    scanf("%s",c1[students-1].phone);

    printf("\n\n Contact added\n\n");
}
void search_contacts(notebook c1[])
{
    int search_choice;
    char temp_phone[20];
    int i,j,jack=0;
    char last[100],first[100];
    printf("What do you want to search by??\n1. Last name\n2. Phone number\n\n");
    scanf("%d",&search_choice);
    switch (search_choice)
    {
    case 1:
        printf("Please enter the last name you want to find    :    ");
        scanf("%s",&last);
        printf("\n");
        for (i=0; i<students; i++)
        {
            if (strcasecmp(c1[i].LastName,last)==0)
            {
                printf("First name     :  %s\n",c1[i].FirstName);
                printf("Last  name     :  %s\n",c1[i].LastName);
                printf("Date of birth  :  %d/%d/%d\n",c1[i].DOB.day,c1[i].DOB.month,c1[i].DOB.year);
                printf("Address        :  %s\n",c1[i].address);
                printf("Email          :  %s\n",c1[i].email);
                printf("Phone number   :  %s\n",c1[i].phone);
                  printf("\n\n");
                jack++;
            }
        }
        if(jack>1)
        {
            printf("Please confirm the first name   :    ");
            scanf("%s",first);
            printf("\n");
            for(i=0; i<students; i++)
            {
                if (strcasecmp(c1[i].FirstName,first)==0&&strcasecmp((c1[i].LastName),last)==0)
                {
                    printf("First name     :  %s\n",c1[i].FirstName);
                    printf("Last  name     :  %s\n",c1[i].LastName);
                    printf("Date of birth  :  %d/%d/%d\n",c1[i].DOB.day,c1[i].DOB.month,c1[i].DOB.year);
                    printf("Address        :  %s\n",c1[i].address);
                    printf("Email          :  %s\n",c1[i].email);
                    printf("Phone number   :  %s\n\n",c1[i].phone);
                    return;
                }
            }
            printf("First Name Not found!!\n\n");
        }
        if (!jack)
            printf("\nNOT FOUND!!\n\n");
        break;
    case 2:
        printf("Please enter phone number : ");
        scanf("%s",&temp_phone);
        for (i=0; i<=students; i++)
        {
            if(strcmp(c1[i].phone,temp_phone)==0)
            {
                printf("First name     :  %s\n",c1[i].FirstName);
                printf("Last  name     :  %s\n",c1[i].LastName);
                printf("Date of birth  :  %d/%d/%d\n",c1[i].DOB.day,c1[i].DOB.month,c1[i].DOB.year);
                printf("Address        :  %s\n",c1[i].address);
                printf("Email          :  %s\n",c1[i].email);
                printf("Phone number   :  %s\n\n",c1[i].phone);
                return;
            }
        }
        printf("\nNot found!!\n\n");
    }
}

void Sort(notebook c1[])
{
    int i,j,choice;
    notebook b;
    printf("What do you want to sort by ??\n1. Last name\n2. Date Of Birth\n3. Print Data\n\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        for(i=0; i<students; i++)
        {
            for(j=i+1; j<students; j++)
            {

                if (strcasecmp(c1[i].LastName,c1[j].LastName)>0)
                {
                    b=c1[i];
                    c1[i]=c1[j];
                    c1[j]=b;
                }
                else if (strcasecmp(c1[i].LastName,c1[j].LastName)==0&&strcasecmp(c1[i].FirstName,c1[j].FirstName)>0)
                {
                    b=c1[i];
                    c1[i]=c1[j];
                    c1[j]=b;

                }
            }
        }
        printf("After sorting :\n\n");
        for (i=0; i<students; i++)
        {
            printf("%s\t%s\t%d-%d-%d\t%s\t%s\t%s\n",c1[i].FirstName,c1[i].LastName,c1[i].DOB.day,c1[i].DOB.month,c1[i].DOB.year,c1[i].address,c1[i].email,c1[i].phone);
        }
        printf("\n");
        break;
    case 2 :
        for(i=0; i<students; i++)
        {
            for(j=i+1; j<students; j++)
            {
                if (c1[i].DOB.year>c1[j].DOB.year)
                {
                    b=c1[i];
                    c1[i]=c1[j];
                    c1[j]=b;
                }
                else if(c1[i].DOB.year==c1[j].DOB.year)
                {
                    if(c1[i].DOB.month>c1[j].DOB.month)
                    {
                        b=c1[i];
                        c1[i]=c1[j];
                        c1[j]=b;
                    }
                    else if (c1[i].DOB.month==c1[j].DOB.month)
                    {
                        if(c1[i].DOB.day>c1[j].DOB.day)
                        {
                            b=c1[i];
                            c1[i]=c1[j];
                            c1[j]=b;
                        }
                    }
                }
            }
        }
        printf("After sorting :\n\n");
        for (i=0; i<students; i++)
        {
            printf("%s\t%s\t%d-%d-%d\t%s\t%s\t%s",c1[i].FirstName,c1[i].LastName,c1[i].DOB.day,c1[i].DOB.month,c1[i].DOB.year,c1[i].address,c1[i].email,c1[i].phone);
            if (i<students-1)
                printf("\n");
        }
        printf("\n\n");
        break;
    case 3:
        for (i=0; i<students; i++)
        {
            printf("%s\t%s\t%d-%d-%d\t%s\t%s\t%s",c1[i].FirstName,c1[i].LastName,c1[i].DOB.day,c1[i].DOB.month,c1[i].DOB.year,c1[i].address,c1[i].email,c1[i].phone);
            if (i<students-1)
                printf("\n");
        }
        printf("\n\n");
        break;
    default :
        printf("Please enter valid number !!\n\n");
    }
}
void Modify(notebook c1[])
{
    printf("Please enter the last name you want to modify    :    ");
    notebook e1[100];
    int i,j,jack=0,choice;
    char last[100],first[100];
    scanf("%s",&last);
    printf("\n");
    for (i=0; i<students; i++)
    {
        if (strcasecmp(c1[i].LastName,last)==0)
        {
            printf("First name     :  %s\n",c1[i].FirstName);
            printf("Last  name     :  %s\n",c1[i].LastName);
            printf("Date of birth  :  %d/%d/%d\n",c1[i].DOB.day,c1[i].DOB.month,c1[i].DOB.year);
            printf("Address        :  %s\n",c1[i].address);
            printf("Email          :  %s\n",c1[i].email);
            printf("Phone number   :  %s\n\n",c1[i].phone);
            jack++;
        }
    }
    if(jack)
    {
        printf("Please confirm the first name   :    ");
        scanf("%s",first);
        printf("\n");
        for(i=0; i<students; i++)
        {
            if (strcasecmp(c1[i].FirstName,first)==0&&strcasecmp(c1[i].LastName,last)==0)
            {
                printf("What do you want to modify??\n");
                printf("1. First name\n2. Last Name\n3. Day of Birth\n4. Month of Birth\n5. Year of Birth\n6. Address\n7. Email\n8. Phone\n9. Back to Menu\n\n");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1 :
                    printf("Please enter data   :  ");
                    scanf("%s",&c1[i].FirstName);
                    printf("\nModified\n\n");
                    break;
                case 2 :
                    printf("Please enter data   :  ");
                    scanf("%s",&c1[i].LastName);
                    printf("\nModified\n\n");
                    break;
                case 3:
                    printf("Please enter data   :  ");
                    scanf("%d",&c1[i].DOB.day);
                    printf("\nModified\n\n");
                    break;
                case 4:
                    printf("Please enter data   :  ");
                    scanf("%d",&c1[i].DOB.month);
                    printf("\nModified\n\n");
                    break;
                case 5:
                    printf("Please enter data   :  ");
                    scanf("%d",&c1[i].DOB.year);
                    printf("\nModified\n\n");
                    break;
                case 6:
                    printf("Please enter data   :  ");
                    fflush(stdin);
                    fgets(c1[i].address,100,stdin);
                    c1[i].address[strcspn(c1[i].address,"\n")]='\0';
                    fflush(stdin);
                    printf("\nModified\n\n");
                    break;
                case 7:
                    printf("Please enter data   :  ");
                    scanf("%s",&c1[i].email);
                    printf("\nModified\n\n");
                    break;
                case 8:
                    printf("Please enter data   :  ");
                    scanf("%s",&c1[i].phone);
                    printf("\nModified\n\n");
                    break;
                case 9:
                    return;
                default:
                    printf("Error !!  Please enter right number\n\n");
                    break;
                }
            }
        }
    }
    if (!jack)
        printf("\nNOT FOUND\n");

}
void Save(notebook c1[])
{
    FILE*f1=fopen("C:\\Term 3\\programming 1\\Ahmed\\PhoneBook.txt","w");
    int i,j;
    for(i=0; i<students; i++)
    {
        fprintf(f1,"%s,%s,%d-%d-%d,%s,%s,%s",c1[i].FirstName,c1[i].LastName,c1[i].DOB.day,c1[i].DOB.month,c1[i].DOB.year,c1[i].address,c1[i].email,c1[i].phone);
        if(i<students-1)
        {
            fprintf(f1,"\n");
        }
    }
    fclose(f1);
    printf("\nSaved Successfully!!.\n\n");
}
void Delete(notebook c1[])
{
    printf("Please enter the last name you want to find\n\n");
    notebook e1[100];
    int i,j,jack=0;
    char last[100],first[100];
    scanf("%s",&last);
    for (i=0; i<students; i++)
    {
        if (strcasecmp(c1[i].LastName,last)==0)
        {
            printf("\n%s\t%s\t%d-%d-%d\t%s\t%s\t%s\n\n",c1[i].FirstName,c1[i].LastName,c1[i].DOB.day,c1[i].DOB.month,c1[i].DOB.year,c1[i].address,c1[i].email,c1[i].phone);            //  e1[i]=c1[i];
            jack++;
        }
    }
    if(jack)
    {
        printf("Please verify by first name\n\n");
        scanf("%s",first);
        for(i=0; i<students; i++)
        {
            if (strcasecmp(c1[i].FirstName,first)==0&&strcasecmp(c1[i].LastName,last)==0)
            {
                c1[i]=c1[students-1];
                students--;
                printf("\nContact Deleted\n\n");
                return;
            }
        }
        printf("\nFirst name is incorrect!!\n\n");
    }
    if (!jack)
        printf("\nNOT FOUND\n");
}

void Welcome()
{
    notebook c1[100];
    Load(c1);
    printf("\n");
    int choice,flag=0;
    while(!flag)
    {
        printf("Choose your desired mode :\n");
        printf("1. Add\n2. Delete\n3. Search\n4. Modify\n5. Sort\n6. Save\n7. QUIT\n\n\n");
        scanf("%d",&choice);
        printf("\n\n");
        switch (choice)
        {
        case 1 :
            Add(c1);
            break;
        case 2 :
            Delete(c1);
            break;
        case 3 :
            search_contacts(c1);
            break;
        case 4 :
            Modify(c1);
            break;
        case 5 :
            Sort(c1);
            break;
        case 6 :
            Save(c1);
            break;
        case 7 :
            printf("Do you want to save your changes ??\n1. Yes\t2. No\t3. Back\n\n");
            int QuitChoice;
            scanf("%d",&QuitChoice);
            if (QuitChoice==1)
            {
                Save(c1);
                flag=1;
            }
            else if(QuitChoice==2)
            {
                printf("Not Saved !!\n\n");
                flag=1;
            }
            else if(QuitChoice==3)
            {
                printf("\n\nNot quitted\n\n");
            }
            else
            {
                printf("\n\nPlease enter valid choice.\n\n");
            }
            break;
        default:
            printf("Error !! Please enter right number.\n\n");
        }
    }
}
