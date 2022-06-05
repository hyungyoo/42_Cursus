
all :
	@cd main_tester && bash ./test.sh

re:	fclean all

fclean:
	@printf "pas besoin de fclean\n"
	@rm -rf ./main_tester/diff

clean:
	@printf "pas besoin de clean\n"
	@rm -rf ./main_tester/diff

.PHONY: all re fclean clean
