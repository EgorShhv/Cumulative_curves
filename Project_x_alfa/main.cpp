#include <iostream>
#include <math.h>
#include <vector>

#include "Table_value.h"

#define eps 1e-6

 /*------------------------------------------------------------\
|                                                               |            
|                   f(x)=x^a, f(x)c[0,1]                        |            
|                                                               |                        
|   /|\ y = f(x)                                                |            
|    |                                                          |            
|  1-|- - - - - - - - - - - - - - __                            |            
| y2-| - - - - - - - - - ________/  |                           |            
|    |             ____/|           |                           |            
| y1-|- - - - -___/     |           |                           |           
|    |       _/|        |           |                           |           
|    |     _/  |        |     C     |                           |           
|    |    /    |   B    |           |                           |            
|    |   /     |        |           |                           |            
|    |  |   A  |        |           |                           |            
|    | /       |        |           |                           |            
|    |/________|________|___________|_______ >                  |            
|   0         x1       x2           1        x                  |            
|                                                               |            
|                                                               |           
|   S(A) = 1/2 * (0,x1) * (x1,y1)                               |          
|                                                               |           
|   S(B) = 1/2 * [(x1,y1) + (x2,y2)] * (x1,x2)                  |           
|                                                               |           
|   S(C) = 1/2 * [(x2,y2) + (1,1)] * (x2,1)                     |           
|                                                               |           
|                                                               |           
|   S = S(A) + S(B) + S(C)                                      |           
|                                                               |
|   S --> max                                                   |
|                                                               |
\--------------------------------------------------------------*/ 

using namespace std;

int main()
{
    double steps = 0.1;     // Шаг альфы 0,1
    double steps_x = 0.0001;   // Шаг иксов 0,01

    Table_value table;

    for (double alf = steps; 1 - alf > eps; alf+=steps)
    { 
        double current_area = 0;
        double max_area = 0;
        double current_x1 = 0;
        double current_x2 = 0;
        
        for (double x1 = steps_x; x1 < 0.5; x1+=steps_x) // x1
        {
            double x1y1 = pow(x1, alf);

            for (double x2 = x1 + steps_x; x2 < 1; x2+=steps_x) //x2
            {
                double x2y2 = pow(x2, alf);
                current_area = 0.5 * (x1 * x1y1 + (x1y1 + x2y2) * (x2 - x1) + (x2y2 + 1) * (1 - x2));

                if (current_area > max_area)
                {
                    max_area = current_area;
                    current_x1 = x1;
                    current_x2 = x2;
                }
                // Сравнение ее с предыдущими вычислениями
            }
        }

        table.add_row(alf, current_x1, current_x2);
    }

    table.print_table();

    table.print_table_in_file();
}