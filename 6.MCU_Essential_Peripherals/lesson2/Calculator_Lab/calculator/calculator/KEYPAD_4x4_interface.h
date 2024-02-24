/*
 * KBD_interface.h
 *
 *  Created on: Mar 16, 2023
 *      Author: Hello
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define KPD_NOT_PRESSED  0Xff

void    KPD_getValue   (u8* returned_value);
void    KPD_init       (void);

#endif /* KPD_INTERFACE_H_ */
