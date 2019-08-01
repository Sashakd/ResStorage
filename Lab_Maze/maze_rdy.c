#include "maze_rdy.h"
// �������� ���������� ��������  // -------- ���� ��������� �� ��������� ������ ��������� ����

// �������� ��������� �������� �� ������������
int check_maze_file(FILE* f) // ��������� ��������
{
    int h, w;
    if (fscanf(f, "[h: %d ; w: %d ]\n", &h, &w) == 2)
    {
        char ch;

        // ��������
        for (int i=0; i<h; i++)
        {
            //fscanf(f, "%c", &ch);
            for (int j=0; j<w; j++)
            {
                if ((fscanf(f, "%c", &ch) == 1)&&((i=0)||(i=w-1)))
                {
                    if (ch != '#')
                        return 0;
                }
                else
                {
                    if ((j == 0)||(j == h-1))
                    {
                        if (ch != '#')
                            return 0;
                    }
                    else
                    {
                        if (!((ch == '#')&&(ch == 'B')&&(ch == 'N')&&(ch == ' ')))
                            return 0;
                    }
                }
            }
            // ������� ��� ���
            fscanf(f, "%c", &ch);
        }
    }
    else
        return 0;

    rewind(f);

    return 1;
}

// ���������� �������� (�������) � ���������� ������
int* get_maze_arr(FILE* f, int *r, int *c, int max_sz)
{
    int *buf;

    int h, w;
	
	// if(check_maze_file(f))
	
    if (fscanf(f, "[h: %d ; w: %d]", &h, &w) == 2)
    {
	    *r = h;
		*c = w;
		
		if (((h*w) <= max_sz)&&((h*w) > 0))
		{
            buf = calloc(h*w, sizeof(int));

            if (buf)
            {
			    char ch; 
				
                // ��������� ���� ����
                for (int i=0; i<h; i++)
                {
                    // ������� ������ ��������
                    fscanf(f, "%c", &ch);

                    for (int j=0; j<w; j++)
                    {
                        if (fscanf(f, "%c", &ch) == 1)
                        {
                            if (ch == '#')
                                *(buf+i*w+j) = 1;
                            if (ch == 'B')
                                *(buf+i*w+j) = 2;
                            if (ch == 'N')
                                *(buf+i*w+j) = 3;
                        }
                        else
                            return NULL;
                    }       
                }
            }
            else
                return NULL;
        }
		else
		    return NULL;
	}
    else
        return NULL;

    return buf;
}

// ������ ���������.  (������ ����� � ���� ������� ���)
void print_maze(int* arr, int r, int c) // ����� ������� ���� �� ������ ���������, �� ���������� �������� B & N
{
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            int a = *(arr+i*c+j);

            switch(a) // �����
            {
                case 0:  // ��������
                    printf(" ");
                break;
                case 1:  // �����
                    printf("%c", 177);
                break;
                case 2:  // ������
                    printf("B");
                break;
                case 3:  // �����
                    printf("N");
                break;
                case 4:  // ����� ����������� ����
                    printf("X");
                break;
                case 5:  // ����� ������� �������
                    printf("%c", 1); // <--�������� �������
                break;
            }               
        }    
   
        printf("\n");
    }
}

// ������� ��������� � �������� (��������� �������� ��������)
int get_value_arr(int* arr, int ix, int jy, int c)
{
    return *(arr+ix*c+jy);
}
