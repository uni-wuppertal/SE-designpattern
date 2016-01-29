// Demonstration von Strategiemuster.
//
// Haeufig gibt es mehere Strategien zum Auswaehlen,
// in diesem Beispiel ist nur eine Strategie gegeben - 
// wir zeigen also nur wie ein Algorithmus in die Strate-
// gieklasse ausgelagert werden kann.


#include <iostream>

#define N 5

// forward declaration (class prototype)
class Data;         // Abstrakte Daten Klasse

class IntData;      // Konkrete Klasse
class FloatData;    // Konkrete Klasse

// Strategie Klasse 'Sort' with Strategiemethode 'sort.'
class Sort {
public:
    Sort(void) {};
    void sort(Data &d);
};


class Data {
public:
    Data(void) {
        sortstrategy = NULL;  // Start without a particular sort strategy.
    };
    void sort(void) {
        // Hier wird das Sortieren zur Strategieklasse delegiert.
        // Merke: die Sortierstrategie kann zur Laufzeit entschieden 
        //        werden.
        sortstrategy = new Sort();
        sortstrategy->sort(*this);
        delete sortstrategy;
        // Abgeleitete Klassen koennen diese Methode ueberschreiben.
    }
    virtual bool greater(int i, int j) = 0; 
    virtual void swap(int i, int j) = 0; 
protected:                 
    Sort *sortstrategy;      // protected, nicht private, damit
                             // abgeleitete Klassen damit arbeiten 
                             // koennen.
};


void Sort::sort(Data &d){
        for (int i=0; i < N; i++) {
            for (int j=i+1; j < N; j++) {
                if (d.greater(i, j)) 
                    d.swap(i, j); 
            }           
        }   
    }  


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
    };  

private:
    float data[N];
};


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

 }



