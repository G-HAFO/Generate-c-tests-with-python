## Getting Started

### Prerequisites
* Python 3.10
* git version 2.37.3
* Python libraries:
                
    * docopt (0.6.2) 
    ```npm
    pip install docopt
    ```  
### Quick Start

Run the followin commands in CMD:

* Download  the project
```npm
 git clone https://gitlab.com/gregorhafnar2/iskra.git
```
* Open the project
```npm 
 cd iskra
```
* Compile the project with CMake
```npm
 cmake -G "MinGW Makefiles" -B build -S .
```
* Open scripts directory
```npm
 cd scripts
```
* Run the python program
```npm
 py Python_C_test_generator.py -B PC
```
* Exit the scripts directory and open build directory
```npm
 cd ../build
```
* Compile C code with MinGW
```npm
 mingw32-make
```
* Run our program ( should print our test results)
```npm
 ctest -V
```



### Usage

You can change certain parameters in /scripts/Python_C_test_generator.py to better suit your needs. 

The following parameters can be changed (change is done in create_random_functions function):
  * n (default value = 20) - how many differents test will be generated
  * size (default value = 384) - bit size of our calculated number
  * value_min (default = 384) - miminum value of our randomly generated function
  * value_max (default value =-1 + 2 ** 384 ) - maximal value of our randomly generated function
  *  build_type -don't change the value of this parameter

When running Python_C_test_generator.py, you will be prompted with message how to correctly use the program.
```
py Python_C_test_generator.py
Usage:
  Python_C_test_generator.py (-B|--build) <type>
  Python_C_test_generator.py (-h | --help)

```
You have two different build options -> "PC" or "stevec". Build the desired build_typeas such (you can use either "--build" or "-B"):
```npm
py Python_C_test_generator.py -B stevec
```
or
```npm
py Python_C_test_generator.py -B PC
```

If you want help, run the following command:
```npm
py Python_C_test_generator.py -h
```
