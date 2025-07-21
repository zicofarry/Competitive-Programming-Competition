#include <stdio.h>

typedef struct {
    int nomor;
    int k;
    long long a, b;
} Tim;

long long maxPenonton = 0;

void simulasi(Tim tim[], int ukuran, long long penontonSaatIni) {
    // if (penontonSaatIni + (ukuran / 2) * 1000000000 < maxPenonton) return; // Pruning: Skip jika tidak bisa lebih optimal

    if (ukuran == 1) { 
        if (penontonSaatIni > maxPenonton) {
            maxPenonton = penontonSaatIni;
        }
        return;
    }

    // Tim nextRound[ukuran / 2];
    static Tim nextRound[1 << 16];

    for (int mask = 0; mask < (1 << (ukuran / 2)); mask++) {
        long long totalPenonton = penontonSaatIni;

        for (int i = 0; i < ukuran; i += 2) {
            int idx = i / 2;
            long long penonton = 0;

            if (mask & (1 << idx)) {
                if (tim[i].k < tim[i + 1].k) {
                    penonton = tim[i].a + tim[i + 1].b;
                } else {
                    penonton = tim[i + 1].a + tim[i].b;
                }
                nextRound[idx] = tim[i];
            } else {
                if (tim[i + 1].k < tim[i].k) {
                    penonton = tim[i + 1].a + tim[i].b;
                } else {
                    penonton = tim[i].a + tim[i + 1].b;
                }
                nextRound[idx] = tim[i + 1];
            }

            totalPenonton += penonton;
        }

        simulasi(nextRound, ukuran / 2, totalPenonton);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int m = 1 << n;
    Tim tim[m];

    for (int i = 0; i < m; i++) {
        scanf("%d %lld %lld", &tim[i].k, &tim[i].a, &tim[i].b);
        tim[i].nomor = i + 1;
    }

    simulasi(tim, m, 0);
    printf("%lld\n", maxPenonton);
    return 0;
}