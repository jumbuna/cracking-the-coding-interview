cmake_minimum_required(VERSION 3.0)

project(1_3 VERSION 1.0)

add_executable(1_3 solution.c)

enable_testing()

add_test(NAME Run COMMAND 1_3 hello)

add_test(NAME Usage COMMAND 1_3)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: *")

function(test_1_3 str expect)
    add_test(NAME test_${str} COMMAND 1_3 ${str})
    set_tests_properties(test_${str} PROPERTIES PASS_REGULAR_EXPRESSION "${str}: ${expect}")
endfunction()

test_1_3(jumbuna jumbna)
test_1_3(correct coret)
test_1_3(promotion promtin)
test_1_3(good god)
test_1_3(duplicate duplicate)
test_1_3(crave crave)
test_1_3(aa a)
test_1_3(cologne colgne)
test_1_3(tooth toh)
test_1_3(bristle bristle)
test_1_3(flutter fluter)