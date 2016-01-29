// Demonstration von Templatemuster.
//
// Allgemeine Sortiermethode ist in der Basisklasse,
// die abgeleiteten Klassen stellen konkrete Operation
// zur Datenmanipulierung zur Verfuegung.

#include <iostream>

#define N 5

// Abstrakte Template Klasse
class Data {
public:
    Data(void) {};
    void sort(void) {                        // Template of sort 
        for (int i=0; i < N; i++)            // algorithm  
            for (int j=i+1; j < N; j++) {
                if (greater(i, j)) 
                    swap(i, j);
            }
        }
    virtual bool greater(int i, int j) = 0; 
    virtual void swap(int i, int j) = 0;  
};


// Concrete Class for FloatData
class FloatData : public Data {
public:
    FloatData(float *array) {
        for (int i = 0; i < N; i++) 
            data[i] = array[i];
    }
    bool greater(int i, int j) {
            if (data[i] > data[j])
                return true;
            else
                return false;
    }
    void swap(int i, int j) {
        float tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
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



// Concrete Class for IntData
class IntData : public Data {
public:
    IntData(int *array) {
        for (int i = 0; i < N; i++) 
            data[i] = array[i];
    }
    bool greater(int i, int j) {
            if (data[i] > data[j])
                return true;
            else
                return false;
    }
    void swap(int i, int j) {
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
    void report(void) {
        std::cout << "[" << data[0];;
        for (int i=1; i < N; i++) {
            std::cout << ", " << data[i];
        }   
        std::cout << "]" << std::endl;
    }
private:
    int data[N];
};



int main(void) {
    // create IntData object with some values
    int input[N] = {0, 1, -1, 2, -2};
    IntData id(input);                   // id for IntData

    std::cout << "IntData example:" << std::endl;
    id.report();
    id.sort();
    id.report();

    // create FloatData object with some values
    float input_float[N] = {0.1, 1.1, -1.1, 2.1, -2.1};
    FloatData fd(input_float);           // fd for FloatData

    std::cout << "FloatData example:" << std::endl;
    fd.report();
    fd.sort();
    fd.report();

    return 0;
 }



