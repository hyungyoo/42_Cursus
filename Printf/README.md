# ft_printf

## Partie obligatoire

• Le prototype de ft_printf devra être int ft_printf(const char *, ...);

• Vous devez recoder la fonction printf de la libc

• Vous ne devez pas gérer de buffer, contrairement au vrai printf

• Vous devez gérer les conversions suivantes : cspdiuxX%

• Vous devez gérer n’importe quelle combinaison de flags ’-0.*’ et la taille de champ minimale avec toutes les conversions

• Votre rendu sera comparé au vrai printf

• Vous devez utiliser la commande ar pour créer votre librairie, l’utilisation de la commande libtool est interdite

## 새롭게 접한것

• 가변인수 (va_list, va_start, va_arg, va_copy, va_end)

• printf의 옵션들

• 컴파일 옵션 (-l, -L, -g -fsanitize=address)

#### 기록들
1. https://velog.io/@hyungyoo/ftprintf-구현
2. https://velog.io/@hyungyoo/ftprintf-2-일차
3. https://velog.io/@hyungyoo/ftprintf-3-일차
