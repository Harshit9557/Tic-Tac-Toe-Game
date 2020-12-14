#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,m,n,l,b,v;
    for(k=0;;k++)
    {
        char z,t;
        if(z=='Y' || k==0)
        {
            l=0;
            char s1[100],s2[100],s3[100],s4[100],a[3][3];
            fflush(stdin);
            printf("Enter a name for X player : \n");
            gets(s1);
            printf("Enter a name for the O player : \n");
            gets(s2);
            for(i=0;;i++)
            {
                printf("Who plays first, %s or %s?\n",s1,s2);
                gets(s3);
                if(strcmp(s3,s2)==0 || strcmp(s3,s1)==0)
                    break;
                else
                    printf("%s is not a registered player\n",s3);
            }
            if(strcmp(s3,s2)==0)
                strcpy(s4,s1);
            else if(strcmp(s3,s1)==0)
                strcpy(s4,s2);
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    a[i][j]='.';
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                    printf("%c ",a[i][j]);
                printf("\n");
            }
            for(i=0;i<9;i++)
            {
                if(i%2==0)
                {
                    printf("Player of current turn : ");
                    puts(s3);
                    printf("\n");
                }
                else
                {
                    printf("Player of current turn : ");
                    puts(s4);
                    printf("\n");
                }
                for(j=0;;j++)
                {
                    printf("Choose a row number (0 to 2) :\n");
                    scanf("%d",&m);
                    if(m>2 || m<0)
                        printf("%d is not a valid row.\n",m);
                    else
                    {
                        printf("Choose a column number (0 to 2) :\n");
                        scanf("%d",&n);
                        if(n>2 || n<0)
                            printf("%d\n%d is not a valid column.\n",m,n);
                        else
                            break;
                    }
                }
                if(i%2==0 && a[m][n]=='.')
                {
                    a[m][n]='X';
                    for(b=0;b<3;b++)
                    {
                        for(j=0;j<3;j++)
                            printf("%c ",a[b][j]);
                        printf("\n");
                    }
                }
                else if(i%2!=0 && a[m][n]=='.')
                {
                    a[m][n]='O';
                    for(b=0;b<3;b++)
                    {
                        for(j=0;j<3;j++)
                            printf("%c ",a[b][j]);
                        printf("\n");
                    }
                }
                else
                    printf("The column is occupied. Please enter a valid row and column\n");
                char t;
                if(a[0][0]==a[0][1] && a[0][0]==a[0][2])
                {
                    t=a[0][0];
                    l=1;
                }
                else if(a[1][0]==a[1][1] && a[1][0]==a[1][2])
                {
                    t=a[1][0];
                    l=1;
                }
                else if(a[2][0]==a[2][1] && a[2][1]==a[2][2])
                {
                    t=a[2][0];
                    l=1;
                }
                else if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
                {
                    t=a[0][0];
                    l=1;
                }
                else if(a[0][2]==a[1][2] && a[1][2]==a[2][2])
                {
                    t=a[1][2];
                    l=1;
                }
                else if(a[0][1]==a[1][1] && a[1][1]==a[2][1])
                {
                    t=a[1][1];
                    l=1;
                }
                else if(a[0][0]==a[1][0] && a[1][0]==a[2][0])
                {
                    t=a[1][0];
                    l=1;
                }
                else if(a[0][2]==a[1][1] && a[1][1]==a[2][0])
                {
                    t=a[0][2];
                    l=1;
                }
                if(l==0 && t!='.' || l==1 && t!='.')
                {
                    printf("Game is over:\n");
                    if(l==0)
                        printf("It is a tie!\n");
                    else if(t=='X')
                    {
                        puts(s3);
                        printf("wins!\n");
                    }
                    else
                    {
                        puts(s4);
                        printf("wins!\n");
                    }
                    for(v=0;;v++)
                    {
                        printf("Would you like to play again? (Y/N)\n\n\n");
                        scanf("%c",&z);
                        if(z=='Y' || z=='N')
                            break;
                        else
                            printf("%c is not a valid answer.\n",z);
                    }
                    break;
                }
            }
        }
        else
        {
            printf("Bye!");
            break;
        }
    }
    return 0;
}
