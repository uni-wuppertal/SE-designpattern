// Beispiel: C++ Templateklasse um Float und Integerdatentypen
// zu unterstuetzen.


#include <iostream>

// limite data to N=5 items for example
#define N 5

template <class T>
class MyData {
public:
    // Constructor, expects int array with 5 elements
    MyData(T *array) {
        for (int i = 0; i < N; i++) 
            data[i] = array[i];
    }

    // swap data with index i and index j
    void swap(int i, int j) {
        T tmp = data[i];
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
    T data[N];
};

int main(void) {

    // create MyData<int> object with some values
    int input[N] = {0, 1, -1, 2, -2};
    MyData<int> id(input);                   // id for IntData

    std::cout << "IntData example:" << std::endl;
    id.report();
    id.sort();
    id.report();

    // create MyData<float> object with some values
    float input_float[N] = {0.1, 1.1, -1.1, 2.1, -2.1};
    MyData<float> fd(input_float);           // fd for FloatData

    std::cout << "FloatData example:" << std::endl;
    fd.report();
    fd.sort();
    fd.report();

    return 0;
 }


