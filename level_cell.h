#ifndef LEVEL_CELL_H
#define LEVEL_CELL_H

typedef struct s_d_cell {
    int value;
    int max_level;    // Adding the max_level field
    struct s_d_cell** next;
} t_d_cell;

// Function to create a new cell
t_d_cell* create_cell(int value, int level);

#endif // LEVEL_CELL_H
