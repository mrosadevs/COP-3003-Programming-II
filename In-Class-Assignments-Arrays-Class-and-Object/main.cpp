#include <iostream>

const int SIZE = 5;

class Order {
public:
    int num[SIZE];

    Order() {
        num[0] = 42;
        num[1] = 7;
        num[2] = -3;
        num[3] = 19;
        num[4] = 5;
    }

    void ascending() {
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - 1 - i; j++) {
                if (num[j] > num[j + 1]) {
                    int max = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = max;
                }
            }
        }
    }

    void descending() {
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - 1 - i; j++) {
                if (num[j] < num[j + 1]) {
                    int min = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = min;
                }
            }
        }
    }

    void print(const char* label) const {
        std::cout << label << ": ";
        for (int i = 0; i < SIZE; i++) {
            std::cout << num[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Order c1;
    c1.print("Original");

    c1.ascending();
    c1.print("Ascending");

    c1.descending();
    c1.print("Descending");

    return 0;
}
