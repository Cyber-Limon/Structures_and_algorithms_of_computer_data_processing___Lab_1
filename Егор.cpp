#include <iostream> 
#include <list> 
#include <time.h> 
 
 
using namespace std; 
 
int main() 
{ 
    setlocale(LC_ALL, "Ru"); 
 
    srand(time(NULL)); 
 
    int const length = 48; 
 
    int const Size = length / 2; 
    list<int> A[Size]; 
 
    float count = Size; 
 
    int count_swap = 0; 
 
    cout << "Последовательность сгенерированных ключей:" << endl; 
 
    for (int i = 0; i < 48; i++) { 
        int start = 100; 
        int end = 999; 
        int x = rand() % (end - start + 1) + start; 
 
        if ((i + 1) % 10 == 0) 
            cout << x << endl; 
        else 
            cout << x << " "; 
 
        int pos = (x * x % 1000) % Size; 
        A[pos].push_back(x); 
        count_swap += A[pos].size() + 1; 
    } 
 
    cout << endl << endl; 
 
 
    for (int i = 0, j = 0; i < Size; i++) { 
        cout << i; 
        for (int a : A[i]) 
        { 
            cout << '\t' << a; 
        } 
        cout << endl; 
    } 
 
 
    int count_empty = 0; 
    for (int i = 0; i < Size; i++) 
        if (A[i].empty()) 
            count_empty++; 
 
    cout << endl << endl << "Коэф. заполненности таблицы - " << (length - count_empty) / (float)Size; 
    cout << endl << "Среднее число шагов - " << count_swap / float(length); 
 
    cout << endl << endl << endl << endl << endl << endl; 
}
