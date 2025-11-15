# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 06:18:52 by ilouacha          #+#    #+#              #
#    Updated: 2025/11/15 06:18:53 by ilouacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- Variables -----
MCU = atmega328p            # c'est notre microcontrôleur
F_CPU = 16000000UL          # fréquence du MCU
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os

# ----- Fichiers -----
SRC = main.c
BIN = main.bin
HEX = main.hex

# ----- Règles -----

all: hex flash

# règle hex : compile main.c -> main.bin -> main.hex
hex: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)
	$(OBJCOPY) -O ihex -R .eeprom $(BIN) $(HEX)

# règle flash : envoie main.hex sur le microcontrôleur
flash: $(HEX)
	avrdude -p $(MCU) -c arduino -P /dev/ttyUSB0 -b 115200 -U flash:w:$(HEX):i

# règle clean : supprime fichiers générés
clean:
	rm -f $(BIN) $(HEX)
