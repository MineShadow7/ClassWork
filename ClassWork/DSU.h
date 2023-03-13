#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class DSU {
protected:
    int size;
    int* p;
    int* rank;
    bool* right;
    bool* bottom;
public:
    DSU(int _size) {
        size = _size;
        p = new int[size];
        rank = new int[size];
        bottom = new bool[size];
        right = new bool[size];
        for (int i = 0; i < size; i++) {
            MakeSet(i);
        }
    }

    void MakeSet(int x) {
        p[x] = x;
        rank[x] = 0;
    }

    int Find(int x) {
        if (x != p[x])
            return Find(p[x]);
        return x;
    }

    void Unite(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if (rank[x] > rank[y])
            p[py] = px;
        else
        {
            p[px] = py;
            if (rank[x] == rank[y])
                ++rank[py];
        }
    }

    bool getRight(int x) { return right[x]; }
        bool getBottom(int x) { return bottom[x]; }
    void setRighttoFalse(int x) { right[x] = false; }
    void setBottomtoFalse(int x) { bottom[x] = false; }

    void print() {
        for (int i = 0; i < size; std::cout << '(' << p[i] << ')', i++);
    }

    void printMaze(int n) {

        std::cout << "   ";
        for (int i = 1; i < n; i++) {
            std::cout << "___";
        }
        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            std::cout << "|";
            for (int j = n * i; j < n + n * i; j++) {
                if (j == n * n - 1) {
                    std::cout << "  |";
                }
                else if (getRight(j) && getBottom(j)) {
                    std::cout << "__|";
                }
                else if (getRight(j)) {
                    std::cout << "  |";
                }
                else if (getBottom(j)) {
                    std::cout << "__ ";
                }
                else  {
                    std::cout << "   ";
                }
            }
            std::cout << std::endl;
        }
    }
};
