ifeq ($(PLATFORM),MSP432)
	SOURCES = *.c

	INCLUDES = ../include/CMSIS/cmsis_gcc.h \
	   	../include/CMSIS/core_cm4.h \
	   	../include/CMSIS/core_cmFunc.h \
	   	../include/CMSIS/core_cmInstr.h \
	   	../include/CMSIS/core_cmSimd.h \
	   	../include/common/memory.h \
	   	../include/common/platform.h \
	   	../include/msp432/msp432p401r.h \
	   	../include/msp432/msp_compatibility.h \
	   	../include/msp432/system_msp432p401r.h

else
	SOURCES = main.c \
		  memory.c

	INCLUDES = ../include/common/memory.h \
		../include/common/platform.h
endif
