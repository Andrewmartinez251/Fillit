/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:57:59 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/17 22:31:10 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H 
# define TESTING_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "tetrimino.h"
#include "shape.h"
#include "output.h"

void	cmd_help(void);
void	cmd_overlaps(int i, int j);
int		get_number_of_tets(void);
void	cmd_del(int index);
void	cmd_reset(void);
void	cmd_list(void);
void	cmd_set(int index, int id, int x, int y);
void	cmd_show(int index);
void	cmd_size(int size);
void	cmd_print(void);
void	print_tet_raw(char *str);
void	print_shape(unsigned short shape);
void	test_identify(char *data);
void	print_tet_listing(int i);
void	cmd_inb(int i);
int		process_stdin(void);
int		process_script(char *filename);
int		process_cmd(char **words);
void	cmd_overlaps_all(void);
void	cmd_move(int index, int x, int y);
int		idx_atoi(char *index_str);
void	cmd_rf(char *filename);


#endif
