# This tester is from 42_container_tester(jcluzet <jcluzet@student.42.fr> : https://github.com/JCluzet/42_container_tester)
# For personnal use, I modified its path and some options to facilitate my correction.


if [[ "$1" == "cleanup" ]]; then
    rm -rf result diff
    exit 0  
fi


# if [ "$1" == "--sanitize" ] || [ "$2" == "--sanitize" ] || [ "$3" == "--sanitize" ]; then
#     DEBUG="-fsanitize=address -g3"
# else
#     DEBUG=""
# fi

# if command timeout is not installed, tell a wrong message
# out=$(timeout && echo $?)
# if [ "$out" == "124" ]; then
#     timeoutt=""
#     else #success time out case -> return 0
#     timeoutt="timeout 4"
# fi
# if [ ! -x "$(command -v timeout)" ]; then
#     echo "Command timeout is not installed. Please install it."
#     exit 1
# fi

RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'
YELLOW='\033[0;33m'
BOLD='\033[1m'
RESETBOLD='\033[21m'
PURPLE='\033[0;35m'
WHITE='\033[1;37m'
BLUE='\033[34m'

output=$(echo -e "test")
if [[ $output == "test" ]]; then
    clear
else
    clear
    printf "${RED}ERROR :${RESET} Please launch this script with bash. ${GREEN} \n\nTry : ${RESET}bash mytester.sh\n\n"
    exit 1
fi

# clear

header() {
    printf "$WHITE
$BOLD$BLUE# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    FT_CONTAINERS                                      :+:      :+:    :+:    #
#            SELF_TESTER                              +:+ +:+         +:+      #
#                                                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    keulee                                            #+#    #+#              #
#    Vector / Stack / Map / Set                       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #$RESET\n\n"
}

rm -rf test_logs >/dev/null 2>&1
rm -rf result >/dev/null 2>&1
rm -rf diff >/dev/null 2>&1

test_byfolder() {
    for folder in test_main_folder/$folderact/; do
        #stock folder in foldername variable in MAJ mode (upper case) and remove the last / to get the name of the folder and remove the first 5 characteres
        foldername=$(echo $folder | tr '[:lower:]' '[:upper:]' | sed 's/^.\{17\}//' | sed 's/.$//')
        if [ $i -ne 0 ]; then
            printf "\n$YELLOW$BOLD$foldername$RESET\n"
        else
            printf "$YELLOW$BOLD$foldername$RESET\n"
        fi
        for actual_test in $(find $folder -name "*.cpp" -type f); do
            # if [ $actual_test == "lexicographical_comp"]
            testing
            i=$(($i + 1))
        done
    done
}

switch_tostud() {
    cat test_main_folder/main.hpp | sed 's/using namespace std/using namespace ft/g' | sed 's/namespace std/namespace ft/g' >maintmp.hpp
    rm test_main_folder/main.hpp
    mv maintmp.hpp test_main_folder/main.hpp
}

switch_toboc() {
    cat test_main_folder/main.hpp | sed 's/using namespace ft/using namespace std/g' | sed 's/namespace ft/namespace std/g' >maintmp.hpp
    rm test_main_folder/main.hpp
    mv maintmp.hpp test_main_folder/main.hpp
}

giveup=0

