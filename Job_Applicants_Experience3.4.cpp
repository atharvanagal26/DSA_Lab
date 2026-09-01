#include <iostream>
#include <string>
using namespace std;

struct Applicant {
    string name;
    int experience; // Years of experience
};

void merge(Applicant arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Applicant L[50], R[50];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].experience >= R[j].experience) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Applicant arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    Applicant candidates[5] = {
        {"Ram", 3},
        {"Sham", 8},
        {"Siya", 5},
        {"Diya", 12},
        {"Rahul", 2}
    };
    int n = 5;

    cout << "APPLICANTS LIST (UNSORTED)\n";
    for (int i = 0; i < n; i++) {
        cout << candidates[i].name << " - " << candidates[i].experience << " years exp\n";
    }

    // Perform Merge Sort
    mergeSort(candidates, 0, n - 1);

    cout << "\nMOST EXPERIENCED CANDIDATES FIRST\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << candidates[i].name << " - " << candidates[i].experience << " years exp\n";
    }

    return 0;
}