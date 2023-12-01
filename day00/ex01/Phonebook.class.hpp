/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:44:48 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/11 11:17:53 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <string>
# include <iomanip>

# include "Contact.class.hpp"

class Phonebook
{
private:
    unsigned int    size;
    Contact         contacts[MAX_CONTACTS];

public:
    Phonebook();
    ~Phonebook();

    void addContact();
    void searchContact();
};

#endif