testing() {
    switch_tostud
    rm a.out >/dev/null 2>&1
    actual=$(echo $actual_test | sed 's/.*\///' | sed 's/\.cpp//')
    # echo $actual
    #remove the 5 first characters of the string and adding .log at the end
    logs=$(echo $actual_test | sed 's/^.\{5\}//' | sed 's/\.cpp//')
    logs=test_logs/$logs.log
    # replace every // by /
    logs=$(echo $logs | sed 's/\/\//\//g')
    #echo ">>$logs<<"
    actualnb=$(echo $actual | wc -c)
    # printf ">>$actual<<\n"
    maxnb=22
    getspace=$(($maxnb - $actualnb))
    c++ -Wall -Wextra -Werror -std=c++98 $DEBUG $actual_test >.dev 2>&1 #FT COMPLIE START
    # output maxnb - maxnb space characters
    if [ "$?" == "0" ]; then
        printf "$WHITE$BOLD$actual$RESET" #stack_top
        while [ $getspace -gt 0 ]; do
            getspace=$(($getspace - 1))
            printf " "                    
        done
        printf "$GREEN        🆗      $RESET"
        nul=0
        giveup=10
    else
        printf "$RED$BOLD$actual$RESET"
        while [ $getspace -gt 0 ]; do
            getspace=$(($getspace - 1))
            printf " "
        done
        mkdir -p $logs >/dev/null 2>&1
        rm -r $logs
        cat .dev >$logs
        printf "$RED        ❌      $RESET $YELLOW  SKIPPED $RESET "
        giveup=$((giveup + 1))
        nul=1
    fi
    # if giveup=5 then we skip the test
    if [ $giveup -eq 4 ] && [ $ignoreerror -eq 0 ]; then
        clear
        printf "STOP TESTER: too many${RED} ERROR $RESET \n"
        printf "Please check your error :\n\n\n"
        cat $logs >&2
        printf "$WHITE           └──> Find and fix this error in your code$BOLD logs in folder :$RESET$WHITE test_logs$RESET\n\n"
        exit
    fi
    if [ -f a.out ]; then
        ./a.out > result/ft.$actual.result
    fi


    if [ $nul -eq 0 ]; then
        # if a.out take more than 1 second to execute, it's a timeout error

        # starttime=$(date +%s)
        # time ./a.out 2>&1 ; sleep 1 ; kill -9 $! >/dev/null 2>&1
        # # if process is still running after 1 second, it's a timeout error
        # endtime=$(date +%s)
        # echo "heyyyy"
        # if [ $(($endtime - $starttime)) -gt 1 ]; then
        #     printf "$RED        TIMEOUT $RESET"
        #     nul=1
        # fi

        timeout=0
        # if timeout command exist 

        outputstud=$($timeoutt ./a.out)
        out=$(echo $?)
        if [ "$out" == "124" ]; then
            # printf "$RED        TIMEOUT $RESET"
            timeout=1
        else
            stud_time="$(time (./a.out) 2>&1 1>/dev/null)"
        fi
        switch_toboc #STD TEST COMPLIE START
        c++ -Wall -Wextra -Werror -std=c++98 -g3 $actual_test >.dev 2>&1
        if [ "$?" == "0" ]; then
            printf " $GREEN    🆗     $RESET"
            nul=0
        else
            mkdir -p $logs >/dev/null 2>&1
            rm -r $logs
            cat .dev >$logs 
            printf "|$RED    ❌     $RESET"
            nul=1
        fi
        outputboc=$(./a.out)
        boc_time="$(time (./a.out) 2>&1 1>/dev/null)"
        diffoutput=$(diff <(echo "$outputstud") <(echo "$outputboc"))
    else
        diffoutput="diff ❌"
    fi

    if [ -f a.out ]; then
        ./a.out > result/std.$actual.result
    fi
    # remove all after first newline
    # stud_t=$(echo $stud_time | cut -d " " -f 1)
    # echo $stud_t
    # boc_t=$(echo $boc_time | cut -d " " -f 1 )
    # echo $boc_t
    stud_t=$(echo $stud_time | sed 's/.\{5\}//' | cut -d " " -f 1 | sed 's/.\{2\}//' | sed 's/.$//' | sed s/','/'.'/g)
    boc_t=$(echo $boc_time | sed 's/.\{5\}//' | cut -d " " -f 1 | sed 's/.\{2\}//' | sed 's/.$//' | sed s/','/'.'/g)
    if [ -z "$diffoutput" ] && [ $nul -eq 0 ]; then
        printf "| $GREEN   🆗    $RESET|"
        # if stud_t - boc_t < 0.3 then OK else KO
        # good1="$stud_t $boc_t"
        good=$(echo "$stud_t<$boc_t*20" | bc) #bc: calcul
        # good=$(echo "$good1" | awk '{if ($1-$2 < 0.06) print "OK"; else print "KO"}')
        if [ "$good" == "1" ]; then
            printf "  $GREEN$stud_t"
            printf "s$RESET   $GREEN$boc_t"
            printf "s$RESET "
            goodtest=$((goodtest + 1))
        else
            if [ "$DEBUG" != "-fsanitize=address -g3" ]; then
                printf "  $GREEN$stud_t"
                printf "s$RESET  | $RED$boc_t"
                printf "s$RESET | $RED--> >20x slower than std $RESET" # GESTON DU TEMPS DE COMPILATION          !!!!!!!!!!!!!
            else
                printf "$GREEN   Try without --SANITIZE    $RESET "
                    goodtest=$((goodtest + 1))

            fi
        fi
    else
        if [ "$diffoutput" != "diff ❌" ] && [ $nul -eq 0 ]; then
            mkdir -p diff >/dev/null 2>&1
            # echo "ok"
            # rm -r $logs
            echo "----------------------- FT RESULT:" >diff/$actual.diff
            cat result/ft.$actual.result >>diff/$actual.diff
            echo "----------------------- STD RESULT:" >>diff/$actual.diff
            cat result/std.$actual.result >>diff/$actual.diff
            echo " >> ----------------------- DIFF CHECK " >>diff/$actual.diff
            diff result/ft.$actual.result result/std.$actual.result >>diff/$actual.diff
        fi
        if [ "$timeout" == "1" ]; then
            # printf "| $RED   ❌  $RESET  |  $GREEN$boc_t$RED  $WHITE |$RED TIMEOUT $RESET"
            printf "| $RED   ❌  $RESET  |  $RED TIMEOUT $RESET | $GREEN$boc_t  $WHITE$RESET"
        elif [ "$actual" == "map_maxsize" ] && [ ! -s "$diffoutput" ]; then
            # printf "| $WHITE   ❗  $RESET -> $RED map::max_size() it's ok$RESET"
            printf "| $WHITE   ❗  $RESET  | $GREEN $stud_t"
            printf "s$RESET   $GREEN$boc_t"
            printf "s$RESET "
        elif [ "$actual" == "set_maxsize" ] && [ ! -s "$diffoutput" ]; then
            # printf "| $WHITE   ❗  $RESET -> $RED map::max_size() it's ok$RESET"
            printf "| $WHITE   ❗  $RESET  | $GREEN $stud_t"
            printf "s$RESET   $GREEN$boc_t"
            printf "s$RESET "
        else
            printf "| $RED   ❌  $RESET -> $RED check test_logs folder / result folder / diff folder$RESET"
        fi
    fi
    if [ "$goloop" == "0" ]; then
        printf "\n"
    fi
}

