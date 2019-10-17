/* 
 * File:   mcp47x6.h
 * Author: raphael.pereira
 *
 * Created on 29 de Junho de 2018, 13:30
 */

#ifndef MCP47X6_H
#define	MCP47X6_H

#define MCP47x6_ADR_A0 0xC0
#define MCP47x6_ADR_A1 0xC2
#define MCP47x6_ADR_A2 0xC4
#define MCP47x6_ADR_A3 0xC6
#define MCP47x6_ADR_A4 0xC8
#define MCP47x6_ADR_A5 0xCA
#define MCP47x6_ADR_A6 0xCC
#define MCP47x6_ADR_A7 0xCE

#define GENERAL_CALL_ADR 0x00
#define GENERAL_CALL_RESET_ADR 0x06
#define GENERAL_CALL_WAKEUP_ADR 0x09

// Programmable Gain definitions
#define MCP47x6_GAIN_MASK	0xFE
#define MCP47x6_GAIN_1X	0x00
#define MCP47x6_GAIN_2X	0x01

// Power Down Mode definitions
#define MCP47x6_PWRDN_MASK     0xF9
#define MCP47x6_AWAKE          0x00
#define MCP47x6_PWRDN_1K       0x02
#define MCP47x6_PWRDN_100K     0x04
#define MCP47x6_PWRDN_500K     0x06

// Reference Voltage definitions
#define MCP47x6_VREF_MASK             0xE7
#define MCP47x6_VREF_VDD              0x00
#define MCP47x6_VREF_VREFPIN	      0x10
#define MCP47x6_VREF_VREFPIN_BUFFERED 0x18

// Command definitioins
#define MCP47x6_CMD_MASK       0x1F
#define MCP47x6_CMD_VOLDAC     0x00
#define MCP47x6_CMD_VOLALL     0x40
#define MCP47x6_CMD_VOLCONFIG  0x80
#define MCP47x6_CMD_ALL        0x60

unsigned char value_lo = 0;
unsigned char value_hi = 0;

void MCP47x6_Init();
void MCP47x06_Reset();
void MCP47x06_Wakeup();
unsigned int MCP47x6_Read_DAC(unsigned char mcp47x06_adr);

void MCP47x6_Write_DAC(unsigned char mcp47x6_adr, unsigned int value_dac);

#endif	/* MCP47X6_H */

