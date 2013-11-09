# ------------------------------------------------------------------------------
# 
# Copyright (c) 2013, Jean-David Gadina - www.xs-labs.com
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
#  -   Redistributions of source code must retain the above copyright notice,
#      this list of conditions and the following disclaimer.
#  -   Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#  -   Neither the name of 'Jean-David Gadina' nor the names of its
#      contributors may be used to endorse or promote products derived from
#      this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
# 
# ------------------------------------------------------------------------------

# $Id$

#-------------------------------------------------------------------------------
# General
#-------------------------------------------------------------------------------

# Targets / Architectures

TARGET_ABI_MACHO                        := macho
TARGET_32_MACHO                         := i386
TARGET_64_MACHO                         := x86_64
TARGET_32_MARCH_MACHO                   := i386
TARGET_64_MARCH_MACHO                   := x86-64
TARGET_32_TRIPLE_MACHO                  := i386-apple-darwin
TARGET_64_TRIPLE_MACHO                  := x86_64-apple-darwin

TARGET_ABI_ELF                          := elf
TARGET_32_ELF                           := i386
TARGET_64_ELF                           := x86_64
TARGET_32_MARCH_ELF                     := i386
TARGET_64_MARCH_ELF                     := x86-64
TARGET_32_TRIPLE_ELF                    := i386-elf-freebsd
TARGET_64_TRIPLE_ELF                    := x86_64-elf-freebsd

TARGET_ABI_EFI                          := efi
TARGET_32_EFI                           := i386
TARGET_64_EFI                           := x86_64
TARGET_32_MARCH_EFI                     := i386
TARGET_64_MARCH_EFI                     := x86-64
TARGET_32_TRIPLE_EFI                    := i386-efi-pe
TARGET_64_TRIPLE_EFI                    := x86_64-efi-pe

TARGET_ABI                              := $(TARGET_ABI_ELF)
TARGET_32                               := $(TARGET_32_ELF)
TARGET_64                               := $(TARGET_64_ELF)
TARGET_32_MARCH                         := $(TARGET_32_MARCH_ELF)
TARGET_64_MARCH                         := $(TARGET_64_MARCH_ELF)
TARGET_32_TRIPLE                        := $(TARGET_32_TRIPLE_ELF)
TARGET_64_TRIPLE                        := $(TARGET_64_TRIPLE_ELF)

#-------------------------------------------------------------------------------
# Paths
#-------------------------------------------------------------------------------

# Toolchain

PATH_TOOLCHAIN                          := /usr/local/xeos-build/

# Toolchain software

PATH_TOOLCHAIN_YASM                     := $(PATH_TOOLCHAIN)yasm/
PATH_TOOLCHAIN_GMP                      := $(PATH_TOOLCHAIN)gmp/
PATH_TOOLCHAIN_MPFR                     := $(PATH_TOOLCHAIN)mpfr/
PATH_TOOLCHAIN_BINUTILS                 := $(PATH_TOOLCHAIN)binutils/
PATH_TOOLCHAIN_CMAKE                    := $(PATH_TOOLCHAIN)cmake/
PATH_TOOLCHAIN_LLVM                     := $(PATH_TOOLCHAIN)llvm/

# Project root directories

PATH_PROJECT                            := $(realpath $(dir $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))/
PATH_BUILD                              := $(PATH_PROJECT)build/
PATH_RELEASE                            := $(PATH_PROJECT)release/
PATH_SRC                                := $(PATH_PROJECT)source/
PATH_TOOLS                              := $(PATH_PROJECT)tools/
PATH_SW                                 := $(PATH_PROJECT)software-deps/

# Build directories

