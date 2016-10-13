Cortex
====

a brainfuck interpreter to run and understand brainfuck written in c++11.

## Usage

### Run Brainfuck code

You can specify brainfuck source code as command line argument.

```sh
$ cortex source.bf
```

When you want to input into brainfuck code, you can use pipe
instead of inputting manually.

```sh 
$ cat input.dat | cortex source.bf
```

### As an Interpreter

```sh
$ cortex
cortex/ +++++++++[>+++++++++++[>+>+>+<<<-]>>+>+<<<<-]>+++[>+>+>+<<<-]>.>.>.
cortex/ run
foo
cortex/ show # you can show the procedure after run the code.
================================================================================
+++++++++[>+++++++++++[>+>+>+<<<-]>>+>+<<<<-]>+++[>+>+>+<<<-]>.>.>.
^
|00|00|00|00|00|
 ^
================================================================================
+++++++++[>+++++++++++[>+>+>+<<<-]>>+>+<<<<-]>+++[>+>+>+<<<-]>.>.>.
         ^
|09|00|00|00|00|
 ^
================================================================================
+++++++++[>+++++++++++[>+>+>+<<<-]>>+>+<<<<-]>+++[>+>+>+<<<-]>.>.>.
          ^
|09|00|00|00|00|
    ^
================================================================================
+++++++++[>+++++++++++[>+>+>+<<<-]>>+>+<<<<-]>+++[>+>+>+<<<-]>.>.>.
                      ^
|09|0B|00|00|00|
    ^
================================================================================
+++++++++[>+++++++++++[>+>+>+<<<-]>>+>+<<<<-]>+++[>+>+>+<<<-]>.>.>.
                       ^
|09|0B|00|00|00|
       ^
================================================================================
+++++++++[>+++++++++++[>+>+>+<<<-]>>+>+<<<<-]>+++[>+>+>+<<<-]>.>.>.
                        ^
|09|0B|01|00|00|
       ^
```

## Licensing Terms


