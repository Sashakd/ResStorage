#include "bnumb.h"
#include "print_text.h"
#include "norm.h"
#include "multiply.h"

#include <stdio.h>
#include <locale.h>
#include <string.h>

// ������� 26 ???
// ������ 1 (2)

/*
TESTS
-24.3673E-35
-.13E-12
+0.1E-132
+1
+12345676543234565432345
+123456543212345665432345676543
-1234567876543212345654323454312


���������:     
	
	+0.5E+1

      *

     -2

      =

     -0.1E+1
	 
	 11*12
*/



int main(void)
{
	int choice = 0;
	
	setlocale(LC_ALL , "Rus");
	
	while (1)
	{
	    print_menu();
	
	    if (scanf("%d", &choice) == 1)
	    {
	        switch(choice)
       	    {
			/*
		        case 1:
			    {
				    struct big_numb* n1;
					
					print_i_line(2);
					
					printf("���� : ");
					n1 = get_i_big_numb(stdin);
					printf("\n�����: ");
					if (n1)
					    print_big_numb(*n1);
					else
					    printf("---");
					printf("\n");
					
			        break;
			    }
			    case 2:
			    {
				    struct big_numb* n2;
					
					print_f_line(2);
					
					printf("���� : ");
					n2 = get_big_numb(stdin);
					printf("\n�����: ");
					if (n2)
					    print_big_numb(*n2);
					else
					    printf("---");
					printf("\n");
					
			        break;
			    }
				case 3:
				{
				    struct big_numb* n3;
					
					print_f_line(2);
					
					printf("���� : ");
					n3 = get_big_numb(stdin);
					printf("\n�����: ");
					if (n3)
					    print_big_numb(*n3);
					else
					    printf("---");
						
					printf("\n�������: ");
					print_mantis(n3->mant, n3->dot_pos, n3->m_len);
					printf("\n");
					printf("\n");
					
				    char answ[7];
					char rem = '0';
					
					printf("\n������� ����������� ������ (L/R):\n");
					
				    scanf("%s", answ);
					
					if ((strncmp(answ, "L", 5) == 0) || (strncmp(answ, "R", 6) == 0))
					{
					    if (strncmp(answ, "L", 5) == 0) // �����
						{
						    n3 = move_mantis(n3, "left", &rem);
							(n3->m_len)--;
						}
						else  // ������
						    n3 = move_mantis(n3, "right", &rem);
						
						printf("\n�������: ");
					    print_mantis(n3->mant, n3->dot_pos, n3->m_len);
					    printf("\n");
						printf("���: %c\n", rem);
					    printf("\n");
					}
					else
					    printf("\n\n������! ������������ ���� ��������. �������� ����������.\n");
						
					break;
				}
				case 4:
				{
				    struct big_numb* n4;  // ������������
					
					print_i_line(2);
					
					printf("���� : ");
					n4 = get_big_numb(stdin);
					printf("\n�����: ");
					if (n4)
					{
					    print_big_numb(*n4);
						printf("\n����:  ");
						n4 = normalize(n4);
						print_big_numb(*n4);
						printf("\n");
					}
					else
					    printf("---");
					
					printf("\n");
					
					break;
				}
			*/
				case 5:
				{
				    // ���������
					struct big_numb* n5; // �����
					struct big_numb* n6; // ������������
					struct big_numb* result;
					
					printf("������� ��������������: \n");
					print_f_line(0);
					printf("     ");
					n6 = get_big_numb(stdin);
					
					if (n6)
					{
						printf("������� �����: \n");
						print_i_line(0);
						printf("     ");
					    n5 = get_i_big_numb(stdin);
						
						if (n5)
						{
							result = multiply_FxI(n5, n6);
							if (result)
							{
								printf("\n\n");
								printf("���������:\n\n");
								printf("     ");
								print_big_numb(*n6);
								printf("\n\n      * \n\n");
								printf("     ");
								print_i_big_numb(*n5);
								printf("\n\n      = \n\n");
								printf("     ");
								print_big_numb(*result);
								printf("\n");
								print_f_line(0);
								printf("\n\n");
							}
							else
								printf("������! ������������ �������!");
						}
						else
							printf("������! �������� ���� ������! (������ ������ �����)");
					}
					else
						printf("������! �������� ���� �������������! (������ ������ �����)");
					
					printf("\n");
					
					break;
				}
			    case 6:
			    {
			        return 0;
			    }
			    default:
			    {
			        printf("\n\n����� �������� ���! ���������� �����.\n");
				    break;
			    }
		    }	
	    }
	    else
		{
	        printf("\n\n������! ������������ ���� ��������. �������� ����������.\n");
			return -1;
		}
	}
	
    return 0;
}