PATH_BUILD_TOOLS                        := $(PATH_BUILD)tools/
PATH_BUILD_TOOLS_BIN                    := $(PATH_BUILD_TOOLS)bin/
PATH_BUILD_TOOLS_MKINITRD               := $(PATH_BUILD_TOOLS)mkinitrd/
PATH_BUILD_TOOLS_LOCALEDEF              := $(PATH_BUILD_TOOLS)localedef/
PATH_BUILD_BOOT                         := $(PATH_BUILD)boot/
PATH_BUILD_BOOT_BIOS                    := $(PATH_BUILD_BOOT)bios/
PATH_BUILD_BOOT_UEFI                    := $(PATH_BUILD_BOOT)uefi/
PATH_BUILD_INITRD                       := $(PATH_BUILD)initrd/
PATH_BUILD_TMP                          := $(PATH_BUILD)tmp/
PATH_BUILD_MOUNT                        := $(PATH_BUILD)mount/
PATH_BUILD_32                           := $(PATH_BUILD)$(TARGET_32)/
PATH_BUILD_64                           := $(PATH_BUILD)$(TARGET_64)/
PATH_BUILD_32_CORE                      := $(PATH_BUILD_32)core/
PATH_BUILD_64_CORE                      := $(PATH_BUILD_64)core/
PATH_BUILD_32_CORE_BIN                  := $(PATH_BUILD_32_CORE)bin/
PATH_BUILD_64_CORE_BIN                  := $(PATH_BUILD_64_CORE)bin/
PATH_BUILD_32_CORE_OBJ                  := $(PATH_BUILD_32_CORE)obj/
PATH_BUILD_64_CORE_OBJ                  := $(PATH_BUILD_64_CORE)obj/
PATH_BUILD_32_CORE_OBJ_KERNEL           := $(PATH_BUILD_32_CORE_OBJ)xeos/
PATH_BUILD_64_CORE_OBJ_KERNEL           := $(PATH_BUILD_64_CORE_OBJ)xeos/
PATH_BUILD_32_CORE_OBJ_ACPI             := $(PATH_BUILD_32_CORE_OBJ)acpi/
PATH_BUILD_64_CORE_OBJ_ACPI             := $(PATH_BUILD_64_CORE_OBJ)acpi/
PATH_BUILD_32_CORE_OBJ_ACPI_ACPICA      := $(PATH_BUILD_32_CORE_OBJ)acpi-acpica/
PATH_BUILD_64_CORE_OBJ_ACPI_ACPICA      := $(PATH_BUILD_64_CORE_OBJ)acpi-acpica/
PATH_BUILD_32_CORE_OBJ_ACPI_OSL         := $(PATH_BUILD_32_CORE_OBJ)acpi-osl/
PATH_BUILD_64_CORE_OBJ_ACPI_OSL         := $(PATH_BUILD_64_CORE_OBJ)acpi-osl/
PATH_BUILD_32_LIB                       := $(PATH_BUILD_32)lib/
PATH_BUILD_64_LIB                       := $(PATH_BUILD_64)lib/
PATH_BUILD_32_LIB_BIN                   := $(PATH_BUILD_32_LIB)bin/
PATH_BUILD_64_LIB_BIN                   := $(PATH_BUILD_64_LIB)bin/
PATH_BUILD_32_LIB_OBJ                   := $(PATH_BUILD_32_LIB)obj/
PATH_BUILD_64_LIB_OBJ                   := $(PATH_BUILD_64_LIB)obj/
PATH_BUILD_32_LIB_OBJ_C99               := $(PATH_BUILD_32_LIB_OBJ)c99/
PATH_BUILD_64_LIB_OBJ_C99               := $(PATH_BUILD_64_LIB_OBJ)c99/
PATH_BUILD_32_LIB_OBJ_C11               := $(PATH_BUILD_32_LIB_OBJ)c11/
PATH_BUILD_64_LIB_OBJ_C11               := $(PATH_BUILD_64_LIB_OBJ)c11/
PATH_BUILD_32_LIB_OBJ_SYSTEM            := $(PATH_BUILD_32_LIB_OBJ)system/
PATH_BUILD_64_LIB_OBJ_SYSTEM            := $(PATH_BUILD_64_LIB_OBJ)system/
PATH_BUILD_32_LIB_OBJ_POSIX             := $(PATH_BUILD_32_LIB_OBJ)posix/
PATH_BUILD_64_LIB_OBJ_POSIX             := $(PATH_BUILD_64_LIB_OBJ)posix/
PATH_BUILD_32_LIB_OBJ_PTHREAD           := $(PATH_BUILD_32_LIB_OBJ)pthread/
PATH_BUILD_64_LIB_OBJ_PTHREAD           := $(PATH_BUILD_64_LIB_OBJ)pthread/
PATH_BUILD_32_LIB_OBJ_ICONV             := $(PATH_BUILD_32_LIB_OBJ)iconv/
PATH_BUILD_64_LIB_OBJ_ICONV             := $(PATH_BUILD_64_LIB_OBJ)iconv/
PATH_BUILD_32_LIB_OBJ_BLOCKS            := $(PATH_BUILD_32_LIB_OBJ)blocks/
PATH_BUILD_64_LIB_OBJ_BLOCKS            := $(PATH_BUILD_64_LIB_OBJ)blocks/
PATH_BUILD_32_LIB_OBJ_DISPATCH          := $(PATH_BUILD_32_LIB_OBJ)dispatch/
PATH_BUILD_64_LIB_OBJ_DISPATCH          := $(PATH_BUILD_64_LIB_OBJ)dispatch/
PATH_BUILD_32_LIB_OBJ_OBJC              := $(PATH_BUILD_32_LIB_OBJ)objc/
PATH_BUILD_64_LIB_OBJ_OBJC              := $(PATH_BUILD_64_LIB_OBJ)objc/
PATH_BUILD_32_LIB_OBJ_ELF               := $(PATH_BUILD_32_LIB_OBJ)elf/
PATH_BUILD_64_LIB_OBJ_ELF               := $(PATH_BUILD_64_LIB_OBJ)elf/
PATH_BUILD_32_MODULES                   := $(PATH_BUILD_32)modules/
PATH_BUILD_64_MODULES                   := $(PATH_BUILD_64)modules/
PATH_BUILD_32_MODULES_BIN               := $(PATH_BUILD_32_MODULES)bin/
PATH_BUILD_64_MODULES_BIN               := $(PATH_BUILD_64_MODULES)bin/
PATH_BUILD_32_MODULES_OBJ               := $(PATH_BUILD_32_MODULES)obj/
PATH_BUILD_64_MODULES_OBJ               := $(PATH_BUILD_64_MODULES)obj/
PATH_BUILD_32_MODULES_OBJ_TEST          := $(PATH_BUILD_32_MODULES_OBJ)test/
PATH_BUILD_64_MODULES_OBJ_TEST           = $(PATH_BUILD_64_MODULES_OBJ)test/

