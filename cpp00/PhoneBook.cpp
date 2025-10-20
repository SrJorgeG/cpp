/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:38:46 by jgomez-d          #+#    #+#             */
/*   Updated: 2025/10/20 23:28:32 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::monitor()
{
	std::string	buff;
	do
	{
		std::getline(std::cin, buff);
		if (buff == "ADD")
			add();
		if (buff == "SEARCH")
			search();
	} while (buff != "EXIT");
}

void	PhoneBook::add()
{
	i_
}

void	PhoneBook::search()
{
	
}
