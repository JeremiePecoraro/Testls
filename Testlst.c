#include "includes.h"

typedef struct lst{
    int nbr;
    struct lst *next;
    struct lst *prev; 
} type_lst;

int comp(const void *a, const void *b) {
    const int *pa = (const int *) a;
    const int *pb = (const int *) b;
    return (*pa) - (*pb);
}

int main(void) {

    int array_int[5] = {5, 6, 4, 2, 1};
    int i = 0;

    int size = sizeof(array_int) / sizeof(int);
    qsort(array_int, size, sizeof(int), comp);

    type_lst *lst_0 = (type_lst *) malloc(sizeof(type_lst));
    type_lst *lst_1 = (type_lst *) malloc(sizeof(type_lst));
    type_lst *lst_2 = (type_lst *) malloc(sizeof(type_lst));
    type_lst *lst_3 = (type_lst *) malloc(sizeof(type_lst));
    type_lst *lst_4 = (type_lst *) malloc(sizeof(type_lst));

    lst_0->nbr = array_int[0];
    lst_1->nbr = array_int[1];
    lst_2->nbr = array_int[2];
    lst_3->nbr = array_int[3];
    lst_4->nbr = array_int[4];

    lst_0->next = lst_1;
    lst_1->next = lst_2;
    lst_2->next = lst_3;
    lst_3->next = lst_4;
    lst_4->next = lst_0; 
    
    lst_0->prev = lst_4; 
    lst_1->prev = lst_0;
    lst_2->prev = lst_1;
    lst_3->prev = lst_2;
    lst_4->prev = lst_3;

    while (i < 5) {
        printf("%i\n", array_int[i]);
        i++;
    }

    type_lst *lst_temp = lst_0;
    do {
        printf("le nbr est : %i\n", lst_temp->nbr);
        lst_temp = lst_temp->next;
    } while (lst_temp != lst_0);

    lst_temp = lst_0->next;
    free(lst_0);
    lst_0 = lst_temp;

    lst_temp = lst_1->next;
    free(lst_1);
    lst_1 = lst_temp;

    lst_temp = lst_2->next;
    free(lst_2);
    lst_2 = lst_temp;

    lst_temp = lst_3->next;
    free(lst_3);
    lst_3 = lst_temp;

    lst_temp = lst_4->next;
    free(lst_4);
    lst_4 = lst_temp;

    return 0;
}
