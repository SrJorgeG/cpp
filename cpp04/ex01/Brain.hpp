#pragma once

#include <string>
#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(std::string ideas[],  int size);
	Brain(const Brain& other);
	~Brain();
	Brain& operator=(const Brain& other);

	const std::string			getIdea(int index) const;
	const std::string*	getIdeas() const;
	void				setIdeas(std::string ideas[], int size);
	void				setIdea(int index, const std::string& idea);
	
};