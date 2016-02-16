//
//  knightTour.h
//  KnightsTour
//
//  Created by Kaixi Ji on 7/15/15.
//  Copyright (c) 2015 Kaixi Ji. All rights reserved.
//

#ifndef __KnightsTour__knightTour__
#define __KnightsTour__knightTour__

#include <iostream>
#include <iomanip>
#include <array>
#include <tuple>
#include <string>
#include <list>
#include <map>
using namespace std;


class knightTour
{
public:
    
    int m_x;
    int n_y;
    
    int steps;
    pair<int, int> position;
    list<pair<int, int>> moves;
    map<pair<int, int>, int> po_map;
    list<pair<int, int>> po_stack;
    
    knightTour(int m, int n, pair<int, int>startpo);
    
    void printboard();
    bool inboard(pair<int, int> po);
    bool validstep(pair<int, int> po);
    int adjnum(pair<int, int>);
    list<pair<int, int>> SortAdj();
    bool DFSTour();
};



#endif /* defined(__KnightsTour__knightTour__) */
