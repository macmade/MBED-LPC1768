################################################################################
# The MIT License (MIT)
# 
# Copyright (c) 2015 Jean-David Gadina - www.xs-labs.com
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
################################################################################

################################################################################
# Configuration
################################################################################

# Project specific
DIR_BUILD     := ./build/
DIR_BUILD_BIN := $(DIR_BUILD)bin/
DIR_BUILD_OBJ := $(DIR_BUILD)obj/
DIR_INC       := ./include/
DIR_SRC       := ./source/

# Extensions
EXT_BIN := .bin
EXT_ELF := .elf
EXT_HEX := .hex
EXT_LST := .lst
EXT_MAP := .map
EXT_O   := .o
EXT_S   := .s
EXT_H   := .h
EXT_C   := .c
EXT_CPP := .cpp

# Paths
PATH_INC := ./mbed                                          \
            ./mbed/TARGET_LPC1768                           \
            ./mbed/TARGET_LPC1768/TOOLCHAIN_GCC_ARM         \
            ./mbed/TARGET_LPC1768/TARGET_NXP                \
            ./mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X \
            ./mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X/TARGET_MBED_LPC1768
PATH_LIB := ./mbed/TARGET_LPC1768/TOOLCHAIN_GCC_ARM

# Toolchain paths
TOOLCHAIN     := /usr/local/mbed/
TOOLCHAIN_BIN := $(TOOLCHAIN)bin/

# Toolchain software
AS      := $(TOOLCHAIN_BIN)arm-none-eabi-as
CC      := $(TOOLCHAIN_BIN)arm-none-eabi-gcc
CPP     := $(TOOLCHAIN_BIN)arm-none-eabi-g++
LD      := $(TOOLCHAIN_BIN)arm-none-eabi-gcc
OBJCOPY := $(TOOLCHAIN_BIN)arm-none-eabi-objcopy
OBJDUMP := $(TOOLCHAIN_BIN)arm-none-eabi-objdump
SIZE    := $(TOOLCHAIN_BIN)arm-none-eabi-size

# Flags
FLAGS_INC       := -I$(DIR_INC) $(foreach _I,$(PATH_INC),$(addprefix -I,$(_I)))
FLAGS_LIB       := $(foreach _L,$(PATH_LIB),$(addprefix -L,$(_L)))
FLAGS_CPU       := -mcpu=cortex-m3 -mthumb
FLAGS_WARN      := -Wall -Werror
FLAGS_AS        := $(FLAGS_CPU)
FLAGS_CC        := $(FLAGS_CPU)         \
                   $(FLAGS_WARN)        \
                   -MMD                 \
                   -MP                  \
                   -fno-common          \
                   -fno-exceptions      \
                   -fmessage-length=0   \
                   -ffunction-sections  \
                   -fdata-sections      \
                   -fomit-frame-pointer \
                   $(FLAGS_INC)
FLAGS_CC_C      := -std=c11
FLAGS_CC_CPP    := -std=c++11 \
                   -fno-rtti
FLAGS_CC_MACROS := -DTARGET_LPC1768                     \
                   -DTARGET_M3                          \
                   -DTARGET_CORTEX_M                    \
                   -DTARGET_NXP                         \
                   -DTARGET_LPC176X                     \
                   -DTARGET_MBED_LPC1768                \
                   -DTOOLCHAIN_GCC_ARM                  \
                   -DTOOLCHAIN_GCC                      \
                   -D__CORTEX_M3                        \
                   -DARM_MATH_CM3                       \
                   -DMBED_BUILD_TIMESTAMP=1429283868.72 \
                   -D__MBED__=1 
FLAGS_LD        := $(FLAGS_CPU)                                         \
                   --specs=nano.specs                                   \
                   -u _printf_float                                     \
                   -u _scanf_float                                      \
                   -Wl,--gc-sections                                    \
                   -Wl,--wrap,main                                      \
                   -Wl,-Map=$(DIR_BUILD_BIN)$(PROJECT)$(EXT_MAP),--cref \
                   $(FLAGS_LIB)

# Libraries
LIBS := -lmbed   \
        -lstdc++ \
        -lsupc++ \
        -lm      \
        -lc      \
        -lgcc    \
        -lnosys

