#include "cell.h"
#include "list.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "timer.h"

//ex

int main() {
    int n =14;
    int taille = pow(2, n) - 1;
    int count = 2;
    int array[100000] = {0};
    for (int i = 1; i < pow(2, n); i++) {
        array[i] = 1;
    }
    while (count < pow(2, n)) {
        for (int i = 1; i < pow(2, n); i++) {
            if (i % count == 0) {
                array[i] += 1;
            }
        }
        count = count * 2;
    }
    t_d_list *list = create_list(n);
    for (int i = 1; i < pow(2, n); i++) {
        t_d_cell *cell = create_cell(i, array[i]);
        insert_cell_sorted(list, cell);
    }

    startTimer();
    int valueToSearch = 489; // Replace with the value you want to search for
    for (int i = 0;i<1000000;i++){
        search_list(list, rand() % (int)pow(2,n));
    }
    stopTimer();
    printf("Execution Time for search_list: ");
    displayTime(); // Display the time taken by the search_list function
    startTimer();
    for (int i = 0;i<100000;i++){
        search_level_zero(list, rand() % (int)pow(2,n));
    }
    stopTimer();
    printf("Execution Time for search_list zero: ");
    displayTime(); // Display the time taken by the search_list function
    return 0;
}

