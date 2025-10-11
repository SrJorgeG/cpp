/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 04:39:02 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/10/11 05:15:53 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_H
# define CONTACTS_H

# include <iostream>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string DarkestSecret;
	int			PhoneNumber;
public:
	Contact();
	Contact(Contact& Contact);
	~Contact();
	Contact& Operator(Contact& Contact);
};

#endif // CONTACTS_H
