#include "level_list.h"
#include <stdio.h>
#include <stdlib.h>


t_d_list* create_list(int max_level) {
    t_d_list* list = (t_d_list*)malloc(sizeof(t_d_list));
    list->head = (t_d_cells**)malloc(sizeof(t_d_cells*) * (max_level + 1));
    for (int i = 0; i <= max_level - 1; i++) {
        list->head[i] = NULL;
    }
    list->max_level = max_level;
    return list;
}

void insert_cell_at_head(t_d_list* list, t_d_cells* cell) {
    for (int i = 0; i < *cell->max_level && i < list->max_level; i++) {
        cell->next[i] = list->head[i];
        list->head[i] = cell;
    }
}

void display_cells_at_level(t_d_list* list, int level) {
    t_d_cells* current = list->head[level];
    while (current != NULL) {
        if (current->contact == NULL) {
            break;
        }
        printf("%s -> ", current->contact->surname);
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

int compareContacts(t_d_cells* cell1, t_d_cells* cell2) {
    return strcmp(cell1->contact->surname, cell2->contact->surname);
}

void insert_cell_sorted(t_d_list* list, t_d_cells* cell) {
    t_d_cells* current = NULL;
    for (int i = list->max_level - 1; i >= 0; i--) {
        if (*cell->max_level > i) {
            if (!list->head[i] || compareContacts(list->head[i], cell) > 0) {
                cell->next[i] = list->head[i];
                list->head[i] = cell;
            }
            else {
                current = list->head[i];
                while (current->next[i] != NULL && compareContacts(current->next[i], cell) < 0) {
                    current = current->next[i];
                }
                cell->next[i] = current->next[i];
                current->next[i] = cell;
            }
        }
    }
}

void reset_list(t_d_list* list) {
    t_d_cells* tab[100] = { 0 };
    t_d_cells* current = list->head[0];
    int count = 0;
    while (current->next[0] != NULL) {
        tab[count] = current;
        current = current->next[0];
        count += 1;
    }
    tab[count] = current;
    for (int i = 0; i <= list->max_level - 1; i++) {
        list->head[i] = NULL;
    }
    for (int j = count; j >= 0; j--) {
        insert_cell_sorted(list, tab[j]);
    }
}


void adjustLevels(t_d_list* list) {
    t_d_cells *current = list->head[0];
    t_d_cells *prev = NULL;
    while (current != NULL) {
        if (prev == NULL) {
            *current->max_level = 4;
            prev = current;
            current = current->next[0];
            continue;
        }
        else {
            if (prev->contact->surname[0] != current->contact->surname[0]) {
                *current->max_level = 4;
            }
            else if (prev->contact->surname[0] == current->contact->surname[0]){
                if (prev->contact->surname[1] != current->contact->surname[1]){
                    *current->max_level = 3;
                }
                else if (prev->contact->surname[1] == current->contact->surname[1]){
                    if (prev->contact->surname[2] != current->contact->surname[2]){
                        *current->max_level = 2;
                    }
                    else{
                        *current->max_level = 1;
                    }
                }
            }

        }
        prev = current;
        current = current->next[0];
    }
}

void search_list(t_d_list * list,char *names){
    if (list->head[0] == NULL){
        printf("The list is empty");
        return;
    }
    t_d_cells *around = list->head[3];
    t_d_cells* current = NULL;
    int count = -3;
    for (int i = list->max_level - 1; i > 0; i--){
        current = around;
        while ((current->contact->surname[i+count] != names[i+count] && current->next[i] != NULL) || current->next[i] != NULL){
            current = current->next[i];
        }
        around = current;
        count +=2;
    }
    current = around;
    if (current->contact->surname[2] != names[2]) {
        printf("Nothing found");
        return;
    }
    while (current->next[0] != NULL){
        if (current->contact->surname[2] != current->next[0]->contact->surname[2]){
            break;
        }
        printf("%s,",current->contact->surname);
        current = current->next[0];
    }
    printf("%s.",current->contact->surname);
}

void saveAppointments(t_d_list *list){
    // write all appointments in a file CSV
    FILE *file = fopen("appointements.csv", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    t_d_cells *current = list->head[0];
    Appointment* currentAppointment;
    while (current != NULL) {
        for (int i = 0; i < *(current->numberOfAppointment); i++){
            currentAppointment = current->appointments[i];
            fprintf(file, "%s,%d,%d,%d,%d,%d,%d,%d,%s\n", current->contact->surname, currentAppointment->day, currentAppointment->month, currentAppointment->year, currentAppointment->startHour, currentAppointment->startMinute, currentAppointment->durationHours,currentAppointment->durationMinutes, currentAppointment->purpose);
        
        }
        printf("%s\n",current->contact->surname);
        current = current->next[0];
    }
    fclose(file);

}


void loadContact(t_d_list *list) {
    FILE *file = fopen("nat2021.csv", "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    int count = 0;
    char line[100]; // Assuming lines won't exceed 100 characters
    while (fgets(line, sizeof(line), file) && count < 1) {
        // Remove newline character if present
        printf("%s",line);
        char *newline = strchr(line, '\n');
        if (newline) {
            *newline = '\0';
        }

        // Create a new contact with the extracted name
        int* a = (int*)malloc(sizeof(int));
        *a = 1;
        Contact newContact;
        newContact.surname = line;
        newContact.firstName = "Augustin";
        t_d_cells *newcell = create_cells(&newContact, a);
        printf("%s",newcell->contact->surname);
        insert_cell_sorted(list, newcell);
        show_all_levels(list);
        count++;
    }
    printf("mm");
    fclose(file);
}