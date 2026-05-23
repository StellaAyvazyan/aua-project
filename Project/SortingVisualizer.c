#include <stdio.h>

int comparisons = 0;
int swaps = 0;

void show(int a[], int n, int i, int j) {
    int k, value;

    if (i != -1 && j != -1) {
        printf("Comparing: %d and %d\n", a[i], a[j]);
    }

    printf("Comparisons: %d  Swaps/Moves: %d\n", comparisons, swaps);

    for (k = 0; k < n; k++) {
        value = a[k];

        printf("%2d: ", value);

        for (int x = 0; x < value; x++) {
            printf("#");
        }

        printf("\n");
    }

    printf("----------------------\n");
}

void bubble(int a[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            comparisons++;
            show(a, n, j, j + 1);

            if (a[j] > a[j + 1]) {

                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swaps++;
                show(a, n, j, j + 1);
            }
        }
    }
}

void insertion(int a[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {

        key = a[i];
        j = i - 1;

        while (j >= 0) {

            comparisons++;
            show(a, n, j, i);

            if (a[j] > key) {
                a[j + 1] = a[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }

        a[j + 1] = key;
        swaps++;

        show(a, n, j + 1, i);
    }
}

void merge(int a[], int n, int left, int mid, int right) {
    int temp[100];
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {

        comparisons++;
        show(a, n, i, j);

        if (a[i] < a[j]) {
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }

        swaps++;
        k++;
    }

    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
        swaps++;
    }

    while (j <= right) {
        temp[k] = a[j];
        j++;
        k++;
        swaps++;
    }

    for (i = left; i <= right; i++) {
        a[i] = temp[i];
    }

    show(a, n, -1, -1);
}

void mergeSort(int a[], int n, int left, int right) {

    int mid;

    if (left >= right) {
        return;
    }

    mid = (left + right) / 2;

    mergeSort(a, n, left, mid);
    mergeSort(a, n, mid + 1, right);

    merge(a, n, left, mid, right);
}

int partition(int a[], int n, int low, int high) {

    int pivot = a[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++) {

        comparisons++;
        show(a, n, j, high);

        if (a[j] < pivot) {

            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            swaps++;
            show(a, n, i, j);
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    swaps++;
    show(a, n, i + 1, high);

    return i + 1;
}

void quickSort(int a[], int n, int low, int high) {

    int p;

    if (low >= high) {
        return;
    }

    p = partition(a, n, low, high);

    quickSort(a, n, low, p - 1);
    quickSort(a, n, p + 1, high);
}

void reset() {
    comparisons = 0;
    swaps = 0;
}

int main() {

    int n, choice;
    int original[100];
    int a[100];

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter numbers:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &original[i]);
    }

    printf("\n1. Bubble\n2. Insertion\n3. Merge\n4. Quick\n");
    printf("Choose: ");
    scanf("%d", &choice);

    for (int i = 0; i < n; i++) {
        a[i] = original[i];
    }

    reset();

    if (choice == 1) {
        bubble(a, n);
    }
    else if (choice == 2) {
        insertion(a, n);
    }
    else if (choice == 3) {
        mergeSort(a, n, 0, n - 1);
    }
    else if (choice == 4) {
        quickSort(a, n, 0, n - 1);
    }

    printf("\nFinal sorted array:\n");
    show(a, n, -1, -1);

    return 0;
}
