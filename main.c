#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "level_list.h"

// il reste . Provide the calculation times for inserting a new contact: see point 2) below.
//2) Trace the complexity of the application:
//As with the level list containing integers, you need to produce a graph comparing execution times
//between:
//i) Search/insertion operations carried out on level 0 only
//ii) These same operations carried out from the highest level
//During the presentation/demonstration, you will be asked to perform this part live.
// La fonction search que j'ai faites elle start par le niveau le plus haut donc faut faire celle qui commence par le plus bas
// et faut faire le truc pour la complexité avec le graphe

int main() {
    int* a = (int*)malloc(sizeof(int));
    *a = 1;
    t_d_list *list =  create_list(4);
    loadContact(list);
    adjustLevels(list);
    reset_list(list);
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Create Contact\n");
        printf("2. Search Contact\n");
        printf("3. Add Appointment\n");
        printf("4. Delete Appointment\n");
        printf("5. Display Appointments\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter the contact details:\n");
                int* a = (int*)malloc(sizeof(int));
                *a = 1;
                printf("Enter the First name");
                char *fname = scanString();
                printf("%s",fname);
                printf("Enter the Last Name");
                char *lname = scanString();
                printf("%s",lname);
                Contact newContact = { .surname = lname, .firstName = fname };
                t_d_cells *cell = create_cells(&newContact,a);
                insert_cell_sorted(list,cell);
                adjustLevels(list);
                reset_list(list);
                break;
            case 2:
                printf("Enter the contact that you search:\n");
                char *name = scanString();
                search_list(list,name);
                break;
            case 3: // Elle marche mais faut faire en sorte qu'elle propose le contact parce que la je lui fait pour la tete
                printf("Enter the purpose of the appointment:\n");
                char *purpose = scanString();
                printf("Enter the day of the appointment:\n");
                int day,month,year,durationMin,durationHour,startHour,startMin;
                scanf("%d",&day);
                printf("Enter the month of the appointment:\n");
                scanf("%d",&month);
                printf("Enter the year of the appointment:\n");
                scanf("%d",&year);
                printf("Enter the hour and the minute of the appointment:\n");
                scanf("%d %d",&startHour,&startMin);
                printf("Enter the duration of the appointment (h min):\n");
                scanf("%d %d",&durationHour,&durationMin);
                printf("New Appointment Add:\n");
                addAppointment(list->head[0],day,month,year,startHour,startMin,durationHour,durationMin,purpose);
            case 4: // Elle marche mais faut faire en sorte qu'elle propose le contact parce que la je lui fait pour la tete et le premier rendez vous
                deleteAppointment(list->head[0],0);
                break;
            case 5:  // pareil
                printContactAppointments(list->head[0]);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            case 7 :
                show_all_levels(list);
                saveAppointments(list);
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 6);
    show_all_levels(list);
    return 0;
}