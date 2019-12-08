/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:09:02 by zszeredi          #+#    #+#             */
/*   Updated: 2019/12/01 16:17:33 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int     verif(t_tetra *s, t_table *s2, int x, int y, int placeit)
{
    int     i;
    int     j;

    i = 0;
    if (placeit == -1)
        return (0);
    while (x + i < s2->table_size && i < 4)
    {
        j = 0;
        while (y + j < s2->table_size && j < 4)
        {
            if (s->tab[i][j] == 1)
            {
                if (s2->square[x + i][y + j] == '.')
                    placeit ? s2->square[x + i][y + j] = s->letter : 0;
                else
                    return (-1);

            }
            j++;
        }
        i++;
    }
    return (1);
}
int        tetri_del(t_tetra *s, t_table *s2 ,int x ,int y)
{
    int     i;
    int     j;

    i = 0;
    while (x + i < s2->table_size && i < 4)
    {
        j = 0;
        while (y + j < s2->table_size && j < 4)
        {
            if (s2->square[x + i][y + j] == s->letter)
                s2->square[x + i][y + j] = '.';
            j++;
        }
        i++;
    }
    return (1);
}
/*
 * char **map == t_table *s2
 * t_tetriminos *tetri == t_tetra *s
 */
int solver(t_table *s2, t_tetra *s)
{
    int  x;
    int  y;
    y = 0;
    if (!s)
        return (0);
    while (y <= s2->table_size)
    {
        x = 0;
        while (x < s2->table_size)
        {
            if (verif(s, s2, x, y, verif(s, s2, x, y, 0)))
            {
                if (solver(s2, s + 1))
                    return (1);
                else
                    tetri_del(s, s2, x, y);
            }
            x++;
        }
        y++;
    }
    return (1);
}
