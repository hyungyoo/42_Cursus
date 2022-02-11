#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator const &copy);
		TargetGenerator  &operator=(TargetGenerator const &rhs);

		std::map<std::string, ATarget *> arr;

	public:
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget *target);
		void	forgetTargetType(std::string const &target);
		ATarget	*createTarget(std::string const &target);

};
