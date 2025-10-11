/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 04:07:37 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/10/11 04:57:19 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contacts.hpp"

class PhoneBook
{
private:
	Contact	Contacts[8];
public:
	PhoneBook();
	PhoneBook(PhoneBook& PhoneBook);
	~PhoneBook();
	PhoneBook Operator(PhoneBook& PhoneBook);
};

#endif // PHONEBOOK_HPP
