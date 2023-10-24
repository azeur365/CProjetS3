#include "level_cell.h"
#include <stdlib.h>

t_d_cell* create_cell(int value, int level) {
    t_d_cell* new_cell = (t_d_cell*)malloc(sizeof(t_d_cell));
    new_cell->value = value;
    new_cell->max_level = level;    // Initializing the max_level field
    new_cell->next = (t_d_cell**)malloc(sizeof(t_d_cell*) * (level+1));
    for (int i = 0; i < level; i++) {
        new_cell->next[i] = NULL;
    }
    return new_cell;
}
