/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:18:32 by ilouacha          #+#    #+#             */
/*   Updated: 2025/11/15 06:24:19 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
    // documents presenting the bit manipulation on registers is found on page 58-59 
    // of the atmega328p datasheet
int main(void) {

    // Configurer PB0 en sortie
    DDRB |= (1 << DDB0);

    // Mettre PB0 à HIGH → allume la LED D1
    PORTB |= (1 << PB0);

    while (1) {
        // boucle infinie
    }
}
