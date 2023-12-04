#include "level_list.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

t_d_list* create_list(int max_level) {
    t_d_list* list = (t_d_list*)malloc(sizeof(t_d_list));
    list->head = (t_d_cell**)malloc(sizeof(t_d_cell*) * (max_level+1));
    for (int i = 0; i <= max_level - 1; i++) {
        list->head[i] = NULL;
    }
    list->max_level = max_level;
    return list;
}

void insert_cell_at_head(t_d_list* list, t_d_cell* cell) {

    for (int i = 0; i < cell->max_level && i < list->max_level; i++) {
        cell->next[i] = list->head[i];
        list->head[i] = cell;
    }
}

void display_cells_at_level(t_d_list* list, int level) {
    t_d_cell* current = list->head[level];
    while (current != NULL) {
        if (current->value == NULL) {
            break;
        }
        printf("%d -> ", current->value);
        current = current->next[level];
    }
    printf("NULL\n");
}

void show_all_levels(t_d_list* list) {
    for (int i = 0; i < list->max_level; i++) {
        printf("Level %d: ", i);
        display_cells_at_level(list, i);
    }
}


void insert_cell_sorted(t_d_list* list, t_d_cell* cell) {
    t_d_cell* current = NULL;
    for (int i = list->max_level - 1; i >= 0; i--) {
        if (cell->max_level > i) {
            if (!list->head[i] || list->head[i]->value > cell->value) {
                cell->next[i] = list->head[i];
                list->head[i] = cell;
            }
            else {
                current = list->head[i];
                while (current->next[i] != NULL && current->next[i]->value < cell->value) {
                    current = current->next[i];
                }
                cell->next[i] = current->next[i];
                current->next[i] = cell;
            }
        }
    }
}

void search_list(t_d_list *list, int value) {
    t_d_cell *current = list->head[list->max_level - 1];// Start from the top
    t_d_cell* around = current;
    for (int i = list->max_level - 1; i >= 0; i--) {
        current = around;
        if (list->head[i]->value <= value){
            while (current->next[i] != NULL && current->value <= value) {
                if (around->value == value) {
                    return;
                }
                current = around;
                current = current->next[i];
            }
        }
        else {
            around = list->head[i-1];
        }
    }
}


void search_level_zero(t_d_list *list, int value) {
    t_d_cell *current = list->head[0]; // Start from level 0

    while (current != NULL && current->value <= value) {
        if (current->value == value) {
            return;
        }
        current = current->next[0]; // Move to the next node at level 0
    }


}