/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 04:42:45 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/10/11 05:25:29 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contact::Contact() : FirstName(""), LastName(""), NickName(""), DarkestSecret(""){}

Contact::Contact(Contact& other)
{
	this->FirstName = other.FirstName;
	this->LastName = other.LastName;
	this->NickName = other.NickName;
	this->DarkestSecret = other.DarkestSecret;
	this->PhoneNumber = other.PhoneNumber;
}

~Contact();