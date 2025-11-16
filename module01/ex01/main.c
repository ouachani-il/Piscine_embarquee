/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 03:23:15 by ilouacha          #+#    #+#             */
/*   Updated: 2025/11/16 06:23:38 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
#include <util/delay.h>

int main() {
    //led D2 est en sortie
    DDRB |= (1 << DDB1);
    // Comme il est interdit d'utiliser _delay_ms ainsi que PORTB dans 
    // une boucle, on va configurer le timer
    
    while (1) {
    }
    }
int main(void)
{
    // PB1 (OC1A) doit être en sortie pour laisser le timer le piloter
    DDRB |= (1 << DDB1);

    // Mode CTC : WGM12 = 1
    TCCR1B |= (1 << WGM12);

    // Toggle OC1A on compare match : COM1A0 = 1
    TCCR1A |= (1 << COM1A0);

    // Valeur pour 0.5 s → toggle à 2 Hz
    OCR1A = 7812;

    // Prescaler 1024 : CS12 = 1, CS11 = 0, CS10 = 1
    TCCR1B |= (1 << CS12) | (1 << CS10);

    // Boucle infinie vide
    while (1) {
        // rien du tout !
    }
}
