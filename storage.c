#include "fillit.h"

int     move_up(t_tetra *tetra)
{
    int     i;
    int     j;

    i = 0;
    while (i < 4)
    {
        if (tetra->tab[0][i] == 1)
            return (0);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (i != 3)
                tetra->tab[i][j] = tetra->tab[i + 1][j];
            else
                tetra->tab[i][j] = 0;
            j++;
        }
        i++;
    }
    return (1);
}

int     move_left(t_tetra *tetra)
{
    int     i;
    int     j;

    i = 0;
    while (i < 4)
    {
        if (tetra->tab[i][0] == 1)
            return (0);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (j != 3)
                tetra->tab[i][j] = tetra->tab[i][j + 1];
            else
                tetra->tab[i][j] = 0;
           j++;
        }
        i++;
    }
    return (1);
}

void    move_up_left(t_tetra **t, int nb)
{
    int     possible;
    t_tetra *tetros;

    tetros = *t;
    while (nb)
    {
        possible = 1;
        while (possible)
            possible = move_left(tetros) | move_up((tetros));
        tetros++;
        nb--;
    }
}
/*
 *  Take index and create a double char array set to NULL and return it
 */
char    **ft_create_double_array(int x, int y)
{
    char    **str_d;
    int     i;
    str_d = ft_memalloc((x * sizeof(char*)));
    i = 0;
    while (i < x)
    {
        str_d[i] = ft_memalloc(y * sizeof(char));
        i++;
    }
    return(str_d);
}

/*
 * take a double char array full with tetrominos and the number of tetrominos
 * and return a t_tetra structure array whit in each dimention
 *      tab[4][4] fot the tetro and the total number of tetros
 */
t_tetra *ft_store_teros(char **tetros, int nb)
{
    t_tetra *res;
    int     i;
    int     j;
    int     m;
    int     n;

    res = ft_memalloc(nb * sizeof(t_tetra));
    i = 0;
    while (i < nb - 1)
    {
        m = 0;
        j = 0;
        res[i].total_tetros = nb - 1;
        while (m < 4)
        {
            n = 0;
            while (n < 4)
            {
                if (tetros[i][j] == '.')
                    res[i].tab[m][n] = 0;
                else
                    res[i].tab[m][n] = 1;
                j++;
                n++;
            }
            j++;
            m++;
        }
        i++;
    }
    move_up_left(&res, res[0].total_tetros);
    return (res);
}

/*
 * this one is only to check if we stored the tetros, it will be remove for the moulinette
 * it takes the t_tetra array and print them all on screen
 */
void     ft_print_tetros(t_tetra *t)
{
    int m;
    int i;
    int j;

    ft_putchar('\n');
    m = 0;
    while (m < t[0].total_tetros)
    {
        i = 0;
        while (i < 4)
        {
            j = 0;
            while (j < 4)
            {
                ft_putnbr(t[m].tab[i][j]);
                j++;
            }
            ft_putchar('\n');
            i++;
        }
        ft_putchar('\n');
        m++;
    }
}