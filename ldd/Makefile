#########################################
# Makefile for STM32F0 + reserved memory
#########################################

TARGET    = firmware
BUILD_DIR = build

# Toolchain
CC      = arm-none-eabi-gcc
AS      = arm-none-eabi-as
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

# CPU flags — adjust for your chip
CPU_FLAGS = -mcpu=cortex-m0 -mthumb

# Source files
C_SOURCES  = src/main.c src/reserved_memory.c
ASM_SOURCE = startup_stm32f0xx.s
LINKER     = linker.ld

# Compiler flags
CFLAGS  = $(CPU_FLAGS)
CFLAGS += -Wall -Wextra               # all warnings
CFLAGS += -O1                         # light optimization
CFLAGS += -ffunction-sections         # each function in own section
CFLAGS += -fdata-sections             # each variable in own section
CFLAGS += -Isrc                       # include path
CFLAGS += -g                          # debug symbols

# Linker flags
LDFLAGS  = $(CPU_FLAGS)
LDFLAGS += -T$(LINKER)
LDFLAGS += -Wl,--gc-sections          # remove unused sections
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/$(TARGET).map   # generate map file
LDFLAGS += -nostdlib                  # no host libc
LDFLAGS += -Wl,--print-memory-usage   # show Flash/RAM usage

# Object files
OBJS  = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(C_SOURCES))
OBJS += $(BUILD_DIR)/startup.o

#########################################
# Build rules
#########################################

all: $(BUILD_DIR)/$(TARGET).bin size

# Compile C files
$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble startup
$(BUILD_DIR)/startup.o: $(ASM_SOURCE) | $(BUILD_DIR)
	$(CC) $(CPU_FLAGS) -c $< -o $@

# Link → ELF
$(BUILD_DIR)/$(TARGET).elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# ELF → raw binary for flashing
$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# Show Flash/RAM sizes
size: $(BUILD_DIR)/$(TARGET).elf
	$(SIZE) $

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Flash via OpenOCD + ST-Link
flash: $(BUILD_DIR)/$(TARGET).bin
	openocd -f interface/stlink.cfg \
		-f target/stm32f0x.cfg \
		-c "program $(BUILD_DIR)/$(TARGET).bin \
		verify reset exit 0x08000000"

# Erase entire chip
erase:
	openocd -f interface/stlink.cfg \
		-f target/stm32f0x.cfg \
		-c "init; reset halt; flash erase_address \
		0x08000000 0x10000; exit"

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all flash erase clean size
