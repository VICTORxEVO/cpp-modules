/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:04:22 by ysbai-jo          #+#    #+#             */
/*   Updated: 2025/05/20 19:04:23 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void contact::SetPhoneNum(std::string str)
{
    this->info[3] = str;
}

void contact::SetSecret(std::string str)
{
    this->info[5] = str;
}

void contact::SetFirstName(std::string str)
{
    this->info[0] = str;
}

void contact::SetLastName(std::string str)
{
    this->info[1] = str;
}

void contact::SetNickName(std::string str)
{
    this->info[2] = str;
}

std::string contact::GetFirstName(void) const
{
    return (this->info[0]);
}

std::string contact::GetLastName(void) const
{
    return (this->info[1]);
}

std::string contact::GetNickName(void) const
{
    return (this->info[2]);
}

std::string contact::GetPhoneNum() const
{
    return (this->info[3]);
}

std::string contact::GetSecret() const
{
    return (this->info[5]);
}