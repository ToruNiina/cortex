Cortex
====

a brainfuck interpreter to run and understand brainfuck written in c++11.

## Usage

### Run Brainfuck code

You can specify brainfuck source code as command line argument.

```sh
$ cortex source.bf
```

### As an Interpreter

```sh
$ cortex
cortex) ++++++++++[>+++++++[>+>+>+<<<-]>>+>+<<<<-]>>>->-<<.>.>.
cortex) run
FOO
cortex) dump
++++++++++[>+++++++[>+>+>+<<<-]>>+>+<<<<-]>>>->-<<.>.>.
                                                       ^
|00|00|46|4F|4F|
             ^^
cortex) exit
```

supported commands 

| command          |                                                |
|:-----------------|:-----------------------------------------------|
| (brainfuck code) | append code                                    |
| run              | run the code                                   |
| run-stepwise     | run the code and dump step and step            |
| dump             | dump data and instruction and its ptrs         |
| clear            | clear data and instruction                     |
| exit             | exit cortex. you can use quit and bye instread |

## Build

use CMake.

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Licensing Terms
This project is licensed under the terms of the MIT License.
See LICENSE for the project license.

- Copyright (c) 2016 Toru Niina

all rights reserved.
