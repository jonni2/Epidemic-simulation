Some information before starting the program:

To compile it is necessary to have CMake installed. Type on terminal:
1) cmake .
2) make

To execute the program type on terminal:
./Epidemic_Simulator.exe

To execute the tests type on terminal one of the following commands (Global Tests to run all of them at the same time. It may take a while to execute!):
1) ./Run_Board_Tests.exe
2) ./Run_Evolve_Tests.exe
3) ./Run_Input_Tests.exe
4) ./Run_Time_Function_Tests.exe
5) ./Run_Whole_Program_Tests.exe
6) ./Run_Global_Tests.exe

The program will guide the user through the execution.
The program will start by asking the user to modify the Input_Config files. The user can leave the SETTINGS.txt unmodified and can instead modify the INPUT_BOARD.txt file to set the initial configuration. The user can also leave the INPUT_BOARD.txt file empty.

When the program asks the user to modify the input files, if these files are missing, the program will re-create the default input files. If the SETTINGS.txt file is not in the correct format, the program will stop after printing an error message. If the user is not able to remember the correct input format he can simply delete the SETTINGS.txt and INPUT_BOARD.txt files and the program will re-create the default input files.

If the INPUT_BOARD.txt has incorrect dimensions (compared to the SETTINGS.txt dimensions), the program will re-create an empty INPUT_BOARD.txt. If, instead, the INPUT_BOARD.txt file uses incorrect symbols, the program will terminate and print an error message.


Description of the infection PARAMETERS:

1) quarantine_threshold: to INCREASE the quarantine rate DECREASE this parameter (to a minimum of 0.0). To execute without quarantine set this paramenter to 1.0.

2) heal_threshold: to INCREASE the probability of healing DECREASE this parameter (to a minimum of 0.0).

3) infect_threshold: to INCREASE the probability of infection DECREASE this parameter (to a minimum of 0.0).

4) death_threshold: to INCREASE the probability of death DECREASE this parameter (to a minimum of 0.0).
