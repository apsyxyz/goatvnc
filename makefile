SRC = goatvnc.c
OUT = goatvnc

build:
	CC $(SRC) -o $(OUT) -lvncserver -lgd
