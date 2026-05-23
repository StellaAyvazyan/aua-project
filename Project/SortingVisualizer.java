import java.util.Scanner;

public class SortingVisualizer{

    static int comparisons = 0;
    static int swaps = 0;

    static void show(int[] a, int i, int j){
        if (i!=-1 && j!=-1) {
            System.out.println("Comparing: " + a[i] + " and " + a[j]);
        }

        System.out.println("Comparisons: " + comparisons + "  Swaps/Moves: " + swaps);

        for (int value : a){
            System.out.printf("%2d: ", value);
            for (int k = 0; k < value; k++)
                System.out.print("#");
            System.out.println();
        }

        System.out.println("----------------------");
    }

    static void bubble(int[] a){
        for (int i = 0; i < a.length-1; i++){
            for (int j = 0; j < a.length-i-1; j++){
                comparisons++;
                show(a, j, j+1);

                if (a[j] > a[j+1]){
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;

                    swaps++;
                    show(a, j, j+1);
                }
            }
        }
    }

    static void insertion(int[] a){
        for (int i = 1; i < a.length; i++){
            int key = a[i];
            int j = i-1;

            while (j >= 0){
                comparisons++;
                show(a, j, i);

                if (a[j] > key){
                    a[j+1] = a[j];
                    swaps++;
                    j--;
                } else{
                    break;
                }
            }

            a[j+1] = key;
            swaps++;
            show(a, j+1, i);
        }
    }

    static void mergeSort(int[] a, int prev, int next){
        if (prev >= next) return;

        int mid = (prev + next)/2;

        mergeSort(a, prev, mid);
        mergeSort(a, mid+1, next);
        merge(a, prev, mid, next);
    }

    static void merge(int[] a, int prev, int mid, int next){
        int[] temp = new int[a.length];

        int i = prev, j = mid+1, k = prev;

        while (i <= mid && j <= next){
            comparisons++;
            show(a, i, j);

            if (a[i] < a[j]){
                temp[k++] = a[i++];
            } else{
                temp[k++] = a[j++];
            }

            swaps++;
        }

        while (i <= mid){
            temp[k++] = a[i++];
            swaps++;
        }

        while (j <= next){
            temp[k++] = a[j++];
            swaps++;
        }

        for (i = prev; i <= next; i++){
            a[i] = temp[i];
        }

        show(a, -1, -1);
    }

    static void quickSort(int[] a, int low, int high){
        if (low >= high) return;

        int p = partition(a, low, high);

        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }

    static int partition(int[] a, int low, int high){
        int pivot = a[high];
        int i = low-1;

        for (int j = low; j < high; j++){
            comparisons++;
            show(a, j, high);

            if (a[j] < pivot){
                i++;

                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                swaps++;
                show(a, i, j);
            }
        }

        int temp = a[i+1];
        a[i+1] = a[high];
        a[high] = temp;

        swaps++;
        show(a, i+1, high);

        return i+1;
    }

    static void reset(){
        comparisons = 0;
        swaps = 0;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size: ");
        int n = sc.nextInt();

        int[] original = new int[n];

        System.out.println("Enter numbers:");
        for (int i = 0; i < n; i++)
            original[i] = sc.nextInt();

        System.out.println("\n1. Bubble\n2. Insertion\n3. Merge\n4. Quick");
        System.out.print("Choose: ");
        int choice = sc.nextInt();

        int[] a = original.clone();
        reset();

        if (choice == 1) bubble(a);
        else if (choice == 2) insertion(a);
        else if (choice == 3) mergeSort(a, 0, a.length - 1);
        else if (choice == 4) quickSort(a, 0, a.length - 1);

        System.out.println("\nFinal sorted array:");
        show(a, -1, -1);
    }
}