# Source directories

PATH_SRC_INC                            := $(PATH_SRC)include/
PATH_SRC_BOOT                           := $(PATH_SRC)boot/
PATH_SRC_BOOT_BIOS                      := $(PATH_SRC_BOOT)bios/
PATH_SRC_BOOT_UEFI                      := $(PATH_SRC_BOOT)uefi/
PATH_SRC_CORE                           := $(PATH_SRC)core/
PATH_SRC_CORE_KERNEL                    := $(PATH_SRC_CORE)xeos/
PATH_SRC_CORE_ACPI                      := $(PATH_SRC_CORE)acpi/
PATH_SRC_LIB                            := $(PATH_SRC)lib/
PATH_SRC_LIB_C99                        := $(PATH_SRC_LIB)c99/
PATH_SRC_LIB_C11                        := $(PATH_SRC_LIB)c11/
PATH_SRC_LIB_SYSTEM                     := $(PATH_SRC_LIB)system/
PATH_SRC_LIB_POSIX                      := $(PATH_SRC_LIB)posix/
PATH_SRC_LIB_PTHREAD                    := $(PATH_SRC_LIB)pthread/
PATH_SRC_LIB_ICONV                      := $(PATH_SRC_LIB)iconv/
PATH_SRC_LIB_BLOCKS                     := $(PATH_SRC_LIB)blocks/
PATH_SRC_LIB_DISPATCH                   := $(PATH_SRC_LIB)dispatch/
PATH_SRC_LIB_OBJC                       := $(PATH_SRC_LIB)objc/
PATH_SRC_LIB_ELF                        := $(PATH_SRC_LIB)elf/
PATH_SRC_MODULES                        := $(PATH_SRC)modules/
PATH_SRC_MODULES_TEST                   := $(PATH_SRC_MODULES)test/

# Tools directories

PATH_TOOLS_MKINITRD                     := $(PATH_TOOLS)mkinitrd/
PATH_TOOLS_LOCALEDEF                    := $(PATH_TOOLS)localedef/

# Release directories

PATH_RELEASE_CDROM                      := $(PATH_RELEASE)cdrom/
PATH_RELEASE_FLOPPY                     := $(PATH_RELEASE)floppy/

