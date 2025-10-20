/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 04:42:45 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/10/20 23:22:07 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret, std::string phoneNumber) : firstName_(firstName), lastName_(lastName), nickName_(nickName), darkestSecret_(darkestSecret), phoneNumber_(phoneNumber){}

Contact::Contact(const Contact& other)
{
	this->firstName_ = other.firstName_;
	this->lastName_ = other.lastName_;
	this->nickName_ = other.nickName_;
	this->darkestSecret_= other.darkestSecret_;
	this->phoneNumber_ = other.phoneNumber_;
}

Contact::~Contact()
{
}
