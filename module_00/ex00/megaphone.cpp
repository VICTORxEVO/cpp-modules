/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:04:09 by ysbai-jo          #+#    #+#             */
/*   Updated: 2025/05/20 19:04:10 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *av[])
{
    int i;
    int j;

    i = 0;
    if (ac <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (++i < ac)
    {
        j = -1;
        while (av[i][++j])
        {
            if (av[i][j] >= 'a' && av[i][j] <= 'z')
                std::cout << (char)std::toupper((av[i][j]));
            else
                std::cout << av[i][j];
        }
    }
    std::cout << std::endl;
    return 0;
}
