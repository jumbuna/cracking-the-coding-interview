cmake_minimum_required(VERSION 3.0)

project(1_4 VERSION 1.0)

add_executable(1_4 solution.c)

enable_testing()

add_test(NAME Run COMMAND 1_4 hello leloh)

add_test(NAME Usage COMMAND 1_4)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: *")

function(test_1_4 str1 str2 expect)
    add_test(NAME test_${str1} COMMAND 1_4 ${str1} ${str2})
    set_tests_properties(test_${str1} PROPERTIES PASS_REGULAR_EXPRESSION "<${str1}, ${str2}>: ${expect}")
endfunction()

test_1_4(anagram gramana "True")
test_1_4(grafitti gartifi "False")
test_1_4(spar rasp "True")
test_1_4(colon loocn "True")
test_1_4(protest stropet "True")
test_1_4(cron norc "True")
test_1_4(blast slatb "True")
test_1_4(anime maine "True")
test_1_4(parrot rapport "False")
test_1_4(11252 21521 "True")
test_1_4(close scole "True")