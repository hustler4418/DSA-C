#include<stdio.h>

int main() {
    int arr[100];
    int s = 8;

    for (int i = 0; i < s; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
        getchar();
    }

    int start = 0;
    int end = s;
    int key = 71;

    while (start < end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            printf("Key found at index %d\n", mid);
            break;  // Add break to exit the loop when the key is found
        } else if (arr[mid] < key) {
            start = mid;  // Adjust start index
        } else {
            end = mid;  // Adjust end index
        }
    }

    return 0;
}
