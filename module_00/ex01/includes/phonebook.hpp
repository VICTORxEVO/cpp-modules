/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:04:30 by ysbai-jo          #+#    #+#             */
/*   Updated: 2025/05/22 10:44:02 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
# define PHONEBOOK

#include <string>
#include <iostream>
#include <cstdlib>

class contact
{
    private:
        std::string info[5];
    public:
        void SetFirstName(std::string str);
        void SetLastName(std::string str);
        void SetNickName(std::string str);
        void SetPhoneNum(std::string str);
        void SetSecret(std::string str);
        std::string GetFirstName() const;
        std::string GetLastName() const;
        std::string GetNickName() const;
        std::string GetPhoneNum() const;
        std::string GetSecret() const;
};



class phonebook
{
    private:
        contact contacts[8];
    public:
        int index ;    

        void add();
        void search();
};










#endif