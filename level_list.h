#ifndef LEVEL_LIST_H
#define LEVEL_LIST_H

#include "level_cell.h"

typedef struct s_d_list {
    t_d_cell** head;
    int max_level;
} t_d_list;

t_d_list* create_list(int max_level);
void insert_cell_at_head(t_d_list* list, t_d_cell* cell);
void display_cells_at_level(t_d_list* list, int level);
void show_all_levels(t_d_list* list);
void insert_cell_sorted(t_d_list* list, t_d_cell* cell);

#endif // LEVEL_LIST_H