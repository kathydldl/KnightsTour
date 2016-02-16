//
//  main.cpp
//  KnightsTour
//
//  Created by Kaixi Ji on 7/15/15.
//  Copyright (c) 2015 Kaixi Ji. All rights reserved.
//

#include "knightTour.h"

int main()
{
    while (true){
        cout << "columns on board: ";
        int col;
        cin >> col;
        cout << "rows on board: ";
        int row;
        cin >> row;
        cout << "starting column (1 - " << col << "): ";
        int col_s;
        cin >> col_s;
        col_s--;
        cout << "starting row (1 - " << row << "): ";
        int row_s;
        cin >> row_s;
        row_s--;
        
        knightTour kt(col, row, make_pair(col_s, row_s));
        
        bool possible = kt.DFSTour();
        if (possible){
            cout << "Knight's Tour is possible." << endl;
            kt.printboard();
        }
        else{
            cout << "Knight's Tour is not possible." << endl;
        }
        
    }
    
    
    return 0;
    
}
