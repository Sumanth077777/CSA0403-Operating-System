#include <stdio.h>          
struct Student {                              
    char name[20];
    int roll_number;
};          
int main()  
{ 
    FILE *fp;
    struct Student s = {"", 0};
    if (!(fp = fopen( "student.txt", "r+" ))) 
    {
      printf("File cannot be opened.");
      return 0;
    }
    while(1)
    {
        printf("Enter roll number from (1 to 100) , -1 to end input : ");
        scanf("%d",&s.roll_number);
        if(s.roll_number == -1)
            break;
        printf("Enter name : ");
        scanf("%s",s.name);
        fseek(fp,(s.roll_number-1)*sizeof(s),0);
        fwrite(&s, sizeof(s), 1, fp);
    }
    fclose(fp); 
    return 0;
}
