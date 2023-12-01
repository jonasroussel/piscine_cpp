/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:08:50 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/10 16:46:26 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

/**
 * Constructors
 */

Contact::Contact() {}
Contact::~Contact() {}

/**
 * Getters
 */

std::string Contact::getFirstName()
{
    return this->firstName;
}

std::string Contact::getLastName()
{
    return this->lastName;
}

std::string Contact::getNickname()
{
    return this->nickname;
}

std::string Contact::getLogin()
{
    return this->login;
}

std::string Contact::getPostalAddress()
{
    return this->postalAddress;
}

std::string Contact::getEmailAddress()
{
    return this->emailAddress;
}

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}

std::string Contact::getBirthdayDate()
{
    return this->birthdayDate;
}

std::string Contact::getFavoriteMeal()
{
    return this->favoriteMeal;
}

std::string Contact::getUnderwearColor()
{
    return this->underwearColor;
}

std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}

/**
 * Setters
 */

void Contact::setFirstName(std::string value)
{
    this->firstName = value;
}

void Contact::setLastName(std::string value)
{
    this->lastName = value;
}

void Contact::setNickname(std::string value)
{
    this->nickname = value;
}
void Contact::setLogin(std::string value)
{
    this->login = value;
}

void Contact::setPostalAddress(std::string value)
{
    this->postalAddress = value;
}

void Contact::setEmailAddress(std::string value)
{
    this->emailAddress = value;
}

void Contact::setPhoneNumber(std::string value)
{
    this->phoneNumber = value;
}

void Contact::setBirthdayDate(std::string value)
{
    this->birthdayDate = value;
}

void Contact::setFavoriteMeal(std::string value)
{
    this->favoriteMeal = value;
}

void Contact::setUnderwearColor(std::string value)
{
    this->underwearColor = value;
}

void Contact::setDarkestSecret(std::string value)
{
    this->darkestSecret = value;
}
