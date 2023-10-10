//
// Created by ufabi on 04.10.2023.
//

#include <iostream>
#include "CTableFunctions.h"

void CTableFunctions::v_show_table(int *iArr, int iSize) {
    for (int *i = iArr; i < iArr + iSize; i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void CTableFunctions::v_alloc_table_fill_34(int iSize) {
    if (iSize > 0) {
        int *i_arr = new int[iSize];
        const int *i_value = new int(34);

        for (int i = 0; i < iSize; i++) {
            i_arr[i] = *i_value;
        }

        v_show_table(i_arr, iSize);

        delete[] i_arr;
        delete i_value;
    } else {
        std::cout << "Error during allocation" << std::endl;
    }
}

bool CTableFunctions::b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeY > 0 && iSizeX > 0) {
        *piTable = new int *[iSizeX];

        for (int i = 0; i < iSizeX; i++) {
            (*piTable)[i] = new int[iSizeY];
        }
        return true;
    } else {
        return false;
    }
}

bool CTableFunctions::b_dealloc_table_2_dim(int **piTable, int iSizeX) {
    if (iSizeX > 0) {
        for (int i = 0; i < iSizeX; i++) {
            delete piTable[i];
        }
        delete piTable;
        return true;
    } else {
        return false;
    }
}

/// alloc without using indexes of array
bool CTableFunctions::b_alloc_table_2_dim_other_way(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX>0 && iSizeY>0) {
        *piTable = new int *[iSizeX];
        for (int i=0; i<iSizeX; i++) {
            *(*piTable+i) = new int[iSizeY];
        }

        for (int i=0; i<iSizeX; i++) {
            for (int j=0; j<iSizeY; j++) {
                *(*(*piTable+i)+j) = i+j;
                std::cout<<*(*(*piTable+i)+j)<<"\t";
            }
            std::cout<<std::endl;
        }
        return true;
    } else {
        return false;
    }
}