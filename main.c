#include "level_cell.h"
#include "level_list.h"
#include <stdio.h>

int main() {
    t_d_list* list = create_list(3);

    t_d_cell* cell1 = create_cell(5, 2);
    insert_cell_sorted(list, cell1);

    t_d_cell* cell2 = create_cell(3, 1);
    insert_cell_sorted(list, cell2);

    t_d_cell* cell3 = create_cell(7, 0);
    insert_cell_sorted(list, cell3);

    t_d_cell* cell4 = create_cell(1, 1);
    insert_cell_at_head(list, cell4);

    show_all_levels(list);

    return 0;
}
