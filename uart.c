#include "uart.h"
#include <stdint.h>

//Check if the receiver is empty
__attribute__((always_inline)) inline _Bool uart_is_rx_empty() {
	return (global_uart->state_reg & UART_RX_FIFO_NOT_EMPTY) ? 0 : 1;
}

// Check if the transmitter is empty
__attribute__((always_inline)) inline _Bool uart_is_tx_empty() {
	return (global_uart->state_reg & UART_TX_EMPTY) ? 1 : 0;
}


// Send a single character to the UART
void uart_send_char(uint8_t ch) {
    
    while (!uart_is_tx_empty()) {
        // If the transmitter is not empty, wait until it becomes empty
    }

    // Write the character to the transmitter
    global_uart->tx = ch;
    
    
}
// Waits until a character is received on UART (RX) and returns it.
uint32_t uart_get_char(){

    while(uart_is_rx_empty()){
        // Wait until data is available in the RX buffer
    }
    return global_uart->rx;
    
}
