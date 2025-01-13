#include <stdio.h>

int lenofchararr(char arr[])
{
    int i = 0;
    while (arr[i] != '\0')
    {
        i++;
    }
    return i;
}

void onearray(char *arr1, char *arr2, char *out)
{
    int i = 0, j = 0;
    while (arr1[i] != '\0')
    {
        out[i] = arr1[i];
        i++;
    }
    while (arr2[j] != '\0')
    {
        out[i + j] = arr2[j];
        j++;
    }
    out[i + j] = '\0';
}

void merge(char arr[], int l, int m, int r)
{
    int i, j, k;
    int s1 = m - l + 1;
    int s2 = r - m;

    char L[s1], R[s2];

    for (i = 0; i < s1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < s2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0, j = 0, k = l;
    while (i < s1 && j < s2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < s1)
    {
        arr[k++] = L[i++];
    }
    while (j < s2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSortAlt(char  *arr1, char *arr2, char *out) {
    int i, j, k;
    i = 0, j = 0, k = 0;
    while(arr1[i] != '\0' && arr2[j] != '\0'){
        out[k++] = arr1[i++];
        out[k++] = arr2[j++];
    }
    while(arr1[i] != '\0'){
        out[k++] = arr1[i++];
    }
    while(arr2[j] != '\0'){
        out[k++] = arr2[j++];
    }
    out[k++] = '\0';
} 


void mergeSort(char arr[], int l, int r)
{
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    } 
}

int main()
{
    char arr1[100];
    char arr2[100];
    char concatarr[200];
    int selection;
    do
    {
        printf("Select which merge you want\n1) Alternating Letters\n2) In Order\n> ");
        scanf("%d", &selection);
    } while (selection != 1 && selection != 2);
    scanf("%s", arr1);
    scanf("%s", arr2);
    if(selection == 1){
            mergeSortAlt(arr1,arr2,concatarr);
    } else {
        onearray(arr1, arr2, concatarr);
        mergeSort(concatarr, 0, lenofchararr(concatarr) - 1);
    }
    printf("%s", concatarr);
    return 0;
} 