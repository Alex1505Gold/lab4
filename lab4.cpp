

#include <iostream>
#include <ctime>

void cocktail(int arr[], int n) {
    int8_t f = 1;
    int strt = 0;
    int end = n - 1;
    while (f) {
        for (int i = strt; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                int k = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = k;
                f = 1;
            }  
        }
    if (!f) break;
    f = 0;
    end--;
    for (int i = end - 1; i >= strt; --i) {
        if (arr[i] > arr[i + 1]) {
            int k = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = k;
            f = 1;
        }
    }
    strt++;
    }        
}

void merge_o(int [], int, int, int);

void merge_s(int arr[], int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        merge_s(arr, l, mid);
        merge_s(arr, mid + 1, h);
        merge_o(arr, l, h, mid);
    }
 
}

void merge_o(int arr[], int l, int h, int mid) {
    int i, j, k, c[50];
    i = l;
    k = i;
    j = mid + 1;
    while ((i <= mid) && (j <= h)) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            ++k; ++i;
        }
        else {
            c[k] = arr[j];
            ++k; ++j;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= h) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (int y = l; y < k; ++y) arr[y] = c[y];
}

void shell(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int tmp = arr[i];
            int j;
            for (j = i; (j >= gap) && (arr[j - gap] > tmp); j -= gap) arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
    }
}

int main()
{
    int a[30];
    std::srand(std::time(nullptr));
    for (int i = 0; i < 30; ++i) {
        a[i] = std::rand() % 201 - 100;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    cocktail(a, 30);
    for (int i = 0; i < 30; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 30; ++i) {
        a[i] = std::rand() % 201 - 100;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    merge_s(a, 0, 30 - 1);
    for (int i = 0; i < 30; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 30; ++i) {
        a[i] = std::rand() % 201 - 100;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    shell(a, 30);
    for (int i = 0; i < 30; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}


