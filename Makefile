# sharing basic makefile

PRO_DIR		:= .
PROJ_NAME	:= demo_stm32f407vgt6u
OUTPUT_PATH := $(PRO_DIR)/output

INC_DIR		:= $(PRO_DIR)/inc
SRC_DIR 	:= $(PRO_DIR)/src
LINKER_FILE	:= $(PRO_DIR)/linker/stm32f407vgt6u.ld

COMPILER_DIR 	:= C:/GCC/8-2018-q4-major
PREFIX_GCC_COMPILER	:= arm-none-eabi
CC				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-gcc
ASM				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-as
LD				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-ld

FILE_TO_LINK	:= $(OUTPUT_PATH)/main.o $(OUTPUT_PATH)/startup_ARMCM4.o

CC_OPT			:= -march=armv7-m -mcpu=cortex-m4 -c -O0 -g -mthumb -I$(INC_DIR)
ASM_OPT			:= -march=armv7-m -mcpu=cortex-m4 -c -mthumb
LD_OPT			:= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK)

$(OUTPUT_PATH)/main.o: $(SRC_DIR)/main.c
	@echo "compile $(SRC_DIR)/main.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/main.c -o $(OUTPUT_PATH)/main.o

$(OUTPUT_PATH)/startup_ARMCM4.o: $(SRC_DIR)/startup_ARMCM4.S
	@echo "compile $(SRC_DIR)/startup_ARMCM4.S file"
	$(ASM) $(ASM_OPT) $(SRC_DIR)/startup_ARMCM4.s -o $(OUTPUT_PATH)/startup_ARMCM4.o

build: $(FILE_TO_LINK) $(LINKER_FILE)
	@echo "link object files to create new binary image ($(PROJ_NAME).elf)"
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf
	
clean:
	@rm -rf $(OUTPUT_PATH)/*

