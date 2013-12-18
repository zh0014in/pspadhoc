/*
 * This file is part of PRO ONLINE.

 * PRO ONLINE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * PRO ONLINE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PRO ONLINE. If not, see <http://www.gnu.org/licenses/ .
 */

#ifndef _ADHOC_FUNCTIONS_H_
#define _ADHOC_FUNCTIONS_H_

/**
 * Mersenne Twister Number Generator
 * @param max Maximum Range of Number
 * @return Random unsigned 32bit Number
 */
uint32_t _getRandomNumber(uint32_t max);

/**
 * Closes & Deletes all PDP Sockets
 */
void _deleteAllPDP(void);

/**
 * Closes & Deletes all PTP Sockets
 */
void _deleteAllPTP(void);

/**
 * Deletes all Gamemode Buffer
 */
void _deleteAllGMB(void);

/**
 * Local MAC Check
 * @param saddr To-be-checked MAC Address
 * @return 1 if valid or... 0
 */
int _IsLocalMAC(const SceNetEtherAddr * addr);

/**
 * PDP Port Check
 * @param port To-be-checked Port
 * @return 1 if in use or... 0
 */
int _IsPDPPortInUse(uint16_t port);

/**
 * PDP Socket Counter
 * @return Number of internal PDP Sockets
 */
int _getPDPSocketCount(void);

/**
 * Broadcast MAC Check
 * @param addr To-be-checked MAC Address
 * @return 1 if Broadcast MAC or... 0
 */
int _isBroadcastMAC(const SceNetEtherAddr * addr);

/**
 * PTP Socket Counter
 * @return Number of internal PTP Sockets
 */
int _getPTPSocketCount(void);

/**
 * Check whether PTP Port is in use or not
 * @param port To-be-checked Port Number
 * @return 1 if in use or... 0
 */
int _IsPTPPortInUse(uint16_t port);

/**
 * Add Port Forward to Router
 * @param protocol "TCP" or "UDP"
 * @param port To-be-forwarded Port Number
 */
void sceNetPortOpen(const char * protocol, uint16_t port);

/**
 * Remove Port Forward from Router
 * @param protocol "TCP" or "UDP"
 * @param port To-be-removed Port Number
 */
void sceNetPortClose(const char * protocol, uint16_t port);

#endif
