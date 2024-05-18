

rfid.ino RFID.cpp RFID
    .h

    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53
/* RFID.h - Library to use ARDUINO RFID MODULE KIT 13.56 MHZ WITH TAGS SPI W AND
 * R BY COOQROBOT. Based on code Dr.Leong   ( WWW.B2CQSHOP.COM ) Created by
 * Miguel Balboa (circuitito.com), Jan, 2012. Modified by Paul Kourany to run on
 * Spark Core with added support for Software SPI, Mar, 2014.
 */
#ifndef RFID_h
#define RFID_h
#include "application.h"
/* !!! Uncomment the following line if SOFT SPI is to be used !!! */
#define _USE_SOFT_SPI_
/******************************************************************************
 * Definitions
 ******************************************************************************/
#define MAX_LEN 16  // Largo mÃ¡ximo de la matriz
// MF522 comando palabra
#define PCD_IDLE 0x00        // NO action; Y cancelar el comando
#define PCD_AUTHENT 0x0E     // autenticaciÃ³n de clave
#define PCD_RECEIVE 0x08     // recepciÃ³n de datos
#define PCD_TRANSMIT 0x04    // Enviar datos
#define PCD_TRANSCEIVE 0x0C  // Enviar y recibir datos
#define PCD_RESETPHASE 0x0F  // reajustar
#define PCD_CALCCRC 0x03     // CRC calcular
// Mifare_One  Tarjeta Mifare_One comando palabra
#define PICC_REQIDL \
    0x26  // Area de la antena no esta tratando de entrar en el estado de reposo
#define PICC_REQALL \
    0x52  // Todas las cartas para encontrar el Ã¡rea de la antena
#define PICC_ANTICOLL 0x93   // anti-colisiÃ³n
#define PICC_SElECTTAG 0x93  // elecciÃ³n de tarjeta
#define PICC_AUTHENT1A 0x60  // verificaciÃ³n key A
#define PICC_AUTHENT1B 0x61  // verificaciÃ³n Key B
#define PICC_READ 0x30       // leer bloque
#define PICC_WRITE 0xA0      // Escribir en el bloque
#define PICC_DECREMENT 0xC0  // cargo
#define PICC_INCREMENT 0xC1  // recargar
#define PICC_RESTORE 0xC2    // Transferencia de datos de bloque de buffer
#define PICC_TRANSFER 0xB0   // Guardar los datos en el bÃºfer
#define PICC_HALT 0x50       // inactividad
// MF522 CÃ³digo de error de comunicaciÃ³n cuando regresÃ³
#define MI_OK 0
#define MI_NOTAGERR 1
#define MI_ERR 2
//------------------ MFRC522 registro---------------
// Page 0:Command and Status
#define Reserved00 0x00
#define CommandReg 0x01
#define CommIEnReg 0x02
    Ready.watch_i2c v5 .6.0
