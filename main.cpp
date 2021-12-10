#include <fstream>
#include <cstdlib>
#include <ctime>
long long partition(long long* a, long long l, long long r) {
    long long i = l;
    long long j = r;
    long long index = l + (rand()%(r-l));
    long long pivot = a[index];
    do {
        while(a[i] < pivot) {
            ++i;
        }
        while(a[j] > pivot) {
            --j;
        }
        if ( i >= j) {
            break;
        }
        std::swap(a[i++], a[j--]);
    } while (true);
    return j;
}

void quick_sort(long long* a, long long l, long long r) {
    if (r - l < 1) {
        return;
    }
    long long p = partition(a, l, r);
    quick_sort(a, l, p);
    quick_sort(a, p+1, r);
}

int main() {
    srand(time(nullptr));
    long long n;
    std::ifstream fin("sort.in");
    std::ofstream fout("sort.out");
    fin >> n;
    long long* b = new long long[n];
    for (long long i = 0; i < n; ++i) {
        fin >> b[i];
    }
    quick_sort(b, 0, n-1);
    for (long long i = 0; i < n; ++i) {
        fout << b[i] << " ";
    }
    return 0;
}