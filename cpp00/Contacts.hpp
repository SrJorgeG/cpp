/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 04:39:02 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/10/20 23:24:32 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_H
# define CONTACTS_H

# include <iostream>

class Contact
{
private:
	std::string firstName_;
	std::string	lastName_;
	std::string nickName_;
	std::string darkestSecret_;
	std::string phoneNumber_;
public:
	Contact(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, std::string phoneNumber);
	Contact(const Contact& Contact);
	~Contact();
	Contact& operator=(const Contact& Contact);
};

#endif // CONTACTS_H
