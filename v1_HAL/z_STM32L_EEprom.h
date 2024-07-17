/*
 * z_STM32L_Internal_EEprom.h
 *
 *  Created on: May 16, 2024
 *      Author: mauro
 */

#ifndef INC_Z_STM32L_EEPROM_H_
#define INC_Z_STM32L_EEPROM_H_



void STM32L_LockEeprom();
void STM32L_UnlockEeprom();
void STM32L_EraseEeprom(uint32_t Cmd, uint32_t address) ;
void STM32L_ProgramEeprom(uint32_t Cmd, uint32_t address, uint32_t value);



#endif /* INC_Z_STM32L_EEPROM_H_ */