#-------------------------------------------------------------------------------
# File extensions
#-------------------------------------------------------------------------------

EXT_ASM                                 := .s
EXT_ASM_32                              := 32.s
EXT_ASM_64                              := 64.s
EXT_C                                   := .c
EXT_H                                   := .h
EXT_OBJ                                 := .o
EXT_OBJ_PIC                             := .o-pic
EXT_BIN_RAW                             := .BIN
EXT_BIN                                 := .$(TARGET_ABI)
EXT_KMOD                                := .kmod

#-------------------------------------------------------------------------------
# Software
#-------------------------------------------------------------------------------

# Assembler

AS                                      := $(PATH_TOOLCHAIN_YASM)bin/yasm
AS_32                                   := $(AS)
AS_64                                   := $(AS)

# Linker

LD_MACHO_32                             := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_MACHO)/bin/ld
LD_MACHO_64                             := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_64_TRIPLE_MACHO)/bin/ld
LD_ELF_32                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_ELF)/bin/ld
LD_ELF_64                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_64_TRIPLE_ELF)/bin/ld
LD_EFI_32                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_EFI)/bin/ld
LD_EFI_64                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_64_TRIPLE_EFI)/bin/ld
LD_32                                   := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE)/bin/ld
LD_64                                   := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_64_TRIPLE)/bin/ld

# C compiler

CC                                      := $(PATH_TOOLCHAIN_LLVM)bin/clang
CC_32                                   := $(CC)
CC_64                                   := $(CC)

# Archiver

AR_MACHO_32                             := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_MACHO)/bin/ar
AR_MACHO_64                             := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_MACHO)/bin/ar
AR_ELF_32                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_ELF)/bin/ar
AR_ELF_64                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_ELF)/bin/ar
AR_EFI_32                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_EFI)/bin/ar
AR_EFI_64                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_EFI)/bin/ar
AR_32                                   := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE)/bin/ar
AR_64                                   := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE)/bin/ar

RANLIB_MACHO_32                         := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_MACHO)/bin/ranlib
RANLIB_MACHO_64                         := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_MACHO)/bin/ranlib
RANLIB_ELF_32                           := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_ELF)/bin/ranlib
RANLIB_ELF_64                           := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_ELF)/bin/ranlib
RANLIB_EFI_32                           := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_EFI)/bin/ranlib
RANLIB_EFI_64                           := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE_EFI)/bin/ranlib
RANLIB_32                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE)/bin/ranlib
RANLIB_64                               := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32_TRIPLE)/bin/ranlib

# Static analyzer

SCANBUILD                               := $(PATH_TOOLCHAIN_LLVM)tools/scan-build/scan-build
SCANVIEW                                := $(PATH_TOOLCHAIN_LLVM)tools/scan-view/scan-view

# Utilities

MAKE                                    := make
CMAKE                                   := $(PATH_TOOLCHAIN_CMAKE)bin/cmake
CD                                      := cd
MV                                      := mv
CP                                      := cp
RM                                      := rm
TAR                                     := tar
SUDO                                    := sudo
SVN                                     := svn
DD                                      := dd
EXEC                                    := exec
PRINT                                   := echo
MKDIR                                   := mkdir
PATCH                                   := patch
TOUCH                                   := touch
SOURCE                                  := source
PYTHON                                  := python
TOOLS_CC                                := cc

#-------------------------------------------------------------------------------
# Software arguments
#-------------------------------------------------------------------------------

# C compiler warning flags

ARGS_CC_WARN                            := -Weverything -Werror
ARGS_CC_STD                             := -std=c99
ARGS_CC_CONST                           := -D __XEOS__ -D _POSIX_C_SOURCE=200809L -U __FreeBSD__ -U __FreeBSD_kernel__
ARGS_CC_INC                             := -I $(PATH_SRC_INC)
ARGS_CC_MISC                            := -Os -nostdlib -nostdinc -fno-builtin -fblocks
ARGS_CC_PIC                             := -fPIC

