#include <iostream>
using namespace std;

int N, M, B;
int minHeight = 1e9, maxHeight;
int minCost = 1e9, finalHeight;
int field[500][500];

void calculateCost(int targetHeight) {
    int blocksIn = B;
    int totalCost = 0;

    // 높은 땅의 블록 제거 및 비용 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] > targetHeight) {
                totalCost += 2 * (field[i][j] - targetHeight);
                blocksIn += field[i][j] - targetHeight;
            }
        }
    }

    // 낮은 땅에 블록 추가 및 비용 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] < targetHeight) {
                totalCost += targetHeight - field[i][j];
                blocksIn -= targetHeight - field[i][j];
                if (blocksIn < 0) return;
            }
        }
    }

    // 비용 갱신
    if (totalCost <= minCost) {
        minCost = totalCost;
        finalHeight = max(finalHeight, targetHeight);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            minHeight = min(minHeight, field[i][j]);
            maxHeight = max(maxHeight, field[i][j]);
        }
    }

    for (int i = minHeight; i <= maxHeight; i++) {
        calculateCost(i); 
    }

    cout << minCost << " " << finalHeight;

    return 0;
}
