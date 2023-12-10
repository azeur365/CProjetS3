#ifndef LEVEL_LIST_H
#define LEVEL_LIST_H

#include "level_cell.h"

typedef struct s_d_list {
    t_d_cells** head;
    int max_level;
} t_d_list;

t_d_list* create_list(int max_level);
void insert_cell_at_head(t_d_list* list, t_d_cells* cell);
void display_cells_at_level(t_d_list* list, int level);
void show_all_levels(t_d_list* list);
void insert_cell_sorted(t_d_list* list, t_d_cells* cell);
void reset_list(t_d_list* list);
void adjustLevels(t_d_list* list);
void search_list(t_d_list * list,char *names);
void saveAppointments(t_d_list *list);
void loadAppointments(t_d_list *list);
void loadContact(t_d_list *list);


#endif // LEVEL_LIST_H