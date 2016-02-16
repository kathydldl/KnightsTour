//
//  knightTour.cpp
//  KnightsTour
//
//  Created by Kaixi Ji on 7/15/15.
//  Copyright (c) 2015 Kaixi Ji. All rights reserved.
//

#include "knightTour.h"


knightTour::knightTour(int m, int n, pair<int, int>startpo){
    
    this->m_x = m;
    this->n_y = n;
    this->steps = 0;
    this->position = startpo;
    
    this->moves.push_back(make_pair(2, 1));
    this->moves.push_back(make_pair(1, 2));
    this->moves.push_back(make_pair(-1, 2));
    this->moves.push_back(make_pair(-2, 1));
    this->moves.push_back(make_pair(-2, -1));
    this->moves.push_back(make_pair(-1, -2));
    this->moves.push_back(make_pair(1, -2));
    this->moves.push_back(make_pair(2, -1));
    
    for (int j = n-1; j >= 0 ; j--){
        for (int i = 0; i < m; i++){
            pair<int, int> temppo = make_pair(i, j);
            int tempnum = 0;
            this->po_map[temppo] = tempnum;
        }
    }
}

void knightTour::printboard(){
    for (int j = n_y - 1; j >= 0; j--){
        string row = "";
        for (int i = 0; i < m_x; i++){
            pair<int, int> temppo = make_pair(i, j);
            row += (to_string(po_map[temppo]) + ", ");
        }
        cout << row << endl;
    }
}

bool knightTour::inboard(pair<int, int> po){
    if (get<0>(po) < 0 || get<0>(po) >= m_x || get<1>(po) < 0 || get<1>(po) >= n_y){
        return false;
    }
    else{
        return true;
    }
}

bool knightTour::validstep(pair<int, int> po){
    if (po_map[po] == 0){
        return true;
    }
    else{
        return false;
    }
}

int knightTour::adjnum(pair<int, int> po){
    int num = 0;
    list<pair<int, int>>::iterator i;
    for (i = moves.begin(); i != moves.end(); i++){
        int newx = get<0>(po) + get<0>(*i);
        int newy = get<1>(po) + get<1>(*i);
        if (inboard(make_pair(newx, newy)) && validstep(make_pair(newx, newy))){
            num++;
        }
    }
    return num;
}

list<pair<int, int>> knightTour::SortAdj(){
    struct pairnum{
        pair<int, int> ipair;
        int num;
    };
    list<pairnum> pairnum_list;
    
    list<pair<int, int>>::iterator i;
    for (i = moves.begin(); i != moves.end(); i++){
        int newx = get<0>(position) +get<0>(*i);
        int newy = get<1>(position) +get<1>(*i);
        pair<int, int> newpair = make_pair(newx, newy);
        if (inboard(newpair) && validstep(newpair)){
            int newnum = adjnum(newpair);
            pairnum newpairnum;
            newpairnum.ipair = newpair;
            newpairnum.num = newnum;
            pairnum_list.push_back(newpairnum);
        }
    }
    //random_shuffle(pairnum_list.begin(), pairnum_list.end());
    pairnum_list.sort([](const pairnum & a, const pairnum & b) { return a.num < b.num; });
    
    list<pair<int, int>> SAdj;
    list<pairnum>::iterator n;
    for (n = pairnum_list.begin(); n != pairnum_list.end(); n++){
        SAdj.push_back((*n).ipair);
    }
    return SAdj;
}

bool knightTour::DFSTour()
{
    steps++;
    po_map[position] = steps;
    po_stack.push_back(position);
    
    bool flag;
    if (steps<m_x*n_y){
        
        flag = false;
        list<pair<int, int>> adj_list = SortAdj();
        
        if (adj_list.size() != 0){
            list<pair<int, int>>::iterator i = adj_list.begin();
            while (i != adj_list.end() && flag == false){
                position = *i;
                flag = DFSTour();
                i++;
            }
        }
        if (!flag){	//backtrack
            steps--;
            if (steps == 0)
                return flag;
            po_map[position] = 0;
            po_stack.pop_back();
            position = po_stack.back();
        }
        
    }
    else{
        flag = true;
    }
    
    return flag;
}
