/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:15:46 by ilouacha          #+#    #+#             */
/*   Updated: 2025/11/15 23:05:51 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
#include <util/delay.h>

int main() {
    // documents presenting the bit manipulation on registers is found on page 58-59 
    // of the atmega328p datasheet
    // PB0 = sortie → LED D1
    DDRB |= (1 << DDB0); 
    // PD2 = entrée → bouton SW1
    DDRD &= ~( 1 << DDD2);
    // Activer la résistance pull-up sur PD2
    // Bouton relâché = HIGH
    // Bouton appuyé = LOW
    PORTD |= (1 << PD2);
    uint8_t previous_button = 1; // 1 : relâché, 0 : appuyé

    while (1){
        uint8_t current_button = (PIND & (1 << PIND2) ) ? 1 : 0;//1:bouton relaché, 0 sinon
        // FRONT DESCENDANT : HIGH -> LOW => bouton pressé
        if (previous_button == 1 && current_button == 0){
            // We have two ways to toggle the LED, either by using XOR or by using the PIN register
            //PORTB ^= (1 << PB0); //allumer la led si éteinte, éteindre si allumée
            PINB |= 1 <<PB0; //toggle de la led
        } 
        previous_button = current_button;
        _delay_ms(10); //anti-rebond
    }
    
    
}