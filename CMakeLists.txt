cmake_minimum_required(VERSION 3.10.2)

project(Launch)

#Build the program

add_executable(Epidemic_Simulator.exe main.cpp Board_Utilities/board.cpp Board_Evolution/evolve.cpp Board_Evolution/step.cpp)
set_target_properties(Epidemic_Simulator.exe PROPERTIES COMPILE_FLAGS "-Wall -Wextra")
target_link_libraries(Epidemic_Simulator.exe -fsanitize=address)

#Build the Tests

#1) Board tests
add_executable(Run_Board_Tests.exe Tests/run_tests.cpp Tests/Board_Tests/board_test.cpp Board_Utilities/board.cpp)
add_test(NAME Board_tests COMMAND Run_Board_Tests)

#2) Input tests
add_executable(Run_Input_Tests.exe Tests/run_tests.cpp Tests/Input_Tests/input_test.cpp Board_Utilities/board.cpp)
add_test(NAME Input_Tests COMMAND Run_Input_Tests)

#3) Evolve and Step tests
add_executable(Run_Evolve_Tests.exe Tests/run_tests.cpp Tests/Epidemic_Evolution_Tests/evolution_test.cpp Board_Evolution/step.cpp Board_Evolution/evolve.cpp Board_Utilities/board.cpp)
add_test(NAME Evolve_Tests COMMAND Run_Evolve_Tests)

#4) Time_Function tests
add_executable(Run_Time_Function_Tests.exe Tests/run_tests.cpp Tests/Time_Function_Tests/time_function_test.cpp Board_Utilities/board.cpp)
add_test(NAME Time_Function_Tests COMMAND Run_Time_Function_Tests)

#5) Whole_Program test
add_executable(Run_Whole_Program_Tests.exe Tests/run_tests.cpp Tests/Whole_Program_Tests/whole_program_test.cpp Board_Utilities/board.cpp Board_Evolution/evolve.cpp Board_Evolution/step.cpp)
add_test(NAME Whole_Program_Tests COMMAND Run_Whole_Program_Tests)

#6) Global tests
add_executable(Run_Global_Tests.exe Tests/run_tests.cpp Board_Utilities/board.cpp Board_Evolution/evolve.cpp Board_Evolution/step.cpp Tests/Board_Tests/board_test.cpp Tests/Epidemic_Evolution_Tests/evolution_test.cpp Tests/Input_Tests/input_test.cpp Tests/Time_Function_Tests/time_function_test.cpp Tests/Whole_Program_Tests/whole_program_test.cpp)
add_test(NAME Global_Tests COMMAND Run_Global_Tests)