# Other resources
LD_SCRIPT := ./mbed/TARGET_LPC1768/TOOLCHAIN_GCC_ARM/LPC1768.ld
SYS_OBJ   := ./mbed/TARGET_LPC1768/TOOLCHAIN_GCC_ARM/cmsis_nvic.o     \
             ./mbed/TARGET_LPC1768/TOOLCHAIN_GCC_ARM/system_LPC17xx.o \
             ./mbed/TARGET_LPC1768/TOOLCHAIN_GCC_ARM/board.o          \
             ./mbed/TARGET_LPC1768/TOOLCHAIN_GCC_ARM/retarget.o       \
             ./mbed/TARGET_LPC1768/TOOLCHAIN_GCC_ARM/startup_LPC17xx.o

# Debug
ifeq ($(DEBUG),1)
	
    FLAGS_CC += -g  \
                -O0 \
                -DDEBUG
    
else
    
    FLAGS_CC += -Os \
                -DNDEBUG
    
endif

################################################################################
# Display
################################################################################

ifndef XCODE_VERSION_MAJOR

# Colors for the terminal output
COLOR_NONE   := "\x1b[0m"
COLOR_GRAY   := "\x1b[30;01m"
COLOR_RED    := "\x1b[31;01m"
COLOR_GREEN  := "\x1b[32;01m"
COLOR_YELLOW := "\x1b[33;01m"
COLOR_BLUE   := "\x1b[34;01m"
COLOR_PURPLE := "\x1b[35;01m"
COLOR_CYAN   := "\x1b[36;01m"

endif

# Current GIT branch
BRANCH := $(shell git rev-parse --abbrev-ref HEAD 2>/dev/null | tr '[:lower:]' '[:upper:]')

################################################################################
# Functions
################################################################################

MBED_FUNC_S_FILES      = $(foreach _F,$(wildcard $(1)*$(EXT_S)),$(_F))
MBED_FUNC_C_FILES      = $(foreach _F,$(wildcard $(1)*$(EXT_C)),$(_F))
MBED_FUNC_CPP_FILES    = $(foreach _F,$(wildcard $(1)*$(EXT_CPP)),$(_F))
MBED_FUNC_SOURCE_FILES = $(call MBED_FUNC_S_FILES,$(1)) $(call MBED_FUNC_C_FILES,$(1)) $(call MBED_FUNC_CPP_FILES,$(1))
MBED_FUNC_O_FILES      = $(foreach _F,$(FILES),$(patsubst %,$(DIR_BUILD_OBJ)%$(EXT_O),$(subst /,.,$(patsubst $(DIR_SRC)%,%,$(_F)))))

PRINT      = echo -e "[ "$(COLOR_PURPLE)$(MAKELEVEL)$(COLOR_NONE) "]> "$(foreach _P,$(BRANCH) $(PROMPT) $(PROJECT),"[ "$(COLOR_GREEN)$(_P)$(COLOR_NONE)" ]>")" *** "$(1)
PRINT_FILE = $(call PRINT,$(1)): $(2)

################################################################################
# Targets
################################################################################

# Default shell
SHELL := /bin/bash

# Clear any existing search path
VPATH =
vpath

# Add search paths for source files
vpath %$(EXT_S)   $(DIR_SRC)
vpath %$(EXT_C)   $(DIR_SRC)
vpath %$(EXT_CPP) $(DIR_SRC)

# Clears any existing suffix
.SUFFIXES:

# Phony targets
.PHONY: all   \
        clean \
        install

# Precious targets
.PRECIOUS: $(DIR_BUILD_OBJ)%$(EXT_S)$(EXT_O)   \
           $(DIR_BUILD_OBJ)%$(EXT_C)$(EXT_O)   \
           $(DIR_BUILD_OBJ)%$(EXT_CPP)$(EXT_O) \
           $(DIR_BUILD_BIN)%$(EXT_ELF)         \
           $(DIR_BUILD_BIN)%$(EXT_BIN)         \
           $(DIR_BUILD_BIN)%$(EXT_HEX)         \
           $(DIR_BUILD_BIN)%$(EXT_LST)

.SECONDEXPANSION:

all: $(DIR_BUILD_BIN)$(PROJECT)$(EXT_BIN) $(DIR_BUILD_BIN)$(PROJECT)$(EXT_HEX) $(DIR_BUILD_BIN)$(PROJECT)$(EXT_LST)
	
	@:
	
