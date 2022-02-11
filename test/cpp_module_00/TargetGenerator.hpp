#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map<std::string, ATarget *>	arr;

		TargetGenerator(TargetGenerator const &copy);
		TargetGenerator &operator=(TargetGenerator const &rhs);
	
	public:
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget *target);
		void	forgetTargetType(std::string const &name_target);
		ATarget *createTarget(std::string const &target);
};
