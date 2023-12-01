/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:36:34 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/10 18:06:36 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Phonebook.class.hpp"
#include "Contact.class.hpp"

void help()
{
    std::cout << "ADD     Add a new contact to phonebook" << std::endl;
    std::cout << "SEARCH  Display contacts in table" << std::endl;
}

bool eval(std::string cmd, Phonebook *phonebook)
{
    if (cmd == "EXIT")
        return false;
    else if (cmd == "HELP")
        help();
    else if (cmd == "ADD")
        phonebook->addContact();
    else if (cmd == "SEARCH")
        phonebook->searchContact();

    return true;
}

int main(int argc, char const *argv[])
{
    Phonebook       phonebook;
    std::string     cmd;

    while (true) {
        std::cout << "phonebook> ";
        std::getline(std::cin, cmd);
        
        if (eval(cmd, &phonebook) == false) {
            return 0;
        }
    }

    return 0;
}
