
$숫자 

ls | << end

< Makefile  | cat

< Makefile > file | ls
--> cat file ==> ls list


mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew

Edit ~/.profile to include

export PATH=$HOME/homebrew/bin:$PATH
brew install gcc
