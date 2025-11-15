/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:24:58 by ilouacha          #+#    #+#             */
/*   Updated: 2025/11/15 10:40:53 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <avr/io.h>
#include <util/delay.h>

int main() {
    // documents presenting the bit manipulation on registers is found on page 58-59 
    // of the atmega328p datasheet
    
    // PB0 = sortie → LED D1
    DDRB |= (1 << DDB0); // 1 : output, 0 : input 0000 00001

    // PD2 = entrée → bouton SW1
    DDRD &= ~(1 << DDD2); // : input 0   port d 0000 0000 <- 3eme bite a 0 means that the 
                        //pin2 of port D is input.
    
    // Activer la résistance pull-up sur PD2
    // Bouton relâché = HIGH
    // Bouton appuyé = LOW
    PORTD |= (1 << PD2);
    
    while(1){
        if (PIND & (1 << PIND2)) { // if the pin2 of port D is high
            PORTB &= ~(1 << PB0); // turn off the led
        } else {
            PORTB |= (1 << PB0); // turn on the led
        }
        // Petite pause pour éviter l'effet rebond (bouncing), delay = 5 car lke redond dure en moyenne 1ms
        _delay_ms(5); 
    }    

}