#include<stdio.h>
#include<conio.h>   //ʹ��getch()���� 
#include<time.h> 
#include <stdlib.h>
int num[4][4];
int score, gameover, ifappear, gamew, gamef,move;
char key;
int main();
void explation()
{
    void menu();
    system("cls");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t******************        ***************\n");
    printf("\t\t******************��Ϸ����***************\n");
    printf("\t\t******************        ***************\n");
    printf("\t\t*****************************************\t\t\n");
    printf("��ҿ���ѡ���ϡ��¡����һ�W��A��S��Dȥ�ƶ�����\n");
    printf("���ѡ��ķ�����������ͬ��������ϲ�\n");
    printf("�ϲ����õ�����������������Ӽ�Ϊ�ò�����Ч�÷�\n");
    printf("���ѡ��ķ����л���ǰ���пո������λ��\n");
    printf("ÿ�ƶ�һ������λ�������һ��2��4\n");
    printf("���̱������������޷�������Ч�ƶ����и�����Ϸ����\n");
    printf("�����ϳ���2048����ʤ����Ϸ����\n");
    printf("����������ȥ�ƶ�����\n");
    printf("�밴������������˵�...\n");
    getch();
    system("cls");
    main();
}
void gamefaile()
{
    int i, j;
    system("cls");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t*****************          **************\n");
    printf("\t\t***************** You Fail **************\n");
    printf("\t\t*****************          **************\n");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t\t---------------------\n\t\t\t");
    for (j = 0; j<4; j++)
    {
        for (i = 0; i<4; i++)
            if (num[j][i] == 0)
                printf("|    ");
            else
                printf("|%4d", num[j][i]);
        printf("|\n");
        printf("\t\t\t---------------------\n\t\t\t");
    }
    printf("��ĳɼ���%d,�ƶ���%d��\n", score,move);
    printf("�밴������������˵�...\n");
    getch();
    system("cls");
    main();
 
}
void gamewin()
{
    int i, j;
    system("cls");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t******************         **************\n");
    printf("\t\t****************** You Win **************\n");
    printf("\t\t******************         **************\n");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t\t---------------------\n\t\t\t");
    for (j = 0; j<4; j++)
    {
        for (i = 0; i<4; i++)
            if (num[j][i] == 0)
                printf("|    ");
            else
                printf("|%4d", num[j][i]);
        printf("|\n");
        printf("\t\t\t---------------------\n\t\t\t");
    }
    printf("��ĳɼ���%d,�ƶ���%d��\n", score,move);
    printf("�밴������������˵�...\n");
    getch();
    system("cls");
    main();
}
void prin()
{
    int i, j;
    system("cls");
    printf("\t\t*****************************************\t\t\n");//�������
    printf("\t\t*****************          **************\n");
    printf("\t\t***************** ��Ϸ��ʼ **************\n");
    printf("\t\t*****************          **************\n");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t      �밴�������W��A��S��D�ƶ�����\n");//���������ʾ���
    printf("\t\t          ��ESC���������˵�\n");
    printf("\t\t\t---------------------\n\t\t\t");
    for (j = 0; j<4; j++)                 //���4*4�ı��
    {
        for (i = 0; i<4; i++)
            if (num[j][i] == 0)
                printf("|    ");
            else
                printf("|%4d", num[j][i]);
        printf("|\n");
        printf("\t\t\t---------------------\n\t\t\t");
    }
    printf("��ĳɼ���%d���ƶ���%d��\n", score,move);//����÷ֺ��ƶ�����
}
void appear()
{
    int i, j,ran,t[16],x=0,a,b;
    srand((int)time(0));          //������ӳ�ʼ��
    for (j = 0; j < 4; j++)      //���հ׵���������걣�浽�м�����t��
        for (i = 0; i < 4;i++)
            if (num[j][i] == 0)
            {
                t[x] = j * 10 + i;
                x++;
            }
    if (x == 1)            //��t�����ȡһ������
        ran = x - 1;
    else
        ran = rand() % (x - 1);
    a = t[ran] / 10;      //ȡ�������ֵ��ʮλ��
    b = t[ran] % 10;     //ȡ�������ֵ�ĸ�λ��
    srand((int)time(0));
    if ((rand() % 9)>2)    //�ڴ˿հ����������ֵ2��4
        num[a][b] = 2;
    else
        num[a][b] = 4;
}
void close()
{
    exit(0);
}
void add(int *p)
{
     
    int i=0, b;
    while (i<3)
    {
        if (*(p + i) != 0)
        {
            for (b = i + 1; b < 4; b++)
            {
                if (*(p + b) != 0)
                    if (*(p + i) == *(p + b))
                    {
                    score = score + (*(p + i)) + (*(p + b));
                    *(p + i) = *(p + i) + *(p + b);
                    if (*(p + i) == 2048)
                        gamew = 1;
                    *(p + b) = 0;
                    i = b + i;
                    ++ifappear;
                    break;
                    }
                    else
                    {
                        i = b;
                        break;
                    }
            }
            if (b == 4)
                i++;
        }
        else
            i++;
    }
 
}
void Gameplay()
{
    int i, j, g, e, a, b[4];
    appear();
    appear();
    while (1)
    {
        if (ifappear!=0)
            appear();
        prin();
        key = getch();
        switch (key)
        {
        case 'w':
        case 'W':
        case 72:
            ifappear = 0;
            for (j = 0; j < 4; j++)
            {
                for (i = 0; i < 4; i++)
                {
                    b[i] = num[i][j];
                    num[i][j] = 0;
                }
                add(b);
                e = 0;
                for (g = 0; g < 4; g++)
                {
                    if (b[g] != 0)
                    {
                        num[e][j] = b[g];
                        if (g != e)
                            ++ifappear;
                        e++;
                    }
                }
            }
            if (ifappear!=0)
                ++move;
        break;
        case 's':
        case 'S':
        case 80:
            ifappear = 0;
            for (j = 0; j < 4; j++)
            {
                for (i = 0; i < 4; i++)
                {
                    b[i] = num[i][j];
                    num[i][j] = 0;
                }
                add(b);
                e = 3;
                for (g = 3; g>=0; g--)
                {
                    if (b[g] != 0)
                    {
                        num[e][j] = b[g];
                        if (g != e)
                            ++ifappear;
                        e--;
                    }
                }
            }
            if (ifappear != 0)
                ++move;
        break;
        case 'a':
        case 'A':
        case  75:
            ifappear = 0;
            for (j = 0; j < 4; j++)
            {
                for (i = 0; i < 4; i++)
                {
                    b[i] = num[j][i];
                    num[j][i] = 0;
                }
                add(b);
                e = 0;
                for (g = 0; g < 4; g++)
                {
                    if (b[g] != 0)
                    {
                        num[j][e] = b[g];
                        if (g!=e)
                            ++ifappear;
                        e++;
                    }
                }
            }
            if (ifappear != 0)
                ++move;
        break;
        case 'd':
        case 'D':
        case  77:
            ifappear = 0;
            for (j = 0; j < 4; j++)
            {
                for (i = 0; i < 4; i++)
                {
                    b[i] = num[j][i];
                    num[j][i] = 0;
                }
                add(b);
                e = 3;
                for (g = 3; g >=0; g--)
                {
                    if (b[g] != 0)
                    {
                        num[j][e] = b[g];
                        if (g!=e)
                            ++ifappear;
                        e--;
                    }
                }
            }
            if (ifappear != 0)
                ++move;
        break;
        case 27:
            system("cls");
            main();
            break;
 
        }
        for (j = 0; j < 4; j++)
        {
            for (i = 0; i < 4; i++)
            {
                if (j < 3)
                {
                    if (i < 3)
                    {
                        if (num[j][i] == num[j + 1][i] || num[j][i] == num[j][i + 1] || num[j][i] == 0)
                        {
                            gamef = 0;
                            break;
                        }
                        else
                            gamef = 1;
                    }
                    else
                    {
                        if (num[j][i] == num[j + 1][i] || num[j][i] == 0)
                        {
                            gamef = 0;
                            break;
                        }
                        else
                            gamef = 1;
                    }
                }
                else
                {
                    if (i < 3)
                    {
                        if (num[j][i] == num[j][i + 1] || num[j][i] == 0 || num[j][i + 1] == 0)
                        {
                            gamef = 0;
                            break;
                        }
                        else
                            gamef = 1;
                    }
                }
 
            }
            if (gamef == 0)
                break;
        }
        if (gamef == 1 || gamew == 1)
            break;
 
    }
    if (gamef == 1)
        gamefaile();
    else
        gamewin();
}
void menu()
{
    int n;
    printf("\t\t*****************************************\t\t\n");            //�����Ϸ�˵���ͼ��
    printf("\t\t*              1����ʼ��Ϸ              *\n");
    printf("\t\t*              2����Ϸ����              *\n");
    printf("\t\t*              3���˳���Ϸ              *\n");
    printf("\t\t*****************************************\n");
    printf("������1��2��3:[ ]\b\b");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        Gameplay();                                                         //��Ϸ��ʼ����
        break;
    case 2:
        explation();                                                       //��Ϸ������
        break;
    case 3:
        close();                                                          //�ر���Ϸ����
        break;
    }
}
int main()
{
    int j, i;
    for (j = 0; j < 4; j++)             //��4*4���г�ʼ��ֵΪ0
        for (i = 0; i < 4; i++)
            num[j][i] = 0;
    gamew = 0;                        //��Ϸ��ʤ���жϱ�����ʼ��
    gamef = 0;                       //��Ϸʧ�ܵ��жϱ�����ʼ��
    ifappear = 0;                   //�ж��Ƿ�Ӧ���������2��4�ı�����ʼ��
    score = 0;                     //��Ϸ�÷ֱ�����ʼ��
    gameover = 0;                 //��Ϸ�Ƿ�����ı�����ʼ��
    move = 0;                    //��Ϸ���ƶ�������ʼ��
    menu();                     //�������˵�����
    return 0;
}
