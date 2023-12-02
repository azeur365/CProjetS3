#include "level_cell.h"
#include "level_list.h"
#include <stdio.h>

//ex

int main() {
    t_d_list* list = create_list(4);

    t_d_cell* cell1 = create_cell(18, 2);

    insert_cell_sorted(list, cell1);
    
    t_d_cell* cell2 = create_cell(34, 1);

    insert_cell_sorted(list, cell2);

    show_all_levels(list);

    

    return 0;
}
