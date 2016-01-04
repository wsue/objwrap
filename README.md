# objwrap
it is an objdump program's wrap(but build from use)
it provide callback functions to parse elf file

if you need to parse elf file(disassemble/get symbol table and so on)
it maybe useful.

## compile:
    1.	download binutils's source code to current directory

    2.	run make
	make
	after success compile, the ouput obj will copy to ../out/binutils directory

    3.  use:
	use dumpwrap_load interface to parse elf file.

