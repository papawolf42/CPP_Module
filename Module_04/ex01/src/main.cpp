/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:48:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 16:05:51 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* i = new Dog();
	const Animal* j = new Cat();

	Dog* dog_base = (Dog*)i;
	Cat* cat_base = (Cat*)j;

	dog_base->addIdea("walk! walk! outside!");
	dog_base->addIdea("I'm hungry~");
	dog_base->addIdea("I love you!");
	cat_base->addIdea("Don't look at me human!");
	cat_base->addIdea("Don't touch me human!");
	cat_base->addIdea("Why don't you give me food!");
	std::cout << std::endl;

	unsigned int size = 6;
	Animal* animals[size];
	std::cout << std::endl;

	for (unsigned idx = 0; idx < size / 2; idx++) {
		animals[idx] = new Dog(*dog_base);
	}
	for (unsigned idx = size / 2; idx < size; idx++) {
		animals[idx] = new Cat(*cat_base);
	}
	for (unsigned int idx = 0; idx < size; idx++) {
		if (idx < size / 2) {
			unsigned int num = idx % 3 + 1;
			std::cout << ((Dog*)animals[idx])->getIdea(num) << std::endl;
		} else {
			unsigned int num = idx % 3 + 1;
			std::cout << ((Cat*)animals[idx])->getIdea(num) << std::endl;
		}
		delete animals[idx];
	}

	// Animal* ptr;
	// ptr = new Dog(*dog_base);

	// Dog* ptr_d = (Dog*)ptr;
	// Dog c;

	// c = *ptr_d;

	// std::cout << ((Dog*)ptr)->getIdea(1) << std::endl;
	// std::cout << ptr_d->getIdea(1) << std::endl;
	// std::cout << c.getIdea(1) << std::endl;
}