echo "----------- FT_CONTAINERS TESTER FOLDER PATH CHECK ----------------"
printf "\n"
path_stack=$(find ../. -name "stack.hpp" -o -name "Stack.hpp" | head -n 1)
if [ "$path_stack" == "" ]; then
    printf "$RED \nCan't find any files named 'stack.hpp' or 'Stack.hpp' in the current directory or in subdirectories.$RESET\n\nExpected Tree:\n\n. [your_project]\n└── container_test\n    └── mytest.sh \n\nEnter your path to the file 'stack.hpp' or 'Stack.hpp' : "
else
    printf "path for Stack: $GREEN $path_stack$RESET"
fi


# echo "TESTING FT_CONTAINERS"
ignoreerror=0

printf "\n"
path_vector=$(find ../. -name "vector.hpp" -o -name "Vector.hpp" | head -n 1)
if [ "$path_vector" == "" ]; then
    printf "$RED \nCan't find any files named 'vector.hpp' or 'Vector.hpp' in the current directory or in subdirectories.$RESET\n\nExpected Tree:\n\n. [your_project]\n└── container_test\n    └── mytest.sh \n\nEnter your path to the file 'stack.hpp' or 'Stack.hpp' : "
    # read path_vector
else
    printf "path for Vector: $GREEN $path_vector$RESET"
fi
# if there is a using namespace in Stack.hpp or stack.hpp, then show error

printf "\n"
path_map=$(find ../. -name "map.hpp" -o -name "Map.hpp" | head -n 1)
if [ "$path_map" == "" ]; then
    printf "$RED \nCan't find any files named 'map.hpp' or 'Map.hpp' in the current directory or in subdirectories.$RESET\n\nExpected Tree:\n\n. [your_project]\n└── container_test\n    └── mytest.sh \n\nEnter your path to the file 'stack.hpp' or 'Stack.hpp' : "
