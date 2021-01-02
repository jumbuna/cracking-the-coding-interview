cmake_minimum_required(VERSION 3.0)

project(1_1 VERSION 1.0)

add_executable(1_1 solution.c)

enable_testing()

add_test(NAME Run COMMAND 1_1 hello)

add_test(NAME Usage COMMAND 1_1)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: *")

function(test_1_1 str expect)
    add_test(NAME test_${str} COMMAND 1_1 ${str})
    set_tests_properties(test_${str} PROPERTIES PASS_REGULAR_EXPRESSION "${str}: ${expect}")
endfunction()

test_1_1("hello" "False")
test_1_1("jacob" "True")
test_1_1("proposal" "False")
test_1_1("candy" "True")
test_1_1("guacamole" "False")
test_1_1("gravel" "True")
test_1_1("post" "True")
test_1_1("colon" "False")
test_1_1("cmake" "True")
test_1_1("complete" "False")
test_1_1("protagonist" "False")
