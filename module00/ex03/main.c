/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:15:46 by ilouacha          #+#    #+#             */
/*   Updated: 2025/11/15 11:02:04 by ilouacha         ###   ########.fr       */
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
    uint8_t led_state = 0; // 0 : éteinte, 1 : allumée

    while (1){
        uint8_t button_state = (PIND & (1 << PIND2) ) ? 1 : 0;//1:bouton relaché, 0 sinon
        // FRONT DESCENDANT : HIGH -> LOW => bouton pressé
        if (button_state == 1 && led_state == 0){
            PORTB |= (1 << PB0); //allumer la led
            led_state = 1;
        } 
        else if (button_state == 1 && led_state == 1){
            PORTB &= ~(1 << PB0); //éteindre la led
            led_state = 0;
        }
        _delay_ms(10);
    }
    
    
}