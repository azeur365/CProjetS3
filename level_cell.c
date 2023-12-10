#include "level_cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

t_d_cells* create_cells(Contact *contact,int *level) {
    t_d_cells* new_cell = (t_d_cells*)malloc(sizeof(t_d_cells));
    if (new_cell == NULL) {
        return NULL;
    }
    new_cell->contact = (Contact*)malloc(sizeof(Contact));
    new_cell->contact->surname = strdup(contact->surname);
    new_cell->contact->firstName = strdup(contact->firstName);
    int *appointmentCount = (int*)malloc(sizeof(int));
    *appointmentCount = 0;
    new_cell->numberOfAppointment = appointmentCount;
    new_cell->appointments = (Appointment**)malloc(sizeof(Appointment*)*(*new_cell->numberOfAppointment+2));
    for(int i = 0;i < *new_cell->numberOfAppointment+1;i++){
        new_cell->appointments[i] = NULL;
    }
    new_cell->next = (t_d_cells**)malloc(sizeof(t_d_cells*) * (3 + 1));
    for (int i = 0; i < *level; i++) {
        new_cell->next[i] = NULL;
    }
    new_cell->max_level = level;
    return new_cell;
}


char *scanString(void) {
    char *input = (char *) malloc(sizeof(char) * 20);
    if (input == NULL) {
        return NULL;
    }
    int maxSize = 20;
    int length = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (!isalpha(c)) {
            continue;
        }
        input[length++] = c;
        if (length == maxSize - 1) {
            maxSize *= 2;
            input = (char *) realloc(input, sizeof(char) * maxSize);
            if (input == NULL) {
                return NULL;
            }
        }
    }

    input[length] = '\0'; // Add null terminator
    return input;
}


void printContactAppointments(t_d_cells *cell) {
    for (int i = 0; i <= *(cell->numberOfAppointment)-1; i++) {
        Appointment *currentAppointment = cell->appointments[i];
        printf("Appointment Date: %d/%d/%d\n", currentAppointment->day,
               currentAppointment->month, currentAppointment->year);
        printf("Appointment Time: %02d:%02d - %02d:%02d\n",
               currentAppointment->startHour, currentAppointment->startMinute,
               currentAppointment->startHour + currentAppointment->durationHours,
               currentAppointment->startMinute + currentAppointment->durationMinutes);
        printf("Purpose: %s\n\n", currentAppointment->purpose);
    }
}

Appointment * create_appointment(int day,int month,int year,int startHour,int startMinute,int durationHours,int durationMinutes,char *purpose){
    Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));
    newAppointment->day = day;
    newAppointment->month = month;
    newAppointment->year = year;
    newAppointment->startHour = startHour;
    newAppointment->startMinute = startMinute;
    newAppointment->durationHours = durationHours;
    newAppointment->durationMinutes = durationMinutes;
    newAppointment->purpose = purpose;
    newAppointment->next = NULL;
    return newAppointment;
}

void addAppointment(t_d_cells *cell,int day,int month,int year,int startHour,int startMinute,int durationHours,int durationMinutes,char *purpose) {
    Appointment *newAppointment = create_appointment(day,month,year,startHour,startMinute,durationHours,durationMinutes,purpose);
    int newAppointmentIndex = *cell->numberOfAppointment;
    cell->appointments[newAppointmentIndex] = newAppointment;
    *cell->numberOfAppointment += 1;
    printf("Appointment created for %s %s\n", cell->contact->firstName, cell->contact->surname);
}

void deleteAppointment(t_d_cells *cell, int index) {
    if (index < 0 || index >= *(cell->numberOfAppointment)) {
        printf("Invalid appointment index.\n");
        return;
    }
    free(cell->appointments[index]);
    for (int i = index; i < *(cell->numberOfAppointment) - 1; i++) {
        cell->appointments[i] = cell->appointments[i + 1];
    }

    *(cell->numberOfAppointment) -= 1;
    printf("Appointment at index %d deleted.\n", index);
}