else
    printf "path for Map: $GREEN $path_map$RESET"
fi

printf "\n"
path_set=$(find ../. -name "set.hpp" -o -name "Set.hpp" | head -n 1)
if [ "$path_set" == "" ]; then
    printf "$RED \nCan't find any files named 'set.hpp' or 'Set.hpp' in the current directory or in subdirectories.$RESET\n\nExpected Tree:\n\n. [your_project]\n└── container_test\n    └── mytest.sh \n\nEnter your path to the file 'stack.hpp' or 'Stack.hpp' : "
else
    printf "path for Set: $GREEN $path_set$RESET"
fi

printf "\n"
path_utils=$(find ../. -name "utils.hpp" -o -name "Utils.hpp" | head -n 1)
if [ "$path_utils" == "" ]; then
    printf "$RED \nCan't find any files named 'utils.hpp' or 'Utils.hpp' in the current directory or in subdirectories.$RESET\n\nExpected Tree:\n\n. [your_project]\n└── container_test\n    └── mytest.sh \n\nEnter your path to the file 'stack.hpp' or 'Stack.hpp' : "
else
    printf "path for Utils: $GREEN $path_utils$RESET"
fi
printf "\n\n"

# check_folderpath
printf "Everything Alright, Continue ? (y/n) : "
while true;
do
    read answer
    if [ "$answer" == "y" ]; then
        printf "$RESET"
        break ;
    elif [ "$answer" == "n" ]; then
        printf "\n"
        printf "If it's not right path, change it in$RED$BOLD mytester.sh PATH MANUAL CONFIG at 370 line$RESET, and try again plz\n"
        printf "Test stops here\n"
        sleep 2;
        exit 1
    else
        printf "type y or n only plz (in miniscule)\n"
    fi
done
printf "\n"

# check debug flag on or off
printf "Test with flag -fsanitizer? (y/n): "
while true;
do
    read answer
    if [ "$answer" == "y" ]; then
        DEBUG="-fsanitize=address -g3"
        break ;
    elif [ "$answer" == "n" ]; then
        DEBUG=""
        break ;
    else
        printf "type y or n only plz (in miniscule)\n"
    fi
done
printf "\n"


clear
header

#check if ft_containers using "using namesapce"
if [ "$(cat $path_stack | grep "using namespace")" != "" ]; then
    printf "$RED \nYour Stack.hpp file contains a$WHITE using namespace$RED !\n ->$WHITE This is not allowed, please remove it for testing.$RESET\n"
    exit
fi
if [ "$(cat $path_stack | grep "using namespace")" != "" ]; then
    printf "$RED \nYour Vector.hpp file contains a$WHITE using namespace$RED !\n ->$WHITE This is not allowed, please remove it for testing.$RESET\n"
    exit
fi
if [ "$(cat $path_map | grep "using namespace")" != "" ]; then
    printf "$RED \nYour Map.hpp file contains a$WHITE using namespace$RED !\n ->$WHITE This is not allowed, please remove it for testing.$RESET\n"
    exit
fi

cat test_main_folder/main.hpp | sed '12,100d' >maintmp.hpp # if adding line in .hpp then add +1 to 22
rm test_main_folder/main.hpp
mv maintmp.hpp test_main_folder/main.hpp
mkdir -p result diff

################################################################################################################### PATH MANUAL CONFIG
#change path here manually if you have a problem to detect path automatically
echo "#include \"../$path_stack\"" >>test_main_folder/main.hpp
echo "#include \"../$path_vector\"" >>test_main_folder/main.hpp
echo "#include \"../$path_map\"" >>test_main_folder/main.hpp
echo "#include \"../$path_set\"" >>test_main_folder/main.hpp
########################################################################################################################################

printf "\n                       $WHITE          COMPILE        $RESET  $WHITE   DIFF  $RESET    $WHITE     TIME$RESET"
printf "\n                       $WHITE      FT     $RESET  $WHITE    STD    $RESET  $WHITE        $RESET    $WHITE FT  $RESET   $WHITE  STD$RESET\n"
 
