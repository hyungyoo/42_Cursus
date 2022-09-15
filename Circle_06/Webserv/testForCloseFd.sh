#!/bin/zsh

checkPs=$(ps -a | grep webserv)
vide=""

if [ $checkPs -eq $vide ] 
then
	echo "no ps of webserv"
else
	webserv=$(ps -a | grep webserv | cut -d " " -f2)
	while [ true ]
	do
		lsof -p $webserv | grep TCP
		sleep 2
		echo ""
	done
	echo "test is over"
fi