ARGS_CC_TARGET_MACHO_32                 := -march=$(TARGET_32_MARCH_MACHO) -target $(TARGET_32_TRIPLE_MACHO)
ARGS_CC_TARGET_MACHO_54                 := -march=$(TARGET_64_MARCH_MACHO) -target $(TARGET_64_TRIPLE_MACHO)
ARGS_CC_TARGET_ELF_32                   := -march=$(TARGET_32_MARCH_ELF) -target $(TARGET_32_TRIPLE_ELF)
ARGS_CC_TARGET_ELF_64                   := -march=$(TARGET_64_MARCH_ELF) -target $(TARGET_64_TRIPLE_ELF)
ARGS_CC_TARGET_EFI_32                   := -march=$(TARGET_32_MARCH_EFI) -target $(TARGET_32_TRIPLE_EFI)
ARGS_CC_TARGET_EFI_64                   := -march=$(TARGET_64_MARCH_EFI) -target $(TARGET_64_TRIPLE_EFI)
ARGS_CC_TARGET_32                       := -march=$(TARGET_32_MARCH) -target $(TARGET_32_TRIPLE)
ARGS_CC_TARGET_64                       := -march=$(TARGET_64_MARCH) -target $(TARGET_64_TRIPLE)

ARGS_CC_MACHO_32                        := $(ARGS_CC_TARGET_MACHO_32) $(ARGS_CC_MISC) $(ARGS_CC_INC) $(ARGS_CC_STD) $(ARGS_CC_WARN) $(ARGS_CC_CONST)
ARGS_CC_MACHO_64                        := $(ARGS_CC_TARGET_MACHO_64) $(ARGS_CC_MISC) $(ARGS_CC_INC) $(ARGS_CC_STD) $(ARGS_CC_WARN) $(ARGS_CC_CONST)
ARGS_CC_ELF_32                          := $(ARGS_CC_TARGET_ELF_32) $(ARGS_CC_MISC) $(ARGS_CC_INC) $(ARGS_CC_STD) $(ARGS_CC_WARN) $(ARGS_CC_CONST)
ARGS_CC_ELF_64                          := $(ARGS_CC_TARGET_ELF_64) $(ARGS_CC_MISC) $(ARGS_CC_INC) $(ARGS_CC_STD) $(ARGS_CC_WARN) $(ARGS_CC_CONST)
ARGS_CC_EFI_32                          := $(ARGS_CC_TARGET_EFI_32) $(ARGS_CC_MISC) $(ARGS_CC_INC) $(ARGS_CC_STD) $(ARGS_CC_WARN) $(ARGS_CC_CONST)
ARGS_CC_EFI_64                          := $(ARGS_CC_TARGET_EFI_64) $(ARGS_CC_MISC) $(ARGS_CC_INC) $(ARGS_CC_STD) $(ARGS_CC_WARN) $(ARGS_CC_CONST)
ARGS_CC_32                              := $(ARGS_CC_TARGET_32) $(ARGS_CC_MISC) $(ARGS_CC_INC) $(ARGS_CC_STD) $(ARGS_CC_WARN) $(ARGS_CC_CONST)
ARGS_CC_64                              := $(ARGS_CC_TARGET_64) $(ARGS_CC_MISC) $(ARGS_CC_INC) $(ARGS_CC_STD) $(ARGS_CC_WARN) $(ARGS_CC_CONST)

# Linker flags

ARGS_LD_32                              := -z max-page-size=0x1000 -s
ARGS_LD_64                              := -z max-page-size=0x1000 -s
ARGS_LD_SHARED_32                       := -z max-page-size=0x1000 -s --shared
ARGS_LD_SHARED_64                       := -z max-page-size=0x1000 -s --shared

# Archiver flags

ARGS_AR_32                              := rcs
ARGS_AR_64                              := rcs

# Assembler flags

ARGS_AS_32                              := -f $(TARGET_ABI)
ARGS_AS_64                              := -f $(TARGET_ABI)64

# Static analyzer

ARGS_SCANBUILD                          := --use-analyzer $(CC)
ARGS_SCANVIEW                           := 

# Utilities

ARGS_MAKE_CLEAN                         := clean
ARGS_MAKE_BUILD                         := all
ARGS_MAKE_INSTALL                       := install
ARGS_CP                                 := 
ARGS_RM                                 := -rf
ARGS_DD                                 := conv=notrunc
ARGS_HDID                               := -nobrowse -nomount
ARGS_TAR_EXPAND                         := -xf
ARGS_SVN_CO                             := checkout