i=0
goodtest=0
        goloop=0

# [ -z ] : 문자열의 길이가 0이면 참
# [ -n ] : 문자열의 길이가 0이 아니면 참

# [ -eq ] : 값이 같으면 참
# [ -ne ] : 값이 다르면 참
# [ -gt ] :  값1 > 값2
# [ -ge ] : 값1  >= 값2
# [ -lt ] : 값1 < 값2
# [ -le ] : 값1 <= 값2

# [ -a ] : &&연산과 동일 and 연산
# [ -o ] : ||연산과 동일 xor 연산

# 
# [ -d ] : 파일이 디렉토리면 참
# [ -b ] : 파일이 존재하고 블록장치 파일인 경우 true
# [ -e ] : 파일이 있으면 참
# [ -L ] : 파일이 심볼릭 링크면 참
# [ -r ] : 파일이 읽기 가능하면 참
# [ -s ] : 파일의 크기가 0 보다 크면 참
# [ -w ] : 파일이 쓰기 가능하면 참
# [ -x ] : 파일이 실행 가능하면 참
# [ -f ] : 파일이 존재하고 정규 파일인 경우 true
# [ 파일1 -nt 파일2 ]  : 파일1이 파일2보다 최신파일이면 참
# [ 파일1 -ot 파일2 ]  : 파일1이 파일2보다 이전파일이면 참
# [ 파일1 -ef 파일2 ] : 파일1이 파일2랑 같은 파일이면 참
# 출처: https://jink1982.tistory.com/48 [돼민이:티스토리]


# for each folder in the directory main/
# if there is a argument then only test the file name given in argument
if [ $1 ]; then
    # if argument is "stack" or "STACK" then only test the stack
    if [ "$1" == "stack" ]; then
        folderact="stack"
        test_byfolder
    elif [ "$1" == "vector" ]; then
        folderact="vector"
        test_byfolder
    elif [ "$1" == "map" ]; then
        folderact="map"
        test_byfolder
    elif [ "$1" == "set" ]; then
        folderact="set"
        test_byfolder
    elif [ "$1" == "utils" ]; then
        folderact="utils"
        test_byfolder
    # elif $1 is a folder name
    elif [ "$1" == "test_main_folder" ] || [ "$1" == "test_main_folder/" ]; then
        folderact="*"
        test_byfolder
    elif [ -d "$1" ]; then #if argument is directory
        folderact=$(echo $1 | sed 's/^.\{17\}//')
        test_byfolder
    elif [ -f "$1" ]; then #if 
        actual_test=$1
        # if [ "$2" == "--loop" ] || [ "$3" == "--loop" ] || [ "$4" == "--loop" ] ; then
        #     ignoreerror=1
        #     while [ 1 ]; do
        #         goloop=1
        #         printf "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
        #         testing
        #     done
        # fi
        testing
        i=$(($i + 1))
    else
        printf "$RED\n$RESET$1$RED is not valid folder or file.\n$RESET\nExemple : bash mytest.sh stack\n          bash mytest.sh vector\n          bash mytest.sh map\n          bash mytest.sh main_test_folder/vector/vector_constructor.cpp\n          bash mytest.sh main_test_folder/stack/stack_pop.cpp\n"
        # printf " --sanitize : Launch select test with -fsanitize=address \n" 
        # printf " --verbose : Print all the result test in test_logs \n\n"
        exit 1
    fi
else
    folderact="*"
    test_byfolder
fi

rm .dev >/dev/null 2>&1
rm a.out >/dev/null 2>&1

if [ $goodtest -eq $i ]; then
    printf "\n $WHITE RESULT : $GREEN$goodtest$RESET/$WHITE$i $RESET\n\n"
else
    printf "\n $WHITE RESULT : $RED$goodtest$RESET/$WHITE$i $RESET\n"
fi
printf "\n"
printf "$WHITE  Check logs in the folder $BLUE \e[3mtest_logs or result\e[0m $WHITE if you need.$WHITE$RESET\n"
printf "$BOLD  ❗If Diff ❌ concerns with $BLUE \e[3mmax_size()\e[0m$WHITE, it's ok there's no problem.$RESET\n\n"
