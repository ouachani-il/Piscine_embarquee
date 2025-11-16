/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:22:23 by ilouacha          #+#    #+#             */
/*   Updated: 2025/11/16 01:22:11 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
#include <util/delay.h>

int main() {
    // documents presenting the bit manipulation on registers is found on page 58-59 
    // of the atmega328p datasheet
    
    // leds D1, D2, D3 et D4 sont des sorties
    DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB4);
    
    // PD2 = entrée → bouton SW1 et PD3 = entrée → bouton SW2 
    DDRD &= ~(( 1 << DDD2) | ( 1 << DDD3));
    // Activer la résistance pull-up sur PD2, idem pour PD4
    // Bouton relâché = HIGH
    // Bouton appuyé = LOW
    PORTD |= (1 << PD2) | (1 << PD4);
    
    uint8_t value = 0;
    uint8_t previous_SW1 = 1; // 1 : relâché, 0 : appuyé
    uint8_t previous_SW2 = 1; // 1 : relâché, 0 : appuyé

    while (1){
        uint8_t current_SW1 = (PIND & (1 << PIND2) ) ? 1 : 0;//1:bouton relaché, 0 sinon
        uint8_t current_SW2 = (PIND & (1 << PIND4) ) ? 1 : 0;//1:bouton relaché, 0 sinon

        // SW1 FRONT DESCENDANT : HIGH -> LOW => bouton pressé
        if (previous_SW1 == 1 && current_SW1 == 0){
            // we increment value
            value++;
            if (value > 15)
                value = 0;            
        } 
        // SW2 FRONT DESCENDANT : HIGH -> LOW => bouton pressé
        if (previous_SW2 == 1 && current_SW2 == 0){
            // we increment value
            if (value > 0)
                value--;
            else
                value = 15;
        } 
        // we update the LEDs according to value
        PORTB = (PORTB & 0b11101000) | (value & 0b00000111) | ((value & 0b00001000) << 1 );
        previous_SW1 = current_SW1;
        previous_SW2 = current_SW2;
        _delay_ms(10); //anti-rebond
    }
    
    
}