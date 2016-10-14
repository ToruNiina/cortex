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
foo
cortex) dump
++++++++++[>+++++++[>+>+>+<<<-]>>+>+<<<<-]>>>->-<<.>.>.
                                                       ^
|00|00|46|4F|4F|
             ^^
```

## Licensing Terms
This project is licensed under the terms of the MIT License.
See LICENSE for the project license.

- Copyright (c) 2016 Toru Niina

all rights reserved.
