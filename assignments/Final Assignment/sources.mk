ifeq ($(PLATFORM),MSP432)
	SOURCES = src/*.c

	INCLUDES = ../include/CMSIS \
	   	../include/common \
	   	../include/msp432

else
	SOURCES = src/main.c \
		  src/memory.c \
		  src/data.c \
		  src/stats.c \
		  src/course1.c

	INCLUDES = ../include/common
endif
