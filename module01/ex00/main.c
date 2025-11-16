/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:30:15 by ilouacha          #+#    #+#             */
/*   Updated: 2025/11/16 03:21:52 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
#include <util/delay.h>

int main() {
    // led D2 est en sortie
    DDRB |= (1 << DDB1);

    while (1) {
        PORTB |= (1 << PB1); // Allumer la LED D2
        _delay_ms(500); // Attendre 500 ms
        PORTB &= ~(1 << PB1); // Éteindre la LED D2
        _delay_ms(500); // Attendre 500 ms
    }
}