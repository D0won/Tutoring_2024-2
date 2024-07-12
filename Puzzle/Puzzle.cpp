#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Not__(void)
{
    printf("입력이 불가합니다. 다시 입력하세요 \n");
}

int main(void)
{
    int arr[5][5] = {0};
    int ser[25] = {0};
    int i,j,dir = 9,k = 0,end,temp, chec, chec_;

    srand((unsigned)time(NULL));

    k = 0;
    while(k < 25)
    {
        i = rand()%5;
        j = rand()%5;
        if(arr[i][j] == 0)
        {
            arr[i][j] = k;
            k++;
        }
    }

    end = 0;
    while(1)
    {
        for(i = 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(arr[i][j] == 0)
                    printf("%3c", '+');
                else
                    printf("%3d", arr[i][j]);
            }
            printf("\n");
        }
        if(chec_ == 5)
            break;
        chec = 0;
        for(i = 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(arr[i][j] == 0)
                {
                    printf("바꾸고 싶은 숫자를 입력하세요 : ");
                    scanf("%d",&dir);

                    if(arr[i+1][j] == dir)
                    {
                        if(i+1 == 5)
                        {
                            Not__();
                            continue;
                        }
                        temp = arr[i+1][j];
                        arr[i+1][j] = arr[i][j];
                        arr[i][j] = temp;
                        chec = 1;
                        break;
                    }
                    else if(arr[i-1][j] == dir)
                    {
                        if(i - 1 == -1)
                        {
                            Not__();
                            continue;
                        }
                        temp = arr[i-1][j];
                        arr[i-1][j] = arr[i][j];
                        arr[i][j] = temp;
                        chec = 1;
                        break;
                    }
                    else if(arr[i][j+1] == dir)
                    {
                        if(j+1 == 5)
                        {
                            Not__();
                            continue;
                        }
                        temp = arr[i][j+1];
                        arr[i][j+1] = arr[i][j];
                        arr[i][j] = temp;
                        chec = 1;
                        break;
                    }
                    else if(arr[i][j-1] == dir)
                    {
                        if(j-1 ==-1)
                        {
                            Not__();
                            continue;
                        }
                        temp = arr[i][j-1];
                        arr[i][j-1] = arr[i][j];
                        arr[i][j] = temp;
                        chec = 1;
                        break;
                    }
                    else
                    {
                        Not__();
                        continue;
                    }

                }
                    if(chec == 1)
                        break;
                }
                if(chec == 1)
                    break;
            }

        end = 0;
        for(i = 0; i < 5; i++)
        {
            chec_ = 0;
            for(j = 0; j < 5; j++)
            {
                if(arr[i][j] == end)
                {
                    end++;
                    chec_++;
                }
            }
            if(chec_ == 5)
                break;
        }
    }
}