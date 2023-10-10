//
// Created by ufabi on 04.10.2023.
//

#ifndef TEP_CTABLEFUNCTIONS_H
#define TEP_CTABLEFUNCTIONS_H

class CTableFunctions {
public:
    static void v_alloc_table_fill_34(int iSize);

    static bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);

    static bool b_dealloc_table_2_dim(int **piTable, int iSizeX);

    static bool b_alloc_table_2_dim_other_way(int ***piTable, int iSizeX, int iSizeY);

private:
    static void v_show_table(int *iArr, int iSize);
};


#endif //TEP_CTABLEFUNCTIONS_H