clean:
	
	@$(call PRINT,Cleaning all build files)
	@rm -rf $(DIR_BUILD_BIN)*
	@rm -rf $(DIR_BUILD_OBJ)*

install: all
	
	@if [ -d /Volumes/MBED/ ]; then $(call PRINT,Installing project on controller) && cp -f $(DIR_BUILD_BIN)$(PROJECT)$(EXT_BIN) /Volumes/MBED/; else $(call PRINT,Controller is not connected - Skipping install); fi
	
$(DIR_BUILD_BIN)%$(EXT_BIN): $(DIR_BUILD_BIN)$(PROJECT)$(EXT_ELF)
	
	@$(call PRINT_FILE,$(COLOR_CYAN)Generating binary file$(COLOR_NONE),$(COLOR_GRAY)$(notdir $@)$(COLOR_NONE))
	@$(OBJCOPY) -O binary $< $@

$(DIR_BUILD_BIN)%$(EXT_HEX): $(DIR_BUILD_BIN)$(PROJECT)$(EXT_ELF)
	
	@$(call PRINT_FILE,$(COLOR_CYAN)Generating Intel hex file$(COLOR_NONE),$(COLOR_GRAY)$(notdir $@)$(COLOR_NONE))
	@$(OBJCOPY) -O ihex $< $@

$(DIR_BUILD_BIN)%$(EXT_LST): $(DIR_BUILD_BIN)$(PROJECT)$(EXT_ELF)
	
	@$(call PRINT_FILE,$(COLOR_CYAN)Generating object dump$(COLOR_NONE),$(COLOR_GRAY)$(notdir $@)$(COLOR_NONE))
	@$(OBJDUMP) -Sdh $< > $@

$(DIR_BUILD_BIN)%$(EXT_ELF): _FILES = $(call MBED_FUNC_O_FILES)
$(DIR_BUILD_BIN)%$(EXT_ELF): $$(_FILES) $(SYS_OBJ)
	
	@$(call PRINT_FILE,$(COLOR_CYAN)Linking ELF executable$(COLOR_NONE),$(COLOR_GRAY)$(notdir $@)$(COLOR_NONE))
	@$(LD) $(FLAGS_LD) -T$(LD_SCRIPT) -o $@ $^ $(LIBS)
	
$(DIR_BUILD_OBJ)%$(EXT_S)$(EXT_O): _FILE = $(patsubst %,$(DIR_SRC)%$(EXT_S),$(subst .,/,$*))
$(DIR_BUILD_OBJ)%$(EXT_S)$(EXT_O): $$(_FILE)
	
	@$(call PRINT_FILE,Compiling ASM file,$(COLOR_YELLOW)$(_FILE)$(COLOR_NONE) "->" $(COLOR_GRAY)$(notdir $@)$(COLOR_NONE))
	@$(AS) $(FLAGS_AS) -o $@ $<
	
$(DIR_BUILD_OBJ)%$(EXT_C)$(EXT_O): _FILE = $(patsubst %,$(DIR_SRC)%$(EXT_C),$(subst .,/,$*))
$(DIR_BUILD_OBJ)%$(EXT_C)$(EXT_O): $$(_FILE)
	
	@$(call PRINT_FILE,Compiling C file,$(COLOR_YELLOW)$(_FILE)$(COLOR_NONE) "->" $(COLOR_GRAY)$(notdir $@)$(COLOR_NONE))
	@$(CC) $(FLAGS_CC_C) $(FLAGS_CC) $(FLAGS_CC_MACROS) -o $@ -c $<
	
$(DIR_BUILD_OBJ)%$(EXT_CPP)$(EXT_O): _FILE = $(patsubst %,$(DIR_SRC)%$(EXT_CPP),$(subst .,/,$*))
$(DIR_BUILD_OBJ)%$(EXT_CPP)$(EXT_O): $$(_FILE)
	
	@$(call PRINT_FILE,Compiling C++ file,$(COLOR_YELLOW)$(_FILE)$(COLOR_NONE) "->" $(COLOR_GRAY)$(notdir $@)$(COLOR_NONE))
	@$(CPP) $(FLAGS_CC_CPP) $(FLAGS_CC) $(FLAGS_CC_MACROS) -o $@ -c $<
