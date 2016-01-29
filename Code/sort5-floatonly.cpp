#include <iostream>

// limite data to N=5 items for example
#define N 5

class FloatData {
public:
    // Constructor, expects int array with 5 elements
    FloatData(float *array) {
        for (int i = 0; i < N; i++) 
            data[i] = array[i];
    }

    // swap data with index i and index j
    void swap(int i, int j) {
        float tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }

    // comparison
    bool greater(int i, int j) {
        if (data[i] > data[j])
            return true;
        else
            return false;
    }

    // trivial sorting algorithm
    void sort(void) {
        for (int i=0; i < N; i++)
            for (int j=i+1; j < N; j++) {
                if (greater(i, j))
                    swap(i, j);
            }
        }

    // reporting mechanism to stdout
    void report(void) {
        std::cout << "[" << data[0];;
        for (int i=1; i < N; i++) {
            std::cout << ", " << data[i];
        }
        std::cout << "]" << std::endl;
    }

private:
    float data[N];
};

int main(void) {

    float input_float[N] = {0.5, 1, -1, 2.5, -20};
    FloatData f(input_float);

    f.report();
    f.swap(1, 2);
    f.report();
    f.sort();
    f.report();

}



