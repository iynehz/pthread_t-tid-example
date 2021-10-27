CC=gcc
CFLAGS=-std=c99
LDFLAGS=-lpthread
OUTDIR=./out

all : out/run_thread out/check

${OUTDIR}/run_thread : run_thread.c
	mkdir -p ${OUTDIR}
	${CC} ${CFLAGS} $< ${LDFLAGS} -o $@

${OUTDIR}/check : check.c
	mkdir -p ${OUTDIR}
	${CC} ${CFLAGS} $< ${LDFLAGS} -o $@

