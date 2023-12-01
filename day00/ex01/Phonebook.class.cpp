/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:50:36 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/11 11:18:08 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

static std::string truncField(std::string field)
{
    if (field.length() > 10)
        return field.substr(0, 9).append(".");
    return field;
}

Phonebook::Phonebook()
{
    this->size = 0;
}

Phonebook::~Phonebook() {}

void Phonebook::addContact()
{
    Contact     *contact;
    std::string buff;

    if (this->size >= MAX_CONTACTS)
    {
        std::cout << "Your phonebook is full (max: " << MAX_CONTACTS
            << " contacts)" << std::endl;
        return;
    }

    contact = this->contacts + this->size;
    
    std::cout << "First name: ";
    std::getline(std::cin, buff);
    contact->setFirstName(buff);

    std::cout << "Last name: ";
    std::getline(std::cin, buff);
    contact->setLastName(buff);
    
    std::cout << "Nickname: ";
    std::getline(std::cin, buff);
    contact->setNickname(buff);
    
    std::cout << "Login: ";
    std::getline(std::cin, buff);
    contact->setLogin(buff);
    
    std::cout << "Postal address: ";
    std::getline(std::cin, buff);
    contact->setPostalAddress(buff);
    
    std::cout << "Email address: ";
    std::getline(std::cin, buff);
    contact->setEmailAddress(buff);
    
    std::cout << "Phone number: ";
    std::getline(std::cin, buff);
    contact->setPhoneNumber(buff);
    
    std::cout << "Birthday date: ";
    std::getline(std::cin, buff);
    contact->setBirthdayDate(buff);
    
    std::cout << "Favorite meal: ";
    std::getline(std::cin, buff);
    contact->setFavoriteMeal(buff);

    std::cout << "Underwear color: ";
    std::getline(std::cin, buff);
    contact->setUnderwearColor(buff);

    std::cout << "Darkest secret: ";
    std::getline(std::cin, buff);
    contact->setDarkestSecret(buff);

    this->size++;
}

void Phonebook::searchContact()
{
    int     index;
    Contact contact;

    if (this->size <= 0) {
        std::cout << "Your phonebook is empty" << std::endl;
        return;
    }

    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;

    for (int i = 0; i < this->size; i++) {
        contact = this->contacts[i];

        std::cout
        << "|" << std::setw(10) << i
        << "|" << std::setw(10) << truncField(contact.getFirstName())
        << "|" << std::setw(10) << truncField(contact.getLastName())
        << "|" << std::setw(10) << truncField(contact.getNickname())
        << "|" << std::endl;
    }

    std::cout << "Select a contact by his index: ";
    std::cin >> index;
    std::cin.get();

    if (std::cin.good() && index >= 0 && index < this->size)
    {
        contact = this->contacts[index];

        std::cout
        << "First name: " << contact.getFirstName() << std::endl
        << "Last name: " << contact.getLastName() << std::endl
        << "Nickname: " << contact.getNickname() << std::endl
        << "Login: " << contact.getLogin() << std::endl
        << "Postal address: " << contact.getPostalAddress() << std::endl
        << "Email address: " << contact.getEmailAddress() << std::endl
        << "Phone number: " << contact.getPhoneNumber() << std::endl 
        << "Birthday date: " << contact.getBirthdayDate() << std::endl
        << "Favorite meal: " << contact.getFavoriteMeal() << std::endl
        << "Underwear color: " << contact.getUnderwearColor() << std::endl
        << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
    }
    else
    {
        std::cout << "Sorry, selected index is invalid (between 0 and "
            << this->size - 1 << ")" << std::endl;
    }
}
