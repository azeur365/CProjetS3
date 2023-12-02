#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct {
    char *surname;
    char *firstName;
} Contact;

typedef struct {
    int day;
    int month;
    int year;
    int startHour;
    int startMinute;
    int durationHours;
    int durationMinutes;
    char *purpose;
    struct Appointment *next;
} Appointment;


typedef struct s_d_cells {
    int *max_level;
    Contact *contact;
    Appointment **appointments;
    int *numberOfAppointment;
    struct s_d_cells **next;
} t_d_cells;

t_d_cells* create_cells(Contact *contact,int *level);
char *scanString(void);
void printContactAppointments(t_d_cells *cell) ;
void addAppointment(t_d_cells *cell,int day,int month,int year,int startHour,int startMinute,int durationHours,int durationMinutes,char *purpose);
Appointment * create_appointment(int day,int month,int year,int startHour,int startMinute,int durationHours,int durationMinutes,char *purpose);
void deleteAppointment(t_d_cells *cell, int index);