#-------------------------------------------------------------------------------
# Search paths
#-------------------------------------------------------------------------------

# Clear any existing search path
VPATH =
vpath

#-------------------------------------------------------------------------------
# File suffixes
#-------------------------------------------------------------------------------

# Clears any existing suffix
.SUFFIXES:

#-------------------------------------------------------------------------------
# Display
#-------------------------------------------------------------------------------

COLOR_NONE                              := "\x1b[0m"
COLOR_GRAY                              := "\x1b[30;01m"
COLOR_RED                               := "\x1b[31;01m"
COLOR_GREEN                             := "\x1b[32;01m"
COLOR_YELLOW                            := "\x1b[33;01m"
COLOR_BLUE                              := "\x1b[34;01m"
COLOR_PURPLE                            := "\x1b[35;01m"
COLOR_CYAN                              := "\x1b[36;01m"

#-------------------------------------------------------------------------------
# Functions
#-------------------------------------------------------------------------------

XEOS_FUNC_S_SRC                         = $(foreach dir,$(1),$(wildcard $(1)*$(EXT_ASM_32)))
XEOS_FUNC_S_SRC_REL                     = $(notdir $(call XEOS_FUNC_S_SRC,$(1)))
XEOS_FUNC_S_OBJ_REL                     = $(subst $(EXT_ASM_32),$(EXT_ASM_32)$(EXT_OBJ),$(call XEOS_FUNC_S_SRC_REL,$(1)))
XEOS_FUNC_S_OBJ                         = $(addprefix $(1),$(call XEOS_FUNC_S_OBJ_REL,$(2)))

XEOS_FUNC_C_SRC                         = $(foreach dir,$(1),$(wildcard $(1)*$(EXT_C)))
XEOS_FUNC_C_SRC_REL                     = $(notdir $(call XEOS_FUNC_C_SRC,$(1)))
XEOS_FUNC_C_OBJ_REL                     = $(subst $(EXT_C),$(EXT_C)$(EXT_OBJ),$(call XEOS_FUNC_C_SRC_REL,$(1)))
XEOS_FUNC_C_OBJ                         = $(addprefix $(1),$(call XEOS_FUNC_C_OBJ_REL,$(2)))

#-------------------------------------------------------------------------------
# Targets with second expansion
#-------------------------------------------------------------------------------

# Declaration for precious targets, to avoid cleaning of intermediate files
.PRECIOUS:  $(PATH_BUILD_64)%$(EXT_ASM_64)$(EXT_OBJ_PIC)    \
            $(PATH_BUILD_64)%$(EXT_ASM_64)$(EXT_OBJ)        \
            $(PATH_BUILD_32)%$(EXT_ASM_32)$(EXT_OBJ_PIC)    \
            $(PATH_BUILD_64)%$(EXT_C)$(EXT_OBJ_PIC)         \
            $(PATH_BUILD_64)%$(EXT_C)$(EXT_OBJ)             \
            $(PATH_BUILD_32)%$(EXT_C)$(EXT_OBJ_PIC)

.SECONDEXPANSION:

# Compiles an assembly file (64 bits - PIC)
$(PATH_BUILD_64)%$(EXT_ASM_64)$(EXT_OBJ_PIC): $$(notdir $$(subst $(EXT_OBJ_PIC),,$$@))
	
	@$(PRINT) $(PROMPT)"Compiling assembly file [ 64 bits - PIC ]: "$(COLOR_YELLOW)"$(notdir $< )"$(COLOR_NONE)" -> "$(COLOR_GRAY)"$(notdir $@)"$(COLOR_NONE)
	@$(AS_64) $(ARGS_AS_64) -o $@ $(abspath $<)

# Compiles an assembly file (64 bits)
$(PATH_BUILD_64)%$(EXT_ASM_64)$(EXT_OBJ): $$(notdir $$(subst $(EXT_OBJ),,$$@)) $$(subst $(EXT_OBJ),$(EXT_OBJ_PIC),$$@)
	
	@$(PRINT) $(PROMPT)"Compiling assembly file [ 64 bits       ]: "$(COLOR_YELLOW)"$(notdir $< )"$(COLOR_NONE)" -> "$(COLOR_GRAY)"$(notdir $@)"$(COLOR_NONE)
	@$(AS_64) $(ARGS_AS_64) -o $@ $(abspath $<)

