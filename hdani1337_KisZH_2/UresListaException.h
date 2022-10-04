#pragma once

#include <exception>

class UresListaException : public std::exception {
	std::string message;
public:
	UresListaException(std::string str) : std::exception() {
		message = str;
	}

	virtual const char *what() const throw() {
		return message.c_str();
	}
};


