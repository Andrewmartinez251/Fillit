/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrmart <andrmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 23:40:19 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/18 21:44:13 by andrmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracking.h"
#include <string.h>
#include "testing.h"
#include "shape.h"
#include "tetrimino.h"

int                 *init_pos(void)
{
    int *ret = malloc(2 * sizeof(int));
    
    ret[0] = 0;
    ret[1] = 0;
    return (ret);
}

int                 next_pos(unsigned short tet, int pos[2], unsigned short grid_size) // update the position, consider logical assumptions with regard to id, return NULL if a greater grid_size is needed
{
    set_pos(&tet, ++X, Y);
    if (!(in_x_bounds(tet, grid_size)))
    {
        X = 0;
        puts("happy y");
        set_pos(&tet, 0, ++Y);
    }
    if (!(in_y_bounds(tet, grid_size)))
    {
        puts("return 42");
        return (0);
    }
    puts("return 45");
    return (1);
}

int                 is_next_pos(unsigned short tet, int pos[2], unsigned short grid_size) // update the position, consider logical assumptions with regard to id, return NULL if a greater grid_size is needed
{
    unsigned short tmp;

    tmp = tet;
    set_pos(&tmp, ++X, Y);
    if (!(in_x_bounds(tmp, grid_size)))
    {
        X = 0;
        set_pos(&tmp, 0, ++Y);
    }
    if (!(in_y_bounds(tmp, grid_size)))
    {
        puts("return 42");
        return (0);
    }
    puts("return 45");
    return (1);
}

unsigned short      validate(unsigned short arr[26], int n)
{
    int i;
    unsigned short i_temp;
    unsigned short n_temp;

	i = -1;
    while (++i < n)
    {
        i_temp = arr[i];
        n_temp = arr[n];
        if (overlaps(i_temp, n_temp))
            return (0);
    }
    puts("exit validate()");
    return (1);
}

void                pos_of(unsigned short *arr, int n, int pos[2])
{
    pos[0] = TET_GET_X(arr[n]);
    pos[1] = TET_GET_Y(arr[n]);
}

unsigned short      backtracking(unsigned short *arr, int n, int pos[2], unsigned short *grid_size) // n is zero based
{
    // cmd_show(n);
    // if (n == 2)
    //     return (1);
    printf("n: %d pos: %d %d grid_size: %d\n", n, X, Y, *grid_size);

    if (!(arr[n]))
    {
        printf("return 72\n");
        return (1); // finished backtracking
    }
    set_pos(&arr[n], X, Y);        
    if (validate(arr, n)) // create please
    {
        if (backtracking(arr, n + 1, init_pos(), grid_size))
        {
            printf("return 80\n");
            return (1);           
        }     
    }
    if (next_pos(arr[n], pos, *grid_size))
    {
        // return (backtracking(arr, the_good(n), NULL, ++grid_size));
        printf("return 87\n");
        return (backtracking(arr, n, pos, grid_size));
    }
    pos_of(arr, n - 1, pos);
    next_pos(arr[n - 1], pos, *grid_size);
    if (is_next_pos(arr[0], pos, *grid_size))
    {
        return (backtracking(arr, n - 1, pos, grid_size));    
    }
    pos_of(arr, n, pos);
    printf("return 90\n");
    (*grid_size)++;
    return  (backtracking(arr, 0, init_pos(), grid_size));
}