# Compiles an assembly file (32 bits - PIC)
$(PATH_BUILD_32)%$(EXT_ASM_32)$(EXT_OBJ_PIC): $$(notdir $$(subst $(EXT_OBJ_PIC),,$$@))
	
	@$(PRINT) $(PROMPT)"Compiling assembly file [ 32 bits - PIC ]: "$(COLOR_YELLOW)"$(notdir $< )"$(COLOR_NONE)" -> "$(COLOR_GRAY)"$(notdir $@)"$(COLOR_NONE)
	@$(AS_32) $(ARGS_AS_32) -o $@ $(abspath $<)

# Compiles an assembly file (32 bits)
$(PATH_BUILD_32)%$(EXT_ASM_32)$(EXT_OBJ): $$(notdir $$(subst $(EXT_OBJ),,$$@)) $$(subst $(EXT_OBJ),$(EXT_OBJ_PIC),$$@)
	
	@$(PRINT) $(PROMPT)"Compiling assembly file [ 32 bits       ]: "$(COLOR_YELLOW)"$(notdir $< )"$(COLOR_NONE)" -> "$(COLOR_GRAY)"$(notdir $@)"$(COLOR_NONE)
	@$(AS_32) $(ARGS_AS_32) -o $@ $(abspath $<)
	@if [ -f $(abspath $(subst $(EXT_ASM_32),$(EXT_ASM_64),$<)) ]; then $(MAKE) $(subst $(PATH_BUILD_32),$(PATH_BUILD_64),$(subst $(EXT_ASM_32),$(EXT_ASM_64),$@)); fi

# Compiles a C file (64 bits - PIC)
$(PATH_BUILD_64)%$(EXT_C)$(EXT_OBJ_PIC): $$(notdir $$(subst $(EXT_OBJ_PIC),,$$@))
	
	@$(PRINT) $(PROMPT)"Compiling C file [ 64 bits - PIC ]: "$(COLOR_YELLOW)"$(notdir $< )"$(COLOR_NONE)" -> "$(COLOR_GRAY)"$(notdir $@)"$(COLOR_NONE)
	@$(CC_64) $(ARGS_CC_PIC) $(ARGS_CC_64) -o $@ -c $(abspath $<)

# Compiles a C file (64 bits)
$(PATH_BUILD_64)%$(EXT_C)$(EXT_OBJ): $$(notdir $$(subst $(EXT_OBJ),,$$@)) $$(subst $(EXT_OBJ),$(EXT_OBJ_PIC),$$@)
	
	@$(PRINT) $(PROMPT)"Compiling C file [ 64 bits       ]: "$(COLOR_YELLOW)"$(notdir $< )"$(COLOR_NONE)" -> "$(COLOR_GRAY)"$(notdir $@)"$(COLOR_NONE)
	@$(CC_64) $(ARGS_CC_64) -o $@ -c $(abspath $<)

# Compiles a C file (32 bits - PIC)
$(PATH_BUILD_32)%$(EXT_C)$(EXT_OBJ_PIC): $$(notdir $$(subst $(EXT_OBJ_PIC),,$$@))
	
	@$(PRINT) $(PROMPT)"Compiling C file [ 32 bits - PIC ]: "$(COLOR_YELLOW)"$(notdir $< )"$(COLOR_NONE)" -> "$(COLOR_GRAY)"$(notdir $@)"$(COLOR_NONE)
	@$(CC_32) $(ARGS_CC_PIC) $(ARGS_CC_32) -o $@ -c $(abspath $<)

# Compiles a C file (32 bits)
$(PATH_BUILD_32)%$(EXT_C)$(EXT_OBJ): $$(notdir $$(subst $(EXT_OBJ),,$$@)) $$(subst $(PATH_BUILD_32),$(PATH_BUILD_64),$$@) $$(subst $(EXT_OBJ),$(EXT_OBJ_PIC),$$@)
	
	@$(PRINT) $(PROMPT)"Compiling C file [ 32 bits       ]: "$(COLOR_YELLOW)"$(notdir $< )"$(COLOR_NONE)" -> "$(COLOR_GRAY)"$(notdir $@)"$(COLOR_NONE)
	@$(CC_32) $(ARGS_CC_32) -o $@ -c $(abspath $<)
