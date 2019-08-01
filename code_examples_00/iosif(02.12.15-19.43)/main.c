#include <stdio.h>
#include <stdlib.h>

struct list_el
{
    int number;

    struct list_el* prev;
    struct list_el* next;
};

struct list_el* add_after_el(struct list_el* head, const int tmp)
{
    struct list_el* curr = head;

    if (curr)
    {
        while (curr->next)
            curr = curr->next;

        struct list_el* buff = calloc(1, sizeof(struct list_el));

        if (buff)
        {
            curr->next = buff;
            buff->number = tmp;
            buff->prev = curr;
            buff->next = NULL;
        }

        return buff;
    }
    else
    {
        struct list_el* buff = calloc(1, sizeof(struct list_el));

        if (buff)
        {
            buff->number = tmp;
            buff->prev = NULL;
            buff->next = NULL;

            return buff;
        }
        else
            return NULL;
    }
}

struct list_el* init_c_list(const int cnt)
{
    if (cnt > 0)
    {
        struct list_el* head = NULL;

        head = add_after_el(head, 1);

        if (head)
        {
            struct list_el* curr = head;

            int i = 2;

            while (i <= cnt)
            {
                curr = add_after_el(curr, i);

                i = i+1;

                if (!curr)
                    return head;
                    //return NULL;
            }

            curr->next = head;
            head->prev = curr;

            return head;
        }
        else
            return NULL;
    }
    else
        return NULL;
}

void print_c_list(struct list_el* head)
{
    if (head)
    {
        struct list_el* curr = head;

        //printf("\nLIST CONTAINS:\n");
        printf(" %d", curr->number);
        curr = curr->next;

        while ((curr)&&(curr != head))
        {
            printf(" %d", curr->number);
            curr = curr->next;
        }

        printf("\n");
    }
    else
        printf("(EMPTY)\n");
}

struct list_el* del_current(struct list_el* head)
{
    if (head != head->next)
    {
        struct list_el* prev = head->prev;
        struct list_el* next = head->next;

        free(head);

        prev->next = next;
        next->prev = prev;

        return next;
    }
    else
    {
        free(head);
        return NULL;
    }
}

void free_list(struct list_el* head)
{
    while (head)
        head = del_current(head);
}

int main(void)
{
    struct list_el* curr = NULL;
    int n = 0;
    int m = 0;

    printf ("Write N: ");

    if  (scanf("%d", &n) == 1)
    {
        if (n > 0)
        {
            printf ("Write M: ");

            if (scanf("%d", &m) == 1)
            {
                if (m > 0)
                {
                    curr = init_c_list(n);

                    printf("INITIAL LIST:\n");
                    if (curr)
                        print_c_list(curr);
                    else
                        printf("(EMPTY)\n");

                    int i = 0;

                    while ((curr) && (curr != curr->next))
                    {
                        i++;

                        if (i == m)
                        {
                            curr = del_current(curr);
                            //print_c_list(curr);
                            i = 0;
                        }
                        else
                            curr = curr->next;
                    }

                    printf("RESULT:");
                    print_c_list(curr);

                    free_list(curr);
                }
                else
                {
                    printf("ERROR! Wrong M value\n");
                    return -4;
                }
            }
            else
            {
                printf("ERROR! Wrong M input\n");
                return -3;
            }
        }
        else
            printf("ERROR! Wrong N value\n");
            return -2;
    }
    else
    {
        printf("ERROR! Wrong N input\n");
        return -1;
    }

    return 0;
}
