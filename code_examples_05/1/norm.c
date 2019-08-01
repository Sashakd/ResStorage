#include "norm.h"

/*
+0.1E+1
+4


*/

struct big_numb* move_mantis(struct big_numb*  num, char* side, char* rem)  // ��������
{
    if ((strncmp(side, "left", 4) == 0) || (strncmp(side, "right", 5) == 0))
	{
	    if (strncmp(side, "left", 4) == 0)  // �����
		{
		    *rem = *(num->mant);
			
		    for (int i = 1; i < num->m_len; i++)
			    num->mant[i-1] = num->mant[i];
			
			(num->m_len)--; 
		}
		else                                // ������
		{
		    *rem = *(num->mant + num->m_len - 1);
			
			for (int i = num->m_len - 1; i > 0; i--)
			    num->mant[i] = num->mant[i-1];
			
			*(num->mant) = '0';
		}
	
		return num;
	}
	else
	    return NULL;
}

int is_zero(struct big_numb*  num)  // ��������
{
    for (int i = 0; i < num->m_len; i++)
	    if (num->mant[i] != '0')
		    return 0;
	
	return 1;
}

struct big_numb* normalize(struct big_numb*  num)
{
    // ���� �� ���� ������ �� ����� � ����� ���� ����, �� ������� ���� ����� �� ����� � ������ �� ����
    // ����� ����� � ������ �� �����
	
	char rem = 0;
 
    if (is_zero(num)) // �������� �� ��������� ����
	{
		num->sign_m = '+';
		num->m_len = 1;
		num->dot_pos = 1;
		num->e = 0;
	}
	else
	{
	    // �������� ������ ����� ����������� ���������� ������ (������� �� ��������)
	    // �� �������� ����� � ��������� �����
	    //int i = 0;
		while ((num->mant[num->m_len-1] == '0') && (num->m_len >= num->dot_pos))  // � �����
			(num->m_len)--;
		
		// �������� ����� �� ������ ������� � ������ �������
		if ((num->dot_pos == 0) || (num->dot_pos == -1))  // ���� ��� �����
		{
		    num->dot_pos = 1;
			num->e += num->m_len;
		}
		else // � ������  /// <================== �����
		{
		    num->e += num->dot_pos-1; // <===== ���-�� �� ��� ���� dot_pos == 1
			/*
			if (num->mant[0] == '0')  // <== �����������
			    (num->e)--;
			*/
			
			num->dot_pos = 1;
			
			// ���-��� �� ������
			
			// �������� ����� ���� �� ������� ����� �������� �� ����
			while (num->mant[0] == '0')
			{
				num = move_mantis(num, "left", &rem);
				(num->e)--;
			}
		}
	}
    
	return num;
}
