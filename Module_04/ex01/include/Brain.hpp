/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:42:20 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 16:47:35 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {
	private:
	std::string idea_[SizeBrainArray];
	unsigned int num_idea_;

	public:
	Brain();
	Brain(const Brain& ref);
	Brain& operator=(const Brain& ref);
	~Brain();

	void addIdea(std::string& idea);
	std::string getIdea(unsigned int idx) const;
};

#endif
