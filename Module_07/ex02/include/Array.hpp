/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:11:35 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/03 13:20:45 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
	private:
		T				*array_;
		unsigned int	size_;

	public:
		Array() {
			size_ = 0;
			array_ = NULL;
		}
		Array(unsigned int n) {
			size_ = n;
			array_ = new T[size_];
		}
		Array(const Array& ref) {
			size_ = ref.size_;
			array_ = new T[size_];
			for (unsigned int i = 0; i < size_; i++) {
				array_[i] = ref.array_[i];
			}
		}
		~Array() {
			delete[] array_;
		}

		Array& operator=(const Array& ref) {
			delete[] array_;
			size_ = ref.size_;
			array_ = new T[size_];
			for (unsigned int i = 0; i < size_; i++) {
				array_[i] = ref.array_[i];
			}
			return (*this);
		}
		T& operator[](unsigned int i) {
			if (i < 0 || size_ <= i)
				throw outBoundException();
			return (array_[i]);
		}

		unsigned int size() {
			return (size_);
		}

		class outBoundException : public std::exception {
			public:
			const char* what() const throw() {
				return ("cannot access, index is out of the limits");
			}
		};
};
// class Array {
// 	private:
// 		int				*array_;
// 		unsigned int	size_;

// 	public:
// 		Array() {
// 			size_ = 0;
// 			array_ = NULL;
// 		}
// 		Array(unsigned int n) {
// 			size_ = n;
// 			array_ = new int[size_];
// 		}
// 		Array(const Array& ref) {
// 			size_ = ref.size_;
// 			array_ = new int[size_];
// 			for (unsigned int i = 0; i < size_; i++) {
// 				array_[i] = ref.array_[i];
// 			}
// 		}
// 		~Array() {
// 			delete[] array_;
// 		}

// 		Array& operator=(const Array& ref) {
// 			delete[] array_;
// 			size_ = ref.size_;
// 			array_ = new int[size_];
// 			for (unsigned int i = 0; i < size_; i++) {
// 				array_[i] = ref.array_[i];
// 			}
// 			return (*this);
// 		}
// 		int& operator[](unsigned int i) {
// 			if (i < 0 || size_ <= i)
// 				throw outBoundException();
// 			return (array_[i]);
// 		}

// 		unsigned int size() {
// 			return (size_);
// 		}

// 		class outBoundException : public std::exception {
// 			public:
// 			const char* what() const throw() {
// 				return ("cannot access, index is out of the limits");
// 			}
// 		};
// };

#endif
