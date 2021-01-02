cmake_minimum_required(VERSION 3.0)

project(1_2 VERSION 1.0)

add_executable(1_2 solution.c)

enable_testing()

add_test(NAME Run COMMAND 1_2 hello)

add_test(NAME Usage COMMAND 1_2)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: *")

function(test_1_2 str expect)
    add_test(NAME test_${str} COMMAND 1_2 ${str})
    set_tests_properties(test_${str} PROPERTIES PASS_REGULAR_EXPRESSION "${str}: ${expect}")
endfunction()

test_1_2(jacob bocaj)
test_1_2(reverse esrever)
test_1_2(label lebal)
test_1_2(omo omo)
test_1_2(cmake ekamc)
test_1_2(coding gnidoc)
test_1_2(2020 0202)
test_1_2(1331 1331)
test_1_2(flight thgilf)
test_1_2(ballon nollab)