#pragma once
#include <iostream>



class DSU {
protected:
    int size = 10;
    int p[10];
    int rank[10];
public:
    DSU() {
        for (int i = 0; i < size; i++) {
            p[i] = 0;
            rank[i] = 0;
        }
    }

    void MakeSet(int x) {
        p[x] = x;
    }

    int Find(int x) {
        if (p[x] == x) 
            return x;
        return p[x] = Find(p[x]);
    }

    void Unite(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (rank[x] < rank[y])
            p[x] = y;
        else
        {
            p[y] = x;
            if (rank[x] == rank[y])
                ++rank[x];
        }
    }
};
