#! /bin/zsh

##################### valeur ###########################
# color
RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'
YELLOW='\033[0;33m'
BOLD='\033[1m'
RESETBOLD='\033[21m'
PURPLE='\033[0;35m'
WHITE='\033[1;37m'
BLUE='\033[34m'

# for do_test
vector_container="vector"
stack_container="stack"
map_container="map"
set_container="set"

test_folder="./test_main_folder"

# for NAMESPACE
ft=1
std=2

ARRAY_TEST=($map_container $stack_container $vector_container $set_container)

list_test=$(ls ./test_main_folder/vector)








######################### header ##########################

# header for me!
header() {

printf "# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    $GREEN ft_container $RESET                 	       	        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    				                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created by $GREEN hyungyoo $RESET	     	      	       #+#    #+#              #
#    					              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #\n"

}





#################### function ##############################

function check_diff {
	# make diff file
	diff ./diff/ft_$title ./diff/std_$title > ./diff/$title.txt
	
	# remove out stream file
	rm ./diff/ft_$title ./diff/std_$title
	
	if [ -s ./diff/$title.txt ]; then
		printf "$RED			   ko $RESET"
	else
		printf "$GREEN			   ok $RESET"
		rm ./diff/$title.txt
	fi
}


function check_compile {
	if [ "$?" == 0 ]; then
		printf "$GREEN		ok $RESET"
	else
		printf "$RED		ko $RESET"
	fi
}


function check_speed {
	printf "std:  $time_std, ft: $time_ft"
}

function complie_container {
	## 1 est ft, 2 est std pour NAMESPACE 

	# for test file name
	title=$(echo $line | cut -d / -f 2  | sed 's/\.cpp//' )
	printf "$title"
	
	# for complie and stream out in each file
	c++ -std=c++98 -Wall -Wextra -Werror $test_folder/$test_name/$line \
		-D NAMESPACE=$std #>/dev/null 2>&1
	check_compile
	chmod 777 ./a.out #>/dev/null 2>&1
	./a.out > ./diff/std_$title #>/dev/null 2>&1

	c++ -std=c++98 -Wall -Wextra -Werror $test_folder/$test_name/$line \
		-D NAMESPACE=$ft #>/dev/null 2>&1
	check_compile
	chmod 777 ./a.out #>/dev/null 2>&1
        ./a.out > ./diff/ft_$title #>/dev/null 2>&1

	# check_diff
	check_diff $title

	#######################################################!!!
	#to do
	#speed, diff_speed
	#line for ok, ko
	# check time
	#check_speed $time_std $time_ft

	rm ./a.out >/dev/null 2>&1
	printf "\n"
}

function test_container {
	# 2. compile with $1
	#echo "$1 is in function"
	test_name=$1

	ls  $test_folder/$test_name | while read line
	do
		complie_container $test_name $line

	done
}








########################## execute ################################

# test each container with for loop 
do_test() {

	printf "$BOLD$BLUE test file \
	compile for std	\
	complie for ft	\
	diff	\
	speed $RESET\n"

	for i in {0..3}
	do
		printf "\n$BOLD$YELLOW		\
		${ARRAY_TEST[i]} test	$RESET\n\n"
		test_container ${ARRAY_TEST[i]}
	done
}

make_folder() {
	# make diff_folder
	mkdir -p diff_folder
}

remove_folder() {
	# reset diff_folder
	rm -rf diff_folder >/dev/null 2>&1
}


execute() {
	# reset diff_folder
	remove_folder
	# header : creator
	header
	# make diff_folder
	make_folder
	# do_test : with array_test, test all containers
	do_test
}

execute
