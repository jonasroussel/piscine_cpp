/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:07:37 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/10 16:46:12 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

const int MAX_CONTACTS = 8;

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string login;
    std::string postalAddress;
    std::string emailAddress;
    std::string phoneNumber;
    std::string birthdayDate;
    std::string favoriteMeal;
    std::string underwearColor;
    std::string darkestSecret;

public:
    Contact();
    ~Contact();

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getLogin();
    std::string getPostalAddress();
    std::string getEmailAddress();
    std::string getPhoneNumber();
    std::string getBirthdayDate();
    std::string getFavoriteMeal();
    std::string getUnderwearColor();
    std::string getDarkestSecret();

    void setFirstName(std::string);
    void setLastName(std::string);
    void setNickname(std::string);
    void setLogin(std::string);
    void setPostalAddress(std::string);
    void setEmailAddress(std::string);
    void setPhoneNumber(std::string);
    void setBirthdayDate(std::string);
    void setFavoriteMeal(std::string);
    void setUnderwearColor(std::string);
    void setDarkestSecret(std::string);
};


#endif
