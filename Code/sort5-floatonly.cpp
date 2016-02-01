// Mögliche Implementierung für UML Beispiel 'FloatData'

#include <iostream>

// N = 5 für dieses einfache Beispiel
#define N 5

class FloatData {
public:
    // Konstructor, erwarted float array mit 5 Elementen.
    FloatData(float *array) {
        for (int i = 0; i < N; i++) 
            data[i] = array[i];
    }

    // Vertausche Elemente mit Index i und Index j.
    void swap(int i, int j) {
        float tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }

    // vergleiche Elemente mit Index i und j.
    bool greater(int i, int j) {
        if (data[i] > data[j])
            return true;
        else
            return false;
    }

    // (Trivialer) Sortieralgorithmus, der 
    // keinen direkten Datenzugriff braucht, sondern
    // Interfacemethodes swap() und greater() benutzt.
    void sort(void) {
        for (int i=0; i < N; i++)
            for (int j=i+1; j < N; j++) {
                if (greater(i, j))
                    swap(i, j);
            }
        }

    // Reportmechanismus, der aktuelle Elemente berichtet.
    // Hier einfach durch Ausgabe an standard output.
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


// Hauptprogramm, das die Funktionalität demonstriert.
int main(void) {

    float input_float[N] = {0.5, 1, -1, 2.5, -20};
    FloatData f(input_float);

    f.report();
    f.swap(0, 1);
    f.report();
    f.sort();
    f.report();
}



