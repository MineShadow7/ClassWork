#include "DSU.h"

using namespace std;

int main() {
    DSU a;
    a.MakeSet(1);
    a.MakeSet(2);
    a.MakeSet(3);
    a.MakeSet(4);
    a.MakeSet(5);

    cout << a.Find(1) << endl;
    cout << a.Find(2) << endl;
    cout << a.Find(3) << endl;
    cout << a.Find(4) << endl;
    cout << a.Find(5) << endl;

    cout << endl;

    a.Unite(4, 1);
    a.Unite(5, 3);


    cout << a.Find(4) << endl;
    cout << a.Find(1) << endl;
    cout << a.Find(2) << endl;
    cout << a.Find(5) << endl;
    cout << a.Find(3) << endl;

    cout << endl;

    a.Unite(2, 5);

    cout << a.Find(5) << endl;
    cout << a.Find(3) << endl;
    cout << a.Find(2) << endl;
}
