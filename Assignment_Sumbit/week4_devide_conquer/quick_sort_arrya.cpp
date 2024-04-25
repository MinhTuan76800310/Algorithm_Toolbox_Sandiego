#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define MAXN 150000

void NhapMang(int A[], int& N);
void XuatMang(int A[], const int& N);
void hoanvi(int& x, int& y);

vector<int> Partition3(vector<int>& a, int l, int r);
void randomized_quick_sort(vector<int>& a, int l, int r);
void quick_sort_ascending(int a[], int n);

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    quick_sort_ascending(a, n);

    XuatMang(a, n);

    return 0;
}

void NhapMang(int A[], int& N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void XuatMang(int A[], const int& N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

void hoanvi(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
vector<int> Partition3(vector<int>& a, int l, int r) {
    int iter = l;
    vector<int> _equal(2);
    while (iter <= r) {
        if (a[iter] < a[l]) {
            swap(a[iter], a[l]);
            l++;
            iter++;
        }
        else if (a[iter] > a[l]) {
            swap(a[iter], a[r]);
            r--;
        }
        else {
            iter++;
        }
        _equal[0] = l;
        _equal[1] = r;
    }
    return _equal;
}

void randomized_quick_sort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> m(2);
    m = Partition3(a, l, r);

    randomized_quick_sort(a, l, m[0] - 1);
    randomized_quick_sort(a, m[1] + 1, r);
}

void quick_sort_ascending(int a[], int n) {
    vector<int> temp(a, a + n);
    randomized_quick_sort(temp, 0, n - 1);
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}
