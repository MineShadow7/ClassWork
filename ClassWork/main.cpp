#include "DSU.h"
#include <vector>

using namespace std;

int main() {
    DSU a(10);
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


    //make a maze
    srand(time(0));

    int n = 10;
    DSU maze(n * n);

    std::vector<int> wall;
    for (int i = 0; i <= n * n * 2 - 2; i++) {
        if ((i % (2 * n) == 0) || (i > n * (n - 1) * 2)) continue;
        wall.push_back(i);
    }


    while (wall.size() > 0) {
        int size = wall.size();
        int j = rand() % size;


        int x = (wall[j] - 1) / 2;
        if (wall[j] % 2 == 0) {
            if (maze.Find(x) != maze.Find(x + 1)) {
                maze.Unite(maze.Find(x), maze.Find(x + 1));
                maze.setRighttoFalse(x);
            }
        }
            else {
                if (maze.Find(x) != maze.Find(x + n)) {
                    maze.Unite(maze.Find(x), maze.Find(x + n));
                    maze.setBottomtoFalse(x);
                }
            }
            wall.erase(wall.begin() + j);
        }

    maze.printMaze(n);

}
