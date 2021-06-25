# GNL

• Des appels successifs à votre fonction get_next_line doivent vous permettre de lire l’entièreté du texte disponible sur le file descriptor, une ligne à la fois, jusqu’au EOF.

• Lalibftn’estpasautoriséesurceprojet.Vousdevezaujouterlefichierget_next_line_utils.c qui contiendra les fonctions nécessaires au fonctionnement de votre get_next_line.

• Assurez-vous que votre fonction se comporte correctement lorsque vous lisez depuis un fichier ou l’entrée standard.

• Votre programme doit compiler avec le flag -D BUFFER_SIZE=xx Ce define doit être utilisé dans vos appels de read du get_next_line, pour définir la taille du buffer. Cette valeur sera modifiée lors de l’évaluation et par la moulinette.

• Compilation:gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

• Votre read DOIT utiliser le BUFFER_SIZE pour lire depuis un fichier ou depuis le stdin.

• Dans le fichier header get_next_line.h, vous devez avoir au moins le prototype de la function

## 3줄 요약
- static variable을 사용해야함
- write, read, open, close함수들을 공부해야함
- 모든 버퍼 사이즈에 대해서 작동해야함. 각 버퍼사이즈만큼 malloc과 free를 반복하는사람들도있음
