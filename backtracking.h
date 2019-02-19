/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrmart <andrmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 23:39:20 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/18 20:59:37 by andrmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING_H
# define BACKTRACKING_H

# define X pos[0]
# define Y pos[1]

void                 init_pos(int pos[2]);
int                 *pos(int pos[2], unsigned short grid_size);
unsigned short		increase_grid(unsigned short *arr, unsigned short grid_size);
unsigned short      validate(unsigned short arr[26], int n/*, int pos[2]*/);
unsigned short      backtracking(unsigned short *arr, int n, int pos[2], unsigned short grid_size);

#endif
