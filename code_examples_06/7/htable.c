/// ������ ��� ���������� �����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "readstr.h"

#define BUF 5

/// \brief �������������� ���� ������  ������
/// \details �������� ��� ��������, ���� �� ��������� 0
/// \param [in] s - ������, �� ������� ����������
/// \param [in,out] s2 - ������, � ������� ����������
void dubbing(const char *s, char *s2)
{
    int i = 0;
    do
    {
        s2[i] = s[i];
        i++;
    }
    while (s[i-1] != '\0');
}

/// \brief ���������� ������ �� �����
/// \details ���������� ����� ��������� ���������
/// \param [in] f - ����, �� �������� ���������� ������
/// \param [out] *s - ��������� �� ����������� ������
char* freadstring(FILE *f, int* N)
{
    int t=0;
    char *s2;
    char *s = malloc(BUF*sizeof(char));
    if (s == NULL)
        return s;
    char *det = fgets(s, BUF, f);
    if (det == NULL)
    {
        free(s);
        return NULL;
    }
    while (strchr(s, '\n') == NULL && !feof(f))
    {
        t = BUF + strlen(s);
        s2 = malloc(t*sizeof(char));
        if (s2 == NULL)
            return NULL;
        dubbing(s, s2);
        free(s);
        s = s2;
        fgets(s+strlen(s), BUF, f);
    }
    t = strlen(s)+1;
    s2 = malloc(t*sizeof(char));
    if (s2 == NULL)
        return NULL;
    dubbing(s, s2);
    free(s);
    s = s2;
    *N = t;
    return s;
}
