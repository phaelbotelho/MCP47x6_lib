/* 
 * File:   mcp47x6.c
 * Author: raphael.pereira
 *
 * Created on 29 de Junho de 2018, 13:30
 */

#include "mcp47x6.h"
#include "config.h"
#include "my_i2c.h"

void MCP47x6_Init()
{
    MCP47x06_Reset();
}

/*This routine use the General Call to reset the device
 reaload the EEPROM into the DAC registers.*/
void MCP47x06_Reset()
{
    I2C_Start();
    I2C_WriteByte(GENERAL_CALL_ADR); // General Call address.
    I2C_WriteByte(GENERAL_CALL_RESET_ADR); // General Wake-up Command.
    I2C_Stop();
}

/*This routine use the General Call to wake-up the device
 form a power-down, dosn't affect the EEPROM data.*/
void MCP47x06_Wakeup()
{
    I2C_Start();
    I2C_WriteByte(GENERAL_CALL_ADR); // General Call address.
    I2C_WriteByte(GENERAL_CALL_WAKEUP_ADR); // General Wake-up Command.
    I2C_Stop();
}

unsigned int MCP47x6_Read_DAC(unsigned char mcp47x6_adr)
{
    // reads data from the sensor and stores them in temporary variables that
    // are then accessed via public variables
    I2C_Start();
    I2C_WriteByte(mcp47x6_adr); // Send the ADR to the talk device.
    I2C_RepeatedStart();
    I2C_WriteByte(mcp47x6_adr + 1); // Send the ADR to the talk device.
    value_hi = I2C_ReadByte(1); // Read the data
    value_hi = I2C_ReadByte(1); // Read the data
    value_lo = I2C_ReadByte(0); // Read the data
    I2C_Stop();
    
    return (((unsigned int)value_hi) << 8) | (value_lo);
}

void MCP47x6_Write_DAC(unsigned char mcp47x6_adr, unsigned int value_dac)
{
    // Change the baud os i2c form more fast communication.
    //I2C_Init(I2C_HS_Frequency); // I2C 100kHz, 8MHz-CRYSTAL.
    
    I2C_Start();
    I2C_WriteByte(mcp47x6_adr); // Send the ADR to the talk device.
    I2C_WriteByte((unsigned char) ((value_dac >> 8) & 0x0F));// MSB: (D11, D10, D9, D8) 
    I2C_WriteByte((unsigned char) value_dac); // LSB: (D7, D6, D5, D4, D3, D2, D1, D0)
    I2C_Stop();
    
    //I2C_Init(I2C_STD_Frequency); // I2C 100kHz, 8MHz-CRYSTAL.
}



