# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 06:19:17 by ilouacha          #+#    #+#              #
#    Updated: 2025/11/16 01:31:54 by ilouacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- Variables -----
MCU = atmega328p            # changer selon ton microcontrôleur
F_CPU = 16000000UL          # fréquence du MCU
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os
CPPFLAGS = -MMD -MP

# ----- Fichiers -----
SRC = main.c
BIN = main.bin
HEX = main.hex

# ----- Règles -----

all: hex flash

# règle hex : compile main.c -> main.bin -> main.hex
hex: $(HEX)
#headers
#headers = $(wildcard *.h)
$(BIN): $(SRC) #headers
	$(CC) $(CPPFLAGS) $(CFLAGS)  -o $(BIN) $(SRC) 
$(HEX): $(BIN)
	$(OBJCOPY) -O ihex -R .eeprom $(BIN) $(HEX)

# règle flash : envoie main.hex sur le microcontrôleur
flash: $(HEX)
	# Modifier la ligne ci-dessous selon ton programmateur
	avrdude -p $(MCU) -c arduino -P /dev/ttyUSB0 -b 115200 -U flash:w:$(HEX):i

# règle clean : supprime fichiers générés
clean:
	rm -f $(BIN) $(HEX) *.d
	
.PHONY: all flash clean hex
