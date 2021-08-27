gcc main.c  -Wall -Wextra -Werror -lm
gcc mini.c -o original -Wall -Wextra -Werror -lm
echo ""
echo "TEST - <ex_1>"
echo "NO original"
./a.out ./test/ex_1
echo "Original"
./original ./test/ex_1
echo ""
echo "TEST - <ex_2>"
echo "NO original"
./a.out ./test/ex_2
echo "Original"
./original ./test/ex_2
echo ""
echo "TEST - <NULL>"
echo "NO original"
./a.out
echo "Original"
./original
echo ""
echo "TEST - <Error file>"
echo "NO original"
./a.out ./test/ex
echo "Original"
./original ./test/ex
rm a.out
rm original
